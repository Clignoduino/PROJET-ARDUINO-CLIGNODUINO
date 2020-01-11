#include "Arduino.h"

#include <Adafruit_NeoPixel.h>          //Bibliothèque NeoPixel

Adafruit_NeoPixel strip = Adafruit_NeoPixel(21, 6, NEO_GRB + NEO_KHZ800);
//21 LEDS par bande de leds
//Sortie des leds sur le PIN 6
//Paramètre NEO_GRB = Pixels sont raccordés en flux de donnée GRB (GRB=Green,Red,Blue)
//Paramètre NEO_KHZ800 = flux de données à 800 KHz (plupart des NéoPixel basé sur les LEDs w/WS2812)

Adafruit_NeoPixel strip1 = Adafruit_NeoPixel(21, 5, NEO_GRB + NEO_KHZ800);
//21 LEDS par bande de leds
//Sortie des leds sur le PIN 5

uint32_t ORANGE = strip.Color(255, 69, 0);  //Déclaration de la couleur orange
uint32_t ROUGE = strip.Color(255, 0, 0);    //Déclaration de la couleur ROUGE
uint32_t BLEU = strip.Color(0, 0, 128);     //Déclaration de la couleur BLEU

//Besoin de définir les couleurs une seule fois

int n;
