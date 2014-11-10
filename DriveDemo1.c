#pragma config(Hubs,  S1, HTMotor,  HTServo,  none,     none)
#pragma config(Sensor, S1,     ,               sensorI2CMuxController)
#pragma config(Motor,  mtr_S1_C1_1,     DriveLt,       tmotorTetrix, PIDControl)
#pragma config(Motor,  mtr_S1_C1_2,     DriveRt,       tmotorTetrix, PIDControl, reversed)
#pragma config(Servo,  srvo_S1_C2_1,    claw,                 tServoStandard)
#pragma config(Servo,  srvo_S1_C2_2,    servo2,               tServoNone)
#pragma config(Servo,  srvo_S1_C2_3,    servo3,               tServoNone)
#pragma config(Servo,  srvo_S1_C2_4,    servo4,               tServoNone)
#pragma config(Servo,  srvo_S1_C2_5,    servo5,               tServoNone)
#pragma config(Servo,  srvo_S1_C2_6,    servo6,               tServoNone)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

#pragma DebuggerWindows("joystickGame");

short sm=1;

#include "JoystickDriver.c"
task main()
{
	while(true){
		getJoystickSettings(joystick);


		motor[DriveLt]=joystick.joy1_y1-joystick.joy1_x2;
		motor[DriveRt]=joystick.joy1_y1+joystick.joy1_x2;
		if(joystick.joy2_Buttons == 02)// if Button 6 is pressed on joy2:
	  {
	    servo[claw]=200;            // motorA is run at a power level of 50
	  } else {
			servo[claw]=255;
		}

		switch(sm){
			case 1:
			servo[claw]=255

			case 2:
			servo[claw]=200
			break;
		}



		wait1Msec(20);
	}
}
