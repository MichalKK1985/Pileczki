#include <stdint.h>
#ifndef KWADRAT_H
#define KWADRAT_H

#include "Ksztalt.h"

class Kwadrat : public Ksztalt {
private:
    int x, y, rozmiar;
    uint16_t kolor;

public:
    Kwadrat(int x, int y, int rozmiar, uint16_t kolor);
    void rysuj() override;

    void ustawPozycje(int x, int y) ;
  void zmienKolor();


};

#endif
