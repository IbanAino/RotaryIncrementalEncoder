/*






*/

#ifndef EncoderHallEffect_h
#define EncoderHallEffect_h

#include <arduino.h>

class EncoderHallEffect
{
  public:
    // Constructor
    EncoderHallEffect(uint8_t encoderID);

    // Functions

    // Velocity
    void StartSpeedMeasurement();
    void StopSpeedMeasurement();
    int16_t GetSpeed();

    // Rotation
    void StartRotationMeasurement();
    void StopRotationMeasurement();
    int16_t GetRotation();

    // Static functions
    static void handleInterruptA();
    static void handleInterruptC();
 
  private:
     // Attributs
    uint8_t encoderID;
     
    uint8_t hardwarePinEncoderSensorA;
    uint8_t hardwarePinEncoderSensorB;
    uint8_t hardwarePinEncoderSensorC;
    uint8_t hardwarePinEncoderSensorD;

    // Time scheduler to compute speed
    unsigned long timeMilllisecond;

    // Static members
    static int16_t encoderRotationRightCounter;
    static int16_t encoderRotationLeftCounter;
    static uint16_t encoderSpeedRightCounter;
    static uint16_t encoderSpeedLeftCounter;
    static bool flagEMeasureSpeed; 
    static bool flagMeasureRotation;   
};
#endif
