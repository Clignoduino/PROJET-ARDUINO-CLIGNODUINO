#include "Arduino.h"
#include <Adafruit_NeoPixel.h>          //Bibliothèque NeoPixel

#include <SoftwareSerial.h>
SoftwareSerial ArduinoMaster(2,3);      //Bibliothèque Bluetooth (RX TX)


Adafruit_NeoPixel strip = Adafruit_NeoPixel(21, 6, NEO_GRB + NEO_KHZ800);
//21 LEDS par bande de leds
//Sortie des leds sur le PIN 6
//Paramètre NEO_GRB = Pixels sont raccordés en flux de donnée GRB (GRB=Green,Red,Blue)
//Paramètre NEO_KHZ800 = flux de données à 800 KHz (plupart des NéoPixel basé sur les LEDs w/WS2812)

Adafruit_NeoPixel strip1 = Adafruit_NeoPixel(21, 5, NEO_GRB + NEO_KHZ800);
//21 LEDS par bande de leds
//Sortie des leds sur le PIN 5

uint32_t ORANGE = strip.Color(255, 69, 0);  //Déclaration de la couleur orange
uint32_t JAUNEF = strip.Color(88, 41, 0);    //Déclaration de la couleur ROUGE
uint32_t ROUGE = strip.Color(255,0,0);
uint32_t ROSE = strip.Color(220,20,60);
uint32_t BLEU = strip.Color(0, 0, 128);     //Déclaration de la couleur BLEU
uint32_t JAUNE = strip.Color(255, 255, 0);
uint32_t VERT = strip.Color(0,128,0);
uint32_t CITRON = strip.Color(0,255,0);
uint32_t CYAN = strip.Color(38, 196, 236);
uint32_t VIOLET = strip.Color(128,0,128);
uint32_t VIOLETC = strip.Color(121, 28, 248);
uint32_t LAVANDE = strip.Color(204, 204, 255);
uint32_t MARINE = strip.Color(0,0,255);
uint32_t BLANC = strip.Color(255,255,255);

//Besoin de définir les couleurs une seule fois

int n;
