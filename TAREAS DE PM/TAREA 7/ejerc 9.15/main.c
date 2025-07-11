#include <stdio.h>
#include <ctype.h>

// Prototipo
void minymay(FILE *);

int main(void) {
    FILE *ap;

    ap = fopen("arc.txt", "r");

    if (ap != NULL) {
        minymay(ap); // Llamamos la función
        fclose(ap);
    } else {
        printf("No se puede abrir el archivo\n");
    }

    return 0;
}

void minymay(FILE *ap1) {
    char cad[30];
    int i, mi = 0, ma = 0;

    while (fgets(cad, 30, ap1) != NULL) {
        i = 0;
        while (cad[i] != '\0') {
            if (islower(cad[i])) {
                mi++;
            } else if (isupper(cad[i])) {
                ma++;
            }
            i++;
        }
    }

    printf("\n\nNúmero de letras minúsculas: %d", mi);
    printf("\nNúmero de letras mayúsculas: %d\n", ma);
}
