
void acceleration_3D(){
  /*
  Returns the acceleration in x, y, and x directions in units milli-G 
  */
  float X = float((myIMU.readAccelX()));
  float Y = float((myIMU.readAccelY()));
  float Z = float((myIMU.readAccelZ()));

  acceleration[x] = X;
  acceleration[y] = Y;
  acceleration[z] = Z;
}



float magnitude_3D(float X, float Y, float Z){
  /*
  Returns the magnitude of the 3D acceleration vector 
  */
 
  M = sqrt(sq(X)+sq(Y)+sq(Z));

  return M;
}



void step_counter(){
  /*
  Cumulatively sums the number of steps taken. 
  Flashes an LED when a step is logged.
  */

  int th = step_threshold;

  // if the magnitude is greater than the threshold and the flag is down...
  if (M>th && flag==0){
      
      steps=steps+1;      // ...count a setp
 
      flag=1;             // ...raise the flag
      
      digitalWrite(LED_BUILTIN, HIGH);   // LED on
      // neopixel_RED();
      delay(200);                        // wait
      digitalWrite(LED_BUILTIN, LOW);    // LED off
      // neopixel_OFF();
    }


  // if the magnitude is greater than the threshold and the flag is up,
  // the step has already been counted 
  else if (M>th && flag==1)
    {
      // do nothing
    }


  // if the magnitude is less than the threshold and the flag is up,
  if (M<th  && flag==1)
  {   
    flag=0;         // put the flag down
  }
}


//void sudden_fall(){
//}



//void pace(){
//  /*
//  Calculates the average pace; number of steps / time period
//  Lights an LED if the pace exceeds a threshold
//  */
//  unsigned long p = pace_period;
//  int th = pace_threshold;
//
//  // if time since last measurement exceeds period, calculate pace
//  if ((millis() - startTime) > p){
//     int stepsNew = steps;     
//     unsigned long endTime = millis();
//     float paceAve = float(stepsNew - stepsOld) / float(endTime - startTime); 
//     int stepsOld = steps;
//     startTime = millis();
//     Serial.println(paceAve, 6);  
//
//     // if the pace exceeds a threshold, turn LED on
//     if (paceAve > th){     
//        digitalWrite(LED_BUILTIN, HIGH);   // LED on
//        // neopixel_BLUE();
//     }
//  
//     // otherwise turn it off
//     else{                
//        digitalWrite(LED_BUILTIN, LOW);    // LED off
//        // neopixel_OFF();
//     }
//   }
//}
