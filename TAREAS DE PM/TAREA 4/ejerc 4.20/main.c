#include <stdio.h>

/* Funciones y parámetros. */
int F1(int, int *); // Prototipo de función

int A = 3;
int B = 7;
int C = 4; // Variables globales
int D = 2;

void main(void)
{
    A = F1(C, &D);
    printf("\n%d %d %d %d", A, B, C, D);

    C = 3;
    C = F1(A, &C);
    printf("\n%d %d %d %d", A, B, C, D);
}

int F1(int X, int *Y)
{
    int localA;
    localA = X * (*Y);
    C++;               // Aumenta la variable global C
    B += *Y;           // Suma el contenido apuntado por Y a B

    printf("\n%d %d %d %d", localA, B, C, D);

    (*Y)--;            // Decrementa el contenido de Y (NO el puntero)
    return C;
}
