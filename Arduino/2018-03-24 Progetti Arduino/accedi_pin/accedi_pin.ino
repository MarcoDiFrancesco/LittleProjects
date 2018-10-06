#include <dht.h>
#define dht_apin A0;

void setup(){
  pinMode(13,OUTPUT);
  Serial.begin(9600);
  delay(500);
  Serial.println("Umidità e temperatura");
  delay(1000);
}

void loop(){
  DTH.read11(dht_apin);
  digitalWrite(2,HIGH);
  delay(500);
  digitalWrite(2,LOW);
  delay(500);
  
}


