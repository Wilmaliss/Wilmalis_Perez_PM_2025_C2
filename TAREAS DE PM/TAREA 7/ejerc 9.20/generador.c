#include <stdio.h>
#include <string.h>

typedef struct {
    char materia[20];
    int calificacion;
} matcal;

typedef struct {
    int matricula;
    char nombre[20];
    matcal cal[5];
} alumno;

int main() {
    FILE *f = fopen("esc.dat", "wb");
    if (!f) return 1;

    alumno a;

    // Alumna 1: Ana Torres
    a.matricula = 1010;
    strcpy(a.nombre, "Ana Torres");
    strcpy(a.cal[0].materia, "Mat1"); a.cal[0].calificacion = 8;
    strcpy(a.cal[1].materia, "Mat2"); a.cal[1].calificacion = 9;
    strcpy(a.cal[2].materia, "Mat3"); a.cal[2].calificacion = 10;
    strcpy(a.cal[3].materia, "Mat4"); a.cal[3].calificacion = 7;
    strcpy(a.cal[4].materia, "Mat5"); a.cal[4].calificacion = 9;
    fwrite(&a, sizeof(alumno), 1, f);

    // Alumno 2: Luis Gomez
    a.matricula = 1020;
    strcpy(a.nombre, "Luis Gomez");
    strcpy(a.cal[0].materia, "Mat1"); a.cal[0].calificacion = 7;
    strcpy(a.cal[1].materia, "Mat2"); a.cal[1].calificacion = 6;
    strcpy(a.cal[2].materia, "Mat3"); a.cal[2].calificacion = 8;
    strcpy(a.cal[3].materia, "Mat4"); a.cal[3].calificacion = 9;
    strcpy(a.cal[4].materia, "Mat5"); a.cal[4].calificacion = 10;
    fwrite(&a, sizeof(alumno), 1, f);

    // Alumna 3: Marta Perez
    a.matricula = 1030;
    strcpy(a.nombre, "Marta Perez");
    strcpy(a.cal[0].materia, "Mat1"); a.cal[0].calificacion = 9;
    strcpy(a.cal[1].materia, "Mat2"); a.cal[1].calificacion = 10;
    strcpy(a.cal[2].materia, "Mat3"); a.cal[2].calificacion = 10;
    strcpy(a.cal[3].materia, "Mat4"); a.cal[3].calificacion = 10;
    strcpy(a.cal[4].materia, "Mat5"); a.cal[4].calificacion = 9;
    fwrite(&a, sizeof(alumno), 1, f);

    fclose(f);
    return 0;
}

