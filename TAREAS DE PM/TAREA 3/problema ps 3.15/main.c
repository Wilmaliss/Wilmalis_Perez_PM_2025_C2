#include <stdio.h>

int main() {
    int N1, N2, resto;

    // Pedir los datos al usuario
    printf("Ingrese el primer número (N1): ");
    scanf("%d", &N1);

    printf("Ingrese el segundo número (N2): ");
    scanf("%d", &N2);

    // Verificar que sean positivos
    if (N1 <= 0 || N2 <= 0) {
        printf("Los números deben ser naturales (mayores que cero).\n");
        return 1; // salir del programa
    }

    // Calcular el MCD usando el método de Euclides
    while (N2 != 0) {
        resto = N1 % N2;
        N1 = N2;
        N2 = resto;
    }

    // Mostrar resultado
    printf("El MCD es: %d\n", N1);

    return 0;
}
