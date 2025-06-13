#include <stdio.h>

/* Variables globales */
int z, y;

/* Prototipos de funciones */
int F1(float);
void F2(float, int *);

void main(void)
{
    int w;
    float x;

    z = 5;
    y = 7;
    w = 2;
    x = (float)y / z;

    printf("\nPrograma Principal: %d %d %.2f %d", z, y, x, w);
    F2(x, &w);
    printf("\nPrograma Principal: %d %d %.2f %d", z, y, x, w);
}

void F2(float t, int *r)
{
    printf("\nF2: %d %d %.2f %d", z, y, t, *r);

    if (z == 0)
    {
        z = (*r) * 2;
        t = (float)z / 3;
        printf("\nIngresa el valor: ");
        scanf("%d", r);  // Suponiendo que ingresas 6
        printf("\nF2: %d %d %.2f %d", z, y, t, *r);
    }
    else
    {
        z = (*r) * 2;
        printf("\nF2: %d %d %.2f %d", z, y, t, *r);
    }

    *r = F1(t);
}

int F1(float x)
{
    int k;

    if (x != 0)
    {
        k = z - y;
        x++;
    }
    else
    {
        k = z + y;
    }

    printf("\nF1: %d %d %.2f %d", z, y, x, k);
    return k;
}
