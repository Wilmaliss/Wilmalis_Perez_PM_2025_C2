#include <stdio.h>

void trueque(int *x, int *y)
{
    int tem;
    tem = *x;
    *x = *y;
    *y = tem;
}

int suma(int x)
{
    return (x + x);
}

int main(void)
{
    int a = 4, b = 7;

    printf("Antes del trueque: a = %d, b = %d\n", a, b);
    trueque(&a, &b);
    printf("Después del trueque: a = %d, b = %d\n", a, b);

    int resultado = suma(a);
    printf("El doble de a (%d) es: %d\n", a, resultado);

    return 0;
}
