/*----------------------------------------- INCLUDES ------------------------------------------*/
#include "initialization.h"
#include "lcd.h"
#include "led.h"
#include "buzzer.h"
#include "dc_motor.h"
#include "flame_sensor.h"
#include "lm35_sensor.h"
#include "ldr_sensor.h"

int main(void){
	/*-------------------------------- Application Initialization -----------------------------*/

	/* Initialize all modules */
	AllModules_init();

	/* variables definitions */
	uint8 temperature = 0;
	uint8 light_intensity = 0;
	uint8 FlameSensor_value = 0;

	/* Display on LCD */
	LCD_moveCursor(1,0);
	LCD_displayString("Temp=   ");
	LCD_moveCursor(1,8);
	LCD_displayString("LDR=   %");

	while(1){	/*------------------------- Infinite loop --------------------------------*/

		/*--------------------------------- Application Code ----------------------------------*/

		/*---------------------------- Automatic Lighting Control -----------------------------*/

		/* Get light intensity value */
		light_intensity = LDR_getLightIntensity();

		if (light_intensity <= 15)
		{
			/* Intensity < 15%: All 3 LEDs (Red, Green, and Blue) turn ON */
			LED_on(RED);
			LED_on(GREEN);
			LED_on(BLUE);
		}
		else if (light_intensity <= 50)
		{
			/* Intensity 16–50%: Red and Green LEDs turn ON */
			LED_on(RED);
			LED_on(GREEN);
			LED_off(BLUE);
		}
		else if (light_intensity <= 70)
		{
			/* Intensity 51–70%: Only the Red LED turns ON */
			LED_on(RED);
			LED_off(GREEN);
			LED_off(BLUE);
		}
		else if (light_intensity <= 100)
		{
			/* Intensity > 70%: All LEDs are turned OFF */
			LED_off(RED);
			LED_off(GREEN);
			LED_off(BLUE);
		}

		/*---------- Display the light intensity on LCD ----------*/

		LCD_moveCursor(1,12);
		if (light_intensity == 100)
		{
			LCD_intgerToString(light_intensity);
		}
		else
		{
			LCD_intgerToString(light_intensity);
			LCD_displayCharacter(' ');
		}

		/*---------------------------- Automatic Fan Speed Control ----------------------------*/

		/* Get the temperature value */
		temperature = LM35_getTemperature();

		if (temperature >= 40)
		{
			/* Temperature ≥ 40°C: Fan ON at 100% speed */
			DcMotor_Rotate(CW,100);
			LCD_moveCursor(0,4);
			LCD_displayString("FAN is ON");
			LCD_displayCharacter(' ');
		}
		else if (temperature >= 35)
		{
			/* Temperature ≥ 35°C and < 40°C: Fan ON at 75% speed */
			DcMotor_Rotate(CW,75);
			LCD_moveCursor(0,4);
			LCD_displayString("FAN is ON");
			LCD_displayCharacter(' ');
		}
		else if (temperature >= 30)
		{
			/* Temperature ≥ 30°C and < 35°C: Fan ON at 50% speed */
			DcMotor_Rotate(CW,50);
			LCD_moveCursor(0,4);
			LCD_displayString("FAN is ON");
			LCD_displayCharacter(' ');
		}
		else if (temperature >= 25)
		{
			/* Temperature ≥ 25°C and < 30°C: Fan ON at 25% speed */
			DcMotor_Rotate(CW,25);
			LCD_moveCursor(0,4);
			LCD_displayString("FAN is ON");
			LCD_displayCharacter(' ');
		}
		else
		{
			/* Temperature < 25°C: Fan OFF */
			DcMotor_Rotate(STOP,0);
			LCD_moveCursor(0,4);
			LCD_displayString("FAN is OFF");
		}

		/*---------- Display the temperature on LCD ----------*/

		LCD_moveCursor(1,5);
		if (temperature >= 100)
		{
			LCD_intgerToString(temperature);
		}
		else
		{
			LCD_intgerToString(temperature);
			LCD_displayCharacter(' ');
		}

		/*----------------------------- Fire Detection and Alert ------------------------------*/

		/* Get the flame sensor value */
		FlameSensor_value = FlameSensor_getValue();

		if (FlameSensor_value == LOGIC_HIGH)
		{
			/* Fire is detected */
			/* The system raises an alarm and displays "Critical alert!" on the LCD */
			Buzzer_on();
			LCD_clearScreen();
			LCD_moveCursor(0,0);
			LCD_displayString("Critical Alert!");

			/* Polling */
			/* The system remains in alert mode until the flame is no longer detected */
			while (FlameSensor_value == LOGIC_HIGH)
			{
				FlameSensor_value = FlameSensor_getValue();
			}

			/* The flame is no longer detected */
			Buzzer_off();
			LCD_clearScreen();
			LCD_moveCursor(1,0);
			LCD_displayString("Temp=   ");
			LCD_moveCursor(1,8);
			LCD_displayString("LDR=   %");
		}
		else if (FlameSensor_value == LOGIC_LOW)
		{
			/* No fire is detected */
			/* Do nothing */
		}
	}
	/*----------------------------- End of Application Code ------------------------------*/
	return LOGIC_LOW;
}
/*----------------------------- End of main function ------------------------------*/
