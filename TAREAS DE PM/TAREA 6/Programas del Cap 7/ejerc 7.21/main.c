#include <stdio.h>
#include <string.h>

/* Prototipo de función. */
void intercambia(char FRA[][30], int);

int main(void)
{
    int i, n;
    char FRA[20][30];

    printf("\nIngrese el número de filas del arreglo: ");
    scanf("%d", &n);

    /* Validar que n no exceda el tamaño del arreglo */
    if (n <= 0 || n > 20) {
        printf("\nNúmero de filas inválido. Debe estar entre 1 y 20.\n");
        return 1;
    }

    /* Limpiar el buffer de entrada después de scanf */
    while (getchar() != '\n');

    for (i = 0; i < n; i++) {
        printf("\nIngrese la línea de texto número %d: ", i + 1);
        if (fgets(FRA[i], sizeof(FRA[i]), stdin) == NULL) {
            printf("\nError al leer la entrada.\n");
            return 1;
        }
        /* Eliminar salto de línea de FRA[i] */
        FRA[i][strcspn(FRA[i], "\n")] = '\0';
    }

    printf("\n\n");
    intercambia(FRA, n);
    for (i = 0; i < n; i++) {
        printf("\nImpresión de la línea de texto %d: ", i + 1);
        puts(FRA[i]);
    }
    printf("\n"); /* Salto de línea para mejor formato */
    return 0; /* Retorno estándar */
}

void intercambia(char FRA[][30], int n)
{
    /* Esta función intercambia las filas del arreglo. */
    int i, j;
    char cad[30];
    for (i = 0; i < (n / 2); i++) {
        j = n - 1 - i; /* Calcular el índice opuesto correctamente */
        strcpy(cad, FRA[i]);
        strcpy(FRA[i], FRA[j]);
        strcpy(FRA[j], cad);
    }
}
