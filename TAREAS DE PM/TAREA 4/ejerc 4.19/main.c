#include <stdio.h>

/* Funciones y parámetros. */

int a, b, c, d; // Variables globales

void funcion1(int, int *, int *); // Prototipos de funciones
int funcion2(int *, int);

void main(void)
{
    int a; // Variable local que oculta la global 'a'
    a = 1;
    b = 2;
    c = 3;
    d = 4;

    printf("\n%d %d %d %d", a, b, c, d); // Imprime los valores iniciales
    a = funcion2(&a, c);                 // Llamada a funcion2
    printf("\n%d %d %d %d", a, b, c, d); // Imprime los valores finales
}

void funcion1(int r, int *b, int *c)
{
    int d;
    a = *c;
    d = a + 3 + *b;

    if (r) {
        *b = *b + 2;
        *c = *c + 3;
        printf("\n%d %d %d %d", a, *b, *c, d);
    } else {
        *b = *b + 5;
        *c = *c + 4;
        printf("\n%d %d %d %d", a, *b, *c, d);
    }
}

int funcion2(int *d, int c)
{
    int b;
    a = 1;
    b = 7;

    funcion1(-1, d, &b); // Llama a funcion1

    printf("\n%d %d %d %d", a, b, c, *d);

    c += 3;
    (*d) += 2;

    printf("\n%d %d %d %d", a, b, c, *d);

    return (c);
}
