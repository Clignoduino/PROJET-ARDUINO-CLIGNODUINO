#include <SoftwareSerial.h>
SoftwareSerial ArduinoSlave(3,4); //TX branché sur 3 RX branché sur 4
int valeur_flexgauche;          // capte le mouvement du doigt gauche
int ancienne_val_gauche=0;      //déclare une valeur qui va permettre de laisser le cligno gauche actif même quand on baisse le doigt
int valeur_flexdroite;          // capte le mouvement du doigt droit
int ancienne_val_droite=0;      //déclare une valeur qui va permettre de laisser le cligno droit actif même quand on baisse le doigt
int etatgauche=1;               // va définir si on éteint ou allume le cligno gauche
int etatdroite=1;               // va définir si on éteint ou allume le cligno droit


void setup(){
  Serial.begin(9600);
  Serial.println("ENTER Commands:");
  ArduinoSlave.begin(38400);

}

void loop(){
  
  valeur_flexgauche=analogRead(0);  //lit la valeur du flex à gauche
  valeur_flexdroite=analogRead(1);  //lit la valeur du flex à droite
  Serial.print("Valeur gauche : ");
  Serial.print(valeur_flexgauche);
  Serial.print("     Valeur droite : ");
  Serial.println(valeur_flexdroite);

  if (valeur_flexgauche>320 and valeur_flexgauche>ancienne_val_gauche){             //si on veut aller à gauche
    delay(800);                                                                                               //pour être sûr qu'on ne fait pas un geste non voulu
    etatgauche=1-etatgauche;}                                                                                 // une fois que le doigt est levé on va modifier l'état de la led : allumé ou éteint
  
  else if (valeur_flexdroite>335 and valeur_flexdroite>ancienne_val_droite){        //si on veut aller à droite
    delay(800);                                                                                               //pour être sûr qu'on ne fait pas un geste non voulu
    etatdroite=1-etatdroite;}
    
  else if (valeur_flexgauche<210 and valeur_flexdroite<200){                                                  //si on freine
    delay(100);                                                                                               //latence courte car freinage rapide
    ArduinoSlave.write("F");  //envoi le caractère F à l'esclave pour freiner                                                                                                  //Appel la fonction frein 
    etatdroite=1;                                                                                             //si le cligno droit est allumé et qu'on freine alors on éteint le cligno
    etatgauche=1; }                                                                                           // pareil avec le gauche
                  
   else{                                                                                                      //Si on ne fait rien, alors leds éteintes
    ArduinoSlave.write("R");  //envoi le caractère R à l'esclave pour éteindre les leds
    }                                                                               

    
  ancienne_val_gauche=valeur_flexgauche;                                                            // pour reconnaitre si on active ou désactive on va comparer ancienne valeur et nouvelle valeur
  ancienne_val_droite=valeur_flexdroite;                                                            // pareil avec le cligno droit
  while (ArduinoSlave.available()){ //vérifie que l'esclave est connecté
    delay(100);}
  
  if (etatdroite==1 and etatgauche==0){                                                             //si le cligno droit est allumé on allume pas le gauche
    ArduinoSlave.write("G");  //envoi le caractère G à l'esclave pour aller à gauche
    }

  else{                                                                                                      //Si on ne fait rien, alors leds éteintes
    ArduinoSlave.write("R");  //envoi le caractère R à l'esclave pour éteindre les leds
    }   
    
  if (etatgauche==1 and etatdroite==0){                                                             //si le cligno gauche est allumé on allume pas le droit
    ArduinoSlave.write("D");  //envoi le caractère D à l'esclave pour aller à droite
    }
    
  else{ //Si on ne fait rien, alors leds éteintes
    ArduinoSlave.write("R");  //envoi le caractère R à l'esclave pour éteindre les leds
    }
    
    
    delay(500);



}
