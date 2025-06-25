#include <stdio.h>
/* Simétrico.
El programa, al recibir como dato un arreglo bidimensional cuadrado, determina
si el mismo es simétrico. */

const int MAX = 100;

/* Prototipos de funciones */
void Lectura(int [][MAX], int);
int Simetrico(int [][MAX], int);

int main(void) {
    int MAT[MAX][MAX], N, RES;

    do {
        printf("Ingrese el tamaño del arreglo (1 a %d): ", MAX);
        scanf("%d", &N);
    } while (N > MAX || N < 1); // Validación corregida

    Lectura(MAT, N);
    RES = Simetrico(MAT, N);

    if (RES)
        printf("\nEl arreglo bidimensional es simétrico.\n");
    else
        printf("\nEl arreglo bidimensional no es simétrico.\n");

    return 0;
}

void Lectura(int A[][MAX], int T)
/* Lee una matriz cuadrada de tamaño T */
{
    int I, J;
    for (I = 0; I < T; I++)
        for (J = 0; J < T; J++) {
            printf("Fila %d, Columna %d: ", I + 1, J + 1);
            scanf("%d", &A[I][J]);
        }
}

int Simetrico(int A[][MAX], int T)
/* Verifica si una matriz es simétrica */
{
    int I = 0, J, F = 1;
    while ((I < T) && F) {
        J = 0;
        while ((J < I) && F) {
            if (A[I][J] == A[J][I])
                J++;
            else
                F = 0;
        }
        I++;
    }
    return F;
}
