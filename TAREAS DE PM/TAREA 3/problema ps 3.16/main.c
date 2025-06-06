#include <stdio.h>

int main() {
    int N; // N�mero ingresado por el usuario

    // ingresar un n�mero positivo
    printf("Ingrese un n�mero entero positivo: ");
    scanf("%d", &N);

    // imprimir n�meros en orden creciente
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= i; j++) {
            printf("%d ", j); // Imprime n�meros del 1 hasta i
        }
        printf("\n"); // Salto de l�nea
    }

    //  imprimir n�meros en orden decreciente
    for (int i = N - 1; i >= 1; i--) {
        for (int j = 1; j <= i; j++) {
            printf("%d ", j); // Imprime n�meros del 1 hasta i
        }
        printf("\n"); // Salto de l�nea
    }

    return 0; // Finaliza el programa
}

