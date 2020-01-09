
#include "Servo.h"
#include "zf_pwm.h"

void SERVO_PwmInit()  //舵机初始化并置中值
{
	pwm_init(SERVO_PIN ,50,SERVO_MID_VALUE);   
}

void SERVO_SetPwm(duty)
{
	if (duty>=3300&&duty<=4040)
	{
		  pwm_duty(SERVO_PIN,duty);		
	}
}
