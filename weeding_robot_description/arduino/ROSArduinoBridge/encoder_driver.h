/* *************************************************************
   Encoder driver function definitions - by James Nugen
   ************************************************************ */
   
   
#ifdef ARDUINO_ENC_COUNTER
  //below can be changed, but should be PORTD pins; 
  //otherwise additional changes in the code are required
  #define LEFT_ENC_PIN_A PD2  //pin 2
  #define LEFT_ENC_PIN_B PD3  //pin 3
  
  //below can be changed, but should be PORTC pins
  #define RIGHT_ENC_PIN_A 18 //PC4  //pin A4
  #define RIGHT_ENC_PIN_B 19 //PC5   //pin A5

#elif defined MEGA_ENC_COUNTER
  //below can be changed, but should be interruptable pins; 
  #define LEFT_ENC_PIN_A 3
  #define LEFT_ENC_PIN_B 2
  
  //below can be changed, but should be interruptable pins
  #define RIGHT_ENC_PIN_A 19
  #define RIGHT_ENC_PIN_B 18

#endif
   
long readEncoder(int i);
void resetEncoder(int i);
void resetEncoders();
