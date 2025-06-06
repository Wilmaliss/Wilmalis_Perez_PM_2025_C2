#include <stdio.h>
#include <math.h>

int main() {
    int T, P, R;
    long resultado;

    printf("Valores de T, P y R que cumplen:\n");
    printf("7*T^4 - 6*P^3 + 12*R^5 < 5850\n\n");

    for (T = 1; T <= 10; T++) {
        for (P = 1; P <= 10; P++) {
            for (R = 1; R <= 6; R++) { // R^5 crece muy rápido
                resultado = 7 * pow(T, 4) - 6 * pow(P, 3) + 12 * pow(R, 5);

                if (resultado < 5850) {
                    printf("T = %d, P = %d, R = %d -> Resultado = %ld\n", T, P, R, resultado);
                }
            }
        }
    }

    return 0;
}
