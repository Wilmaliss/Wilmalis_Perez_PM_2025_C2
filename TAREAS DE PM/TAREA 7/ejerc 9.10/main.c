#include <stdio.h>

/* Alumnos.
   El programa modifica el promedio de un alumno en un archivo binario
   de acceso directo. */

typedef struct {
    int matricula;
    char nombre[20];
    int carrera;
    float promedio;
} alumno;

void modifica(FILE *);  // Prototipo de función

int main(void) {
    FILE *ar;

    // Abrir el archivo en modo lectura y escritura binaria
    if ((ar = fopen("ad1.dat", "r+b")) != NULL) {
        modifica(ar);
        fclose(ar);
    } else {
        printf("\nEl archivo no se puede abrir\n");
    }

    return 0;
}

void modifica(FILE *ap) {
    int d;
    alumno alu;

    printf("\nIngrese el número de registro que desea modificar: ");
    scanf("%d", &d);

    // Posicionar el puntero en el registro deseado
    fseek(ap, (d - 1) * sizeof(alumno), SEEK_SET);

    // Leer el registro actual
    if (fread(&alu, sizeof(alumno), 1, ap) != 1) {
        printf("No se pudo leer el registro.\n");
        return;
    }

    printf("\nDatos actuales del alumno:");
    printf("\nMatrícula: %d\nNombre: %s\nCarrera: %d\nPromedio actual: %.2f",
           alu.matricula, alu.nombre, alu.carrera, alu.promedio);

    printf("\nIngrese el nuevo promedio del alumno: ");
    scanf("%f", &alu.promedio);

    // Volver a posicionarse para sobreescribir el registro
    fseek(ap, (d - 1) * sizeof(alumno), SEEK_SET);

    // Escribir el registro actualizado
    fwrite(&alu, sizeof(alumno), 1, ap);

    printf("\nRegistro actualizado correctamente.\n");
}
