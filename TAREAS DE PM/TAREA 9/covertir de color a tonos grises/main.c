// Esto es para cargar imágenes
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

// Esto es para guardar imágenes
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb_image_write.h"

#include <stdio.h>
#include <stdlib.h> // para malloc

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Debes escribir el nombre de la imagen.\n");
        return 1;
    }

    int ancho, alto, canales;
    unsigned char *imagen;

    imagen = stbi_load(argv[1], &ancho, &alto, &canales, 0);

    if (imagen == NULL) {
        printf("No se pudo cargar la imagen.\n");
        return 1;
    }

    printf("Imagen cargada.\n");
    printf("Ancho: %d\n", ancho);
    printf("Alto: %d\n", alto);
    printf("Canales: %d\n", canales);

    // Crear nueva imagen para el resultado en gris
    unsigned char *gris = (unsigned char *)malloc(ancho * alto);

    if (gris == NULL) {
        printf("No se pudo crear memoria para la imagen gris.\n");
        stbi_image_free(imagen);
        return 1;
    }

    // Recorrer cada píxel
    for (int i = 0; i < ancho * alto; i++) {
        int r = imagen[i * canales + 0]; // rojo
        int g = imagen[i * canales + 1]; // verde
        int b = imagen[i * canales + 2]; // azul

        // Calcular gris
        unsigned char tono = 0.3 * r + 0.59 * g + 0.11 * b;

        gris[i] = tono; // guardarlo en la nueva imagen
    }

    // Guardar la imagen nueva
    stbi_write_jpg("imagen_gris.jpg", ancho, alto, 1, gris, 100);
    printf("Imagen guardada como 'imagen_gris.jpg'\n");

    // Liberar memoria
    stbi_image_free(imagen);
    free(gris);

    return 0;
}
