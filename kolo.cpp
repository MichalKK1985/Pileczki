
#include "Kolo.h"
#include "Ekran.h"

// Konstruktor
Kolo::Kolo(float x, float y, float promien, uint16_t kolor)
    : x(x), y(y), promien(promien), kolor(kolor) {}

// Metoda do rysowania
void Kolo::rysuj() {
   
    matrix.fillCircle(x, y, promien, kolor);
}

// Metoda grawitacji
void Kolo::Grawitacja() {
    static int czasPoprzedni = millis();
    int czaWyswietlania = 1000;

    // Logowanie pozycji co 1 sekundę
/*if (millis() - czasPoprzedni > czaWyswietlania) {
  Serial.print("X:=");
  Serial.print(x);
  Serial.print("\t\tY:=");
  Serial.println(y);
  czasPoprzedni = millis();
}*/

    // Aktualizacja pozycji
    velocityY += gravity; // Grawitacja działa w dół
    x += velocityX;
    y += velocityY;

    // Kolizje z bokami ekranu
    if (x - promien < 0) {
        x = promien;
        velocityX = -velocityX * restitution; // Tłumione odbicie
    }
    if (x + promien > 63) {
        x = 63 - promien;
        velocityX = -velocityX * restitution;
    }

    // Kolizje z podłożem i sufitem
    if (y + promien > 63) { // Podłoże
        y = 63 - promien;
        velocityY = -velocityY * restitution; // Tłumione odbicie
        velocityX *= friction;               // Tarcie w osi X

        // Zatrzymanie w osi X, jeśli prędkość jest mała
        if (abs(velocityX) < minVelocity) {
            velocityX = 0;
        }

        // Zatrzymanie w osi Y, jeśli prędkość jest mała
        if (abs(velocityY) < minVelocity) {
            velocityY = 0;
        }
    }

    if (y - promien < 0) { // Sufit
        y = promien;
        velocityY = -velocityY * restitution;
    }
}
