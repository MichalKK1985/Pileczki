#ifndef EKRAN_H
#define EKRAN_H

#include <ESP32-HUB75-MatrixPanel-I2S-DMA.h>

class Ekran {
public:
    Ekran();
    void wyczysc();
};

extern MatrixPanel_I2S_DMA matrix; // Globalny obiekt matrycy

#endif
