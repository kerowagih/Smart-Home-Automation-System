 /******************************************************************************
 *
 * Module: Flame Sensor
 *
 * File Name: flame_sensor.c
 *
 * Description: source file for the Flame Sensor driver
 *
 * Author: Kerollos Wagih
 *
 *******************************************************************************/

/*******************************************************************************
 *                                 INCLUDES                                    *
 *******************************************************************************/

#include "flame_sensor.h"
#include "gpio.h"

/*******************************************************************************
 *                      Functions Definitions                                  *
 *******************************************************************************/

/*
 * Description:
 * Function responsible for initializing the flame sensor pin direction.
 */
void FlameSensor_init(void)
{
	GPIO_setupPinDirection(FLAME_SENSOR_PORT_ID, FLAME_SENSOR_PIN_ID, PIN_INPUT);
}

/*
 * Description:
 * Function responsible for reading the value from the flame sensor and returns it.
 */
uint8 FlameSensor_getValue(void)
{
	uint8 FlameSensor_value = 0;

	/* Reading the value from the flame sensor */
	FlameSensor_value = GPIO_readPin(FLAME_SENSOR_PORT_ID, FLAME_SENSOR_PIN_ID);

	/* Return the flame sensor value */
	return FlameSensor_value;
}
