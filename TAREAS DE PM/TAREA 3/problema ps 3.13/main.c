#include <stdio.h>
#include <math.h>

// Función para verificar si un número es primo
int esPrimo(int n) {
    if (n < 2) return 0;
    for (int j = 2; j <= sqrt(n); j++) {
        if (n % j == 0) return 0;
    }
    return 1;
}

int main() {
    int N1, N2, i;

    // Leer los números
    printf("Ingrese dos números enteros positivos: ");
    scanf("%d %d", &N1, &N2);

    // Verificar si son positivos
    if (N1 <= 0 || N2 <= 0) {
        printf("Los números deben ser positivos\n");
        return 0;
    }

    // Asegurar que N1 sea menor o igual a N2
    if (N1 > N2) {
        int temp = N1;
        N1 = N2;
        N2 = temp;
    }

    // Buscar primos gemelos
    printf("Primos gemelos entre %d y %d:\n", N1, N2);
    for (i = N1; i <= N2 - 2; i++) {
        if (esPrimo(i) && esPrimo(i + 2)) {
            printf("(%d, %d)\n", i, i + 2);
        }
    }

    return 0;
}
