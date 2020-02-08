#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SH1106.h>

/* Puisque la bibliothèque est basée sur celle du SSD1306, le constructeur
prévoit qu'on passe le numéro de la broche RESET en argument. Mais le SH1106
n'a pas de broche RESET, alors on écrit n'importe quel entier (de préférence,
le numéro d'une broche de l'Arduino que vous n'utilisez pas). */

Adafruit_SH1106 display(23); 

const unsigned char flechedroite [] PROGMEM = {
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0xff, 0xff, 0xff, 0x00, 0x01, 0xff, 0xff, 0xff, 0x80, 0x00, 
0x1f, 0xff, 0xff, 0xfc, 0x00, 0x01, 0xff, 0xff, 0xff, 0x80, 0x00, 0xff, 0xff, 0xff, 0x80, 0x00, 
0x0f, 0xff, 0xff, 0xfc, 0x00, 0x01, 0xff, 0xff, 0xff, 0x80, 0x00, 0xff, 0xff, 0xff, 0xc0, 0x00, 
0x0f, 0xff, 0xff, 0xfe, 0x00, 0x00, 0xff, 0xff, 0xff, 0xc0, 0x00, 0x7f, 0xff, 0xff, 0xc0, 0x00, 
0x07, 0xff, 0xff, 0xff, 0x00, 0x00, 0xff, 0xff, 0xff, 0xc0, 0x00, 0x7f, 0xff, 0xff, 0xe0, 0x00, 
0x03, 0xff, 0xff, 0xff, 0x00, 0x00, 0x7f, 0xff, 0xff, 0xe0, 0x00, 0x3f, 0xff, 0xff, 0xe0, 0x00, 
0x03, 0xff, 0xff, 0xff, 0x80, 0x00, 0x3f, 0xff, 0xff, 0xf0, 0x00, 0x1f, 0xff, 0xff, 0xf0, 0x00, 
0x01, 0xff, 0xff, 0xff, 0x80, 0x00, 0x3f, 0xff, 0xff, 0xf0, 0x00, 0x1f, 0xff, 0xff, 0xf0, 0x00, 
0x01, 0xff, 0xff, 0xff, 0xc0, 0x00, 0x1f, 0xff, 0xff, 0xf0, 0x00, 0x1f, 0xff, 0xff, 0xf8, 0x00, 
0x00, 0xff, 0xff, 0xff, 0xc0, 0x00, 0x1f, 0xff, 0xff, 0xf8, 0x00, 0x0f, 0xff, 0xff, 0xf8, 0x00, 
0x00, 0xff, 0xff, 0xff, 0xe0, 0x00, 0x1f, 0xff, 0xff, 0xfc, 0x00, 0x07, 0xff, 0xff, 0xfc, 0x00, 
0x00, 0x7f, 0xff, 0xff, 0xf0, 0x00, 0x0f, 0xff, 0xff, 0xfc, 0x00, 0x07, 0xff, 0xff, 0xfc, 0x00, 
0x00, 0x7f, 0xff, 0xff, 0xf0, 0x00, 0x07, 0xff, 0xff, 0xfc, 0x00, 0x07, 0xff, 0xff, 0xfe, 0x00, 
0x00, 0x3f, 0xff, 0xff, 0xf0, 0x00, 0x07, 0xff, 0xff, 0xfe, 0x00, 0x03, 0xff, 0xff, 0xfe, 0x00, 
0x00, 0x1f, 0xff, 0xff, 0xf8, 0x00, 0x03, 0xff, 0xff, 0xff, 0x00, 0x01, 0xff, 0xff, 0xff, 0x00, 
0x00, 0x1f, 0xff, 0xff, 0xfc, 0x00, 0x03, 0xff, 0xff, 0xff, 0x00, 0x01, 0xff, 0xff, 0xff, 0x00, 
0x00, 0x0f, 0xff, 0xff, 0xfc, 0x00, 0x01, 0xff, 0xff, 0xff, 0x80, 0x00, 0xff, 0xff, 0xff, 0x80, 
0x00, 0x0f, 0xff, 0xff, 0xfe, 0x00, 0x01, 0xff, 0xff, 0xff, 0x80, 0x00, 0xff, 0xff, 0xff, 0x80, 
0x00, 0x07, 0xff, 0xff, 0xfe, 0x00, 0x00, 0xff, 0xff, 0xff, 0xc0, 0x00, 0xff, 0xff, 0xff, 0xc0, 
0x00, 0x07, 0xff, 0xff, 0xff, 0x00, 0x00, 0x7f, 0xff, 0xff, 0xc0, 0x00, 0x7f, 0xff, 0xff, 0xc0, 
0x00, 0x03, 0xff, 0xff, 0xff, 0x80, 0x00, 0x7f, 0xff, 0xff, 0xe0, 0x00, 0x3f, 0xff, 0xff, 0xe0, 
0x00, 0x01, 0xff, 0xff, 0xff, 0x80, 0x00, 0x7f, 0xff, 0xff, 0xe0, 0x00, 0x3f, 0xff, 0xff, 0xe0, 
0x00, 0x01, 0xff, 0xff, 0xff, 0x80, 0x00, 0x3f, 0xff, 0xff, 0xf0, 0x00, 0x1f, 0xff, 0xff, 0xf0, 
0x00, 0x01, 0xff, 0xff, 0xff, 0xc0, 0x00, 0x1f, 0xff, 0xff, 0xf0, 0x00, 0x1f, 0xff, 0xff, 0xf8, 
0x00, 0x00, 0xff, 0xff, 0xff, 0xe0, 0x00, 0x1f, 0xff, 0xff, 0xf8, 0x00, 0x0f, 0xff, 0xff, 0xf8, 
0x00, 0x00, 0xff, 0xff, 0xff, 0xe0, 0x00, 0x3f, 0xff, 0xff, 0xf0, 0x00, 0x1f, 0xff, 0xff, 0xf0, 
0x00, 0x00, 0xff, 0xff, 0xff, 0xc0, 0x00, 0x3f, 0xff, 0xff, 0xf0, 0x00, 0x1f, 0xff, 0xff, 0xf0, 
0x00, 0x01, 0xff, 0xff, 0xff, 0x80, 0x00, 0x3f, 0xff, 0xff, 0xe0, 0x00, 0x3f, 0xff, 0xff, 0xe0, 
0x00, 0x03, 0xff, 0xff, 0xff, 0x80, 0x00, 0x7f, 0xff, 0xff, 0xe0, 0x00, 0x3f, 0xff, 0xff, 0xe0, 
0x00, 0x03, 0xff, 0xff, 0xff, 0x00, 0x00, 0xff, 0xff, 0xff, 0xc0, 0x00, 0x7f, 0xff, 0xff, 0xc0, 
0x00, 0x07, 0xff, 0xff, 0xff, 0x00, 0x00, 0xff, 0xff, 0xff, 0xc0, 0x00, 0x7f, 0xff, 0xff, 0xc0, 
0x00, 0x07, 0xff, 0xff, 0xfe, 0x00, 0x01, 0xff, 0xff, 0xff, 0x80, 0x00, 0xff, 0xff, 0xff, 0x80, 
0x00, 0x0f, 0xff, 0xff, 0xfe, 0x00, 0x01, 0xff, 0xff, 0xff, 0x80, 0x00, 0xff, 0xff, 0xff, 0x80, 
0x00, 0x0f, 0xff, 0xff, 0xfc, 0x00, 0x03, 0xff, 0xff, 0xff, 0x00, 0x01, 0xff, 0xff, 0xff, 0x00, 
0x00, 0x1f, 0xff, 0xff, 0xf8, 0x00, 0x03, 0xff, 0xff, 0xfe, 0x00, 0x01, 0xff, 0xff, 0xff, 0x00, 
0x00, 0x1f, 0xff, 0xff, 0xf8, 0x00, 0x07, 0xff, 0xff, 0xfe, 0x00, 0x03, 0xff, 0xff, 0xfe, 0x00, 
0x00, 0x3f, 0xff, 0xff, 0xf0, 0x00, 0x07, 0xff, 0xff, 0xfc, 0x00, 0x07, 0xff, 0xff, 0xfe, 0x00, 
0x00, 0x7f, 0xff, 0xff, 0xf0, 0x00, 0x0f, 0xff, 0xff, 0xfc, 0x00, 0x07, 0xff, 0xff, 0xfc, 0x00, 
0x00, 0x7f, 0xff, 0xff, 0xe0, 0x00, 0x0f, 0xff, 0xff, 0xf8, 0x00, 0x07, 0xff, 0xff, 0xf8, 0x00, 
0x00, 0xff, 0xff, 0xff, 0xe0, 0x00, 0x1f, 0xff, 0xff, 0xf8, 0x00, 0x0f, 0xff, 0xff, 0xf8, 0x00, 
0x00, 0xff, 0xff, 0xff, 0xc0, 0x00, 0x1f, 0xff, 0xff, 0xf0, 0x00, 0x1f, 0xff, 0xff, 0xf8, 0x00, 
0x01, 0xff, 0xff, 0xff, 0xc0, 0x00, 0x3f, 0xff, 0xff, 0xf0, 0x00, 0x1f, 0xff, 0xff, 0xf0, 0x00, 
0x01, 0xff, 0xff, 0xff, 0x80, 0x00, 0x7f, 0xff, 0xff, 0xe0, 0x00, 0x3f, 0xff, 0xff, 0xe0, 0x00, 
0x03, 0xff, 0xff, 0xff, 0x00, 0x00, 0x7f, 0xff, 0xff, 0xe0, 0x00, 0x3f, 0xff, 0xff, 0xe0, 0x00, 
0x03, 0xff, 0xff, 0xff, 0x00, 0x00, 0xff, 0xff, 0xff, 0xc0, 0x00, 0x7f, 0xff, 0xff, 0xc0, 0x00, 
0x07, 0xff, 0xff, 0xfe, 0x00, 0x00, 0xff, 0xff, 0xff, 0xc0, 0x00, 0x7f, 0xff, 0xff, 0xc0, 0x00, 
0x0f, 0xff, 0xff, 0xfe, 0x00, 0x01, 0xff, 0xff, 0xff, 0x80, 0x00, 0xff, 0xff, 0xff, 0xc0, 0x00, 
0x0f, 0xff, 0xff, 0xfc, 0x00, 0x01, 0xff, 0xff, 0xff, 0x80, 0x00, 0xff, 0xff, 0xff, 0x80, 0x00, 
0x1f, 0xff, 0xff, 0xfc, 0x00, 0x03, 0xff, 0xff, 0xff, 0x00, 0x01, 0xff, 0xff, 0xff, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};

const unsigned char flechegauche [] PROGMEM = {
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x01, 0xff, 0xff, 0xff, 0x80, 0x00, 0xff, 0xff, 0xff, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x01, 0xff, 0xff, 0xff, 0x00, 0x01, 0xff, 0xff, 0xff, 0x80, 0x00, 0x3f, 0xff, 0xff, 0xf8, 
0x00, 0x03, 0xff, 0xff, 0xff, 0x00, 0x01, 0xff, 0xff, 0xff, 0x80, 0x00, 0x3f, 0xff, 0xff, 0xf0, 
0x00, 0x03, 0xff, 0xff, 0xfe, 0x00, 0x03, 0xff, 0xff, 0xff, 0x00, 0x00, 0x7f, 0xff, 0xff, 0xf0, 
0x00, 0x07, 0xff, 0xff, 0xfe, 0x00, 0x03, 0xff, 0xff, 0xff, 0x00, 0x00, 0xff, 0xff, 0xff, 0xe0, 
0x00, 0x07, 0xff, 0xff, 0xfc, 0x00, 0x07, 0xff, 0xff, 0xfe, 0x00, 0x00, 0xff, 0xff, 0xff, 0xc0, 
0x00, 0x0f, 0xff, 0xff, 0xf8, 0x00, 0x07, 0xff, 0xff, 0xfc, 0x00, 0x01, 0xff, 0xff, 0xff, 0xc0, 
0x00, 0x0f, 0xff, 0xff, 0xf8, 0x00, 0x0f, 0xff, 0xff, 0xfc, 0x00, 0x01, 0xff, 0xff, 0xff, 0x80, 
0x00, 0x1f, 0xff, 0xff, 0xf8, 0x00, 0x0f, 0xff, 0xff, 0xfc, 0x00, 0x03, 0xff, 0xff, 0xff, 0x80, 
0x00, 0x1f, 0xff, 0xff, 0xf0, 0x00, 0x1f, 0xff, 0xff, 0xf8, 0x00, 0x03, 0xff, 0xff, 0xff, 0x00, 
0x00, 0x3f, 0xff, 0xff, 0xe0, 0x00, 0x3f, 0xff, 0xff, 0xf0, 0x00, 0x07, 0xff, 0xff, 0xff, 0x00, 
0x00, 0x3f, 0xff, 0xff, 0xe0, 0x00, 0x3f, 0xff, 0xff, 0xf0, 0x00, 0x07, 0xff, 0xff, 0xfe, 0x00, 
0x00, 0x7f, 0xff, 0xff, 0xc0, 0x00, 0x3f, 0xff, 0xff, 0xe0, 0x00, 0x0f, 0xff, 0xff, 0xfc, 0x00, 
0x00, 0x7f, 0xff, 0xff, 0xc0, 0x00, 0x7f, 0xff, 0xff, 0xe0, 0x00, 0x1f, 0xff, 0xff, 0xfc, 0x00, 
0x00, 0xff, 0xff, 0xff, 0x80, 0x00, 0xff, 0xff, 0xff, 0xc0, 0x00, 0x1f, 0xff, 0xff, 0xf8, 0x00, 
0x00, 0xff, 0xff, 0xff, 0x80, 0x00, 0xff, 0xff, 0xff, 0xc0, 0x00, 0x3f, 0xff, 0xff, 0xf8, 0x00, 
0x01, 0xff, 0xff, 0xff, 0x00, 0x01, 0xff, 0xff, 0xff, 0x80, 0x00, 0x3f, 0xff, 0xff, 0xf0, 0x00, 
0x01, 0xff, 0xff, 0xff, 0x00, 0x01, 0xff, 0xff, 0xff, 0x80, 0x00, 0x7f, 0xff, 0xff, 0xf0, 0x00, 
0x03, 0xff, 0xff, 0xfe, 0x00, 0x03, 0xff, 0xff, 0xff, 0x00, 0x00, 0x7f, 0xff, 0xff, 0xe0, 0x00, 
0x03, 0xff, 0xff, 0xfe, 0x00, 0x03, 0xff, 0xff, 0xff, 0x00, 0x00, 0xff, 0xff, 0xff, 0xe0, 0x00, 
0x07, 0xff, 0xff, 0xfc, 0x00, 0x07, 0xff, 0xff, 0xfe, 0x00, 0x00, 0xff, 0xff, 0xff, 0xc0, 0x00, 
0x0f, 0xff, 0xff, 0xfc, 0x00, 0x07, 0xff, 0xff, 0xfc, 0x00, 0x01, 0xff, 0xff, 0xff, 0x80, 0x00, 
0x0f, 0xff, 0xff, 0xf8, 0x00, 0x0f, 0xff, 0xff, 0xfc, 0x00, 0x03, 0xff, 0xff, 0xff, 0x80, 0x00, 
0x0f, 0xff, 0xff, 0xf8, 0x00, 0x0f, 0xff, 0xff, 0xf8, 0x00, 0x03, 0xff, 0xff, 0xff, 0x00, 0x00, 
0x1f, 0xff, 0xff, 0xf0, 0x00, 0x1f, 0xff, 0xff, 0xf8, 0x00, 0x07, 0xff, 0xff, 0xff, 0x00, 0x00, 
0x1f, 0xff, 0xff, 0xf8, 0x00, 0x1f, 0xff, 0xff, 0xfc, 0x00, 0x03, 0xff, 0xff, 0xff, 0x00, 0x00, 
0x0f, 0xff, 0xff, 0xf8, 0x00, 0x0f, 0xff, 0xff, 0xfc, 0x00, 0x03, 0xff, 0xff, 0xff, 0x00, 0x00, 
0x07, 0xff, 0xff, 0xfc, 0x00, 0x07, 0xff, 0xff, 0xfc, 0x00, 0x03, 0xff, 0xff, 0xff, 0x80, 0x00, 
0x07, 0xff, 0xff, 0xfc, 0x00, 0x07, 0xff, 0xff, 0xfe, 0x00, 0x01, 0xff, 0xff, 0xff, 0xc0, 0x00, 
0x03, 0xff, 0xff, 0xfe, 0x00, 0x03, 0xff, 0xff, 0xff, 0x00, 0x00, 0xff, 0xff, 0xff, 0xc0, 0x00, 
0x03, 0xff, 0xff, 0xfe, 0x00, 0x03, 0xff, 0xff, 0xff, 0x00, 0x00, 0xff, 0xff, 0xff, 0xe0, 0x00, 
0x01, 0xff, 0xff, 0xff, 0x00, 0x01, 0xff, 0xff, 0xff, 0x80, 0x00, 0x7f, 0xff, 0xff, 0xe0, 0x00, 
0x01, 0xff, 0xff, 0xff, 0x00, 0x01, 0xff, 0xff, 0xff, 0x80, 0x00, 0x7f, 0xff, 0xff, 0xf0, 0x00, 
0x00, 0xff, 0xff, 0xff, 0x80, 0x00, 0xff, 0xff, 0xff, 0xc0, 0x00, 0x3f, 0xff, 0xff, 0xf0, 0x00, 
0x00, 0xff, 0xff, 0xff, 0xc0, 0x00, 0xff, 0xff, 0xff, 0xc0, 0x00, 0x3f, 0xff, 0xff, 0xf8, 0x00, 
0x00, 0x7f, 0xff, 0xff, 0xc0, 0x00, 0x7f, 0xff, 0xff, 0xe0, 0x00, 0x1f, 0xff, 0xff, 0xf8, 0x00, 
0x00, 0x7f, 0xff, 0xff, 0xc0, 0x00, 0x3f, 0xff, 0xff, 0xe0, 0x00, 0x1f, 0xff, 0xff, 0xfc, 0x00, 
0x00, 0x3f, 0xff, 0xff, 0xe0, 0x00, 0x3f, 0xff, 0xff, 0xf0, 0x00, 0x0f, 0xff, 0xff, 0xfe, 0x00, 
0x00, 0x3f, 0xff, 0xff, 0xf0, 0x00, 0x3f, 0xff, 0xff, 0xf0, 0x00, 0x07, 0xff, 0xff, 0xfe, 0x00, 
0x00, 0x1f, 0xff, 0xff, 0xf0, 0x00, 0x1f, 0xff, 0xff, 0xf8, 0x00, 0x07, 0xff, 0xff, 0xfe, 0x00, 
0x00, 0x1f, 0xff, 0xff, 0xf0, 0x00, 0x0f, 0xff, 0xff, 0xfc, 0x00, 0x03, 0xff, 0xff, 0xff, 0x00, 
0x00, 0x0f, 0xff, 0xff, 0xf8, 0x00, 0x0f, 0xff, 0xff, 0xfc, 0x00, 0x03, 0xff, 0xff, 0xff, 0x80, 
0x00, 0x0f, 0xff, 0xff, 0xfc, 0x00, 0x07, 0xff, 0xff, 0xfc, 0x00, 0x01, 0xff, 0xff, 0xff, 0x80, 
0x00, 0x07, 0xff, 0xff, 0xfc, 0x00, 0x07, 0xff, 0xff, 0xfe, 0x00, 0x01, 0xff, 0xff, 0xff, 0xc0, 
0x00, 0x07, 0xff, 0xff, 0xfe, 0x00, 0x03, 0xff, 0xff, 0xff, 0x00, 0x00, 0xff, 0xff, 0xff, 0xc0, 
0x00, 0x03, 0xff, 0xff, 0xfe, 0x00, 0x03, 0xff, 0xff, 0xff, 0x00, 0x00, 0xff, 0xff, 0xff, 0xe0, 
0x00, 0x03, 0xff, 0xff, 0xff, 0x00, 0x01, 0xff, 0xff, 0xff, 0x80, 0x00, 0x7f, 0xff, 0xff, 0xf0, 
0x00, 0x01, 0xff, 0xff, 0xff, 0x00, 0x01, 0xff, 0xff, 0xff, 0x80, 0x00, 0x3f, 0xff, 0xff, 0xf0, 
0x00, 0x00, 0xff, 0xff, 0xff, 0x80, 0x00, 0xff, 0xff, 0xff, 0xc0, 0x00, 0x3f, 0xff, 0xff, 0xf8, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};

const unsigned char frein [] PROGMEM = {
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0xff, 0xff, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0xff, 0xff, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, 0xff, 0xff, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1f, 0xfe, 0xfd, 0xf8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3f, 0xff, 0xff, 0xfc, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7f, 0xff, 0xff, 0xfe, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0xff, 0xff, 0xff, 0xff, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0xff, 0xff, 0xff, 0xff, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0xff, 0xff, 0xff, 0xff, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, 0xff, 0xff, 0xff, 0xff, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x1f, 0xff, 0xff, 0xff, 0xff, 0xf8, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x3f, 0xff, 0xff, 0xff, 0xff, 0xfc, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xfe, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x7e, 0xba, 0x93, 0xc1, 0xf8, 0xbf, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0xfc, 0x08, 0x01, 0x80, 0x78, 0x0e, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0xf9, 0xef, 0x9f, 0x3e, 0x79, 0xcf, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0xf9, 0xff, 0x9f, 0x3f, 0x39, 0xe7, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x79, 0xff, 0xbe, 0x7f, 0x39, 0xef, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0xfc, 0x7f, 0x9e, 0x7f, 0xb9, 0xce, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0xfc, 0x3f, 0x9e, 0x7f, 0x39, 0xcf, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0x8f, 0xbe, 0x7f, 0xb8, 0x1f, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x7f, 0xcf, 0x9f, 0x7f, 0x39, 0xfe, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xef, 0x9e, 0x7f, 0x39, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xcf, 0xbf, 0x3e, 0x79, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0xf1, 0x8f, 0x9f, 0x1c, 0xfb, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x7c, 0x3f, 0x9f, 0xc1, 0xf9, 0xfe, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xfe, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x3f, 0xff, 0xff, 0xff, 0xff, 0xfc, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x1f, 0xff, 0xff, 0xff, 0xff, 0xf8, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, 0xff, 0xff, 0xff, 0xff, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0xff, 0xff, 0xff, 0xff, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0xff, 0xff, 0xff, 0xff, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0xff, 0xff, 0xff, 0xff, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7f, 0xff, 0xff, 0xfe, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3f, 0xff, 0xff, 0xfc, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1f, 0xff, 0xff, 0xf8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, 0xff, 0xff, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0xff, 0xff, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0xaa, 0xaa, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};


void setup()   {

  display.begin();  // initialisation de l'afficheur
  display.clearDisplay();   // ça efface à la fois le buffer et l'écran
}


void loop(){

  /**************************** Dessiner une image  bitmap **********************************/
  // on affiche l'image stockée dans la constante myBitmap définie au début de ce fichier.

  display.fillRect(0,0,128,64,WHITE);  // fond blanc derrière l'image bitmap
  
  display.drawBitmap(0, 0, flechedroite, 128,  64, BLACK);
  
  display.display();
  delay(1000);
  display.clearDisplay();

  display.fillRect(0,0,128,64,WHITE);  // fond blanc derrière l'image bitmap
  
  display.drawBitmap(0, 0, flechegauche, 128,  64, BLACK);
  
  display.display();
  delay(1000);
  display.clearDisplay();
  
  display.fillRect(0,0,128,64,WHITE);  // fond blanc derrière l'image bitmap
  display.drawBitmap(0, 0,frein, 128,  64, BLACK);
  
  display.display();
  delay(1000);
  display.clearDisplay();

}
