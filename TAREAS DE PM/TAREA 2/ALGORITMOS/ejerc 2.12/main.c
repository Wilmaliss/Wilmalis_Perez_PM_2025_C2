#include <stdio.h>
#include <math.h>

int main(void) {  // Agregamos la funci�n main correctamente
    int T, P, N;

    printf("Ingrese los valores de T, P y N: ");
    scanf("%d %d %d", &T, &P, &N);

    if (P != 0) {
        if (pow(T / P, N) == pow(T, N) / pow(P, N)) {  // Se cerr� correctamente el par�ntesis
            printf("\nSe comprueba la igualdad");
        } else {
            printf("\nNo se comprueba la igualdad");
        }
    } else {
        printf("\nP tiene que ser diferente de cero");
    }

    return 0;  // Se a�adi� return 0 para buena pr�ctica en C
}
