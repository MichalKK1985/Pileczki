#include "Kwadrat.h"
#include "Ekran.h" // Dostęp do globalnej matrycy

Kwadrat::Kwadrat(int x, int y, int rozmiar, uint16_t kolor)
    : x(x), y(y), rozmiar(rozmiar), kolor(kolor) {}

void Kwadrat::rysuj() {
    for (int i = x; i < x + rozmiar; i++) {
        for (int j = y; j < y + rozmiar; j++) {
            matrix.drawPixel(i, j, kolor);
        }
    }
}

void Kwadrat::ustawPozycje(int x, int y) {
    this->x = x;
    this->y = y;
}

 void Kwadrat::zmienKolor()
  {
    this->kolor+=1000;
  }
