#include <stdio.h>
/* Arreglo sin elementos repetidos.
El programa, al recibir como dato un arreglo unidimensional desordenado de N
elementos, obtiene como salida ese mismo arreglo pero sin los elementos
repetidos. */
void Lectura(int *, int); /* Prototipos de funciones. */
void Imprime(int *, int);
void Elimina(int *, int *);
/* Observa que en el prototipo de Elimina, el segundo parámetro es por
referencia. Esto, porque el tamaño del arreglo puede disminuir. */
void main(void)
{
    int TAM, ARRE[100];
    /* Se escribe un do-while para verificar que el tamaño del arreglo que se
    ingresa sea correcto. */
    do
    {
        printf("Ingrese el tamaño del arreglo: ");
        scanf("%d", &TAM);
    }
    while (TAM > 100 || TAM < 1);
    Lectura(ARRE, TAM);
    Elimina(ARRE, &TAM);
    /* Observa que el tamaño del arreglo se pasa por referencia.*/
    Imprime(ARRE, TAM);
}
void Lectura(int A[], int T)
/* La función Lectura se utiliza para leer un arreglo unidimensional de T
elementos de tipo entero. */
{
    printf("\n");
    int I;
    for (I = 0; I < T; I++)
    {
        printf("Ingrese el elemento %d: ", I + 1);
        scanf("%d", &A[I]);
    }
}
void Imprime(int A[], int T)
/* La función Imprime se utiliza para imprimir un arreglo unidimensional de T
elementos de tipo entero. */
{
    int I;
    printf("\nArreglo sin elementos repetidos:\n");
    for (I = 0; I < T; I++)
        printf("%d ", A[I]);
    printf("\n");
}
void Elimina(int A[], int *T)
/* La función Elimina remueve los elementos repetidos del arreglo A y actualiza
el tamaño T por referencia. */
{
    int I, J, K;
    for (I = 0; I < *T; I++)
    {
        for (J = I + 1; J < *T; )
        {
            if (A[I] == A[J])
            {
                /* Desplaza los elementos para eliminar el repetido */
                for (K = J; K < *T - 1; K++)
                    A[K] = A[K + 1];
                (*T)--; /* Reduce el tamaño del arreglo */
            }
            else
                J++;
        }
    }
}
