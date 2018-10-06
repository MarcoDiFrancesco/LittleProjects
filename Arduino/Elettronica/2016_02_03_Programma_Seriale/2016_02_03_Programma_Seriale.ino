//pins for the LEDs:
const int: Tx=13;
const int: tot=500;

void setup ()
{
//initialize serial:
Serial.begin(9600);
//make the pins outputs
Pinmode(Tx,OUTPUT); //USCITA DIGITALE
}

void loop ()
{
//if there’s any serial available, read it
while(Serial.available()>0
   {
    //look for the next available integer in the incoming serial stream
    int num=Serial.parseInt();
    //look for the newline. That’s the end of your sentence.
    if (Serial.read()==’\n’)
        {
          delay(500);
          Serial.printin(num,DEC);
          Serial.printin(num,BIN);
          Serial.printin(“”);


          delay(tot);
          digitalWrite(Tx,HIGH);   //start bit
          digital(tot);
          for (int i=0;i<=10;i++)
          digitalWrite(Tx,bitRead(num,i));
          delay(tot);
        }
     digitalWrite(Tx,LOW); //stop bit
     delay(tot);
    }
}
