#include <stdio.h>
#include <stdlib.h>
//Escribir un programa para definir el rango de edad de una persona
// 1- de 0 a�os (anios) 1 a�o - recien nacido
// 2- de 1 a 12 ni�o
// 3- de 12 a�os a 17 es adolescente
// 4- de 18 a 38 es adulto
// 5- de 39 a 75 adulto mayor
// 6- de 76 a 86 es envejeciente
// 7- mayor de 86 es anciano

int main() {
    int edad = 0;
    printf("\nEscriba la edad del paciente: ");
    scanf("%i", &edad);

    if (edad >= 0 && edad <= 130) {
        if (edad == 0) {
            printf("Es un reci�n nacido, la dosis recomendada es 0 ml.");
        } else if (edad <= 12) {
            printf("Es un ninio, la dosis recomendada es 0.5 ml.");
        } else if (edad <= 17) {
            printf("Es un adolescente, la dosis recomendada es 0.75 ml.");
        } else if (edad <= 38) {
            printf("Es un adulto, la dosis recomendada es 1 ml.");
        } else if (edad <= 75) {
            printf("Es un adulto mayor, la dosis recomendada es 1.25 ml.");
        } else if (edad <= 86) {
            printf("Es un envejeciente, la dosis recomendada es 0.75 ml.");
        } else {
            printf("Es un anciano, la dosis recomendada es 0.50 ml.");
        }
    } else
    {
        printf("Valor no valido");
    }

    return 0;
}
