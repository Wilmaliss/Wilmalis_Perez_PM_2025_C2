#include <stdio.h>

int main() {
    int N, i, j;

    // Paso 1: Pedir el número al usuario
    printf("Ingresa un número entero positivo: ");
    scanf("%d", &N);

    // Paso 2: Hacer las filas, desde 0 hasta N-1
    for (i = 0; i < N; i++) {

        // Parte izquierda: imprimir números del 1 hasta N - i
        for (j = 1; j <= N - i; j++) {
            printf("%d ", j);
        }

        // Espacios: 2*i (doble de espacios que la fila actual)
        for (j = 0; j < 2 * i; j++) {
            printf("  ");
        }

        // Parte derecha: imprimir números desde N - i hasta 1
        for (j = N - i; j >= 1; j--) {
            printf("%d ", j);
        }

        // Nueva línea
        printf("\n");
    }

    return 0;
}
