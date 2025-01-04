#include "Ekran.h"
#include "Ksztalt.h"
#include "Kolo.h"
#include "Kwadrat.h"
#include "Napis.h"
#include <vector>
#include "Klawiatura.h"
#include <ESP32-HUB75-MatrixPanel-I2S-DMA.h>



Klawiatura klawiatura(13, 14, 23, 39, 64 , 64);
std::vector<Ksztalt*> ksztalty;

void setup() {
  Serial.begin(115200);
  Ekran ekran; // Ekran musi być zainicjalizowany w setup ponieważ jako obiekt globalny ESP32 może nie być jeszcze gotowy do inicjalizacji
  ekran.wyczysc();
  klawiatura.init();

    // Tworzymy różne kształty
    ksztalty.push_back(new Napis("Witaj Vika ", 2, 25, 0x001F));
    ksztalty.push_back(new Kolo(0, 0, 10, 0xF800));
    ksztalty.push_back(new Kwadrat( 39, 0, 15, 0x07E0));
    
    // Rysujemy wszystkie kształty
    for (auto ksztalt : ksztalty) {
        ksztalt->rysuj();
    }
    ksztalty.clear();
    delay (500);
        // Zwolnienie pamięci
    for (auto ksztalt : ksztalty) {
        delete ksztalt;
    }

    //matrix.fillScreen(0);
}
    
Kwadrat Kwadrat2(0, 0, 20, 0xF800);  

unsigned long CzasPoprzedni=millis();
unsigned long CzasPoprzedniDlaKola=millis();
int przerwa=50;
int czasDodaniaKola=50;
unsigned long fps_timer;

uint16_t time_counter = 0, cycles = 0, fps = 0;
int ileKol=150;
void loop() {
    matrix.flipDMABuffer(); //urzycie podwójnego buffora wrzucić jako funkcję do ekran cpp
    matrix.clearScreen(); // to też jak wyżej 
   if (millis() - CzasPoprzedniDlaKola > czasDodaniaKola)
    {
     if (ileKol) 
     { 
    ksztalty.push_back(new Kolo(random(64),0, random(3,5), random(65000)));
    ileKol--;
    }
    CzasPoprzedniDlaKola = millis();
    }

  klawiatura.update();
  Kwadrat2.ustawPozycje(klawiatura.getX(),klawiatura.getY());
  Kwadrat2.rysuj();

  for (auto ksztalt : ksztalty)
    {
    Kolo* kkk = static_cast<Kolo*>(ksztalt);
    kkk->Grawitacja();
    kkk->rysuj();
    }

 /* if (millis()-CzasPoprzedni > przerwa)
  {
  Serial.print ("X=");
  Serial.print (klawiatura.getX());
  Serial.print ("\t\tY=");
  Serial.print (klawiatura.getY());
  Serial.print ("  \n");
  CzasPoprzedni = millis();
  }*/
  while (millis()-CzasPoprzedni < przerwa); // odczekaj przerwę 
  CzasPoprzedni = millis();
 // matrix.fillScreen(0);

    ++time_counter;
    ++cycles;
    ++fps;

    if (cycles >= 1024) {
        time_counter = 0;
        cycles = 0;
    }



 if (fps_timer + 5000 < millis()){
      Serial.printf_P(PSTR("Effect fps: %d\n"), fps/5);
      fps_timer = millis();
      fps = 0;
    }


}
