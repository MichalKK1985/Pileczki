#ifndef KOLO_H
#define KOLO_H

#include "Ksztalt.h"

class Kolo : public Ksztalt {
private:
    uint16_t kolor;
    // Parametry fizyki obiektu
    float x;  // Pozycja x (środek matrycy)
    float y;  // Pozycja y (środek matrycy)
    float promien = 3.0f;  // Promień kulki
    float velocityX = 1.5f;  // Prędkość w osi X
    float velocityY = 2.0f;  // Prędkość w osi Y

    // Stałe fizyczne
    const float gravity = 0.05;        // Grawitacja (piksele na klatkę^2)
    const float restitution = 0.8;    // Tłumienie odbicia
    const float friction = 0.95;      // Tarcie na podłożu
    const float minVelocity = 0.1;    // Minimalna prędkość dla zatrzymania

public:
    Kolo(float x, float y, float promien, uint16_t kolor);
    void rysuj() override; // Nadpisanie metody
    void Grawitacja() ;
};

#endif




