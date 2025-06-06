#include <stdio.h>
#include <math.h>

int main() {
    int X;
    double sum = 0.0, term;
    int terms = 0;
    double x_rad;

    // Pedir número entero
    printf("Ingrese un número entero para calcular sin(x): ");
    scanf("%d", &X);

    // Convertir X a radianes (por si acaso)
    x_rad = (double)X;

    // Primer término de la serie: x
    term = x_rad;

    // Sumar términos hasta que |term| <= 0.001
    while (fabs(term) > 0.001) {
        sum += term; // Agregar término a la suma
        terms++; // Contar término
        // Calcular siguiente término: (-1)^n * x^(2n+1) / (2n+1)!
        term = -term * x_rad * x_rad / ((2 * terms) * (2 * terms + 1));
    }

    // Mostrar resultado con 4 decimales y número de términos
    printf("sin(%d) = %.4f, términos usados = %d\n", X, sum, terms);

    return 0;
}
