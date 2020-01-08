//programme qui reconnait les mouvements de nos doigts et allume des leds en conséquence 
//version améliorée de la précédente version gère une mémoire.
const int leddroite=10;
const int ledgauche=11;
const int ledfrein=12;
int valeur_flexgauche; // capte le mouvement du doigt gauche
int ancienne_val_gauche=0; //déclare une valeur qui va permettre de laisser le cligno gauche actif même quand on baisse le doigt
int valeur_flexdroite; // capte le mouvement du doigt droit
int ancienne_val_droite=0; //déclare une valeur qui va permettre de laisser le cligno droit actif même quand on baisse le doigt
int etatgauche=1; // va définir si on éteint ou allume le cligno gauche
int etatdroite=1; // va définir si on éteint ou allume le cligno droit

void setup() {
  Serial.begin(9600);
  pinMode(ledgauche,OUTPUT);
  pinMode(leddroite,OUTPUT);
  pinMode(ledfrein,OUTPUT);
}

void loop() {
  valeur_flexgauche=analogRead(0); //lit la valeur du flex à gauche
  valeur_flexdroite=analogRead(1); //lit la valeur du flex à droite
  Serial.print(valeur_flexgauche);
  Serial.print(" ");
  Serial.println(valeur_flexdroite);
  
  if (valeur_flexgauche>240 and valeur_flexdroite<300 and valeur_flexgauche>ancienne_val_gauche){ //si on veut aller à gauche
    delay(800); //pour être sûr qu'on ne fait pas un geste non voulu
    etatdroite=1-etatdroite;} // une fois que le doigt est levé on va modifier l'état de la led : allumé ou éteint
  
  else if (valeur_flexgauche<250 and valeur_flexdroite>260 and valeur_flexdroite>ancienne_val_droite){ //si on veut aller à droite
    delay(800); //pour être sûr qu'on ne fait pas un geste non voulu
    etatgauche=1-etatgauche;} // une fois que le doigt est levé on va modifier l'état de la led : allumé ou éteint
    
  else if (valeur_flexgauche<200 and valeur_flexdroite<200){ //si on freine
    delay(100); //latence courte car freinage rapide
    digitalWrite(ledfrein,LOW);
    etatdroite=1; //si le cligno droit est allumé et qu'on freine alors on éteint le cligno
    etatgauche=1;} // pareil avec le gauche
    
  else {
    digitalWrite(ledgauche,HIGH);
    digitalWrite(leddroite,HIGH);
    digitalWrite(ledfrein,HIGH);} //si on fait rien alors on laisse tout éteint
  ancienne_val_gauche=valeur_flexgauche; // pour reconnaitre si on active ou désactive on va comparer ancienne valeur et nouvelle valeur
  ancienne_val_droite=valeur_flexdroite; // pareil avec le cligno droit
  
  if (etatdroite!=0){ //si le cligno droit est allumé on allume pas le gauche
    digitalWrite(ledgauche,etatgauche);}
    
  else if (etatgauche!=0){ //si le cligno gauche est allumé on allume pas le droit
    digitalWrite(leddroite,etatdroite);}
  delay(500);
    
    
  
  
 
}
