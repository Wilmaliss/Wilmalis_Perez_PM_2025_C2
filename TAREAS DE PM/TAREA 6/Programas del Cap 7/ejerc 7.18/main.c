#include <stdio.h>
#include <string.h> /* Incluye esta línea para strcspn y strlen */

/* Cadena invertida resuelta en forma recursiva. */
void inverso(char *); /* Prototipo de función. */

int main(void)
{
    char fra[50];

    printf("\nIngrese la línea de caracteres: ");
    if (fgets(fra, sizeof(fra), stdin) == NULL) {
        printf("\nError al leer la entrada.\n");
        return 1;
    }
    fra[strcspn(fra, "\n")] = '\0'; /* Línea 13: Eliminar salto de línea */

    if (strlen(fra) == 0) { /* Línea 16: Verificar si la cadena está vacía */
        printf("\nLa cadena está vacía.\n");
        return 1;
    }

    printf("\nEscribe la línea de texto en forma inversa: ");
    inverso(fra);
    printf("\n"); /* Salto de línea para mejor formato */
    return 0;
}

void inverso(char *cadena)
{
    if (cadena[0] != '\0') {
        inverso(cadena + 1);
        putchar(cadena[0]);
    }
}
