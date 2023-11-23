#include "DeviceDriverSet_xxx0.h"

extern DeviceDriverSet_Motor AppMotor;

enum SmartRobotCarMotionControl
{
  F1,       //(1)
  F2,
  S1,
  R1,
  S2,
  F3,
  F4,
  S3,
  R2,
  S4,
  F5,
  F6,
  S5,
  R3,
  S6,
  F7,
  F8,
  stop_it        //(18)
};               //direction方向:（1）、（2）、 （3）、（4）、（5）、（6）

struct Application_xxx
{
  SmartRobotCarMotionControl Motion_Control;
};

extern Application_xxx Application_SmartRobotCarxxx0;

static void ApplicationFunctionSet_SmartRobotCarMotionControl(SmartRobotCarMotionControl direction, uint8_t is_speed)
{
  static uint8_t directionRecord = 0;
  uint8_t Kp, UpperLimit;
  uint8_t speed = is_speed;
  switch (direction)
  {
  case F1: //forward
  case F2: //forward
  case F3: //forward
  case F4: //forward
  case F5: //forward
  case F6: //forward
  case F7: //forward
  case F8: //forward


    AppMotor.DeviceDriverSet_Motor_control(/*direction_A*/ direction_just, /*speed_A*/ speed*2,
                                           /*direction_B*/ direction_just, /*speed_B*/ speed*2, /*controlED*/ control_enable); //Motor control
    break;

  case R1: //right turn
  case R2: //right turn
  case R3: //right turn
    AppMotor.DeviceDriverSet_Motor_control(/*direction_A*/ direction_back, /*speed_A*/ speed,
                                           /*direction_B*/ direction_just, /*speed_B*/ speed*0.55, /*controlED*/ control_enable); //Motor control
    break;

  case S1: //right turn
  case S2: //right turn
  case S3: //right turn
  case S4: //right turn
  case S5: //right turn
  case S6: //right turn
    AppMotor.DeviceDriverSet_Motor_control(/*direction_A*/ direction_back, /*speed_A*/ speed*0,
                                           /*direction_B*/ direction_just, /*speed_B*/ speed*0, /*controlED*/ control_enable); //Motor control
    break;

  case stop_it:
    AppMotor.DeviceDriverSet_Motor_control(/*direction_A*/ direction_void, /*speed_A*/ 0,
                                           /*direction_B*/ direction_void, /*speed_B*/ 0, /*controlED*/ control_enable); //Motor control
    break;
  default:
    break;
  }
}