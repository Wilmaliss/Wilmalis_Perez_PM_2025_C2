#include <stdio.h>
#include <math.h>

/* Expresi�n.
El programa escribe los valores de T, P y Q que satisfacen una determinada
expresi�n. */

int Expresion(int, int, int); /* Prototipo de funci�n. */

void main(void)
{
    int EXP, T = 0, P, Q;

    do {
        P = 0;
        do {
            Q = 0;
            do {
                EXP = Expresion(T, P, Q);
                if (EXP < 5500)
                    printf("\nT: %d, P: %d, Q: %d, Resultado: %d", T, P, Q, EXP);
                Q++;
            } while (Expresion(T, P, Q) < 5500);
            P++;
        } while (Expresion(T, P, 0) < 5500);
        T++;
    } while (Expresion(T, 0, 0) < 5500);
}

int Expresion(int T, int P, int Q)
/* Esta funci�n obtiene el resultado de la expresi�n para los valores
de T, P y Q. */
{
    int RES;
    RES = 15 * pow(T, 4) + 12 * pow(P, 5) + 9 * pow(Q, 6);
    return RES;
}
