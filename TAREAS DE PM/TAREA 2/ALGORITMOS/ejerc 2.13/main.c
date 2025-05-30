#include <stdio.h>
#include <math.h>

/* Funci�n.
   El programa, al recibir como dato un valor entero, calcula el resultado de
   una funci�n.
   Y: variable de tipo entero.
   X: variable de tipo real. */

int main(void) {  // Cambio de void main() a int main()
    float X;
    int Y;

    printf("Ingrese el valor de Y: ");
    scanf("%d", &Y);

    if (Y < 0 || Y > 50) {
        X = 0;
    } else if (Y <= 10) {
        X = 4.0 / Y - Y;  // Asegurar que la divisi�n sea en punto flotante
    } else if (Y <= 25) {
        X = pow(Y, 3) - 12;
    } else {
        X = pow(Y, 2) + pow(Y, 3) - 18;  // Correg� el operador de resta
    }

    printf("\n\nY = %d\tX = %8.2f", Y, X);

    return 0;  // Buenas pr�cticas en C
}
