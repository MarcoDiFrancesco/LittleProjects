#include <TinkerKit.h>
#define O0 11
#define O1 10
#define O2 9
#define O3 6
#define O4 5
#define O5 3
#define I0 A0
#define I1 A1
#define I2 A2
#define I3 A3
#define I4 A4
#define I5 A5

TKThermistor therm(I0);  
float C, F;
int TEMPERATURA=I0;
int temp;
int pin=O0;
int led=O1;
int cic = O2 ; 
void setup() {
Serial.println ( " CLEARDATA " ) ;
Serial.println  ("LABEL,Time,temperatura " ) ;
pinMode ( O0,OUTPUT ) ;   
pinMode ( O1,OUTPUT ) ;   
Serial.begin (9600) ; 
pinMode ( O2, OUTPUT ) ;  
}
void loop() {
  Serial.print ("DATA,TIME, " ) ;
  Serial.println  ( C ) ; 
    C = therm.readCelsius();     	
  F = therm.readFahrenheit();  	
 Serial.print("Analog reading: ");	
  Serial.print(therm.read());vb
  Serial.print("\tC: ");
  Serial.print(C);
  Serial.print("\tF: ");
  Serial.println(C);

  delay (300);
  int val_ADC = analogRead (I0) ;
   temp=analogRead(TEMPERATURA);
if (   temp > 730 ) {
digitalWrite ( O0, HIGH ) ; 
}    
else 
{ 
digitalWrite (O0, LOW ) ;  
}  
}
