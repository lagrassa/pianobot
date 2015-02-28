#include <Servo.h>

#include <Wire.h>

Servo fSharp;
void setup()
{
  Wire.begin(6);                // join i2c bus with address #4
  Wire.onReceive(receiveEvent); // register event
  Serial.begin(9600);           // start serial for output
  pinMode(13, OUTPUT);
  fSharp.attach(9);
  }

void loop()
{
  delay(100);
}

// function that executes whenever data is received from master
// this function is registered as an event, see setup()
void receiveEvent(int howMany)
{
  while(1 < Wire.available()) // loop through all but the last
  {
    char c = Wire.read(); // receive byte as a character
    Serial.print(c);         // print the character
  }
  int x = Wire.read();    // receive byte as an integer
  Serial.println(x);         // print the integer
  if (x % 20 < 10) {
    digitalWrite(13,HIGH);
    fSharp.write(70);
  } else {
    digitalWrite(13,LOW);
    fSharp.write(45);
  }
}
