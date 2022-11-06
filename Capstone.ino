#include <dht.h>
int IN1 = 2;
//Calibating moisture sensor
//fully submered or 100% wet
const int Mhighend = 500;
//fully dry
const int Mlowend = 201;

//Calibating light sensor
//no light
const int Lhighend = 877;
//full light
const int Llowend = 65;

//Calibating Humidity sensor
//no Humidity
const int hhighend = 100;
//raining
const int hlowend = 0;

dht DHT;

#define DHT11_PIN 7


void setup() {
  // put your setup code here, to run once:
  pinMode(IN1, OUTPUT);
  digitalWrite(IN1, HIGH);
  delay(500);
  Serial.begin(9600);
}

void loop() {
  //Assigning pins to variables
  int soilMoisture = analogRead(A0);
  int lightSensor = analogRead(A1);
  
  //Humidity/Temperature
  int chk = DHT.read11(DHT11_PIN);

  //Normalizing data to percentages 0-100
  int moisturePerent = map(soilMoisture, Mhighend, Mlowend, 100, 0);
  int lightPerent = map(lightSensor, Lhighend, Llowend, 100, 0);
  int humidityPerent = map(DHT.humidity, hlowend, hhighend, 100, 0);
  
  //Convert Celcius to Farenheit (Dilion would be proud)
  int temp = DHT.temperature * 1.8 + 32;

  //Data must be sent as:
  //Whole number | CSV | on one line
  Serial.print(lightPerent);
  Serial.print(",");
  Serial.print(moisturePerent);
  Serial.print(",");
  Serial.print(temp);
  Serial.print(",");
  Serial.println(humidityPerent);





  delay(1000);
  // put your main code here, to run repeatedly:

}
