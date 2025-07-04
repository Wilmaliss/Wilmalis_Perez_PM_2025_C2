#include <stdio.h>
#include <string.h>

#define MAX_NOMBRE 50
#define MAX_ALUMNOS 100

typedef struct {
    char nombre[MAX_NOMBRE];
    float promedio;
} Alumno;

int leer_alumnos(Alumno alumnos[], const char* nombre_archivo) {
    FILE *archivo = fopen(nombre_archivo, "rb");
    int contador = 0;
    if (archivo) {
        while (fread(&alumnos[contador], sizeof(Alumno), 1, archivo)) {
            contador++;
        }
        fclose(archivo);
    }
    return contador;
}

void guardar_alumnos(Alumno alumnos[], int n, const char* nombre_archivo) {
    FILE *archivo = fopen(nombre_archivo, "wb");
    if (archivo) {
        fwrite(alumnos, sizeof(Alumno), n, archivo);
        fclose(archivo);
    }
}

void bubble_sort_alfabetico(Alumno alumnos[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (strcmp(alumnos[j].nombre, alumnos[j + 1].nombre) > 0) {
                Alumno temp = alumnos[j];
                alumnos[j] = alumnos[j + 1];
                alumnos[j + 1] = temp;
            }
        }
    }
}

void bubble_sort_promedio(Alumno alumnos[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (alumnos[j].promedio < alumnos[j + 1].promedio) {
                Alumno temp = alumnos[j];
                alumnos[j] = alumnos[j + 1];
                alumnos[j + 1] = temp;
            }
        }
    }
}

void imprimir_alumnos(Alumno alumnos[], int n) {
    printf("\n%-20s\t%s\n", "Nombre", "Promedio");
    printf("--------------------------------\n");
    for (int i = 0; i < n; i++) {
        printf("%-20s\t%.2f\n", alumnos[i].nombre, alumnos[i].promedio);
    }
}

int main() {
    Alumno alumnos[MAX_ALUMNOS];
    char nombre_archivo[] = "alumnos.dat";
    int n = leer_alumnos(alumnos, nombre_archivo);
    char opcion;

    printf("Ingrese datos de alumnos (nombre '000' para terminar):\n");
    while (n < MAX_ALUMNOS) {
        printf("Nombre: ");
        fgets(alumnos[n].nombre, MAX_NOMBRE, stdin);
        alumnos[n].nombre[strcspn(alumnos[n].nombre, "\n")] = 0;

        if (strcmp(alumnos[n].nombre, "000") == 0) {
            break;
        }

        printf("Promedio: ");
        scanf("%f", &alumnos[n].promedio);
        getchar();
        n++;
    }

    guardar_alumnos(alumnos, n, nombre_archivo);

    printf("\n¿Cómo quieres el orden? Alfabéticamente (A) o por promedio (P): ");
    scanf(" %c", &opcion);
    if (opcion == 'A' || opcion == 'a') {
        bubble_sort_alfabetico(alumnos, n);
    } else if (opcion == 'P' || opcion == 'p') {
        bubble_sort_promedio(alumnos, n);
    }

    imprimir_alumnos(alumnos, n);
    return 0;
}
