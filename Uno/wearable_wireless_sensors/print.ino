void print_variables(){

  // comment out if not using accelerometer
  Serial.print(acceleration[x]);       
  Serial.print("\t");
  Serial.print(acceleration[y]);        
  Serial.print("\t");
  Serial.print(acceleration[z]);        
  Serial.print("\t");
  Serial.print(M);  
  Serial.print("\t");
  
  // comment out if not using step counter / pedometer
  Serial.print(steps * 100);
  Serial.print("\t");
  
  // comment out if not using resistance meter
  Serial.print(reading);
  Serial.print("\t");
  Serial.print(voltage);
  Serial.print("\t");
  Serial.print(R1); 
  Serial.print("\t");
  Serial.print(resistivity_1);
  
  Serial.print("\n");    
}

