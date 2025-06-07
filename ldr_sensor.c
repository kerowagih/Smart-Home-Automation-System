 /******************************************************************************
 *
 * Module: LDR Sensor
 *
 * File Name: ldr_sensor.c
 *
 * Description: source file for the LDR Sensor driver
 *
 * Author: Kerollos Wagih
 *
 *******************************************************************************/

/*******************************************************************************
 *                                 INCLUDES                                    *
 *******************************************************************************/

#include "ldr_sensor.h"
#include "adc.h"

/*******************************************************************************
 *                      Functions Definitions                                   *
 *******************************************************************************/

/*
 * Description:
 * Function responsible for calculate the light intensity from the ADC digital value.
 */
uint8 LDR_getLightIntensity(void)
{
	uint8 light_intensity = 0;

	uint16 adc_value = 0;

	/* Read ADC channel where the LDR sensor is connected */
	adc_value = ADC_readChannel(LDR_SENSOR_CHANNEL_ID);

	/* Calculate the light intensity from the ADC value*/
	light_intensity = (uint8)(((uint32)adc_value*LDR_SENSOR_MAX_LIGHT_INTENSITY*ADC_REF_VOLT_VALUE)/(ADC_MAXIMUM_VALUE*LDR_SENSOR_MAX_VOLT_VALUE));

	return light_intensity;
}
