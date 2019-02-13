//*** LIBRARIES ***
#include <arduino.h>
#include "RotaryIncrementalEncoder.h"


//*** OBJECTS DECLARATIONS ***
RotaryIncrementalEncoder* Encoder1;
RotaryIncrementalEncoder* Encoder2;

//*** SETUP ***
void setup() {
  // Serial communicaiton with PC
  Serial.begin(9600);
  Serial.println("Start programm");

  // Objects instanciations
  Encoder1 = new RotaryIncrementalEncoder(1);
  Encoder2 = new RotaryIncrementalEncoder(2);
  
  //Encoder1->StartRotationMeasurement();
  Encoder1->StartSpeedMeasurement();

  //Encoder2->StartRotationMeasurement();
  //Encoder2->StartSpeedMeasurement();
}

//*** MAIN LOOP ***
void loop() {

  Serial.print(Encoder1->GetSpeed());
  //Serial.print(", ");
  //Serial.print(Encoder2->GetRotation());
  Serial.println();

  delay(100);
}
