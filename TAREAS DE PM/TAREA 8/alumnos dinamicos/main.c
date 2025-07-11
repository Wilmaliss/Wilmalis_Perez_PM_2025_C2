#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_NOMBRE 50

typedef struct {
    char nombre[MAX_NOMBRE];
    float promedio;
} Alumno;

int leer_alumnos(Alumno **alumnos, const char* nombre_archivo) {
    FILE *archivo = fopen(nombre_archivo, "rb");
    if (!archivo) return 0;

    fseek(archivo, 0, SEEK_END);
    long tamano = ftell(archivo);
    int num_alumnos = tamano / sizeof(Alumno);
    rewind(archivo);

    *alumnos = (Alumno *)malloc(num_alumnos * sizeof(Alumno));
    if (!*alumnos) {
        fclose(archivo);
        return 0;
    }

    fread(*alumnos, sizeof(Alumno), num_alumnos, archivo);
    fclose(archivo);
    return num_alumnos;
}

void guardar_alumnos(Alumno *alumnos, int n, const char* nombre_archivo) {
    FILE *archivo = fopen(nombre_archivo, "wb");
    if (archivo) {
        fwrite(alumnos, sizeof(Alumno), n, archivo);
        fclose(archivo);
    }
}

void imprimir_alumnos(Alumno *alumnos, int n) {
    printf("\n%-20s\t%s\n", "Nombre", "Promedio");
    printf("--------------------------------\n");
    Alumno *ptr = alumnos;
    for (int i = 0; i < n; i++) {
        printf("%-20s\t%.2f\n", (ptr + i)->nombre, (ptr + i)->promedio);
    }
}

int main() {
    Alumno *alumnos = NULL;
    char nombre_archivo[] = "alumnos.dat";
    int n = leer_alumnos(&alumnos, nombre_archivo);
    int capacidad = n > 0 ? n : 10;
    alumnos = (Alumno *)realloc(alumnos, capacidad * sizeof(Alumno));
    if (!alumnos) {
        printf("Error de memoria.\n");
        return 1;
    }

    printf("Ingrese datos de alumnos (nombre '000' para terminar):\n");
    while (1) {
        if (n >= capacidad) {
            capacidad += 10;
            alumnos = (Alumno *)realloc(alumnos, capacidad * sizeof(Alumno));
            if (!alumnos) {
                printf("Error de memoria.\n");
                return 1;
            }
        }

        Alumno *nuevo = alumnos + n;
        printf("Nombre: ");
        fgets(nuevo->nombre, MAX_NOMBRE, stdin);
        nuevo->nombre[strcspn(nuevo->nombre, "\n")] = 0;

        if (strcmp(nuevo->nombre, "000") == 0) {
            break;
        }

        printf("Promedio: ");
        scanf("%f", &nuevo->promedio);
        getchar();
        n++;
    }

    guardar_alumnos(alumnos, n, nombre_archivo);
    imprimir_alumnos(alumnos, n);

    free(alumnos);
    return 0;
}
