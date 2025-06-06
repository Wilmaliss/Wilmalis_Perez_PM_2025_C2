#include <stdio.h>
#include <math.h>

// Funci�n para verificar si un n�mero es primo
int esPrimo(int n) {
    if (n < 2) return 0; // N�meros menores a 2 no son primos
    for (int j = 2; j <= sqrt(n); j++) {
        if (n % j == 0) return 0; // Si es divisible por j, no es primo
    }
    return 1; // Es primo
}

int main() {
    int NUM;

    // Leer el n�mero
    printf("Ingrese un n�mero entero positivo: ");
    scanf("%d", &NUM);

    // Verificar si el n�mero es positivo
    if (NUM <= 0) {
        printf("El n�mero debe ser positivo\n");
    } else {
        // Imprimir todos los n�meros primos menores a NUM
        printf("N�meros primos menores a %d:\n", NUM);
        for (int i = 2; i < NUM; i++) {
            if (esPrimo(i)) {
                printf("%d ", i);
            }
        }
        printf("\n");
    }

    return 0;
}
