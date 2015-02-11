#pragma config(Hubs,  S1, HTMotor,  HTServo,  none,     none)
#pragma config(Sensor, S2,     IRsensor,       sensorHiTechnicIRSeeker1200)
#pragma config(Sensor, S3,     Eyes,           sensorSONAR)
#pragma config(Motor,  mtr_S1_C1_1,     motorL,        tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C1_2,     motorR,        tmotorTetrix, openLoop, reversed)
#pragma config(Servo,  srvo_S1_C2_1,    servo1,               tServoNone)
#pragma config(Servo,  srvo_S1_C2_2,    servo2,               tServoNone)
#pragma config(Servo,  srvo_S1_C2_3,    servo3,               tServoNone)
#pragma config(Servo,  srvo_S1_C2_4,    servo4,               tServoNone)
#pragma config(Servo,  srvo_S1_C2_5,    servo5,               tServoNone)
#pragma config(Servo,  srvo_S1_C2_6,    servo6,               tServoNone)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

#include "JoystickDriver.c" //Adds the Joystick header file

task main()
{

	while (SensorValue[IRsensor] !=5)// Check if sensor is = to 5
	{
		if (SensorValue[IRsensor] > 5)
		{
			//turn right
			motor[motorL] = -15;
			motor[motorR] =  15;
		}
		else
		{
			//turn left
			motor[motorL] =  15;
			motor[motorR] = -15;
		}

	}

	servo[servo1] = 0;
	wait1Msec(1000);

	while (true) //The program will run forever, or until it is stopped manually
	{
		getJoystickSettings(joystick); //Retrieve joystick values
		if ((joystick.joy1_y1 >= 8) || (joystick.joy1_y1 <= -8)) //A boolean if statement that works as a deadband
		{
			motor[motorR] = joystick.joy1_y1;
		}
		else
		{
			motor[motorR] = 0;
		}
		if ((joystick.joy1_y2 >= 8) || (joystick.joy1_y2 <= -8))
		{
			motor[motorL] = joystick.joy1_y2;
		}
		else
		{
			motor[motorL] = 0;
		}
		if (joy1Btn(1) == 1) // If Joystick 1 Button 1 is pressed do the following:
		{
			servo[servo1] = servo[servo1] + 5; // Take servo posision value and add 1 to it
			wait1Msec(200);
		}

		if (joy1Btn(2) == 1) // If Joystick 1 Button 2 is pressed do the following:
		{
			servo[servo1] = servo[servo1] - 5; // Take servo position and subtract 1 from it
			wait1Msec(200);
		}
	}


}
