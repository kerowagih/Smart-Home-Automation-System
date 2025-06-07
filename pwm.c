 /******************************************************************************
 *
 * Module: PWM
 *
 * File Name: pwm.c
 *
 * Description: Source file for the ATmega32 PWM driver
 *
 * Author: Kerollos Wagih
 *
 *******************************************************************************/

/*******************************************************************************
 *                                 INCLUDES                                    *
 *******************************************************************************/

#include "pwm.h"
#include "gpio.h"
#include "common_macros.h"
#include <avr\io.h>


/*******************************************************************************
 *                      Functions Definitions                                  *
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
void PWM_Timer0_Start(uint8 duty_cycle){

	/*
	 * Timer/Counter Control Register – TCCR0 Bits Description:
	 * Bit 7 – FOC0 = 0 -> PWM mode
	 * Bit 6,3 – WGM01:0 = 11 -> Fast PWM mode
	 * Bit 5:4 – COM01:0 = 10 -> Non-inverting mode
	 * Bit 2:0 – CS02:0 = 101 -> Prescaler: F_CPU/1024
	 */
	TCCR0 = (1<<WGM01) | (1<<WGM00) | (1<<COM01) | (1<<CS02) | (1<<CS00);

	/*
	 * Timer/Counter Register – TCNT0:
	 * initial value = 0
	 */
	TCNT0 = 0;

	/*
	 * Output Compare Register – OCR0:
	 * generate a PWM signal with certain duty cycle using input parameter duty_cycle.
	 */
	OCR0 = ((duty_cycle/100.0) * PWM_TIMER0_MAX_COUNT_VALUE);

	/*
	 * Timer/Counter Interrupt Mask Register – TIMSK Bits Description:
	 * Bit 1 – OCIE0 = 0 -> Disable output Compare Match Interrupt
	 * Bit 0 – TOIE0 = 0 -> Disable overflow Interrupt
	 */
	CLEAR_BIT(TIMSK,OCIE0);
	CLEAR_BIT(TIMSK,TOIE0);

	/*
	 * Configure PB3(OC0) as the output pin
	 */
	GPIO_setupPinDirection(PORTB_ID, PIN3_ID, PIN_OUTPUT);
}
