#include <stdio.h>
#include <ctype.h>

void minymay(FILE *); // Prototipo

int main(void) {
    FILE *ar;

    ar = fopen("arc5.txt", "r");

    if (ar != NULL) {
        minymay(ar); // Llamada a la función
        fclose(ar);
    } else {
        printf("No se pudo abrir el archivo\n");
    }

    return 0;
}

void minymay(FILE *arc) {
    int min = 0, may = 0;
    char p;

    while ((p = fgetc(arc)) != EOF) {
        if (islower(p)) {
            min++;
        } else if (isupper(p)) {
            may++;
        }
    }

    printf("\nLetras minúsculas: %d", min);
    printf("\nLetras mayúsculas: %d\n", may);
}
