#include <Wire.h>
#include <Servo.h>
Servo myServo; 
int internalTime = 0;
void setup()

{
  Wire.begin(4);                // join i2c bus with address #4
  Wire.onReceive(receiveEvent); // register event
  Serial.begin(9600);           // start serial for output
  pinMode(13,OUTPUT);
  myServo.attach(9);
 
}

void loop()
{
  internalTime=Serial.read();
  if (internalTime % 100 < 50) {
    myServo.write(90);
  } else {
    myServo.write(10);
  }
}

