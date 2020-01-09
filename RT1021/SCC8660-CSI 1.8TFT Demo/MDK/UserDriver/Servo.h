#ifndef _SERVO_h
#define _SERVO_h

#define SERVO_PIN   PWM1_MODULE0_CHB_C27       //定义舵机引脚
#define SERVO_MID_VALUE        3660         //定义舵机中值
#define SERVO_RIGHT_VALUE      3300       //定义舵机右边极值
#define SERVO_LEFT_VALUE       4044       //定义舵机左边极值

void SERVO_PwmInit();
void SERVO_SetPwm(int duty);

#endif