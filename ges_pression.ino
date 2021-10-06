//declaration of variables used in the code

unsigned long int debut_ouverture;     //retrieve the time at the moment the valve is opened
unsigned long int fermeture_ouverture; //retrieve the time at the moment the valve is closed
unsigned long int intervalle_ouverture; //calculate the interval between the opening and the closing of the valve

float gaz_plein = 13.5;   //height of a bottle gas here
float temps_gaz = 130;    //mean time to empty a bottle of gas of 4 fireplaces
float conso;              //calculate the consumption of the gas
float quantite_restante;  //calculate the rest in the bottle gas


void setup() {
Serial.begin(9600);  //open the Serial monitor with 9600 Kbps of speed communication
}

void loop() {
  Serial.println("Valeur de debut millis");
  debut_ouverture = millis();  //retrieve timed when the valve is opened
  Serial.println(debut_ouverture); //print out the value
  Serial.println("Valeur de la pression");  
  Serial.println(readPressure(A1));  //read the pressure value
  val = readPressure(A1);   //store it in the val value
  while(val>54000){         //while val>54000, stay in the loop and exit when the value decrease. 
    delay(1000);
    val = readPressure(A1);
  }  
  fermeture_ouverture = millis();  //We are out of the condition and then, we can fix the closed time
    Serial.println("Valeur de fermeture millis");

Serial.println(fermeture_ouverture);
  intervalle_ouverture = fermeture_ouverture - debut_ouverture;   //calculate the opening time of the valve
  Serial.println("Intervalle de l'ouverture");
  Serial.println(intervalle_ouverture);
  intervalle_ouverture = intervalle_ouverture /(3600);  //convert it into hours
  conso = (intervalle_ouverture*13.5);      //calculate consumption (time_consumed * weight of the gas bottle)
  quantite_restante = (1 - conso/135)*100;  //calculate the rest in the gas bottle, then convert it into percentage
  Serial.println("Gaz restant: ");
  Serial.println(quantite_restante);
  delay(1000);
}

//function to retrieve pressure value
float readPressure(int pin){
    int pressureValue = analogRead(pin);
    float pressure=((pressureValue/1024.0)+0.095)/0.000009;
    return pressure;
}
