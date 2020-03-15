#include <DallasTemperature.h>  //Librairie pour la température
#include <OneWire.h>            //Librairie pour la température
#define KY001_Signal_PIN 6      //module temp sur pin 4
OneWire oneWire(KY001_Signal_PIN);          
DallasTemperature sensors(&oneWire);   

//Affiche "Le temps est bon" + la température
void temp(){
    sensors.requestTemperatures();
    if (sensors.getTempCByIndex(0)>15){
    display.setTextSize(2);
    display.setTextColor(WHITE);
    display.setCursor(15,0);
    display.print("Le temps");
    display.setCursor(15,20);
    display.print("est bon !");
    display.setCursor(15,45);
    display.print("T:");
    display.print(sensors.getTempCByIndex(0),1);
    display.print((char)247); // degree symbol 
    display.print("C"); // degree symbol 
    display.display();}
    
    if (sensors.getTempCByIndex(0)<15){
    display.setTextSize(2);
    display.setTextColor(WHITE);
    display.setCursor(6,0);
    display.print("It's cold");
    display.setCursor(9,20);
    display.print("depeche !");
    display.setCursor(15,45);
    display.print("T :");
    display.print(sensors.getTempCByIndex(0),1);
    display.print((char)247); // degree symbol 
    display.print("C"); // degree symbol 
    display.display();
        }}
