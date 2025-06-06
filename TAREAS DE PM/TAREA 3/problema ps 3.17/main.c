#include <stdio.h>

int main() {
    int N;

    // Pedimos el n�mero entero positivo
    printf("Ingrese un n�mero entero positivo: ");
    scanf("%d", &N);

    // Generaci�n de la figura
    for (int i = 1; i <= N; i++) {
        // Imprimir n�meros en orden creciente
        for (int j = 1; j <= i; j++) {
            printf("%d ", j);
        }
        // Imprimir n�meros en orden decreciente
        for (int j = i - 1; j >= 1; j--) {
            printf("%d ", j);
        }
        printf("\n"); // Salto de l�nea
    }

    return 0;
}
