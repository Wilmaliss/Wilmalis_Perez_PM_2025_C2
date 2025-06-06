#include <stdio.h>
#include <math.h>

int main() {
    int X;
    double sum = 0.0, term;
    int terms = 0;
    double x_rad;

    // Pedir n�mero entero
    printf("Ingrese un n�mero entero para calcular sin(x): ");
    scanf("%d", &X);

    // Convertir X a radianes (por si acaso)
    x_rad = (double)X;

    // Primer t�rmino de la serie: x
    term = x_rad;

    // Sumar t�rminos hasta que |term| <= 0.001
    while (fabs(term) > 0.001) {
        sum += term; // Agregar t�rmino a la suma
        terms++; // Contar t�rmino
        // Calcular siguiente t�rmino: (-1)^n * x^(2n+1) / (2n+1)!
        term = -term * x_rad * x_rad / ((2 * terms) * (2 * terms + 1));
    }

    // Mostrar resultado con 4 decimales y n�mero de t�rminos
    printf("sin(%d) = %.4f, t�rminos usados = %d\n", X, sum, terms);

    return 0;
}
