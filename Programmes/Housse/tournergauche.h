void gauche(){
  int val=(analogRead(0)/1023.0)*255;
  
  strip.setPixelColor(3, ORANGE);                 //cas particulier de la led qui s'allume au démarrage
  strip.setBrightness(0);                       //Luminosité à 0%
  strip1.setPixelColor(3, ORANGE);                 //cas particulier de la led qui s'allume au démarrage
  strip1.setBrightness(0);                       //Luminosité à 0%
  for (n=3; n<=21;n++){                         //boucle qui affiche la flèche du bas vers la gauche progressivement
    strip.setPixelColor(n, ORANGE);               //Allume la led n en bleu
    strip.setBrightness(val);                   //Luminosité à 100%
    strip.show();                               //Affiche les modifications  
    strip1.setPixelColor(n, ORANGE);               //Allume la led n en bleu
    strip1.setBrightness(val);                   //Luminosité à 100%
    strip1.show();                               //Affiche les modifications  
    delay(30);
 }
  strip.setBrightness(0);                       //Luminosité à 0%   
  strip1.setBrightness(0);                       //Luminosité à 0%             
  delay(50);            
}
