 /******************************************************************************
 *
 * Module: PWM
 *
 * File Name: pwm.h
 *
 * Description: header file for the ATmega32 PWM driver
 *
 * Author: Kerollos Wagih
 *
 *******************************************************************************/

#ifndef PWM_H_
#define PWM_H_

/*******************************************************************************
 *                                 INCLUDES                                    *
 *******************************************************************************/

#include "std_types.h"

/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/

#define PWM_TIMER0_MAX_COUNT_VALUE	255

/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/

/*
 * Description:
 * function responsible for:
 * 1. initializing Timer0 in PWM mode and sets the required duty cycle.
 * 2. Prescaler: F_CPU/1024.
 * 3. Non-inverting mode.
 * 4. The function configures OC0 as the output pin.
 * Parameters:
 * duty_cycle -> Percentage (0 to 100%) representing the PWM duty cycle.
 */
void PWM_Timer0_Start(uint8 duty_cycle);


#endif /* PWM_H_ */
