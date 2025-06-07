 /******************************************************************************
 *
 * Module: Flame Sensor
 *
 * File Name: flame_sensor.h
 *
 * Description: header file for the Flame Sensor driver
 *
 * Author: Kerollos Wagih
 *
 *******************************************************************************/

#ifndef FLAME_SENSOR_H_
#define FLAME_SENSOR_H_

/*******************************************************************************
 *                                 INCLUDES                                    *
 *******************************************************************************/

#include "std_types.h"

/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/

/* Configure Flame sensor (port and pin) */
#define FLAME_SENSOR_PORT_ID	PORTD_ID
#define FLAME_SENSOR_PIN_ID		PIN2_ID

/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/

/*
 * Description:
 * Function responsible for initializing the flame sensor pin direction.
 */
void FlameSensor_init(void);

/*
 * Description:
 * Function responsible for reading the value from the flame sensor and returns it.
 */
uint8 FlameSensor_getValue(void);

#endif /* FLAME_SENSOR_H_ */
