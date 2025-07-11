#include <stdio.h>
#include <string.h>

typedef struct {
    int clave;
    char nombre[20];
    int carrera;
    float promedio;
    float examen;
    char telefono[12];
} alumno;

int main() {
    FILE *f = fopen("alu1.dat", "wb");
    if (!f) return 1;

    alumno a;

    // Alumna 1
    a.clave = 1010;
    strcpy(a.nombre, "Ana Torres");
    a.carrera = 1;
    a.promedio = 8.6;
    a.examen = 1350.0;
    strcpy(a.telefono, "8091234567");
    fwrite(&a, sizeof(alumno), 1, f);

    // Alumno 2
    a.clave = 1020;
    strcpy(a.nombre, "Luis Gomez");
    a.carrera = 3;
    a.promedio = 7.5;
    a.examen = 1450.0;
    strcpy(a.telefono, "8097654321");
    fwrite(&a, sizeof(alumno), 1, f);

    // Alumna 3
    a.clave = 1030;
    strcpy(a.nombre, "Marta Perez");
    a.carrera = 5;
    a.promedio = 8.9;
    a.examen = 1280.0;
    strcpy(a.telefono, "8098889999");
    fwrite(&a, sizeof(alumno), 1, f);

    fclose(f);
    return 0;
}

