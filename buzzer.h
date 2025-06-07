/******************************************************************************
 *
 * Module: Buzzer
 *
 * File Name: buzzer.h
 *
 * Description: header file for the Buzzer driver
 *
 * Author: Kerollos Wagih
 *
 *******************************************************************************/

#ifndef BUZZER_H_
#define BUZZER_H_

/*******************************************************************************
 *                                 INCLUDES                                    *
 *******************************************************************************/

#include "std_types.h"

/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/

/* Configure Buzzer (port and pin) */
#define BUZZER_PORT_ID		PORTD_ID
#define BUZZER_PIN_ID		PIN3_ID

/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/

/*
 * Description:
 * Function responsible for initializing the buzzer pin direction and turn off the buzzer.
 */
void Buzzer_init(void);

/*
 * Description:
 * Function responsible for activating the buzzer.
 */
void Buzzer_on(void);

/*
 * Description:
 * Function responsible for deactivating the buzzer.
 */
void Buzzer_off(void);

#endif /* BUZZER_H_ */
