#include <stdio.h>

/* Calificaciones.
   El programa, al recibir un grupo de calificaciones de un alumno, obtiene el promedio de calificaciones de cada uno de ellos y, además, los alumnos con el mejor
   y peor promedio.
   I, MAT, MAMAT y MEMAT: variables de tipo entero.
   CAL, SUM, MAPRO, MEPRO y PRO: variables de tipo real. */

int main(void) {  // Cambio de void main() a int main()
    int I, MAT, MAMAT, MEMAT;
    float SUM, PRO, CAL, MAPRO = 0.0, MEPRO = 11.0;

    printf("Ingrese la matrícula del primer alumno (0 para terminar):\t");
    scanf("%d", &MAT);

    while (MAT != 0) {  // Corrección en la condición del bucle
        SUM = 0;

        for (I = 1; I <= 5; I++) {  // Corrección en el operador de comparación
            printf("\tIngrese la calificación del alumno %d: ", I);
            scanf("%f", &CAL);
            SUM += CAL;
        }

        PRO = SUM / 5;
        printf("\nMatrícula: %d\tPromedio: %5.2f", MAT, PRO);

        if (PRO > MAPRO) {
            MAPRO = PRO;
            MAMAT = MAT;
        }

        if (PRO < MEPRO) {
            MEPRO = PRO;
            MEMAT = MAT;
        }

        printf("\n\nIngrese la matrícula del siguiente alumno (0 para terminar): ");
        scanf("%d", &MAT);
    }

    printf("\n\nAlumno con mejor Promedio:\t%d\t%5.2f", MAMAT, MAPRO);
    printf("\n\nAlumno con peor Promedio:\t%d\t%5.2f\n", MEMAT, MEPRO);

    return 0;  // Buenas prácticas en C
}
