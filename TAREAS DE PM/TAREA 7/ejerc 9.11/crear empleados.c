#include <stdio.h>

typedef struct {
    int clave;
    int departamento;
    float salario;
    float ventas[12];
} empleado;

int main() {
    FILE *f = fopen("ad5.dat", "wb");  // Abrir archivo en modo binario escritura
    if (!f) {
        printf("Error al crear el archivo.\n");
        return 1;
    }

    empleado e1;
    e1.clave = 1;
    e1.departamento = 101;
    e1.salario = 50000;

    float ventas_temp[12] = {100000, 120000, 95000, 105000, 98000, 110000,
                             99000, 102000, 96000, 103000, 100000, 101000};
    for (int i = 0; i < 12; i++) {
        e1.ventas[i] = ventas_temp[i];
    }

    fwrite(&e1, sizeof(empleado), 1, f);  // Guardar el registro en el archivo
    fclose(f);

    printf("Archivo creado correctamente.\n");
    return 0;
}


