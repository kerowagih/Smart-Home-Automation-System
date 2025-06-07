 /******************************************************************************
 *
 * Module: DC MOTOR
 *
 * File Name: dc_motor.h
 *
 * Description: header file for the DC MOTOR driver
 *
 * Author: Kerollos Wagih
 *
 *******************************************************************************/

#ifndef DC_MOTOR_H_
#define DC_MOTOR_H_

/*******************************************************************************
 *                                 INCLUDES                                    *
 *******************************************************************************/

#include "std_types.h"

/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/

/* Configure H-bridge inputs*/
/* Configure IN1 (port and pin) */
#define IN1_PORT_ID		PORTB_ID
#define IN1_PIN_ID		PIN0_ID

/* Configure IN2 (port and pin) */
#define IN2_PORT_ID		PORTB_ID
#define IN2_PIN_ID		PIN1_ID

/* Configure Enable1 (port and pin) */
#define ENABLE1_PORT_ID		PORTB_ID
#define ENABLE1_PIN_ID		PIN3_ID

/*******************************************************************************
 *                               Types Declaration                             *
 *******************************************************************************/

typedef enum
{
	STOP,CW,ACW
}DcMotor_State;

/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/

/*
 * Description:
 * Function responsible for initializing the DC motor by setting the direction for
 * the motor pins and stopping the motor at the beginning.
 */
void DcMotor_init(void);

/*
 * Description:
 * Function responsible for Controlling the motor's state (Clockwise/Anti-Clockwise/Stop)
 * and adjusts the speed based on the input duty cycle
 */
void DcMotor_Rotate(DcMotor_State state, uint8 speed);


#endif /* DC_MOTOR_H_ */
