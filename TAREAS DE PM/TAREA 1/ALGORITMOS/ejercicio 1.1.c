#include <stdio.h>

/* Aplicación de operadores. */

int main(void)
{
    int i, j, k = 2, l = 7;

    i = 9 + 3 * 2;             // 3 * 2 = 6, 9 + 6 = 15
    j = 8 % 6 + 4 * 2;         // 8 % 6 = 2, 4 * 2 = 8, 2 + 8 = 10
    i--;                       // i = 14
    printf("\nEl valor de i es: %d", i);

    ++i;                       // i = 15
    k = l++ * 2;               // k = 14, luego l = 8
    printf("\nEl valor de k es: %d", k);

    i = (int)(5.5 * 3 * 2) % 4; // 5.5*3*2 = 33, 33 % 4 = 1
    j = 1 - 2 * (k - 3) / k;    // 1 - (2*11/14) = 1 - 1 = 0
    printf("\nEl valor de j es: %d\n", j);

    return 0;
}
