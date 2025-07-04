#include <stdio.h>

/* Alumnos.
   El programa almacena variables de tipo estructura alumno en un archivo. */

typedef struct {
    int matricula;
    char nombre[20];
    int carrera;
    float promedio;
} alumno;

void escribe(FILE *);  // Prototipo de función

int main(void) {
    FILE *ar;

    if ((ar = fopen("ad1.dat", "wb")) != NULL) {  // apertura en modo binario
        escribe(ar);
        fclose(ar);
    } else {
        printf("\nEl archivo no se puede abrir\n");
    }

    return 0;
}

void escribe(FILE *ap) {
    alumno alu;
    int i = 0, r;

    printf("\n¿Desea ingresar información sobre alumnos? (Sí-1 No-0): ");
    scanf("%d", &r);
    while (r) {
        i++;
        printf("Matrícula del alumno %d: ", i);
        scanf("%d", &alu.matricula);

        getchar();  // Limpiar salto de línea pendiente
        printf("Nombre del alumno %d: ", i);
        fgets(alu.nombre, sizeof(alu.nombre), stdin);
        alu.nombre[strcspn(alu.nombre, "\n")] = '\0';  // Quitar salto de línea

        printf("Carrera del alumno %d: ", i);
        scanf("%d", &alu.carrera);

        printf("Promedio del alumno %d: ", i);
        scanf("%f", &alu.promedio);

        fwrite(&alu, sizeof(alumno), 1, ap);

        printf("\n¿Desea ingresar información sobre más alumnos? (Sí-1 No-0): ");
        scanf("%d", &r);
    }
}
