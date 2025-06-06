#include <stdio.h>

int main() {
    // Declaramos los precios de las localidades
    float L[6];  // Array para precios de las localidades
    int CLA, CAN, boletos_vendidos[6] = {0}; // Inicializamos los boletos vendidos en 0
    float total_recaudado = 0;

    // Pedimos los precios de cada localidad
    for (int i = 0; i < 6; i++) {
        printf("Ingrese el precio de la localidad L%d: ", i + 1);
        scanf("%f", &L[i]);
    }

    // Proceso de ventas
    printf("Ingrese tipo de localidad y cantidad de boletos vendidos (0, 0 para terminar):\n");
    while (1) {
        scanf("%d %d", &CLA, &CAN);
        if (CLA == 0 && CAN == 0) break; // Condición de salida

        if (CLA >= 1 && CLA <= 6) { // Validamos que sea una localidad existente
            float monto_venta = L[CLA - 1] * CAN;
            total_recaudado += monto_venta;
            boletos_vendidos[CLA - 1] += CAN;
        } else {
            printf("Localidad inválida. Intente nuevamente.\n");
        }
    }

    // Mostrar resultados
    printf("\nResumen de ventas:\n");
    for (int i = 0; i < 6; i++) {
        printf("Localidad L%d: %d boletos vendidos\n", i + 1, boletos_vendidos[i]);
    }
    printf("Recaudación total: $%.2f\n", total_recaudado);

    return 0;
}
