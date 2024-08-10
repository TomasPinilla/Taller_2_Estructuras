#include "pixelate_filter.h"

void PixelateFilter::apply(Image& image, int blockSize) {
    std::vector<std::vector<std::vector<int>>> pixels = image.getPixels();
    //-----------------------------------------------------------------------
    // TODO #7: Implementar el filtro pixelar (PIXELATE).
    //Declaracion de variables ancho, alto y canales
    int width = pixels.size();
    int height = pixels[0].size();
    int channels = pixels[0][0].size();
    // Aplicar el filtro de pixelado
    for(int x = 0; x < width; x += blockSize) {
        for(int y = 0; y < height; y += blockSize) {
            int sumR = 0, sumG = 0, sumB = 0;
            int pixelCount = 0;
            // Sumar los valores de color dentro del bloque
            for (int i = 0; i < blockSize && (x + i) < width; ++i) {
                for (int j = 0; j < blockSize && (y + j) < height; ++j) {
                    sumR += pixels[x + i][y + j][0];
                    sumG += pixels[x + i][y + j][1];
                    sumB += pixels[x + i][y + j][2];
                    pixelCount++;
                }
            }
            // Calcular el color promedio del bloque
            int avgR = sumR / pixelCount;
            int avgG = sumG / pixelCount;
            int avgB = sumB / pixelCount;
            // Asignar el color promedio a todos los píxeles del bloque
                    for (int i = 0; i < blockSize && (x + i) < width; ++i) {
                        for (int j = 0; j < blockSize && (y + j) < height; ++j) {
                            pixels[x + i][y + j][0] = avgR;
                            pixels[x + i][y + j][1] = avgG;
                            pixels[x + i][y + j][2] = avgB;
                        }
                    }
                }
            }
    //-----------------------------------------------------------------------
    image.setPixels(pixels);
}
