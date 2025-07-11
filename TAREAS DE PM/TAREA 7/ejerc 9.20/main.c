#include <stdio.h>
#include <string.h>

// Estructura para calificaciones por materia
typedef struct {
    char materia[20];
    int calificacion;
} matcal;

// Estructura para alumno
typedef struct {
    int matricula;
    char nombre[20];
    matcal cal[5]; // 5 materias
} alumno;

// Prototipos
void F1(FILE *);
void F2(FILE *);
float F3(FILE *);

int main(void) {
    FILE *ap;
    float pro;

    ap = fopen("esc.dat", "rb");

    if (ap != NULL) {
        F1(ap);
        F2(ap);
        pro = F3(ap);
        printf("\n\nPROMEDIO GENERAL MATERIA 4: %.2f\n", pro);
        fclose(ap);
    } else {
        printf("\nEl archivo no se puede abrir\n");
    }

    return 0;
}

void F1(FILE *ap) {
    alumno alu;
    int j;
    float sum, pro;

    rewind(ap);
    printf("\nMATRÍCULA Y PROMEDIOS GENERALES:\n");

    while (fread(&alu, sizeof(alumno), 1, ap) == 1) {
        printf("Matrícula: %d\t", alu.matricula);
        sum = 0.0;
        for (j = 0; j < 5; j++)
            sum += alu.cal[j].calificacion;
        pro = sum / 5;
        printf("Promedio: %.2f\n", pro);
    }
}

void F2(FILE *ap) {
    alumno alu;

    rewind(ap);
    printf("\nALUMNOS CON CALIFICACIÓN > 9 EN MATERIA 3:\n");

    while (fread(&alu, sizeof(alumno), 1, ap) == 1) {
        if (alu.cal[2].calificacion > 9)
            printf("Matrícula del alumno: %d\n", alu.matricula);
    }
}

float F3(FILE *ap) {
    alumno alu;
    int i = 0;
    float sum = 0.0;

    rewind(ap);
    while (fread(&alu, sizeof(alumno), 1, ap) == 1) {
        sum += alu.cal[3].calificacion;
        i++;
    }

    if (i == 0)
        return 0.0;
    else
        return sum / i;
}

