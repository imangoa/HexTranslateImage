#ifndef _MOTOR_h
#define _MOTOR_h





#define MOTOR1_A   PWM2_MODULE1_CHA_D4   //����1�����תPWM����
#define MOTOR1_B   PWM2_MODULE0_CHA_D6   //����1�����תPWM����
                        
#define MOTOR2_A   PWM2_MODULE1_CHB_D5   //����2�����תPWM����
#define MOTOR2_B   PWM2_MODULE0_CHB_D7   //����2�����תPWM����


#define MOTOR_PRECISON 12000  //pwmֵ����


void MOTOR_PwmInit(void);
void MOTOR_SetPwm(int duty);


#endif