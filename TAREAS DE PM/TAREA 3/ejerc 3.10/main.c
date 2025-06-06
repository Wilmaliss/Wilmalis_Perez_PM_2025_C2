#include <stdio.h>

/* Pares e impares.
   El programa, al recibir como datos N números enteros, obtiene la suma de los
   números pares y calcula el promedio de los impares.
   I, N, NUM, SPA, SIM, CIM: variables de tipo entero. */

int main(void) {  // Cambio de void main() a int main()
    int I, N, NUM, SPA = 0, SIM = 0, CIM = 0;

    printf("Ingrese el número de datos que se van a procesar:\t");
    scanf("%d", &N);

    if (N > 0) {
        for (I = 1; I <= N; I++) {
            printf("\nIngrese el número %d: ", I);
            scanf("%d", &NUM);

            if (NUM != 0) {
                if (NUM % 2 == 0) {  // Corrección: NUM % 2 determina si es par
                    SPA += NUM;
                } else {
                    SIM += NUM;
                    CIM++;
                }
            }
        }

        printf("\n La suma de los números pares es: %d", SPA);

        if (CIM > 0) {
            printf("\n El promedio de números impares es: %5.2f", (float)SIM / CIM);
        } else {
            printf("\n No hay números impares para calcular el promedio.");
        }
    } else {
        printf("\n El valor de N es incorrecto");
    }

    return 0;
}

