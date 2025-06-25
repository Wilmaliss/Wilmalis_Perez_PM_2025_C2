#include <stdio.h>
#include <ctype.h>

/* Decodifica.
El programa decodifica una cadena de caracteres compuesta por números y letras. */
void interpreta(char *); /* Prototipo de función. */

int main(void)
{
    char cad[50];
    printf("\nIngrese la cadena de caracteres: ");
    fgets(cad, sizeof(cad), stdin); /* Uso de fgets en lugar de gets */

    /* Eliminar el salto de línea que agrega fgets, si está presente */
    for (int i = 0; cad[i] != '\0'; i++) {
        if (cad[i] == '\n') {
            cad[i] = '\0';
            break;
        }
    }

    interpreta(cad);
    printf("\n"); /* Agregar salto de línea al final para mejor formato */
    return 0; /* Retorno estándar */
}

void interpreta(char *cadena)
/* Esta función se utiliza para decodificar la cadena de caracteres. */
{
    int i = 0, j, k;
    while (cadena[i] != '\0')
    {
        if (isalpha(cadena[i])) /* Verifica si el carácter es una letra */
        {
            /* Verificar que hay un número válido antes de la letra */
            if (i > 0 && isdigit(cadena[i - 1])) {
                k = cadena[i - 1] - '0'; /* Convertir carácter numérico a entero */
                for (j = 0; j < k; j++)
                    putchar(cadena[i]);
            }
        }
        i++;
    }
}
