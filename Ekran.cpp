#include "Ekran.h"
#define PANEL_RES_X 64  // Number of pixels wide of each INDIVIDUAL panel module.
#define PANEL_RES_Y 64  // Number of pixels tall of each INDIVIDUAL panel module.
#define PANEL_CHAIN 1   // Total number of panels chained one to another


// Globalny obiekt matrycy
MatrixPanel_I2S_DMA matrix;

Ekran::Ekran() {
    
    HUB75_I2S_CFG mxconfig(PANEL_RES_X, PANEL_RES_Y, PANEL_CHAIN); // Szerokość, wysokość, liczba paneli
    mxconfig.double_buff = true;
    matrix.begin(mxconfig);
    matrix.fillScreen(0); // Wypełnienie ekranu na czarno
    Serial.print("Ekran zainicjalizowany");
   
}

void Ekran::wyczysc() {
    matrix.fillScreen(0);
}
