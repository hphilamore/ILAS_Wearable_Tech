/*
 * Connections : Arduino Uno --> LSM303C
 * 3.3V --> Vdd
 * GND --> GND
 * A4 --> SDA
 * A5 --> SCL
*/

#include "SparkFunLSM303C.h"

LSM303C myIMU;

//int steps = 0, stepsOld = 0, flag = 0;
int steps, stepsOld, flag;

#define suddenFall_threshold 900  // the magnitude of acceleration above which a fall is registered
#define step_threshold 900        // the magnitude of acceleration above which a step is registered
#define pace_period 3000          // the period over which steps are counted to calculate pace
#define pace_threshold 0.0005     // the pace above which a light will switch on

