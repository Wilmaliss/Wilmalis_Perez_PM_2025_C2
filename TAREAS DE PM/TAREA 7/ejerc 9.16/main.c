#include <stdio.h>
#include <stdlib.h>

void sumypro(FILE *); // Prototipo

int main(void) {
    FILE *ap;

    ap = fopen("arc2.txt", "r");
    if (ap != NULL) {
        sumypro(ap); // Ejecuta la función de suma/promedio
        fclose(ap);
    } else {
        printf("No se puede abrir el archivo\n");
    }

    return 0;
}

void sumypro(FILE *ap1) {
    char cad[30];
    int i = 0;
    float sum = 0.0, r;


    while (fgets(cad, 30, ap1) != NULL) {
        r = atof(cad); // Convierte cadena a número (si inicia con número)

        if (r != 0.0) { // Si no es cero, lo cuenta
            i++;
            sum += r;
        }
    }

    printf("\nSuma: %.2f", sum);
    if (i != 0)
        printf("\nPromedio: %.2f\n", sum / i);
}
