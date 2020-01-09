#ifndef _MOTOR_h
#define _MOTOR_h





#define MOTOR1_A   PWM2_MODULE1_CHA_D4   //定义1电机正转PWM引脚
#define MOTOR1_B   PWM2_MODULE0_CHA_D6   //定义1电机反转PWM引脚
                        
#define MOTOR2_A   PWM2_MODULE1_CHB_D5   //定义2电机正转PWM引脚
#define MOTOR2_B   PWM2_MODULE0_CHB_D7   //定义2电机反转PWM引脚


#define MOTOR_PRECISON 12000  //pwm值限制


void MOTOR_PwmInit(void);
void MOTOR_SetPwm(int duty);


#endif