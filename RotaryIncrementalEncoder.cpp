#include "RotaryIncrementalEncoder.h"
#include <arduino.h>


// CONSTRUCTOR
EncoderHallEffect::EncoderHallEffect(uint8_t encoderID){

  this -> encoderID = encoderID; // two encoders availables : encoder 1 and encoder 2

  flagMeasureRotation = false;

  // Encoder 1 sensors A and B
  hardwarePinEncoderSensorA = 2;
  hardwarePinEncoderSensorB = 3;
  // Encoder 2 sensors C and D
  hardwarePinEncoderSensorC = 18;
  hardwarePinEncoderSensorD = 19;

  pinMode(hardwarePinEncoderSensorA, INPUT_PULLUP);
  pinMode(hardwarePinEncoderSensorB, INPUT_PULLUP);
  pinMode(hardwarePinEncoderSensorC, INPUT_PULLUP);
  pinMode(hardwarePinEncoderSensorD, INPUT_PULLUP);

  switch(encoderID){
    case 1 :
      attachInterrupt(digitalPinToInterrupt(hardwarePinEncoderSensorA), handleInterruptA, CHANGE); // Encoder 1
    break;
    case 2 :
      attachInterrupt(digitalPinToInterrupt(hardwarePinEncoderSensorC), handleInterruptC, CHANGE); // Encoder 2
    break;
  }
}


// FUNCTIONS
void EncoderHallEffect::StartSpeedMeasurement(){
  flagEMeasureSpeed = true;
  
  // Reset couteres and timer
  encoderSpeedRightCounter = 0;
  encoderSpeedLeftCounter = 0;
  timeMilllisecond = millis();
}

void EncoderHallEffect::StopSpeedMeasurement(){
  flagEMeasureSpeed = false;
}

int16_t EncoderHallEffect::GetSpeed(){
  
  if(encoderID == 1){
    int16_t motorSpeed = (encoderSpeedRightCounter * 100)/(millis() - timeMilllisecond);
    timeMilllisecond = millis();
    encoderSpeedRightCounter = 0;
    return(motorSpeed);
  }
  else if(encoderID == 2){
    int16_t motorSpeed = (encoderSpeedLeftCounter * 100)/(millis() - timeMilllisecond);
    timeMilllisecond = millis();
    encoderSpeedLeftCounter = 0;
    return(motorSpeed);
  } 
}

void EncoderHallEffect::StartRotationMeasurement(){
  flagMeasureRotation = true;
}

void EncoderHallEffect::StopRotationMeasurement(){
  flagMeasureRotation = false;
}

int16_t EncoderHallEffect::GetRotation(){
  switch(encoderID){
    case 1 :
      return(encoderRotationRightCounter);
    break;
    case 2 :
      return(encoderRotationLeftCounter);
    break;
  }
}

// Encoder 1
static void EncoderHallEffect::handleInterruptA(){
  // Speed measurement
  if(flagEMeasureSpeed){
    encoderSpeedRightCounter++;
  }
  
  // Rotation measurement
  if(flagMeasureRotation){
    if (digitalRead(2) == HIGH) {
      if (digitalRead(3) == LOW) {
        encoderRotationRightCounter++;
      } else {
        encoderRotationRightCounter--;
      }
    } else {
      if (digitalRead(3) == LOW) {
        encoderRotationRightCounter--;
      } else {
        encoderRotationRightCounter++;
      }
    }
  }
}

// Encoder 2
void EncoderHallEffect::handleInterruptC(){
  // Speed measurement
  if(flagEMeasureSpeed){
    encoderSpeedLeftCounter++;
  }
  
  // Rotation measurement
  if(flagMeasureRotation){
    if (digitalRead(2) == HIGH) {
      if (digitalRead(3) == LOW) {
        encoderRotationLeftCounter++;
      } else {
        encoderRotationLeftCounter--;
      }
    } else {
      if (digitalRead(3) == LOW) {
        encoderRotationLeftCounter--;
      } else {
        encoderRotationLeftCounter++;
      }
    }
  }
}
