#include <stdio.h>

int main() {
    int N; // Número ingresado por el usuario

    // ingresar un número positivo
    printf("Ingrese un número entero positivo: ");
    scanf("%d", &N);

    // imprimir números en orden creciente
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= i; j++) {
            printf("%d ", j); // Imprime números del 1 hasta i
        }
        printf("\n"); // Salto de línea
    }

    //  imprimir números en orden decreciente
    for (int i = N - 1; i >= 1; i--) {
        for (int j = 1; j <= i; j++) {
            printf("%d ", j); // Imprime números del 1 hasta i
        }
        printf("\n"); // Salto de línea
    }

    return 0; // Finaliza el programa
}

