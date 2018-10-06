const int  Tx=13;
const int  tot=50;
int a=34;
void setup ()
{
    Serial.begin(9600);
    pinMode(Tx,OUTPUT);
}

void loop ()
{
    Serial.println(a,DEC);
    Serial.println(a,BIN);
    digitalWrite(Tx,HIGH); 
    delay(tot);
    for (int i=0;i<8;i++)
    {
        digitalWrite(Tx,bitRead(a,i));
        delay(tot);
    }
    digitalWrite(Tx,LOW);
    delay(tot);
    delay(1000);
}
