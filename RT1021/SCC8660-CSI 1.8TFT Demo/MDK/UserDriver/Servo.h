#ifndef _SERVO_h
#define _SERVO_h

#define SERVO_PIN   PWM1_MODULE0_CHB_C27       //����������
#define SERVO_MID_VALUE        3660         //��������ֵ
#define SERVO_RIGHT_VALUE      3300       //�������ұ߼�ֵ
#define SERVO_LEFT_VALUE       4044       //��������߼�ֵ

void SERVO_PwmInit();
void SERVO_SetPwm(int duty);

#endif