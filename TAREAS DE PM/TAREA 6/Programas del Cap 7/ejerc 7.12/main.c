#include <stdio.h>
#include <ctype.h>
#include <string.h>

/* Cuenta letras minúsculas y mayúsculas en una cadena de caracteres. */

int main(void)
{
    char cad[50];
    int i = 0, mi = 0, ma = 0;

    printf("\nIngrese la cadena de caracteres (máximo 49 caracteres): ");
    fgets(cad, sizeof(cad), stdin);

    // Eliminar el salto de línea si lo hay
    size_t len = strlen(cad);
    if (len > 0 && cad[len - 1] == '\n') {
        cad[len - 1] = '\0';
    }

    while (cad[i] != '\0')
    {
        if (islower(cad[i]))
            mi++;
        else if (isupper(cad[i]))
            ma++;
        i++;
    }

    printf("\n\nNúmero de letras minúsculas: %d", mi);
    printf("\nNúmero de letras mayúsculas: %d\n", ma);

    return 0;
}
