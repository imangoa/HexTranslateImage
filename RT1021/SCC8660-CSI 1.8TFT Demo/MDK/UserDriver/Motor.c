
#include "Motor.h"
#include "zf_pwm.h"

void MOTOR_PwmInit()
{
	pwm_init(MOTOR1_A,17000,0);
	pwm_init(MOTOR1_B,17000,0);
	pwm_init(MOTOR2_A,17000,0);
	pwm_init(MOTOR2_B,17000,0);
}


void MOTOR_SetPwm(duty)
{
	if(0<=duty) //���1,2   ��ת ����ռ�ձ�Ϊ �ٷ�֮ (1000/TIMER1_PWM_DUTY_MAX*100)
	{
		if(duty>=MOTOR_PRECISON)
			duty=MOTOR_PRECISON;
		pwm_duty(MOTOR1_A, duty);
		pwm_duty(MOTOR1_B, 0);
		pwm_duty(MOTOR2_A, 0);
		pwm_duty(MOTOR2_B, duty);
	}
	else                //���1,2   ��ת
	{
		if(duty<=MOTOR_PRECISON)
			duty=MOTOR_PRECISON;
		pwm_duty(MOTOR1_A, 0);
		pwm_duty(MOTOR1_B, -duty);
		pwm_duty(MOTOR1_A, 0);
		pwm_duty(MOTOR1_B, -duty);
	}
}