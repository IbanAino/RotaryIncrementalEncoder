//*** LIBRARIES ***
#include <arduino.h>
#include "RotaryIncrementalEncoder.h"


//*** ATTRIBUTS ***

// Initialize static members of class RotaryIncrementalEncoder
// Because the RotaryIncrementalEncoder uses interrupts with static
// methods and members this step is needed.
int16_t RotaryIncrementalEncoder::encoderRotationRightCounter;
int16_t RotaryIncrementalEncoder::encoderRotationLeftCounter;
uint16_t RotaryIncrementalEncoder::encoderSpeedRightCounter;
uint16_t RotaryIncrementalEncoder::encoderSpeedLeftCounter;
bool RotaryIncrementalEncoder::flagMeasureSpeed;
bool RotaryIncrementalEncoder::flagMeasureRotation;


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
  
  Encoder1->StartRotationMeasurement();
  //Encoder1->StartSpeedMeasurement();

  Encoder2->StartRotationMeasurement();
  //Encoder2->StartSpeedMeasurement();
}

//*** MAIN LOOP ***
void loop() {

  Serial.print(Encoder1->GetRotation());
  Serial.print(", ");
  Serial.print(Encoder2->GetRotation());
  Serial.println();

  delay(100);
}
