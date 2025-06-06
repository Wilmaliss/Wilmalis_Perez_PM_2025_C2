#include <stdio.h>
#include <math.h>

/* Cálculo de P.
   El programa obtiene el valor de P aplicando una serie determinada.
   I, B, C: variables de tipo entero.
   RES: variable de tipo real de doble precisión. */

int main(void) {  // Cambio de void main() a int main()
    int I = 1, B = 0, C;
    double RES;

    RES = 4.0 / I;
    C = 1;

    while (fabs(3.1415 - RES) > 0.0005) {
        I += 2;
        if (B) {
            RES += 4.0 / I;
            B = 0;
        } else {
            RES -= 4.0 / I;
            B = 1;
        }
        C++;
    }

    // Imprimir el resultado
    printf("\nNúmero de términos: %d", C);
    printf("\nAproximación de π: %.10f\n", RES);

    return 0;
}
