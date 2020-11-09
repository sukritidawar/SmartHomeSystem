#include "dht.h"
#define DHT11_PIN D7
dht DHT11;
int LED = 15;
int sensor = 12;  // pin number of sensor
const int RELAY_PIN = A5; 
void setup() {
  Serial.begin(9600);
  pinMode(LED, OUTPUT);
  pinMode(sensor, INPUT); //set sensor as INPUT
  pinMode(RELAY_PIN, OUTPUT);
}

void loop() {                         
    if(digitalRead(sensor)){    // Checking the sensor
      digitalWrite(LED, HIGH);   // turn the LED ON
      delay(1000);
      DHT11.read11(DHT11_PIN);
      if(DHT11_PIN > 30) { //check whether temperature is greater than 30 Celcius
        digitalWrite(RELAY_PIN, HIGH); // turn on fan 5 seconds
        delay(5000);
      }
    }
    else{
      digitalWrite(LED, LOW);    // turn the LED OFF
      delay(1000); 
      digitalWrite(RELAY_PIN, LOW);  // turn off fan 
      delay(5000);
   }
}
