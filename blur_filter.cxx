#include "blur_filter.h"

BlurFilter::BlurFilter() {
  kernel = {{{1, 1, 1}, {1, 1, 1}, {1, 1, 1}},
            {{1, 1, 1}, {1, 1, 1}, {1, 1, 1}},
            {{1, 1, 1}, {1, 1, 1}, {1, 1, 1}}};
}

void BlurFilter::apply(Image &image) {
    std::vector<std::vector<std::vector<int>>> pixels = image.getPixels();
  //-----------------------------------------------------------------------
  // TODO #4: Implementar el filtro de desenfoque (BLUR).
  // Variables de ancho y largo de la imagen
    int width = pixels.size();
    int height = pixels[0].size();
    int channels = pixels[0][0].size();
// Tamaño del Kernel
    int ksize = kernel.size();
    int kOffset = ksize / 2;
    int ksum = ksize * ksize; // Suma de los valores de Kernel para normalizar
// Inicializa la matriz de píxeles para la nueva imagen desenfocada
    std::vector<std::vector<std::vector<int>>> newPixels (width, std::vector<std::vector<int>>(height, std::vector<int>(channels, 0)));

// Aplicar filtro de desenfoque
     for (int x = kOffset; x < width - kOffset; ++x) {
        for (int y = kOffset; y < height - kOffset; ++y) {
            for (int c = 0; c < channels; ++c) {
                int sum = 0;
                for (int i = -kOffset; i <= kOffset; ++i) {
                    for (int j = -kOffset; j <= kOffset; ++j) {
                        sum += pixels[x + i][y + j][c] * kernel[i + kOffset][j + kOffset][c];
                    }
                }
                newPixels[x][y][c] = sum / ksum;
            }
        }
     }    
    //-----------------------------------------------------------------------
    image.setPixels(newPixels);
  }
