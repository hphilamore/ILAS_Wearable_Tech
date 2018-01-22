// I2C interface by default

#include "Wire.h"
#include "accelerometer_setup.h"
#include "neopixel_setup.h"


//int steps, flag;// , flag_movement;
//float threshold = 1200;
unsigned long startTime = millis();
int interval = 10000;//600000;
int flag_movement = 0;


void setup()
{
  Serial.begin(115200);
  pinMode(LED_BUILTIN, OUTPUT);

  // comment out if not using accelerometer
  if (myIMU.begin() != IMU_SUCCESS)
  {
    Serial.println("Failed acceerometer setup.");
    while(1);
  }

  // comment out if not using neopixel
  strip.begin();
  strip.show();
  
  
}

void loop()
{
  
float x, y, z = acceleration_3D();
float M = magnitude_3D(x, y, z);

Serial.print(x);       //Serial.print(x, 4); 
Serial.print("\t");
Serial.print(y);       //Serial.print(y, 4); 
Serial.print("\t");
Serial.print(z);       //Serial.print(z, 4); 
Serial.print("\t");
Serial.println(M);     //Serial.println(M, 4); 
}

