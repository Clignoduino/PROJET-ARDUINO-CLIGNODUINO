#include <SoftwareSerial.h> // bibliothèque bluetooth
SoftwareSerial ArduinoSlave(3,4); //TX branché sur 3 RX branché sur 4



void setup(){
 Serial.begin(9600);
 Serial.println("ENTER Commands:");
 ArduinoSlave.begin(38400);}

void loop() {
  while (ArduinoSlave.available()){ //vérifie que l'esclave est connecté
    delay(100);
  }
    ArduinoSlave.write("L");  //envoi le caractère L à l'escalve pour allumer la led de l'esclave
    delay(1000);
  }
