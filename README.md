# Smart-Home-Automation-System
Project Title:
Smart Home Automation Using ATmega32, LCD, Temperature Sensor, LDR Sensor, Flame Sensor and Motor Control.

Objective:
Design and implement a smart home system that automates the control of lighting and fan speed based on environmental conditions. The project uses an ATmega32 microcontroller, LM35 temperature sensor, LDR (Light Dependent Resistor), Flame sensor, and a PWM-controlled motor. An LCD provides real-time display, and an H-bridge circuit controls the fan motor. Additionally, LEDs indicate varying light intensity levels.

Project Overview:
This project involves developing a smart home system that adjusts lighting, fan speed, and safety alerts based on environmental conditions:
1. Lighting Control: The LDR detects ambient light intensity and controls three LEDs to indicate different levels of light.
2. Fan Speed Control: The LM35 temperature sensor adjusts the fan speed proportionally to the room temperature.
3. Fire Detection: A flame sensor detects fire, triggers an alarm, and displays a critical alert on the LCD.
4. LCD Display: Shows real-time temperature readings, fan status, light intensity, and alerts.

Features:
• Automatic Lighting Control:
  Based on the LDR readings, the system controls three LEDs according to light intensity thresholds:
   Intensity < 15%: All 3 LEDs (Red, Green, and Blue) turn ON.
   Intensity 16–50%: Red and Green LEDs turn ON.
   Intensity 51–70%: Only the Red LED turns ON.
   Intensity > 70%: All LEDs are turned OFF.

• Automatic Fan Speed Control:
  Fan speed is automatically adjusted based on room temperature, controlled by a PWM signal. The fan operates at different speeds based on temperature ranges:
   Temperature ≥ 40°C: Fan ON at 100% speed.
   Temperature ≥ 35°C and < 40°C: Fan ON at 75% speed.
   Temperature ≥ 30°C and < 35°C: Fan ON at 50% speed.
   Temperature ≥ 25°C and < 30°C: Fan ON at 25% speed.
  Temperature < 25°C: Fan OFF.
  
• Fire Detection and Alert:
The system raises an alarm and displays "Critical alert!" on the LCD if fire is detected. The system remains in alert mode until the flame is no longer detected.

• LCD Display:
  Real-time feedback on system status:
   First Row: Displays "FAN is ON" or "FAN is OFF" based on the fan's state.
   Second Row: Displays "Temp= xxC LDR= xxx%" showing temperature and light intensity.

Operation Description:
• Lighting Control (LDR):
  The LDR monitors light intensity, and the three LEDs are controlled based on the previous mentioned thresholds.
• Temperature Control (LM35):
  The LM35 sensor measures room temperature. The fan speed is controlled using a PWM signal adjusting speed according to temperature ranges specified above.
• Fire Detection:
  The flame sensor triggers an alert when fire is detected:
   Displays "Critical alert!" on the LCD.
   Activates the buzzer.
   The system stays in alert mode until the flame sensor no longer detects fire.
• LCD Display:
  First Row: Indicates the fan status ("FAN is ON" or "FAN is OFF").
  Second Row: Displays temperature ("Temp= xxx") and light intensity ("LDR= xx%").
