#include <stdio.h>

int main() {
    int N;

    // Pedimos el número entero positivo
    printf("Ingrese un número entero positivo: ");

    // Validamos la entrada
    if (scanf("%d", &N) != 1 || N <= 0) {
        printf("Error: Debe ingresar un número entero positivo.\n");
        return 1; // Termina el programa con error
    }

    // Generación de la pirámide equilátera
    for (int i = 1; i <= N; i++) {
        // Imprimir espacios para centrar la pirámide
        for (int s = 0; s < N - i; s++) {
            printf("  "); // Espacios para centrar la fila
        }

        // Imprimir números en orden creciente
        for (int j = i; j <= i + (i - 1); j++) {
            printf("%d ", j % 10);
        }

        // Imprimir números en orden decreciente
        for (int j = i + (i - 2); j >= i; j--) {
            printf("%d ", j % 10);
        }

        printf("\n"); // Salto de línea
    }

    return 0;
}

