#ifndef NAPIS_H
#define NAPIS_H

#include "Ksztalt.h"

class Napis : public Ksztalt {
private:
    const char* tekst;
    int x, y;
    uint16_t kolor;

public:
    Napis(const char* tekst, int x, int y, uint16_t kolor);
    void rysuj() override;
};

#endif
