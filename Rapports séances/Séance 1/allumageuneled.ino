#include <Adafruit_NeoPixel.h>          //Bibliothèque NeoPixel
#define PIN 5                           //Sortie sur la broche 5
#define NUM_LEDS 21                     //Nombre de led (ici, 21) car une bande de led = 21 leds
Adafruit_NeoPixel strip1 = Adafruit_NeoPixel(NUM_LEDS, PIN, NEO_GRB + NEO_KHZ800);
// Paramètre 1 = Le nombre de NéoPixels chainés
// Paramètre 2 = No de broche de données 
// Paramètre 3 = Type de pixel (flags/drapeaux)
//Paramètre NEO_GRB = Pixels sont raccordés en flux de donnée GRB (GRB=Green,Red,Blue)
//Paramètre NEO_KHZ800 = flux de données à 800 KHz (plupart des NéoPixel basé sur les LEDs w/WS2812)


uint32_t ROUGE = strip1.Color(255, 0, 0);    //Déclaration de la couleur ROUGE


void setup() {
  
  strip1.begin();              
  strip1.show();                  // Actualise la bande de led
  strip1.setPixelColor(1,ROUGE); //Allume la 17eme LED de la bande
  strip1.setBrightness(255);      //Luminosité à 100%
  strip1.show();                  // Actualise la bande de led

}

void loop(){}
