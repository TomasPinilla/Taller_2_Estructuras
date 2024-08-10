#include "sepia_filter.h"

void SepiaFilter::apply(Image& image) {
    std::vector<std::vector<std::vector<int>>> pixels = image.getPixels();
    //-----------------------------------------------------------------------
    // TODO #6: Implementar el filtro sepia.
    //Declaracion de las variables ancho y largo de la imagen
    int width = pixels.size();
    int height = pixels[0].size();
    //Recorrer la imagen por pixels
    for (int x = 0; x < width; ++x) {
        for (int y = 0; y < height; ++y) {
            int originalRed = pixels[x][y][0];
            int originalGreen = pixels[x][y][1];
            int originalBlue = pixels[x][y][2];
            // Aplicar la fórmula para el filtro sepia
            int sepiaRed   = std::min(255, (int)(0.393 * originalRed + 0.769 * originalGreen + 0.189 * originalBlue));
            int sepiaGreen = std::min(255, (int)(0.349 * originalRed + 0.686 * originalGreen + 0.168 * originalBlue));
            int sepiaBlue  = std::min(255, (int)(0.272 * originalRed + 0.534 * originalGreen + 0.131 * originalBlue));
            // Asignar los nuevos valores
            pixels[x][y][0] = sepiaRed;
            pixels[x][y][1] = sepiaGreen;
            pixels[x][y][2] = sepiaBlue;
        }
    }
    //-----------------------------------------------------------------------
    image.setPixels(pixels);
}
