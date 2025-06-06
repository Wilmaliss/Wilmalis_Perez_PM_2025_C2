#include <stdio.h>

int main() {
    int N;

    // Pedimos el número entero positivo
    printf("Ingrese un número entero positivo: ");
    scanf("%d", &N);

    // Generación de la figura
    for (int i = 1; i <= N; i++) {
        // Imprimir números en orden creciente
        for (int j = 1; j <= i; j++) {
            printf("%d ", j);
        }
        // Imprimir números en orden decreciente
        for (int j = i - 1; j >= 1; j--) {
            printf("%d ", j);
        }
        printf("\n"); // Salto de línea
    }

    return 0;
}
