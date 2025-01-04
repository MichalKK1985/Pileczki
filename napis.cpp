#include "Napis.h"
#include "Ekran.h"

Napis::Napis(const char* tekst, int x, int y, uint16_t kolor)
    : tekst(tekst), x(x), y(y), kolor(kolor) {}

void Napis::rysuj() {
    matrix.setTextColor(kolor);
    matrix.setCursor(x, y);
    matrix.print(tekst);
}
