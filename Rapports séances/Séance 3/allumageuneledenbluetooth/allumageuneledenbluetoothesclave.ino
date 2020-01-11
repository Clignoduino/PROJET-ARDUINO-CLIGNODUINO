#include <SoftwareSerial.h>                           
SoftwareSerial ArduinoMaster(2,3); //RX TX                  //Bibliothèque pour le Bluetooth
const int LED=4;  

void setup() {
  
 Serial.begin(9600);
 ArduinoMaster.begin(38400);                              //Communication en 38400 bauds
 pinMode(LED,OUTPUT);
}

void loop() {
  
 while (ArduinoMaster.available()) {                          //tant que le module Bluetooth est disponible
  delay(10); 
  if (ArduinoMaster.available() >0) {
    char c = ArduinoMaster.read();        //recoit un caractere et l'affiche sur le moniteur série
    Serial.print(c);
    
    if (c=='L'){                    //Si le HC05 envoit L, la LED s'allume
      digitalWrite(LED,LOW);
      delay(10);                     
      Serial.println("LOW");}
    
    else{                           //Si le HC05 recoit autre chose que L, la LED est éteinte
      digitalWrite(LED,HIGH);
    delay(10);
    Serial.println("HIGH");}
  
  }
}
  ArduinoMaster.flush();            //Efface la mémoire stockée
}




  
