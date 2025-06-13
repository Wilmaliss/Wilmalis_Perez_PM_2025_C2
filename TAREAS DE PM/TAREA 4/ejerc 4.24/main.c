#include <stdio.h>

/* Prototipos de funciones */
int f1(void);
int f2(void);
int f3(void);
int f4(void);

/* Variable global */
int K = 5;

int main(void)
{
    int I;
    for (I = 1; I <= 4; I++)
    {
        printf("\n\nEl resultado de la función f1 es: %d", f1());
        printf("\nEl resultado de la función f2 es: %d", f2());
        printf("\nEl resultado de la función f3 es: %d", f3());
        printf("\nEl resultado de la función f4 es: %d", f4());
    }

    return 0;
}

int f1(void)
{
    K *= K; // K global se modifica (se eleva al cuadrado)
    return K;
}

int f2(void)
{
    int K = 3; // variable local
    K++;
    return K;
}

int f3(void)
{
    static int K = 6; // mantiene su valor entre llamadas
    K += 3;
    return K;
}

int f4(void)
{
    int K_local = 4;
    return K_local + K; // usa la K local y la global (global ya fue modificada por f1)
}
