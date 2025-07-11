#include <stdio.h>

typedef struct {
    int matricula;
    char nombre[20];
    int carrera;
    float promedio;
} alumno;

void ordena(FILE *, FILE *);

int main(void) {
    FILE *ar1, *ar2;

    ar1 = fopen("ad5.dat", "rb"); // Modo binario lectura
    ar2 = fopen("ad6.dat", "wb"); // Modo binario escritura

    if ((ar1 != NULL) && (ar2 != NULL)) {
        ordena(ar1, ar2);
        fclose(ar1);
        fclose(ar2);
        printf("\nArchivo ad6.dat generado correctamente en orden descendente.\n");
    } else {
        printf("\nEl o los archivos no se pudieron abrir\n");
    }

    return 0;
}

void ordena(FILE *ap1, FILE *ap2) {
    alumno alu;
    int t, n, i;

    t = sizeof(alumno);

    fseek(ap1, 0, SEEK_END); // Ir al final
    n = ftell(ap1) / t;      // Total de registros
    rewind(ap1);             // Volver al inicio

    for (i = n - 1; i >= 0; i--) {
        fseek(ap1, i * t, SEEK_SET);  // Posicionarse en el registro i
        fread(&alu, t, 1, ap1);
        fwrite(&alu, t, 1, ap2);
    }
}
