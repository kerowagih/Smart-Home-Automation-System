/******************************************************************************
 *
 * Module: DC MOTOR
 *
 * File Name: dc_motor.c
 *
 * Description: source file for the DC MOTOR driver
 *
 * Author: Kerollos Wagih
 *
 *******************************************************************************/

/*******************************************************************************
 *                                 INCLUDES                                    *
 *******************************************************************************/

#include "dc_motor.h"
#include "gpio.h"
#include "pwm.h"

/*******************************************************************************
 *                      Functions Definitions                                  *
 *******************************************************************************/

/*
 * Description:
 * Function responsible for initializing the DC motor by setting the direction for
 * the motor pins and stopping the motor at the beginning.
 */
void DcMotor_init(void)
{
	/* Initializes the DC motor by setting the direction for the motor pins */
	GPIO_setupPinDirection(IN1_PORT_ID, IN1_PIN_ID, PIN_OUTPUT);
	GPIO_setupPinDirection(IN2_PORT_ID, IN2_PIN_ID, PIN_OUTPUT);
	GPIO_setupPinDirection(ENABLE1_PORT_ID, ENABLE1_PIN_ID, PIN_OUTPUT);

	/* stopping the motor at the beginning */
	DcMotor_Rotate(STOP,0);
}

/*
 * Description:
 * Function responsible for Controlling the motor's state (Clockwise/Anti-Clockwise/Stop)
 * and adjusts the speed based on the input duty cycle
 */
void DcMotor_Rotate(DcMotor_State state, uint8 speed)
{
	switch (state)
	{
	case 0:
		/* STOP */
		GPIO_writePin(IN1_PORT_ID, IN1_PIN_ID, LOGIC_LOW);
		GPIO_writePin(IN2_PORT_ID, IN2_PIN_ID, LOGIC_LOW);
		PWM_Timer0_Start(0);
		break;
	case 1:
		/* ClockWise */
		GPIO_writePin(IN1_PORT_ID, IN1_PIN_ID, LOGIC_LOW);
		GPIO_writePin(IN2_PORT_ID, IN2_PIN_ID, LOGIC_HIGH);
		PWM_Timer0_Start(speed);
		break;
	case 2:
		/* Anti-ClockWise */
		GPIO_writePin(IN1_PORT_ID, IN1_PIN_ID, LOGIC_HIGH);
		GPIO_writePin(IN2_PORT_ID, IN2_PIN_ID, LOGIC_LOW);
		PWM_Timer0_Start(0);
		break;
	default:
		/*
		 * Wrong input
		 * Do nothing
		 */
		break;
	}
}
