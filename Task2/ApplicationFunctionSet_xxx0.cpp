#include "DeviceDriverSet_xxx0.h"

extern DeviceDriverSet_Motor AppMotor;

enum SmartRobotCarMotionControl
{
    F1,           // Forward 1
    F2,           // Forward 2
    S1,           // Stop 1
    R1,           // Right 1
    S2,           // Stop 2
    F3,           // Forward 3
    F4,           // Forward 4
    S3,           // Stop 3
    L1,           // Left 1
    S4,           // Stop 4
    F5,           // Forward 5
    F6,           // Forward 6
    stop_it       // Stop command
};

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
    case F1:
    case F2:
        AppMotor.DeviceDriverSet_Motor_control(direction_just, speed * 2,
                                               direction_just, speed * 2, control_enable);
        break;

    case S1:
    case S2:
    case S3:
    case S4:
        AppMotor.DeviceDriverSet_Motor_control(direction_just, 0,
                                               direction_just, 0, control_enable);
        _delay_ms(250);
        break;

    case R1:
        AppMotor.DeviceDriverSet_Motor_control(direction_back, speed,
                                               direction_just, speed * 0.55, control_enable);
        break;

    case F3:
    case F4:
    case F5:
    case F6:
        AppMotor.DeviceDriverSet_Motor_control(direction_just, speed * 2,
                                               direction_just, speed * 2, control_enable);
        break;

    case L1:
        AppMotor.DeviceDriverSet_Motor_control(direction_just, speed,
                                               direction_back, speed * 0.50, control_enable);
        break;

    case stop_it:
        AppMotor.DeviceDriverSet_Motor_control(direction_void, 0,
                                               direction_void, 0, control_enable);
        break;

    default:
        break;
    }
}
