#include <stdio.h>
#include <string.h>
#include <ctype.h>

/* Minúsculas y mayúsculas.
   El programa, al recibir como dato un arreglo unidimensional de tipo
   cadena de caracteres, determina el número de minúsculas y mayúsculas
   que hay en cada cadena. */

void minymay(char *cadena); // Prototipo de función

int main(void)
{
    int i, n;
    char FRA[20][50]; // Arreglo de 20 filas con hasta 49 caracteres + '\0'

    printf("\nIngrese el número de filas del arreglo: ");
    scanf("%d", &n);
    getchar(); // Limpia el buffer para evitar problemas con fgets

    for (i = 0; i < n; i++)
    {
        printf("Ingrese la línea %d de texto: ", i + 1);
        fgets(FRA[i], sizeof(FRA[i]), stdin);

        // Elimina el salto de línea final si existe
        size_t len = strlen(FRA[i]);
        if (len > 0 && FRA[i][len - 1] == '\n') {
            FRA[i][len - 1] = '\0';
        }
    }

    printf("\n\n");
    for (i = 0; i < n; i++)
        minymay(FRA[i]);

    return 0;
}

void minymay(char *cadena)
/* Esta función se utiliza para calcular el número de minúsculas
   y mayúsculas que hay en cada cadena. */
{
    int i = 0, mi = 0, ma = 0;

    while (cadena[i] != '\0')
    {
        if (islower((unsigned char)cadena[i]))
            mi++;
        else if (isupper((unsigned char)cadena[i]))
            ma++;
        i++;
    }

    printf("\n\nNúmero de letras minúsculas: %d", mi);
    printf("\nNúmero de letras mayúsculas: %d\n", ma);
}
