#include <VirtualWire.h>
#include <SoftwareSerial.h>
SoftwareSerial Xbee(2, 3);
//initializes/defines the output pin of the LM35 temperature sensor
int outputpin= 0; // for reading temperature
int relay = 13;
int relay2 = 12;
int intensity = 7;
//this sets the ground pin to LOW and the input voltage pin to high
void setup()
{
Serial.begin(9600);
pinMode(intensity , INPUT);
pinMode(relay, OUTPUT);
pinMode(relay2, OUTPUT);
digitalWrite(relay, LOW);
}

//main loop
void loop()
{
int rawvoltage= analogRead(outputpin);
float millivolts= (rawvoltage/1024.0) * 5000;
float celsius= millivolts/10;
Serial.print(celsius);
Serial.print(" degrees Celsius, ");

Serial.print((celsius * 9)/5 + 32);
Serial.println(" degrees Fahrenheit");
delay(1000);
if( celsius > 30)
{
 Xbee.write('1');
digitalWrite(relay, HIGH);
}
if(celsius < 30)
{
digitalWrite(relay, LOW);
Xbee.write('2');
}
if(digitalRead(intensity) == HIGH) 
{
digitalWrite(relay2, HIGH);
Xbee.write('a');
}

if(digitalRead(intensity) == LOW)
{
digitalWrite(relay2, LOW);
Xbee.write('b');
}


}
