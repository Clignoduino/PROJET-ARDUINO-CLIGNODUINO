void animationsetup(){
  int val=(analogRead(0)/1023.0)*255;
  strip.begin();
  strip1.begin();
  strip.setPixelColor(17, ORANGE);                //cas particulier de la led qui s'allume au démarrage
  strip.setBrightness(0);                       //Luminosité à 0%  
  strip1.setPixelColor(17, ORANGE);                //cas particulier de la led qui s'allume au démarrage
  strip1.setBrightness(0);                       //Luminosité à 0% 
   
  for (int n=17; n>15;n--){                     //boucle qui affiche la flèche du bas vers la droite progressivement
    strip.setPixelColor(n, ROUGE);               //Allume la led n en bleu
    strip.setBrightness(val);                   //Luminosité à 100%
    strip.show();                               //Affiche les modifications
    strip1.setPixelColor(n, ROUGE);               //Allume la led n en bleu
    strip1.setBrightness(val);                   //Luminosité à 100%
    strip1.show();                               //Affiche les modifications   
 }
 delay(380);
 for (int n=15; n>14;n--){                     //boucle qui affiche la flèche du bas vers la droite progressivement
    strip.setPixelColor(n, ORANGE);               //Allume la led n en bleu
    strip.setBrightness(val);                   //Luminosité à 100%
    strip.show();                               //Affiche les modifications
    strip1.setPixelColor(n, ORANGE);               //Allume la led n en bleu
    strip1.setBrightness(val);                   //Luminosité à 100%
    strip1.show();                               //Affiche les modifications
 }
 delay(380);
 for (int n=14; n>13;n--){                     //boucle qui affiche la flèche du bas vers la droite progressivement
    strip.setPixelColor(n, JAUNEF);               //Allume la led n en bleu
    strip.setBrightness(val);                   //Luminosité à 100%
    strip.show();                               //Affiche les modifications
    strip1.setPixelColor(n, JAUNEF);               //Allume la led n en bleu
    strip1.setBrightness(val);                   //Luminosité à 100%
    strip1.show();                               //Affiche les modifications
 }
 delay(380);
 for (int n=13; n>12;n--){                     //boucle qui affiche la flèche du bas vers la droite progressivement
    strip.setPixelColor(n, JAUNE);               //Allume la led n en bleu
    strip.setBrightness(val);                   //Luminosité à 100%
    strip.show();                               //Affiche les modifications
    strip1.setPixelColor(n, JAUNE);               //Allume la led n en bleu
    strip1.setBrightness(val);                   //Luminosité à 100%
    strip1.show();                               //Affiche les modifications
 }
 delay(380);
 for (int n=12; n>11;n--){                     //boucle qui affiche la flèche du bas vers la droite progressivement
    strip.setPixelColor(n, VERT);               //Allume la led n en bleu
    strip.setBrightness(val);                   //Luminosité à 100%
    strip.show();                               //Affiche les modifications
    strip1.setPixelColor(n, VERT);               //Allume la led n en bleu
    strip1.setBrightness(val);                   //Luminosité à 100%
    strip1.show();                               //Affiche les modifications
 }
 delay(380);
 for (int n=11; n>10;n--){                     //boucle qui affiche la flèche du bas vers la droite progressivement
    strip.setPixelColor(n, CITRON);               //Allume la led n en bleu
    strip.setBrightness(val);                   //Luminosité à 100%
    strip.show();                               //Affiche les modifications
    strip1.setPixelColor(n, CITRON);               //Allume la led n en bleu
    strip1.setBrightness(val);                   //Luminosité à 100%
    strip1.show();                               //Affiche les modifications
 }
 delay(380);
 for (int n=10; n>9;n--){                     //boucle qui affiche la flèche du bas vers la droite progressivement
    strip.setPixelColor(n, CYAN);               //Allume la led n en bleu
    strip.setBrightness(val);                   //Luminosité à 100%
    strip.show();                               //Affiche les modifications
    strip1.setPixelColor(n, CYAN);               //Allume la led n en bleu
    strip1.setBrightness(val);                   //Luminosité à 100%
    strip1.show();                               //Affiche les modifications
 }
 delay(380);
 for (int n=9; n>8;n--){                     //boucle qui affiche la flèche du bas vers la droite progressivement
    strip.setPixelColor(n, BLEU);               //Allume la led n en bleu
    strip.setBrightness(val);                   //Luminosité à 100%
    strip.show();                               //Affiche les modifications
    strip1.setPixelColor(n, BLEU);               //Allume la led n en bleu
    strip1.setBrightness(val);                   //Luminosité à 100%
    strip1.show();                               //Affiche les modifications
 }
 delay(380);
 for (int n=8; n>7;n--){                     //boucle qui affiche la flèche du bas vers la droite progressivement
    strip.setPixelColor(n, MARINE);               //Allume la led n en bleu
    strip.setBrightness(val);                   //Luminosité à 100%
    strip.show();                               //Affiche les modifications
    strip1.setPixelColor(n, MARINE);               //Allume la led n en bleu
    strip1.setBrightness(val);                   //Luminosité à 100%
    strip1.show();                               //Affiche les modifications
 }
 delay(380);
 for (int n=7; n>6;n--){                     //boucle qui affiche la flèche du bas vers la droite progressivement
    strip.setPixelColor(n, VIOLET);               //Allume la led n en bleu
    strip.setBrightness(val);                   //Luminosité à 100%
    strip.show();                               //Affiche les modifications
    strip1.setPixelColor(n, VIOLET);               //Allume la led n en bleu
    strip1.setBrightness(val);                   //Luminosité à 100%
    strip1.show();                               //Affiche les modifications
 }
 delay(380);
 for (int n=6; n>5;n--){                     //boucle qui affiche la flèche du bas vers la droite progressivement
    strip.setPixelColor(n, ROSE);               //Allume la led n en bleu
    strip.setBrightness(val);                   //Luminosité à 100%
    strip.show();                               //Affiche les modifications
    strip1.setPixelColor(n, ROSE);               //Allume la led n en bleu
    strip1.setBrightness(val);                   //Luminosité à 100%
    strip1.show();                               //Affiche les modifications
 }
 delay(380);
 for (int n=5; n>4;n--){                     //boucle qui affiche la flèche du bas vers la droite progressivement
    strip.setPixelColor(n, VIOLETC);               //Allume la led n en bleu
    strip.setBrightness(val);                   //Luminosité à 100%
    strip.show();                               //Affiche les modifications
    strip1.setPixelColor(n, VIOLETC);               //Allume la led n en bleu
    strip1.setBrightness(val);                   //Luminosité à 100%
    strip1.show();                               //Affiche les modifications
 }
 delay(380);
 for (int n=4; n>3;n--){                     //boucle qui affiche la flèche du bas vers la droite progressivement
    strip.setPixelColor(n, BLANC);               //Allume la led n en bleu
    strip.setBrightness(val);                   //Luminosité à 100%
    strip.show();                               //Affiche les modifications
    strip1.setPixelColor(n, BLANC);               //Allume la led n en bleu
    strip1.setBrightness(val);                   //Luminosité à 100%
    strip1.show();                               //Affiche les modifications
 }
 delay(380);
 strip.setBrightness(0);
 strip1.setBrightness(0);
 for (int n=3; n>2;n--){                     //boucle qui affiche la flèche du bas vers la droite progressivement
    strip.setPixelColor(n, BLANC);               //Allume la led n en bleu
    strip.setBrightness(val);                   //Luminosité à 100%
    strip.show();                               //Affiche les modifications
    strip1.setPixelColor(n, BLANC);               //Allume la led n en bleu
    strip1.setBrightness(val);                   //Luminosité à 100%
    strip1.show();                               //Affiche les modifications
 }
 delay(380);
 for (int n=4; n>3;n--){                     //boucle qui affiche la flèche du bas vers la droite progressivement
    strip.setPixelColor(n, BLANC);               //Allume la led n en bleu
    strip.setBrightness(val);                   //Luminosité à 100%
    strip.show();                               //Affiche les modifications
    strip1.setPixelColor(n, BLANC);               //Allume la led n en bleu
    strip1.setBrightness(val);                   //Luminosité à 100%
    strip1.show();                               //Affiche les modifications
 }
 delay(380);
 for (int n=5; n>4;n--){                     //boucle qui affiche la flèche du bas vers la droite progressivement
    strip.setPixelColor(n, VIOLETC);               //Allume la led n en bleu
    strip.setBrightness(val);                   //Luminosité à 100%
    strip.show();                               //Affiche les modifications
    strip1.setPixelColor(n, VIOLETC);               //Allume la led n en bleu
    strip1.setBrightness(val);                   //Luminosité à 100%
    strip1.show();                               //Affiche les modifications
 }
 delay(380);
 for (int n=6; n>5;n--){                     //boucle qui affiche la flèche du bas vers la droite progressivement
    strip.setPixelColor(n, ROSE);               //Allume la led n en bleu
    strip.setBrightness(val);                   //Luminosité à 100%
    strip.show();                               //Affiche les modifications
    strip1.setPixelColor(n, ROSE);               //Allume la led n en bleu
    strip1.setBrightness(val);                   //Luminosité à 100%
    strip1.show();                               //Affiche les modifications
 }
 delay(380);
 for (int n=7; n>6;n--){                     //boucle qui affiche la flèche du bas vers la droite progressivement
    strip.setPixelColor(n, VIOLET);               //Allume la led n en bleu
    strip.setBrightness(val);                   //Luminosité à 100%
    strip.show();                               //Affiche les modifications
    strip1.setPixelColor(n, VIOLET);               //Allume la led n en bleu
    strip1.setBrightness(val);                   //Luminosité à 100%
    strip1.show();                               //Affiche les modifications
 }
 delay(380);
 for (int n=8; n>7;n--){                     //boucle qui affiche la flèche du bas vers la droite progressivement
    strip.setPixelColor(n, MARINE);               //Allume la led n en bleu
    strip.setBrightness(val);                   //Luminosité à 100%
    strip.show();                               //Affiche les modifications
    strip1.setPixelColor(n, MARINE);               //Allume la led n en bleu
    strip1.setBrightness(val);                   //Luminosité à 100%
    strip1.show();                               //Affiche les modifications
 }
 delay(380);
 for (int n=9; n>8;n--){                     //boucle qui affiche la flèche du bas vers la droite progressivement
    strip.setPixelColor(n, BLEU);               //Allume la led n en bleu
    strip.setBrightness(val);                   //Luminosité à 100%
    strip.show();                               //Affiche les modifications
    strip1.setPixelColor(n, BLEU);               //Allume la led n en bleu
    strip1.setBrightness(val);                   //Luminosité à 100%
    strip1.show();                               //Affiche les modifications
 }
 delay(380);
 for (int n=10; n>9;n--){                     //boucle qui affiche la flèche du bas vers la droite progressivement
    strip.setPixelColor(n, CYAN);               //Allume la led n en bleu
    strip.setBrightness(val);                   //Luminosité à 100%
    strip.show();                               //Affiche les modifications
    strip1.setPixelColor(n, CYAN);               //Allume la led n en bleu
    strip1.setBrightness(val);                   //Luminosité à 100%
    strip1.show();                               //Affiche les modifications
 }
 delay(380);
 for (int n=11; n>10;n--){                     //boucle qui affiche la flèche du bas vers la droite progressivement
    strip.setPixelColor(n, CITRON);               //Allume la led n en bleu
    strip.setBrightness(val);                   //Luminosité à 100%
    strip.show();                               //Affiche les modifications
    strip1.setPixelColor(n, CITRON);               //Allume la led n en bleu
    strip1.setBrightness(val);                   //Luminosité à 100%
    strip1.show();                               //Affiche les modifications
 }
 delay(380);
 for (int n=12; n>11;n--){                     //boucle qui affiche la flèche du bas vers la droite progressivement
    strip.setPixelColor(n, VERT);               //Allume la led n en bleu
    strip.setBrightness(val);                   //Luminosité à 100%
    strip.show();                               //Affiche les modifications
    strip1.setPixelColor(n, VERT);               //Allume la led n en bleu
    strip1.setBrightness(val);                   //Luminosité à 100%
    strip1.show();                               //Affiche les modifications
 }
 delay(380);
 for (int n=13; n>12;n--){                     //boucle qui affiche la flèche du bas vers la droite progressivement
    strip.setPixelColor(n, JAUNE);               //Allume la led n en bleu
    strip.setBrightness(val);                   //Luminosité à 100%
    strip.show();                               //Affiche les modifications
    strip1.setPixelColor(n, JAUNE);               //Allume la led n en bleu
    strip1.setBrightness(val);                   //Luminosité à 100%
    strip1.show();                               //Affiche les modifications
 }
 delay(380);
 for (int n=14; n>13;n--){                     //boucle qui affiche la flèche du bas vers la droite progressivement
    strip.setPixelColor(n, JAUNEF);               //Allume la led n en bleu
    strip.setBrightness(val);                   //Luminosité à 100%
    strip.show();                               //Affiche les modifications
    strip1.setPixelColor(n, JAUNEF);               //Allume la led n en bleu
    strip1.setBrightness(val);                   //Luminosité à 100%
    strip1.show();                               //Affiche les modifications
 }
 delay(380);
 for (int n=15; n>14;n--){                     //boucle qui affiche la flèche du bas vers la droite progressivement
    strip.setPixelColor(n, ORANGE);               //Allume la led n en bleu
    strip.setBrightness(val);                   //Luminosité à 100%
    strip.show();                               //Affiche les modifications
    strip1.setPixelColor(n, ORANGE);               //Allume la led n en bleu
    strip1.setBrightness(val);                   //Luminosité à 100%
    strip1.show();                               //Affiche les modifications
 }
 delay(380);
 for (int n=16; n>15;n--){                     //boucle qui affiche la flèche du bas vers la droite progressivement
    strip.setPixelColor(n, ROUGE);               //Allume la led n en bleu
    strip.setBrightness(val);                   //Luminosité à 100%
    strip.show();                               //Affiche les modifications
    strip1.setPixelColor(n, ROUGE);               //Allume la led n en bleu
    strip1.setBrightness(val);                   //Luminosité à 100%
    strip1.show();                               //Affiche les modifications   
 }
 delay(380);
 
 
  strip.setBrightness(0);                       //Luminosité à 0%       
  strip1.setBrightness(0);                       //Luminosité à 0%       
  delay(1);}
	
  
