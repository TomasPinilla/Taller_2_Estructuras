#include "negative_filter.h"

void NegativeFilter::apply(Image& image) {
    std::vector<std::vector<std::vector<int>>> pixels = image.getPixels();
    //-----------------------------------------------------------------------
    // TODO #5: Implementar el filtro negativo (NEGATIVE).
    //Declaracion de variables ancho, alto y canales
    int width = pixels.size();
    int height = pixels[0].size();
    int channels = pixels[0][0].size();
    // Aplicar el filtro negativo
    for (int x = 0; x < width; ++x) {
        for (int y = 0; y < height; ++y) {
            for (int c = 0; c < channels; ++c) {
                pixels[x][y][c] = 255 - pixels[x][y][c];
            }
        }
    }
    //-----------------------------------------------------------------------
    image.setPixels(pixels);
}
