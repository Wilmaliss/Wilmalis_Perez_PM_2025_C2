#include <stdio.h>

int main() {
    float PRE, PAG, Cambio;

    // Entrada de datos
    printf("Ingrese el precio del producto: ");
    scanf("%f", &PRE);
    printf("Ingrese el pago del cliente: ");
    scanf("%f", &PAG);

    // Cálculo del cambio
    Cambio = PAG - PRE;

    // Verificación y muestra de resultados
    if (Cambio < 0) {
        printf("Pago insuficiente.\n");
    } else {
        printf("Cambio a entregar: %.2f\n", Cambio);
    }

    return 0;
}
