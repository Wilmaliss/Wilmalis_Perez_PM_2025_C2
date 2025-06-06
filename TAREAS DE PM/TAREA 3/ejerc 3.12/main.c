#include <stdio.h>
#include <math.h>

/* Serie de ULAM.
   El programa, al recibir como dato un entero positivo, obtiene y escribe
   la serie de ULAM.
   NUM: variable de tipo entero. */

int main(void) {  // Cambio de void main() a int main()
    int NUM;

    printf("Ingresa el número para calcular la serie: ");
    scanf("%d", &NUM);

    if (NUM > 0) {
        printf("\nSerie de ULAM\n");
        printf("%d \t", NUM);

        while (NUM != 1) {
            if (NUM % 2 == 0) {  // Corrección en la verificación de paridad
                NUM = NUM / 2;
            } else {
                NUM = NUM * 3 + 1;
            }
            printf("%d \t", NUM);
        }
    } else {
        printf("\nNUM debe ser un entero positivo");
    }

    return 0;  // Buenas prácticas en C
}
