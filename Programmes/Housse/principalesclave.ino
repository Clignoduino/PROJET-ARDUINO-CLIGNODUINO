#include "bibliotheque.h"
#include "tournerdroite.h"
#include "tournergauche.h"
#include "lumiererouge.h"
#include "freinl.h"
#include "animationsetup.h"

void setup(){
  strip.begin();
  strip.show();                  // Initialise tous les pixels à 'off' (éteint)
  strip1.begin();
  strip1.show();                  // Initialise tous les pixels à 'off' (éteint)
  Serial.begin(9600);
  ArduinoMaster.begin(38400);     //Initialise le module Bluetooth 38400 bauds
  while (ArduinoMaster.available()) {   //tant que le module Bluetooth est disponible
  if (ArduinoMaster.available() >0) {
    char c = ArduinoMaster.read();  //recoit un caractere et l'affiche sur le moniteur série
    Serial.print(c);
    if (c=='S'){         //si l'arduino recoit la lettre D
    delay(100);
    animationsetup();         //affiche l'animation fleche vers la droite
    delay(10);                     
    Serial.println("S");  //affiche D sur le moniteur série
    }
    else{               //si l'arduino recoit autre chose que la lettre D, tout est eteint
      strip.setBrightness(0);                                                                                   
      strip.show();
      strip1.setBrightness(0);                                                                                   
      strip1.show();
    }}}

}

void loop(){
  while (ArduinoMaster.available()) {   //tant que le module Bluetooth est disponible
  delay(10);
  if (ArduinoMaster.available() >0) {
    char c = ArduinoMaster.read();  //recoit un caractere et l'affiche sur le moniteur série
    Serial.print(c);
    if (c=='S'){         //si l'arduino recoit la lettre D
    delay(100);
    animationsetup();         //affiche l'animation fleche vers la droite
    delay(10);                     
    Serial.println("S");  //affiche D sur le moniteur série
    }
    else{               //si l'arduino recoit autre chose que la lettre D, tout est eteint
      strip.setBrightness(0);                                                                                   
      strip.show();
      strip1.setBrightness(0);                                                                                   
      strip1.show();
    }
     
    if (c=='D'){         //si l'arduino recoit la lettre D
      droite();         //affiche l'animation fleche vers la droite
    delay(10);                     
    Serial.println("D");  //affiche D sur le moniteur série
    }
    else{               //si l'arduino recoit autre chose que la lettre D, tout est eteint
      strip.setBrightness(0);                                                                                   
      strip.show();
      strip1.setBrightness(0);                                                                                   
      strip1.show();
    }

    if (c=='G'){                   //si l'arduino recoit la lettre D
      gauche();                   //affiche l'animation fleche vers la gauche
    delay(10);                     
    Serial.println("G");          //affiche G sur le moniteur série
    }
    else{                         //si l'arduino recoit autre chose que la lettre G, tout est eteint
      strip.setBrightness(0);                                                                                   
      strip.show();
      strip1.setBrightness(0);                                                                                   
      strip1.show();
    }
    
    if (c=='F'){                   //si l'arduino recoit la lettre F
      frein();                  //affiche l'animation frein
    delay(10);                     
    Serial.println("F");        //affiche F sur le moniteur série
    }

    else{                         //si l'arduino recoit autre chose que la lettre F, tout est eteint
      strip.setBrightness(0);                                                                                   
      strip.show();
      strip1.setBrightness(0);                                                                                   
      strip1.show();
    }    
  
  }
}
  ArduinoMaster.flush();            //Efface la mémoire stockée

  
}
