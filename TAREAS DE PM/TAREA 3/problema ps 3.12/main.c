#include <stdio.h>
#include <math.h>

// Función para verificar si un número es primo
int esPrimo(int n) {
    if (n < 2) return 0; // Números menores a 2 no son primos
    for (int j = 2; j <= sqrt(n); j++) {
        if (n % j == 0) return 0; // Si es divisible por j, no es primo
    }
    return 1; // Es primo
}

int main() {
    int NUM;

    // Leer el número
    printf("Ingrese un número entero positivo: ");
    scanf("%d", &NUM);

    // Verificar si el número es positivo
    if (NUM <= 0) {
        printf("El número debe ser positivo\n");
    } else {
        // Imprimir todos los números primos menores a NUM
        printf("Números primos menores a %d:\n", NUM);
        for (int i = 2; i < NUM; i++) {
            if (esPrimo(i)) {
                printf("%d ", i);
            }
        }
        printf("\n");
    }

    return 0;
}
