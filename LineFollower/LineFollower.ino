#include "MeMCore.h"

MeLineFollower lineFinder(PORT_2);

MeDCMotor motor1(M1);

MeDCMotor motor2(M2);

uint8_t motorSpeed = -100;

void setup()
{
  //Serial.begin(9600);
}

void loop()
{
  int sensorState = lineFinder.readSensors();
  switch(sensorState) {
    case S1_IN_S2_IN:
      //Serial.println("Sensor 1 and 2 are inside of black line");
      motor1.run(motorSpeed);
      motor2.run(motorSpeed * -1);
      break;
    case S1_IN_S2_OUT:
      //Serial.println("Sensor 2 is outside of black line");
      motor1.run(motorSpeed);
      motor2.run(motorSpeed);
      break;
    case S1_OUT_S2_IN:
      //Serial.println("Sensor 1 is outside of black line");
      motor1.run(motorSpeed * -1);
      motor2.run(motorSpeed * -1);
      break;
    case S1_OUT_S2_OUT:
      // Serial.println("Sensor 1 and 2 are outside of black line");
      motor1.run(motorSpeed);
      motor2.run(motorSpeed);
      break;
    default: break;
  }
}
