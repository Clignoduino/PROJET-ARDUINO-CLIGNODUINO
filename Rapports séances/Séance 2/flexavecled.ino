//programme qui reconnait les mouvements de nos doigts et allume des leds en conséquence 
//première version basique
const int ledgauche=10;
const int leddroite=11;
const int ledfrein=12;
int valeur_flexgauche;
int valeur_flexdroite;
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
  
  if (valeur_flexgauche>240 and valeur_flexdroite<300){ //pour aller à gauche
    delay(1000); // pour être sûr qu'on ne fait pas un mouvement involontaire
    digitalWrite(ledgauche,LOW); // allume la led de gauche
    digitalWrite(leddroite,HIGH);} // éteint celle de droite
  
  else if (valeur_flexgauche<250 and valeur_flexdroite>260){ //pour aller à droite
    delay(1000); // pour éviter mouvements involontaire
    digitalWrite(ledgauche,HIGH); // éteint la led de gauche
    digitalWrite(leddroite,LOW);} // allume celle de droite
    
  else if (valeur_flexgauche<200 and valeur_flexdroite<200){
    delay(500); //délai plus court car il peut y avoir un freinage d'urgence donc l'affichage doit être rapide
    digitalWrite(ledgauche,HIGH); //éteint led de gauche
    digitalWrite(leddroite,HIGH); //éteint led de droite
    digitalWrite(ledfrein,LOW);} // allume led du milieu
    
  else {
    digitalWrite(ledgauche,HIGH); //ne fait rien si rien n'est demander 
    digitalWrite(leddroite,HIGH);
    digitalWrite(ledfrein,HIGH);}
  delay(100);
    
    
  
  
 
}
