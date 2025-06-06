#include <stdio.h>

int main() {
    int N;

    // Pedimos el n�mero entero positivo
    printf("Ingrese un n�mero entero positivo: ");

    // Validamos la entrada
    if (scanf("%d", &N) != 1 || N <= 0) {
        printf("Error: Debe ingresar un n�mero entero positivo.\n");
        return 1; // Termina el programa con error
    }

    // Generaci�n de la pir�mide equil�tera
    for (int i = 1; i <= N; i++) {
        // Imprimir espacios para centrar la pir�mide
        for (int s = 0; s < N - i; s++) {
            printf("  "); // Espacios para centrar la fila
        }

        // Imprimir n�meros en orden creciente
        for (int j = i; j <= i + (i - 1); j++) {
            printf("%d ", j % 10);
        }

        // Imprimir n�meros en orden decreciente
        for (int j = i + (i - 2); j >= i; j--) {
            printf("%d ", j % 10);
        }

        printf("\n"); // Salto de l�nea
    }

    return 0;
}

