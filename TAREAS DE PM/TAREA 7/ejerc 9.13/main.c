#include <stdio.h>

int cuenta(char); // Prototipo

int main(void) {
    int res;
    char car;

    printf("\nIngrese el caracter que se va a buscar en el archivo: ");
    car = getchar();

    res = cuenta(car);

    if (res != -1)
        printf("\n\nEl caracter '%c' se encuentra en el archivo %d veces\n", car, res);
    else
        printf("No se pudo abrir el archivo\n");

    return 0;
}

int cuenta(char car) {
    int con = 0;
    char p;
    FILE *ar;

    ar = fopen("arc.txt", "r"); // Abrir archivo en modo lectura

    if (ar != NULL) {
        while ((p = getc(ar)) != EOF) { // Leer carácter por carácter
            if (p == car)
                con++;
        }
        fclose(ar);
        return con;
    } else {
        return -1;
    }
}
