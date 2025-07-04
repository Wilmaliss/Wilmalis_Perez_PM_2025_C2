#include <stdio.h>

/* Archivos con variables enteras y reales.
   El programa almacena datos de un grupo de alumnos en un archivo. */

int main(void) {
    int i, j, n, mat;
    float cal;
    FILE *ar;

    printf("\nIngrese el número de alumnos: ");
    scanf("%d", &n);

    // Validación opcional (entre 1 y 35)
    if (n < 1 || n > 35) {
        printf("Número de alumnos fuera de rango (1-35).\n");
        return 1;
    }

    if ((ar = fopen("arc8.txt", "w")) != NULL) {
        fprintf(ar, "%d\n", n);  // Guardamos número de alumnos

        for (i = 0; i < n; i++) {
            printf("\nIngrese la matrícula del alumno %d: ", i + 1);
            scanf("%d", &mat);
            fprintf(ar, "%d ", mat);

            for (j = 0; j < 5; j++) {
                printf("Calificación %d: ", j + 1);
                scanf("%f", &cal);
                fprintf(ar, "%.2f ", cal);
            }

            fprintf(ar, "\n");  // salto de línea por alumno
        }

        fclose(ar);
        printf("\nDatos guardados exitosamente en 'arc8.txt'.\n");
    } else {
        printf("No se puede abrir el archivo.\n");
    }

    return 0;
}
