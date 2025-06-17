#include <stdio.h>
/* Frecuencia de calificaciones.
El programa, al recibir como datos las calificaciones de un grupo de 50
alumnos, obtiene la frecuencia de cada una de las calificaciones y además
escribe cuál es la frecuencia más alta. */
const int TAM = 50;
void Lectura(int VEC[], int T);
void Frecuencia(int VEC[], int T1, int FRE[], int T2); /* Prototipo corregido */
void Impresion(int VEC[], int T);
void Mayor(int VEC[], int T);
void main(void)
{
    int CAL[TAM], FRE[6] = {0}; /* Declaración de los arreglos. */
    Lectura(CAL, TAM); /* Se llama a la función Lectura. */
    Frecuencia(CAL, TAM, FRE, 6);
    /* Se llama a la función Frecuencia, se pasan ambos arreglos. */
    printf("\nFrecuencia de Calificaciones\n");
    Impresion(FRE, 6);
    Mayor(FRE, 6);
}
void Lectura(int VEC[], int T)
/* La función Lectura se utiliza para leer el arreglo de calificaciones. */
{
    int I;
    for (I = 0; I < T; I++)
    {
        printf("Ingrese la calificación -0:5- del alumno %d: ", I + 1);
        scanf("%d", &VEC[I]);
    }
}
void Frecuencia(int VEC[], int T1, int FRE[], int T2)
/* La función Frecuencia calcula la frecuencia de cada calificación (0 a 5). */
{
    int I;
    for (I = 0; I < T1; I++)
    {
        if (VEC[I] >= 0 && VEC[I] <= 5) /* Asumimos calificaciones válidas */
            FRE[VEC[I]]++;
    }
}
void Impresion(int VEC[], int T)
/* La función Impresion imprime las frecuencias de las calificaciones. */
{
    int I;
    for (I = 0; I < T; I++)
        printf("\nCalificación %d: %d", I, VEC[I]);
}
void Mayor(int VEC[], int T)
/* La función Mayor encuentra e imprime la frecuencia más alta. */
{
    int I, MAY = VEC[0], IND = 0;
    for (I = 1; I < T; I++)
        if (VEC[I] > MAY)
        {
            MAY = VEC[I];
            IND = I;
        }
    printf("\n\nFrecuencia más alta: %d (Calificación %d)\n", MAY, IND);
}
