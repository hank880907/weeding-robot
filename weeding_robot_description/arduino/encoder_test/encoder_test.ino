/* Encoder Library - Basic Example
 * http://www.pjrc.com/teensy/td_libs_Encoder.html
 *
 * This example code is in the public domain.
 */

#include <Encoder.h>

// Change these two numbers to the pins connected to your encoder.
//   Best Performance: both pins have interrupt capability
//   Good Performance: only the first pin has interrupt capability
//   Low Performance:  neither pin has interrupt capability
Encoder myEnc1(20, 21);
Encoder myEnc2(18, 19);
//   avoid using pins with LEDs attached

void setup() {
  Serial.begin(57600);
  Serial.println("Basic Encoder Test:");
}

long oldPosition1  = -999;
long oldPosition2  = -999;

void loop() {
  long newPosition1 = myEnc1.read();
  long newPosition2 = myEnc2.read();
  if (newPosition1 != oldPosition1 || newPosition2 != oldPosition2) {
    oldPosition1 = newPosition1;
    oldPosition2 = newPosition2;
    Serial.print(newPosition1);
    Serial.print(", ");
    Serial.println(newPosition2);
  }

}
