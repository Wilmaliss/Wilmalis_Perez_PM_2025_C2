#include <stdio.h>

/* Alumnos.
   El programa lee bloques —variables de tipo estructura alumno—
   de un archivo de acceso directo. */

typedef struct {
    int matricula;
    char nombre[20];
    int carrera;
    float promedio;
} alumno;

void lee(FILE *);  // Prototipo de función

int main(void) {
    FILE *ar;

    // Abre el archivo en modo binario para lectura
    if ((ar = fopen("ad1.dat", "rb")) != NULL) {
        lee(ar);        // Llama a la función de lectura
        fclose(ar);     // Cierra el archivo
    } else {
        printf("\nEl archivo no se puede abrir\n");
    }

    return 0;
}

void lee(FILE *ap) {
    alumno alu;
    // Lectura inicial
    int leido = fread(&alu, sizeof(alumno), 1, ap);

    while (leido == 1) {
        printf("\nMatrícula: %d", alu.matricula);
        printf("\tCarrera: %d", alu.carrera);
        printf("\tPromedio: %.2f\t", alu.promedio);
        puts(alu.nombre);  // Muestra el nombre

        // Siguiente lectura
        leido = fread(&alu, sizeof(alumno), 1, ap);
    }
}
