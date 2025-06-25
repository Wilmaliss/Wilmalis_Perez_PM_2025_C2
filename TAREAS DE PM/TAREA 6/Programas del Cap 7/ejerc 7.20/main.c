#include <stdio.h>
#include <string.h>

/* Prototipo de función. */
int longitud(char *cad);

int main(void)
{
    int i, n, l = -1, p, t;
    char cad[50], FRA[20][50];

    printf("\nIngrese el número de filas del arreglo: ");
    scanf("%d", &n);

    /* Validar que n no exceda el tamaño del arreglo */
    if (n <= 0 || n > 20) {
        printf("\nNúmero de filas inválido. Debe estar entre 1 y 20.\n");
        return 1;
    }

    for (i = 0; i < n; i++) {
        printf("\nIngrese la línea %d de texto. Máximo 50 caracteres: ", i + 1);
        if (fgets(FRA[i], sizeof(FRA[i]), stdin) == NULL) {
            printf("\nError al leer la entrada.\n");
            return 1;
        }
        /* Eliminar salto de línea de FRA[i] */
        FRA[i][strcspn(FRA[i], "\n")] = '\0';
    }

    printf("\n");
    for (i = 0; i < n; i++) {
        strcpy(cad, FRA[i]);
        t = longitud(cad);
        if (t > l) {
            l = t;
            p = i;
        }
    }

    printf("\nLa cadena con mayor longitud es: ");
    puts(FRA[p]);
    printf("\nLongitud: %d\n", l); /* Salto de línea agregado */
    return 0; /* Retorno estándar */
}

int longitud(char *cadena)
{
    /* Esta función calcula la longitud de la cadena. */
    int cue = 0;
    while (cadena[cue] != '\0') {
        cue++;
    }
    return (cue);
}
