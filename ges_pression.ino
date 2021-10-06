int i = 1;
unsigned long int debut_ouverture;
unsigned long int fermeture_ouverture;
unsigned long int intervalle_ouverture;

float gaz_plein = 13.5;
float temps_gaz = 130;
float conso;
float quantite_restante;


void setup() {
Serial.begin(9600);
}

void loop() {
  Serial.println("Valeur de debut millis");
  debut_ouverture = millis();
  Serial.println(debut_ouverture);
  Serial.println("Valeur de la pression");
  Serial.println(readPressure(A2)/100000);
  
  while((readPressure(A2)/100000) ){
    delay(1000);
  }  
  fermeture_ouverture = millis();
    Serial.println("Valeur de fermeture millis");

Serial.println(fermeture_ouverture);
  intervalle_ouverture = fermeture_ouverture - debut_ouverture;
  Serial.println("Intervalle de l'ouverture");
  Serial.println(intervalle_ouverture);
  intervalle_ouverture = intervalle_ouverture /(3600000);
  conso = (intervalle_ouverture*13.5)/130;
  quantite_restante = (1 - conso/135)*100;
  Serial.println("Gaz restant: ");
  Serial.println(quantite_restante);
}
float readPressure(int pin){
    int pressureValue = analogRead(pin);
    float pressure=((pressureValue/1024.0)+0.095)/0.000009;
    return pressure;
}
