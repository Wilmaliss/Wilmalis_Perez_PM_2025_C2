#include <stdio.h> //Permite usar funciones para entrada y salida, como printf() y fgets().
#include <string.h> //Te da acceso a funciones para trabajar con cadenas de texto,
#include <ctype.h>  //Sirve para operaciones con caracteres individuales
#include <stdlib.h> // Para system() y exit()

//  Compatibilidad para Windows y otros sistemas (Linux, macOS)
#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#endif

// Definimos true y false para que el código sea más legible
#define true 1
#define false 0

char tablero[8][8] = {
    {'r','n','b','q','k','b','n','r'}, // Fila 0 (Rank 8) - Negras
    {'p','p','p','p','p','p','p','p'}, // Fila 1 (Rank 7) - Negras
    {'.','.','.','.','.','.','.','.'},
    {'.','.','.','.','.','.','.','.'},
    {'.','.','.','.','.','.','.','.'},
    {'.','.','.','.','.','.','.','.'},
    {'P','P','P','P','P','P','P','P'}, // Fila 6 (Rank 2) - Blancas (MAYUSCULAS)
    {'R','N','B','Q','K','B','N','R'}  // Fila 7 (Rank 1) - Blancas (MAYUSCULAS)
};

// Contadores de piezas capturadas
int capturadasBlancas = 0;
int capturadasNegras = 0;

// Banderas para el enroque. Se ponen a 'true' si la pieza se mueve.
int reyBlancoMovido = false;
int torreBlancaIMovida = false; // Torre de la columna 'a'
int torreBlancaDMovida = false; // Torre de la columna 'h'
int reyNegroMovido = false;
int torreNegraIMovida = false; // Torre de la columna 'a'
int torreNegraDMovida = false; // Torre de la columna 'h'

// Prototipos de funciones para que podamos usarlas antes de definirlas
int esMovimientoValido(char pieza, int filaIni, int colIni, int filaFin, int colFin, int ignorarCamino);
int estaEnJaque(char jugadorColor);
void hacerMovimiento(int filaIni, int colIni, int filaFin, int colFin);
void deshacerMovimiento(int filaIni, int colIni, int filaFin, int colFin, char piezaCapturada);

// Función para limpiar la pantalla en cualquier sistema operativo
void limpiarPantalla() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

// Cambiar colores de texto y fondo
void ponerColor(int fondo, int texto) {
#ifdef _WIN32
    HANDLE consola = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(consola, fondo * 16 + texto);
#else
    // NUEVO: Usamos secuencias de escape ANSI para Linux y macOS
    // No es una conversión 1 a 1, pero da colores distintos
    if (fondo == 1 && texto == 15) printf("\x1b[47;30m"); // Fondo blanco, texto negro (Pieza blanca)
    else if (fondo == 1 && texto == 12) printf("\x1b[47;31m"); // Fondo blanco, texto rojo (Pieza negra)
    else if (fondo == 7 && texto == 15) printf("\x1b[40;37m"); // Fondo negro, texto blanco (Pieza blanca)
    else if (fondo == 7 && texto == 12) printf("\x1b[40;31m"); // Fondo negro, texto rojo (Pieza negra)
    else if (fondo == 1 || fondo == 7) printf("\x1b[0m"); // Reset para espacios
    else printf("\x1b[0m"); // Color por defecto para el resto
#endif
}


// Mostrar el tablero y estado
void mostrarTablero(char jugadorAnterior[], int turno, char jugadorActual[]) {
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    printf("ESTADO DEL JUEGO\n");
    printf("> TURNO #%d\n", turno);
    printf("> Le toca a %s\n", jugadorActual);
    // Aviso si el jugador está en jaque
    if (estaEnJaque(jugadorActual[0])) {
        printf("> !!JAQUE!!\n");
    }
    printf("JUGADOR 1: PIEZAS BLANCAS (MAYUSCULAS)\n");
    printf("JUGADOR 2: PIEZAS NEGRAS (minusculas)\n");
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n");

    printf("Tablero despues del movimiento de %s:\n\n", jugadorAnterior);
    ponerColor(0, 14); // Color amarillo para coordenadas
    printf("    a  b  c  d  e  f  g  h\n");
    ponerColor(0, 7); // Resetear color

    for (int fila = 0; fila < 8; fila++) {
        ponerColor(0, 14);
        printf(" %d ", 8 - fila); // Coordenadas 8 a 1
        ponerColor(0, 7);

        for (int col = 0; col < 8; col++) {
            char pieza = tablero[fila][col];
            // Lógica de colores simplificada
            int esCasillaBlanca = (fila + col) % 2 == 0;
            int fondo = esCasillaBlanca ? 7 : 1; // Fondo gris claro o oscuro (consola)
            int texto;

            if (pieza == '.') {
                ponerColor(fondo, fondo);
                printf("   ");
            } else {
                // Piezas blancas son blancas (15), negras son rojas (12)
                texto = isupper(pieza) ? 15 : 12;
                ponerColor(fondo, texto);
                printf(" %c ", pieza); // NUEVO: Mostramos la pieza con su case original
            }
        }
        ponerColor(0, 14);
        printf(" %d\n", 8 - fila);
        ponerColor(0, 7);
    }
    ponerColor(0, 14);
    printf("    a  b  c  d  e  f  g  h\n\n");
    ponerColor(0, 7);

    printf("LEYENDA:\n");
    printf("Q=Reina K=Rey R=Torre B=Alfil N=Caballo P=Peon\n");
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
}
// Función refactorizada para ver si el camino está libre para Torres, Alfiles y Reinas
int esCaminoLibre(int filaIni, int colIni, int filaFin, int colFin) {
    int df = (filaFin > filaIni) ? 1 : (filaFin < filaIni) ? -1 : 0;
    int dc = (colFin > colIni) ? 1 : (colFin < colIni) ? -1 : 0;
    int f = filaIni + df;
    int c = colIni + dc;
    while (f != filaFin || c != colFin) {
        if (tablero[f][c] != '.') return false;
        f += df;
        c += dc;
    }
    return true;
}
// Lógica de movimiento del rey para el enroque
int esMovimientoDeEnroque(int filaIni, int colIni, int filaFin, int colFin) {
    char jugador = isupper(tablero[filaIni][colIni]) ? 'B' : 'N';
    if (abs(colFin - colIni) != 2 || filaIni != filaFin) return false; // No es un movimiento de enroque
    // Enroque corto (hacia la derecha)
    if (colFin > colIni) {
        if ((jugador == 'B' && (reyBlancoMovido || torreBlancaDMovida)) ||
            (jugador == 'N' && (reyNegroMovido || torreNegraDMovida))) return false;
        if (!esCaminoLibre(filaIni, colIni, filaIni, colIni + 3)) return false;
        // El rey no puede pasar por una casilla atacada
        if (estaEnJaque(jugador)) return false; // Ya en jaque
        // Simular movimiento a f1/f8 y ver si hay jaque
        hacerMovimiento(filaIni, colIni, filaIni, colIni + 1);
        if (estaEnJaque(jugador)) {
            deshacerMovimiento(filaIni, colIni, filaIni, colIni + 1, '.');
            return false;
        }
        deshacerMovimiento(filaIni, colIni, filaIni, colIni + 1, '.');
        return true;
    }
    // Enroque largo (hacia la izquierda)
    else {
        if ((jugador == 'B' && (reyBlancoMovido || torreBlancaIMovida)) ||
            (jugador == 'N' && (reyNegroMovido || torreNegraIMovida))) return false;
        if (!esCaminoLibre(filaIni, colIni, filaIni, colIni - 4)) return false;
        // El rey no puede pasar por una casilla atacada
        if (estaEnJaque(jugador)) return false; // Ya en jaque
        hacerMovimiento(filaIni, colIni, filaIni, colIni - 1);
        if (estaEnJaque(jugador)) {
            deshacerMovimiento(filaIni, colIni, filaIni, colIni - 1, '.');
            return false;
        }
        deshacerMovimiento(filaIni, colIni, filaIni, colIni - 1, '.');
        return true;
    }
}
//Parámetro 'ignorarCamino' para la función estaEnJaque
int esMovimientoValido(char pieza, int filaIni, int colIni, int filaFin, int colFin, int ignorarCamino) {
    char piezaOriginal = tablero[filaIni][colIni];
    int df = filaFin - filaIni;
    int dc = colFin - colIni;
    //  No se puede capturar una pieza del mismo color
    if (tablero[filaFin][colFin] != '.' &&
        (isupper(tablero[filaFin][colFin]) == isupper(piezaOriginal))) {
        return false;
    }
    switch (tolower(pieza)) {
        // PEÓN
        case 'p': {
            int sentido = isupper(piezaOriginal) ? -1 : 1; // Blancas suben (-1), negras bajan (+1)
            int filaInicial = isupper(piezaOriginal) ? 6 : 1;
            // Movimiento simple hacia adelante
            if (df == sentido && dc == 0 && tablero[filaFin][colFin] == '.')
                return true;
            // Primer movimiento de dos pasos
            if (df == 2 * sentido && dc == 0 && filaIni == filaInicial &&
                tablero[filaIni + sentido][colIni] == '.' &&
                tablero[filaFin][colFin] == '.')
                return true;
            // Captura en diagonal
            if (df == sentido && abs(dc) == 1 &&
                tablero[filaFin][colFin] != '.' &&
                (isupper(tablero[filaFin][colFin]) != isupper(piezaOriginal)))
                return true;
            return false;
        }
        // TORRE
        case 'r': {
            if (df != 0 && dc != 0) return false; // Solo líneas rectas
            return ignorarCamino || esCaminoLibre(filaIni, colIni, filaFin, colFin);
        }
        // CABALLO
        case 'n':
            return (abs(df) == 2 && abs(dc) == 1) || (abs(df) == 1 && abs(dc) == 2);
        // ALFIL
        case 'b': {
            if (abs(df) != abs(dc)) return false; // Solo en diagonales
            return ignorarCamino || esCaminoLibre(filaIni, colIni, filaFin, colFin);
        }
        // REINA
        case 'q': {
            if ((df != 0 && dc != 0) && (abs(df) != abs(dc))) return false; // Si no es ni recto ni diagonal
            return ignorarCamino || esCaminoLibre(filaIni, colIni, filaFin, colFin);
        }
        // REY
        case 'k': {
            if (esMovimientoDeEnroque(filaIni, colIni, filaFin, colFin)) return true;
            return abs(df) <= 1 && abs(dc) <= 1;
        }
        default:
            return false; // Pieza no reconocida
    }
}
//Función para verificar si un jugador está en jaque
int estaEnJaque(char jugadorColor) {
    int reyFila, reyCol;
    char rey = (jugadorColor == 'B' || jugadorColor == 'b') ? 'K' : 'k';
    // Encontrar al rey
    for (int f = 0; f < 8; f++) {
        for (int c = 0; c < 8; c++) {
            if (tablero[f][c] == rey) {
                reyFila = f;
                reyCol = c;
                break;
            }
        }
    }
    // Revisar si alguna pieza enemiga puede atacar al rey
    for (int f = 0; f < 8; f++) {
        for (int c = 0; c < 8; c++) {
            char pieza = tablero[f][c];
            if (pieza != '.' && (isupper(pieza) != isupper(rey))) {
                // El 'true' final ignora si hay piezas en medio, crucial para detectar jaque
                if (esMovimientoValido(pieza, f, c, reyFila, reyCol, true)) {
                    return true;
                }
            }
        }
    }
    return false;
}
//  Función para realizar un movimiento
void hacerMovimiento(int filaIni, int colIni, int filaFin, int colFin) {
    tablero[filaFin][colFin] = tablero[filaIni][colIni];
    tablero[filaIni][colIni] = '.';
}
// Función para deshacer un movimiento (para validaciones)
void deshacerMovimiento(int filaIni, int colIni, int filaFin, int colFin, char piezaCapturada) {
    tablero[filaIni][colIni] = tablero[filaFin][colFin];
    tablero[filaFin][colFin] = piezaCapturada;
}
//  Función para ver si el jugador tiene algún movimiento legal
int hayMovimientoLegal(char jugadorColor) {
    char pieza;
    for (int f_ini = 0; f_ini < 8; f_ini++) {
        for (int c_ini = 0; c_ini < 8; c_ini++) {
            pieza = tablero[f_ini][c_ini];
            // Si la pieza es del jugador actual
            if (pieza != '.' && (isupper(pieza) == (jugadorColor == 'B'))) {
                // Probar moverla a todas las casillas
                for (int f_fin = 0; f_fin < 8; f_fin++) {
                    for (int c_fin = 0; c_fin < 8; c_fin++) {
                        if (esMovimientoValido(pieza, f_ini, c_ini, f_fin, c_fin, false)) {
                            char piezaCapturada = tablero[f_fin][c_fin];
                            hacerMovimiento(f_ini, c_ini, f_fin, c_fin);
                            if (!estaEnJaque(jugadorColor)) {
                                // Encontramos un movimiento legal
                                deshacerMovimiento(f_ini, c_ini, f_fin, c_fin, piezaCapturada);
                                return true;
                            }
                            deshacerMovimiento(f_ini, c_ini, f_fin, c_fin, piezaCapturada);
                        }
                    }
                }
            }
        }
    }
    return false;
}
//  Función para la promoción del peón
void promocionDePeon(int fila, int col) {
    char nuevaPieza;
    char jugadorColor = (fila == 0) ? 'B' : 'N';

    printf("¡Promoción de peón! Elige una pieza (Q, R, B, N): ");
    while (1) {
        scanf(" %c", &nuevaPieza);
        while(getchar() != '\n'); // Limpiar buffer de entrada

        nuevaPieza = toupper(nuevaPieza);
        if (nuevaPieza == 'Q' || nuevaPieza == 'R' || nuevaPieza == 'B' || nuevaPieza == 'N') {
            tablero[fila][col] = (jugadorColor == 'B') ? nuevaPieza : tolower(nuevaPieza);
            break;
        } else {
            printf("Pieza inválida. Elige Q, R, B o N: ");
        }
    }
}
int main() {
    int turno = 1;
    char jugadorActual[10] = "BLANCAS";
    char jugadorAnterior[10] = "NINGUNO";
    char ultimoMovimiento[20] = "Ninguno";
    char penultimoMovimiento[20] = "Ninguno";
    while (1) {
        limpiarPantalla();
        mostrarTablero(jugadorAnterior, turno, jugadorActual);

        //  Lógica de fin de juego (Jaque Mate y Ahogado)
        char jugadorColor = (strcmp(jugadorActual, "BLANCAS") == 0) ? 'B' : 'N';
        if (!hayMovimientoLegal(jugadorColor)) {
            if (estaEnJaque(jugadorColor)) {
                printf("\n!! JAQUE MATE !!\n");
                printf("Ganan las %s\n", (jugadorColor == 'B') ? "NEGRAS" : "BLANCAS");
            } else {
                printf("\n!! AHOGADO !!\n");
                printf("El juego es un empate.\n");
            }
            break;
        }
        // Historial
        printf("\nHISTORIAL DE MOVIMIENTOS:\n");
        printf("1. %s\n", penultimoMovimiento);
        printf("2. %s\n", ultimoMovimiento);

        // Piezas capturadas
        printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
        printf("CAPTURAS:\n");
        printf("BLANCAS | NEGRAS\n");
        printf("    %d   |   %d\n", capturadasNegras, capturadasBlancas); // Corregido: Blancas capturan piezas Negras y viceversa.
        printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
        // Entrada del jugador
        char entrada[10];
        int filaIni, colIni, filaFin, colFin;

        while(1) { // NUEVO: Bucle para reintentar si el movimiento es inválido
            printf("\nIngresa tu movimiento (%s) (ej: e2:e4 o 0 para salir): ", jugadorActual);
            fgets(entrada, sizeof(entrada), stdin);
            entrada[strcspn(entrada, "\n")] = 0; // Eliminar salto de línea

            if (strcmp(entrada, "0") == 0) {
                 printf("\nGracias por jugar.\n");
                 exit(0);
            }
            if (strlen(entrada) != 5 || entrada[2] != ':' || !isalpha(entrada[0]) || !isdigit(entrada[1]) || !isalpha(entrada[3]) || !isdigit(entrada[4])) {
                printf("Error: Formato inválido. Usa el formato 'a1:b2'.\n");
                continue;
            }
            colIni = tolower(entrada[0]) - 'a';
            filaIni = '8' - entrada[1];
            colFin = tolower(entrada[3]) - 'a';
            filaFin = '8' - entrada[4];
            // Validar dentro del tablero
            if (colIni < 0 || colIni > 7 || colFin < 0 || colFin > 7 ||
                filaIni < 0 || filaIni > 7 || filaFin < 0 || filaFin > 7) {
                printf("Error: Movimiento fuera del tablero.\n");
                continue;
            }
            char pieza = tablero[filaIni][colIni];
            if (pieza == '.') {
                printf("Error: No hay ficha en esa casilla.\n");
                continue;
            }
            int esBlanca = isupper(pieza);
            if ((strcmp(jugadorActual, "BLANCAS") == 0 && !esBlanca) ||
                (strcmp(jugadorActual, "NEGRAS") == 0 && esBlanca)) {
                printf("Error: Esa ficha no es tuya.\n");
                continue;
            }
            if (!esMovimientoValido(pieza, filaIni, colIni, filaFin, colFin, false)) {
                printf("Error: Movimiento no válido para esa pieza.\n");
                continue;
            }
            //Validación de Jaque. No puedes poner a tu rey en jaque.
            char piezaCapturada = tablero[filaFin][colFin];
            hacerMovimiento(filaIni, colIni, filaFin, colFin);

            if (estaEnJaque((strcmp(jugadorActual, "BLANCAS") == 0) ? 'B' : 'N')) {
                deshacerMovimiento(filaIni, colIni, filaFin, colFin, piezaCapturada);
                printf("Error: Movimiento ilegal, tu rey quedaría en jaque.\n");
                continue;
            }
            // Si el movimiento es valido, salimos del bucle de reintento.
            // Si hubo una captura, contamos la pieza.
            if (piezaCapturada != '.') {
                if (isupper(piezaCapturada)) capturadasBlancas++;
                else capturadasNegras++;
            }
            break;
        }
        // Logica de enroque mover la torre también
        char piezaMovida = tablero[filaFin][colFin];
        if (tolower(piezaMovida) == 'k' && abs(colFin - colIni) == 2) {
            if (colFin > colIni) { // Enroque corto
                hacerMovimiento(filaFin, 7, filaFin, colFin - 1);
            } else { // Enroque largo
                hacerMovimiento(filaFin, 0, filaFin, colFin + 1);
            }
        }
        // Actualizar banderas de enroque
        if (piezaMovida == 'K') reyBlancoMovido = true;
        if (piezaMovida == 'k') reyNegroMovido = true;
        if (piezaMovida == 'R' && colIni == 0) torreBlancaIMovida = true;
        if (piezaMovida == 'R' && colIni == 7) torreBlancaDMovida = true;
        if (piezaMovida == 'r' && colIni == 0) torreNegraIMovida = true;
        if (piezaMovida == 'r' && colIni == 7) torreNegraDMovida = true;

        // NUEVO: Comprobar promoción de peón
        if (tolower(piezaMovida) == 'p') {
            if (filaFin == 0 || filaFin == 7) {
                promocionDePeon(filaFin, colFin);
            }
        }
        // Historial
        strcpy(penultimoMovimiento, ultimoMovimiento);
        snprintf(ultimoMovimiento, sizeof(ultimoMovimiento), "%c%c a %c%c",
                 entrada[0], entrada[1], entrada[3], entrada[4]);
        // Tulno
        strcpy(jugadorAnterior, jugadorActual);
        if (strcmp(jugadorActual, "BLANCAS") == 0)
            strcpy(jugadorActual, "NEGRAS");
        else
            strcpy(jugadorActual, "BLANCAS");
        turno++;
    }
    printf("\nGracias por jugar.\n");
    return 0;
}
