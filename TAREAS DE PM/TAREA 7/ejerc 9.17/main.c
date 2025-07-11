#include <stdio.h>
#include <string.h>

/* Reemplaza palabras.
El programa lee cadenas de caracteres de un archivo y cada que vez que
➥encuentra la palabra México escrita en forma incorrecta —la primera con
➥minúscula— la reemplaza por su forma correcta y escribe la cadena en otro
➥archivo. */
void cambia(FILE *, FILE *);

int main(void) {
    FILE *ar;
    FILE *ap;

    ar = fopen("arc.txt", "r");
    ap = fopen("arc1.txt", "w");

    if ((ar != NULL) && (ap != NULL)) {
        cambia(ar, ap);
        fclose(ar);
        fclose(ap);
        printf("Reemplazo completado. Revisa arc1.txt\n");
    } else {
        printf("No se pueden abrir los archivos\n");
    }

    return 0;
}

void cambia(FILE *ap1, FILE *ap2) {
    char cad[100];

    while (fgets(cad, sizeof(cad), ap1) != NULL) {
        char *pos;

        // Buscar "méxico" (con "m" minúscula)
        while ((pos = strstr(cad, "méxico")) != NULL) {
            pos[0] = 'M'; // Reemplazar la 'm' por 'M'
        }

        fputs(cad, ap2); // Escribir cadena modificada
    }
}
