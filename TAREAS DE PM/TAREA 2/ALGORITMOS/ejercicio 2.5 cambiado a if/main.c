#include <stdio.h>
#include <math.h>

/* Función matemática.
   El programa obtiene el resultado de una función.
   OP y T: variables de tipo entero.
   RES: variable de tipo real. */

int main(void) {  // Cambio de void main() a int main()
    int OP, T;
    float RES;

    printf("Ingrese la opción del cálculo y el valor entero: ");
    scanf("%d %d", &OP, &T);

    if (OP == 1) {
        RES = T / 5;
    } else if (OP == 2) {
        RES = pow(T, T);  // La función pow está definida en la biblioteca math.h
    } else if (OP == 3 || OP == 4) {
        RES = 6 * T / 2;
    } else {
        RES = 1;
    }

    printf("\nResultado: %7.2f", RES);

    return 0;  // Buenas prácticas en C
}
