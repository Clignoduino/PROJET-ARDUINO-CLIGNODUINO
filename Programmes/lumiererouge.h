void barrescentrale(){
  
  for (n=4;n<=16;n++){                        //Allume les leds de la deuxieme ligne
    strip.setPixelColor(n, ROUGE);            //Allume la led n en rouge
    strip.setBrightness(255);                 //Luminosité à 100%
    strip.show();                             //Affiche les modifications
    strip1.setPixelColor(n, ROUGE);            //Allume la led n en rouge
    strip1.setBrightness(255);                 //Luminosité à 100%
    strip1.show();                             //Affiche les modifications
  }
}