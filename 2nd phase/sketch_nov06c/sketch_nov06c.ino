
#include <VirtualWire.h>
#include <SoftwareSerial.h>
SoftwareSerial Xbee(2, 3);
const int led = 13;
const int transmit_pin = 12;
int motion = 7;
const int transmit_en_pin = 3;
int bulb = 9; // bulb connected here
char data ; 
boolean flag = 0;
boolean flag2 = 0;

 
 String str;
 char cstr[27];
void setup()
{
    // Initialise the IO and ISR
    vw_set_tx_pin(transmit_pin);
    Serial.begin(9600);

Xbee.begin(9600);
    vw_setup(2000);       // Bits per sec
    pinMode(led, OUTPUT);
    pinMode(motion, INPUT);
    digitalWrite(led, LOW);
    pinMode(bulb, OUTPUT);
}

byte count = 1;

void loop()
{

    if(Xbee.available()>0)
  {
  data = Xbee.read();

} else
if((digitalRead(motion) == 1)&& (flag2 == 1))
{
 digitalWrite(bulb , HIGH ); 
 
}else
if(data == 'a')
{
digitalWrite(bulb, HIGH);
flag = 1;
}else
if(data == 'b')
{
digitalWrite(bulb, LOW);
flag = 0;
} else
if(data == 'o')
{
digitalWrite(bulb, LOW);
flag2 = 0;
}
else
if(data == 'n')
{
//digitalWrite(bulb, HIGH);
flag2 = 1;
}
else 
if((digitalRead(motion) == HIGH) && ( flag == 1) && (flag2 == 1))
{
 digitalWrite(bulb, HIGH); 
 flag = 0;
 flag2 = 0;
} else 
if((digitalRead(motion) ==  LOW) && (flag == 0)&& (flag2 == 0))
{
  digitalWrite(bulb, LOW);
  flag = 1;///////
  flag2 = 1;//////
}else 
if((digitalRead(motion) == HIGH)&& (flag == 0)&& (flag2 == 0))
{
 digitalWrite(bulb, HIGH  ); 
flag = 1;//////
flag2 = 1;/////
 //delay(4000);
 //digitalWrite(bulb, LOW);
}else
if((digitalRead(motion) == HIGH) && (flag2 == 1)) 
{
digitalWrite(bulb , HIGH); 

flag2 = 0; ////////////////////////////////////////
} 
//else
//digitalWrite(bulb, LOW);


}
 
