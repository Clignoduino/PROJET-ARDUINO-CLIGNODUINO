void frein(){
  int val=(analogRead(0)/1023.0)*255;
      
  for (n=3;n<=16;n++){                        //Effet lors du freinage :
    strip.setPixelColor(n,ROUGE);             //Effet qui commence aux extrémités et qui se rassemblent au centre
    strip.setPixelColor(20-n,ROUGE);          
    strip.setBrightness(val);                 //Luminosité à 100%
    strip.show();                             //Affiche les modifications
    strip1.setPixelColor(n,ROUGE);             //Effet qui commence aux extrémités et qui se rassemblent au centre
    strip1.setPixelColor(20-n,ROUGE);          
    strip1.setBrightness(val);                 //Luminosité à 100%
    strip1.show();                             //Affiche les modifications
    delay(20);
  }

}
