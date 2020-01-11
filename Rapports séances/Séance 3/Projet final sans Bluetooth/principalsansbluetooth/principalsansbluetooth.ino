#include "bibliotheque.h"
#include "tournerdroite.h"
#include "tournergauche.h"
#include "lumiererouge.h"
#include "freinl.h"

int valeur_flexgauche;          // capte le mouvement du doigt gauche
int ancienne_val_gauche=0;      //déclare une valeur qui va permettre de laisser le cligno gauche actif même quand on baisse le doigt
int valeur_flexdroite;          // capte le mouvement du doigt droit
int ancienne_val_droite=0;      //déclare une valeur qui va permettre de laisser le cligno droit actif même quand on baisse le doigt
int etatgauche=1;               // va définir si on éteint ou allume le cligno gauche
int etatdroite=1;               // va définir si on éteint ou allume le cligno droit


void setup(){
  
  strip.begin();
  strip.show();                  // Initialise tous les pixels à 'off' (éteint)
  strip1.begin();
  strip1.show();                  // Initialise tous les pixels à 'off' (éteint)
  Serial.begin(9600);

}

void loop(){
  
  valeur_flexgauche=analogRead(0);  //lit la valeur du flex à gauche
  valeur_flexdroite=analogRead(1);  //lit la valeur du flex à droite
  Serial.print("Valeur gauche : ");
  Serial.print(valeur_flexgauche);
  Serial.print("     Valeur droite : ");
  Serial.println(valeur_flexdroite);

  if (valeur_flexgauche>320 and valeur_flexgauche>ancienne_val_gauche){                                       //si on veut aller à gauche
    delay(800);                                                                                               //pour être sûr qu'on ne fait pas un geste non voulu
    etatgauche=1-etatgauche;}                                                                                 // une fois que le doigt est levé on va modifier l'état de la led : allumé ou éteint
  
  else if (valeur_flexdroite>335 and valeur_flexdroite>ancienne_val_droite){                                  //si on veut aller à droite
    delay(800);:                                                                                              //pour être sûr qu'on ne fait pas un geste non voulu
    etatdroite=1-etatdroite;                                                                                  // une fois que le doigt est levé on va modifier l'état de la led : allumé ou éteint
    }
    
  else if (valeur_flexgauche<210 and valeur_flexdroite<200){                                                  //si on freine
    delay(100);                                                                                               //latence courte car freinage rapide
    frein();                                                                                                  //Appelle la fonction animation frein 
    etatdroite=1;                                                                                             //si le cligno droit est allumé et qu'on freine alors on éteint le cligno
    etatgauche=1;                                                                                             // pareil avec le gauche
    }                                                                                           
                  
   else{                                                                                                      //Si on ne fait rien, alors leds éteintes
    strip.setBrightness(0);                                                                                   
    strip.show();
    strip1.setBrightness(0);                                                                                   
    strip1.show();}                                                                               

  ancienne_val_gauche=valeur_flexgauche;                                                            // pour reconnaitre si on active ou désactive on va comparer ancienne valeur et nouvelle valeur
  ancienne_val_droite=valeur_flexdroite;                                                            // pareil avec le cligno droit
  
  if (etatdroite==1 and etatgauche==0){                                                             //on allume le gauche que si le droit n'est pas déjà allumé
    gauche(); }                                                                                     //Appelle fonction animation cligno gauche

  else {
    strip.setBrightness(0);                                                                         //Si on ne fait rien, alors leds éteintes
    strip.show();
    strip1.setBrightness(0);                                                                        //Si on ne fait rien, alors leds éteintes
    strip1.show();}   
    
  if (etatgauche==1 and etatdroite==0){                                                             //on allume le droit que si le gauche n'est pas déjà allumé
    droite();                                                                                       //Appelle fonction animation cligno droit
    }
    
  else {                                                                                            //Si on ne fait rien, alors leds éteintes
    strip.setBrightness(0); 
    strip.show();
    strip1.setBrightness(0); 
    strip1.show();}
    
    
  delay(10);



}
