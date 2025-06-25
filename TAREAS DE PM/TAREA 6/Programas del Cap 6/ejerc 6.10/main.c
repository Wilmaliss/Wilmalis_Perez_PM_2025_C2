#include <stdio.h>
/* Cuadrado mágico.
El programa genera un cuadrado mágico siguiendo los criterios enunciados anteriormente. */
const int MAX = 50;

void Cuadrado(int [][MAX], int);
void Imprime(int [][MAX], int);

int main(void) {
    int CMA[MAX][MAX] = {0}, TAM;

    do {
        printf("Ingrese el tamaño impar de la matriz: ");
        scanf("%d", &TAM);
    } while ((TAM > MAX || TAM < 1) || (TAM % 2 == 0));
    /* Se verifica que TAM sea válido y además impar */

    Cuadrado(CMA, TAM);
    Imprime(CMA, TAM);

    return 0;
}

void Cuadrado(int A[][MAX], int N) {
    int I = 1, FIL = 0, COL = N / 2, NUM = N * N;

    while (I <= NUM) {
        A[FIL][COL] = I;
        if (I % N != 0) {
            FIL = (FIL - 1 + N) % N;  // Mover hacia arriba (con wrap-around)
            COL = (COL + 1) % N;      // Mover hacia la derecha (con wrap-around)
        } else {
            FIL++;  // Mover hacia abajo si es múltiplo de N
        }
        I++;
    }
}

void Imprime(int A[][MAX], int N) {
    int I, J;
    printf("\nCuadrado mágico de orden %d:\n", N);
    for (I = 0; I < N; I++) {
        for (J = 0; J < N; J++) {
            printf("%4d ", A[I][J]);
        }
        printf("\n");
    }
}
