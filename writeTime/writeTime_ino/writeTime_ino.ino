
#include <Wire.h>
int x = 0;
void setup()
{
  Wire.begin(); // join i2c bus (address optional for master)
}

int time = 0;

void loop() {
  Wire.beginTransmission(4); // transmit to device #4
  Wire.write(x);              // sends one byte  
  Wire.endTransmission();    // stop transmitting
  
  Wire.beginTransmission(5); // transmit to device #4
  Wire.write(x);              // sends one byte  
  Wire.endTransmission();    // stop transmitting
  
  Wire.beginTransmission(6); // transmit to device #4
  Wire.write(x);              // sends one byte  
  Wire.endTransmission();    // stop transmitting
  

  x++;
  delay(500);
}
