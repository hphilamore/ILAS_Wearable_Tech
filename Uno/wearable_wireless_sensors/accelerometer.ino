
float acceleration_3D(){
  /*
  Returns the acceleration in x, y, and x directions in units milli-G 
  */
  float x = float((myIMU.readAccelX()));
  float y = float((myIMU.readAccelY()));
  float z = float((myIMU.readAccelZ()));

  return x, y, z;
}



float magnitude_3D(float X, float Y, float Z){
  /*
  Returns the magnitude of the 3D acceleration vector 
  */
 
  float M = sqrt(sq(X)+sq(Y)+sq(Z));

  return M;
}



void step_counter(float mag){
  /*
  Cumulatively sums the number of steps taken. 
  Flashes an LED when a step is logged.
  */

  int th = step_threshold;

  // if the magnitude is greater than the threshold and the flag is down...
  if (mag>th && flag==0){
      
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
  else if (mag>th && flag==1)
    {
      // do nothing
    }


  // if the magnitude is less than the threshold and the flag is up,
  if (mag<th  && flag==1)
  {   
    flag=0;         // put the flag down
  }

  // print the number of steps
  Serial.println(steps);
}


//void sudden_fall(){
//if(M<threshold)
//  {
//    if (flag_movement == 0)
//    {
//      if (millis() - startTime > interval)
//      {
//        strip.setPixelColor(0, 255, 0, 0);                 // HP : Curly braces around code after if statement
//        strip.show();
//       }
//     }
//  
//     else
//     {
//      flag_movement = 0;
//     }
//  }
//
//else
//  {
//    flag_movement = 1;
//    startTime = millis();
//    strip.setPixelColor(0, 0, 0, 0);                   // HP : Curly braces around code after if statement
//    strip.show(); // if the light turns on, the person is in danger.  // HP: Use // for comments
//  }
//  delay(100);
//}
//}

void pace(){
  /*
  Calculates the average pace; number of steps / time period
  Lights an LED if the pace exceeds a threshold
  */
  unsigned long p = pace_period;
  int th = pace_threshold;

  // if time since last measurement exceeds period, calculate pace
  if ((millis() - startTime) > p){
     int stepsNew = steps;     
     unsigned long endTime = millis();
     float paceAve = float(stepsNew - stepsOld) / float(endTime - startTime); 
     int stepsOld = steps;
     startTime = millis();
     Serial.println(paceAve, 6);  

     // if the pace exceeds a threshold, turn LED on
     if (paceAve > th){     
        digitalWrite(LED_BUILTIN, HIGH);   // LED on
        // neopixel_BLUE();
     }
  
     // otherwise turn it off
     else{                
        digitalWrite(LED_BUILTIN, LOW);    // LED off
        // neopixel_OFF();
     }
   }
}
