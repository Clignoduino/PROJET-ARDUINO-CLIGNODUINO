#include <SoftwareSerial.h>
#include "ecran.h"                                                                                    //SCL = A5 et SDA =A4
#include "temperature.h"                                                                            

SoftwareSerial ArduinoSlave(3,4);                                                                     //TX branché sur 3 RX branché sur 4
int valeur_referenced;                                                                                //valeur de référence du doigt gauche pour déterminer si il y a un mouvement
int valeur_referenceg;                                                                                //valeur de référence du doigt droit pour déterminer si il y a un mouvement
int valeur_flexgauche;                                                                                // capte le mouvement du doigt gauche
int ancienne_val_gauche=0;                                                                            //déclare une valeur qui va permettre de laisser le cligno gauche actif même quand on baisse le doigt
int valeur_flexdroite;                                                                                // capte le mouvement du doigt droit
int ancienne_val_droite=0;                                                                            //déclare une valeur qui va permettre de laisser le cligno droit actif même quand on baisse le doigt
int etatgauche=1;                                                                                     // va définir si on éteint ou allume le cligno gauche
int etatdroite=1;                                                                                     // va définir si on éteint ou allume le cligno droit
int ref=25;                                                                                           

int buzzer =8;                                                                                        // Borne de sortie du buzzer
int i=10;

void setup(){
  ArduinoSlave.begin(38400);                                                                          //Bluetooth initialisé à 38400 bauds
  ArduinoSlave.write("S");                                                                            //Envoi S pour afficher l'animation de démarrage sur les leds
  Serial.begin(9600);                                                                                 //Moniteur série initialisé
  sensors.begin();                                                                                    //Le capteur temperature est initialisé
  delay(1000);
  display.begin();                                                                                    // initialisation de l'afficheur
  display.clearDisplay();                                                                             //Efface ce qu'il y a sur l'écran
  Intro();                                                                                            //Affiche Clignoduino et nos prénoms
  sablier();                                                                                          //Animation sablier
  NePasBouger();                                                                                      //Texte "ne pas bouger"
  sablier();                                                                                          //Animation sablier
  delay(2000);                                                                                       //on attend 2 secondes pour être sur que le gant est bien positionné
  valeur_referenceg=analogRead(0);                                                                   //on mesure la valeur du doigt gauche de référence du cycliste
  valeur_referenced=analogRead(1);                                                                   //on mesure la valeur du doigt droit de référence du cycliste
  display.clearDisplay(); 
  }

void loop(){

  
  valeur_flexgauche=analogRead(0);                                                                    //lit la valeur du flex à gauche
  valeur_flexdroite=analogRead(1);                                                                    //lit la valeur du flex à droite
 d delay(50);
  
  while ((valeur_flexgauche==0) || (valeur_flexdroite==0) || (valeur_flexgauche==1023) || (valeur_flexdroite==1023)){     //Si un flex sensor est débranché
    tone(buzzer, 1000,50);                                                                                                //Alors le buzzer fait du bruit
    delay(2000);
    branchement();                                                                                                      //Affiche sur l'écran "vérifiez les cables"
    valeur_flexgauche=analogRead(0);                                                                    //lit la valeur du flex à gauche
    valeur_flexdroite=analogRead(1);                                                                    //lit la valeur du flex à droite
  }
 
  
  if (valeur_flexgauche>valeur_referenceg+ref and valeur_flexgauche>ancienne_val_gauche){              //Si on détacte un écart de +50 entre la position de référence et la nouvelle position alors on veut aller à gauche
    delay(800);                                                                                        //pour être sûr qu'on ne fait pas un geste non voulu
    etatgauche=1-etatgauche;}                                                                          // une fois que le doigt est levé on va modifier l'état de la led : allumé ou éteint
  
  else if (valeur_flexdroite>valeur_referenced+ref and valeur_flexdroite>ancienne_val_droite){        //Si on détacte un écart de +50 entre la position de référence et la nouvelle position alors on veut aller à droite
    delay(800);                                                                                       //pour être sûr qu'on ne fait pas un geste non voulu
    etatdroite=1-etatdroite;}
    
  else if (valeur_flexgauche<valeur_referenceg-ref and valeur_flexdroite<valeur_referenced-ref){       //Si on détacte un écart de -50 entre la position de référence et la nouvelle position pour chaque doigt alors on freine
    delay(100);                                                                                      //latence courte car freinage rapide
    ArduinoSlave.write("F");  //envoi le caractère F à l'esclave pour freiner                        //Appel la fonction frein                                                                                   
    etatdroite=1;                                                                                    //si le cligno droit est allumé et qu'on freine alors on éteint le cligno
    etatgauche=1;                                                                                   // pareil avec le gauche
    freinn();}                                                                                      //Animation freinage
                  
   else{                                                                                            //Si on ne fait rien, alors leds éteintes
    ArduinoSlave.write("R");                                                                        //envoi le caractère R à l'esclave pour éteindre les leds
    delay(100); 
    temp();}                                                                                        //Affiche la température si rien n'est affiché sur l'écran                                                                                

    
  ancienne_val_gauche=valeur_flexgauche;                                                            // pour reconnaitre si on active ou désactive on va comparer ancienne valeur et nouvelle valeur
  ancienne_val_droite=valeur_flexdroite;                                                            // pareil avec le cligno droit
  
  while (ArduinoSlave.available()){                                                                 //vérifie que l'esclave est connecté
    delay(100);}
  
  if (etatdroite==1 and etatgauche==0){                                                             //si le cligno droit est allumé on allume pas le gauche
    ArduinoSlave.write("G");                                                                        //envoi le caractère G à l'esclave pour aller à gauche
    imagegauche();}                                                                                 //Affiche sur l'écran des fleches vers la gauche

  else{                                                                                             //Si on ne fait rien, alors leds éteintes
    ArduinoSlave.write("R");  }                                                                      //envoi le caractère R à l'esclave pour éteindre les leds     
    
  if (etatgauche==1 and etatdroite==0){                                                             //si le cligno gauche est allumé on allume pas le droit
    ArduinoSlave.write("D");                                                                        //envoi le caractère D à l'esclave pour aller à droite      
    imagedroite();}                                                                                 //Affiche sur l'écran des fleches vers la droite  
    
  else{                                                                                             //Si on ne fait rien, alors leds éteintes
    ArduinoSlave.write("R");                                                                        //envoi le caractère R à l'esclave pour éteindre les leds                                                                                 
    delay(500);}

  delay(50);
  while ((sensors.getTempCByIndex(0)>40) || (sensors.getTempCByIndex(0)<=0.00)){                  //Si le module température est débranché
    tone(buzzer, 1000,50);                                                                        //Alors le buzzer fait un bruit
    tone(buzzer, 800,50);    
    display.clearDisplay();
    branchement();}                                                                                //Affiche sur l'écran "vérifiez les cables"
  
  display.display();                                                                                
  display.clearDisplay();}                                                                          //Efface ce qu'il y a sur l'écran
