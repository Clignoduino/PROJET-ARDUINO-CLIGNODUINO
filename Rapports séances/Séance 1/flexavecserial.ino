// code qui affiche les mouvements sur le moniteur série
int valeur_flexgauche;
int valeur_flexdroite;
void setup() {
  Serial.begin(9600);
}

void loop() {
  valeur_flexgauche=analogRead(0); //lit la valeur de tension du flex gauche entre 0 et 1023
  valeur_flexdroite=analogRead(1); //pareil à droite
  Serial.print(valeur_flexgauche);
  Serial.print(" ");
  Serial.print(valeur_flexdroite);
  if (valeur_flexgauche>340 and valeur_flexdroite<300){ //valeurs conditionnelles pour doigt gauche levé
    delay(1000);
    Serial.println(" gauche");}
  
  else if (valeur_flexgauche<340 and valeur_flexdroite>300){//valeurs conditionnelles pour doigt droit levé
    delay(1000);
    Serial.println(" droite");}
    
  else if (valeur_flexgauche<210 and valeur_flexdroite<200){//valeurs conditionnelles pour main doigts qui freinent
    delay(500);
    Serial.println(" frein");}
  else {
    Serial.println(" aucun mouvement");} // main simplement posée sur le guidon
  delay(100); }
  
