#ifndef KSZTALT_H
#define KSZTALT_H
#include <Arduino.h>
class Ksztalt {
public:
    virtual void rysuj() = 0; // Metoda czysto wirtualna
    virtual ~Ksztalt() = default; // Wirtualny destruktor
};

#endif
