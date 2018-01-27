// I2C interface by default

#include "Wire.h"
#include <SoftwareSerial.h>                // comment out if not using software serial for Bluetooth communication
#include "Bluetooth_setup.h"               // comment out if not using software serial for Bluetooth communication
#include "accelerometer_setup.h"           // comment out if not using accelerometer
//#include "neopixel_setup.h"              // comment out if not using neopixel
#include "resistance_meter_setup.h"        // comment out if not measuring resistance



//int steps, flag;// , flag_movement;
//float threshold = 1200;
unsigned long startTime = millis();
int interval = 10000;//600000;
int flag_movement = 0;


void setup()
{
  //Serial.begin(115200);
  pinMode(LED_BUILTIN, OUTPUT);

  // comment out if not using software serial for bluetooth
  BTserial.begin(9600);

  // comment out if not using accelerometer
  if (myIMU.begin() != IMU_SUCCESS)
  {
    //Serial.println("Failed accelerometer setup.");
    while(1);
  }

//  // comment out if not using neopixel
//    strip.begin();
//    strip.show();  
}


void loop()
{
  
acceleration_3D();

M = magnitude_3D(acceleration[x], 
                 acceleration[y], 
                 acceleration[z]);

step_counter();

resistance();

resistivity();

LED_mapToInput();

print_variables();
   
delay(200);
}

