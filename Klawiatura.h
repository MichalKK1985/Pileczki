#define INTERWAL_WYSWIETLANIA 50 // Interwał wyświetlania "Trzymam"
#define OPOZNIENIE 100            // Opóźnienie dla przycisków
#define CZAS_TRZYMANIA 300       // Czas wymagany do uruchomienia długiego trzymania

#include <Arduino.h>

class Klawiatura {
private:
    struct Button {
        int pin;                 // Numer pinu
        bool currentState;       // Aktualny stan przycisku
        bool previousState;      // Poprzedni stan przycisku
        unsigned long pressTime; // Czas ostatniego wciśnięcia
        unsigned long lastPrintTime; // Czas ostatniego wyświetlenia "Trzymam"
    };

    Button buttons[4];           // Tablica przycisków
    int x;                       // Pozycja X
    int y;                       // Pozycja Y
    const int xMax;
    const int yMax;

public:
    Klawiatura(int pinPrawo, int pinDol, int pinGora, int pinLewo, int zakresX, int zakresY) : x(0), y(0), xMax(zakresX), yMax(zakresY) { // wymagane podanie pinów podłączenia klawiatury. Na przyszłość dodać konstruktor domyślny dla pinów zdefiniowanych przez define
        buttons[0] = {pinPrawo, false, false, 0, 0};
        buttons[1] = {pinDol, false, false, 0, 0};
        buttons[2] = {pinGora, false, false, 0, 0};
        buttons[3] = {pinLewo, false, false, 0, 0};
       
    }

    void init() {
        for (auto &button : buttons) {
            pinMode(button.pin, INPUT);
        }
    }

    int getX()
    {
      return x;
    }

    int getY()
    {
      return y;
    }

    void update() {
        handleButton(buttons[0], x, 1); // Prawo: zwiększa X
        handleButton(buttons[1], y, 1); // Dół: zwiękasz Y
        handleButton(buttons[2], y, -1); // Góra: zmniejsza Y
        handleButton(buttons[3], x, -1); // Lewo: zmniejsza X
       
       if (x < 0 || x > xMax) {             // sprawdzamy warunek czy x mieści się pomiędzy 0 a 63
      x = (x < 0) ? 0 : xMax;               // jeżeli x jest mniejsze od zera to wstawiamy zero jeżeli nie to 63
        }

      if (y < 0 || y > yMax) {
        y = (y < 0) ? 0 : yMax;
        }

     //  Serial.print("Pozycja: X=");
      // Serial.print(x);
       //Serial.print(", Y=");
       //Serial.print(y); 
       //Serial.print("\n");
    
    }

private:
    void handleButton(Button &button, int &coordinate, int delta) {
        button.currentState = digitalRead(button.pin);

        // Obsługa krótkiego naciśnięcia
        if (button.currentState && !button.previousState) {
            if (millis() - button.pressTime > OPOZNIENIE) {
                coordinate += delta;
                button.pressTime = millis(); // Aktualizacja czasu wciśnięcia
            }
        }

        // Obsługa długiego trzymania
        if (button.currentState) {
            if (millis() - button.pressTime > CZAS_TRZYMANIA) {
                if (millis() - button.lastPrintTime >= INTERWAL_WYSWIETLANIA) {
                    coordinate += delta;
                    button.lastPrintTime = millis(); // Aktualizacja czasu wyświetlenia
                }
            }
        }

        // Aktualizacja poprzedniego stanu
        button.previousState = button.currentState;
    }
};

