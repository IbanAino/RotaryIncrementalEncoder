//*** LIBRARIES ***
#include <arduino.h>
#include "RotaryIncrementalEncoder.h"


//*** ATTRIBUTS ***

// Initialize static members of class EncoderHallEffect
// Because the RotaryIncrementalEncoder uses interrupts with static
// methods and members this step is needed.
int16_t EncoderHallEffect::encoderRotationRightCounter;
int16_t EncoderHallEffect::encoderRotationLeftCounter;
uint16_t EncoderHallEffect::encoderSpeedRightCounter;
uint16_t EncoderHallEffect::encoderSpeedLeftCounter;
bool EncoderHallEffect::flagEMeasureSpeed;
bool EncoderHallEffect::flagMeasureRotation;


//*** OBJECTS DECLARATIONS ***
EncoderHallEffect* Encoder1;

//*** SETUP ***
void setup() {
  // Serial communicaiton with PC
  Serial.begin(9600);
  Serial.println("Start programm");

  // Objects instanciations
  Encoder1 = new EncoderHallEffect(1);
  
  //Encoder1->StartRotationMeasurement();
  Encoder1->StartSpeedMeasurement();
}

//*** MAIN LOOP ***
void loop() {

  //Serial.println(Encoder1->GetRotation());
  Serial.println(Encoder1->GetSpeed());

  delay(100);
}
