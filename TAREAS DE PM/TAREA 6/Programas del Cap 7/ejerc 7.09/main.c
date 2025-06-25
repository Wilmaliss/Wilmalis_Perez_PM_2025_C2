#include <stdio.h>
#include <string.h>

/* Cuenta caracteres.
   El programa, al recibir como datos una cadena de caracteres y un caracter,
   cuenta cuántas veces se encuentra el caracter en la cadena. */

int cuenta(char *, char); // Prototipo de función

int main(void)
{
    char car, cad[50];
    int res;

    printf("\nIngrese la cadena de caracteres: ");
    fgets(cad, sizeof(cad), stdin);

    // Eliminar salto de línea al final
    size_t len = strlen(cad);
    if (len > 0 && cad[len - 1] == '\n') {
        cad[len - 1] = '\0';
    }

    printf("\nIngrese el caracter: ");
    car = getchar();

    res = cuenta(cad, car);

    printf("\n\n'%c' se encuentra %d veces en la cadena \"%s\"\n", car, res, cad);

    return 0;
}

int cuenta(char *cad, char car)
/* Esta función cuenta cuántas veces aparece un carácter en la cadena. */
{
    int i = 0, r = 0;

    while (cad[i] != '\0')
    {
        if (cad[i] == car)
            r++;
        i++;
    }

    return r;
}
