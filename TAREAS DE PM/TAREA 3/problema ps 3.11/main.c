#include <stdio.h>

int main() {
    int N;
    printf("Ingrese el numero de años: ");
    scanf("%d", &N);

    float VIN[N][4];
    float total_tipo[4] = {0};
    float total_anual[N];

    // Leer los datos
    for (int i = 0; i < N; i++) {
        total_anual[i] = 0; // Inicializa total anual
        printf("\nAño %d:\n", i + 1);
        for (int j = 0; j < 4; j++) {
            printf("  Litros del tipo de vino %d: ", j + 1);
            scanf("%f", &VIN[i][j]);
            total_tipo[j] += VIN[i][j];    // Acumula por tipo
            total_anual[i] += VIN[i][j];   // Acumula por año
        }
    }

    //  totales por tipo
    printf("\n--- Total producido por tipo de vino ---\n");
    for (int j = 0; j < 4; j++) {
        printf("Tipo %d: %.2f litros\n", j + 1, total_tipo[j]);
    }

    // totales por año
    printf("\n--- Total producido por año ---\n");
    for (int i = 0; i < N; i++) {
        printf("Año %d: %.2f litros\n", i + 1, total_anual[i]);
    }

    return 0;
}
