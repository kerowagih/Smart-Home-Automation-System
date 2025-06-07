 /******************************************************************************
 *
 * File Name: initialization.c
 *
 * Description: Source file for the initialization driver
 *
 * Author: Kerollos Wagih
 *
 *******************************************************************************/

/*******************************************************************************
 *                                 INCLUDES                                    *
 *******************************************************************************/

#include "initialization.h"
#include "adc.h"
#include "lcd.h"
#include "led.h"
#include "buzzer.h"
#include "dc_motor.h"
#include "flame_sensor.h"

/*******************************************************************************
 *                      Functions Definitions                                  *
 *******************************************************************************/

/*
 * Description:
 * Function responsible for initializing all modules
 */
void AllModules_init(void)
{
	/* Initialize ADC Module */
	ADC_init();

	/* Initialize LCD Module */
	LCD_init();

	/* Initialize LEDS Module */
	LEDS_init();

	/* Initialize Buzzer Module */
	Buzzer_init();

	/* Initialize DC Motor Module */
	DcMotor_init();

	/* Initialize Flame Sensor Module */
	FlameSensor_init();
}
