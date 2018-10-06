#include <dht11.h>

#define DHT11_PIN1 A1
#define DHT11_PIN2 A2
#define DHTTYPE DHT11

dht11 sensore;  

void setup(){
  Serial.begin(9600);
  pinMode(2,OUTPUT);
  pinMode(3,OUTPUT);
  pinMode(4,OUTPUT);
  
  digitalWrite(2,HIGH); // Sensore temperatura 1
  digitalWrite(3,HIGH); // Sensore temperatura 1
  digitalWrite(4,HIGH); // Sensore temperatura 1

}

void loop(){
  temperatureSensor(1);
  temperatureSensor(2);
  delay(200);
}

void temperatureSensor(int nPin){
  Serial.print("Sensore temperatura ");
  Serial.print(nPin);
  Serial.print(", \t");
  if(nPin == 1){
    sensore.read(DHT11_PIN1); // READ DATA    
  } else if (nPin == 2) {
    sensore.read(DHT11_PIN2); // READ DATA
  } else {
    Serial.print("Errore");
  }
  /*
  // Check se il sensore di temperatura/umidità funziona  
  switch (chk){
    case DHTLIB_OK:  
                Serial.print("OK,\t\t"); 
                break;
    case DHTLIB_ERROR_CHECKSUM: 
                Serial.print("Checksum error,\t"); 
                break;
    case DHTLIB_ERROR_TIMEOUT: 
                Serial.print("Time out error,\t"); 
                break;
    default: 
                Serial.print("Unknown error,\t"); 
                break;
  }
  */
 // Display data
  Serial.print(sensore.humidity,1); // Print umidità
  Serial.print(",\t");
  Serial.println(sensore.temperature,1); // Print temperatura
}

