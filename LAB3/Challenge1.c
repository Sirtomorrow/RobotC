#pragma config(Sensor, S1,     touchSensor,    sensorEV3_Touch)
#pragma config(Sensor, S2,     gyroSensor,     sensorEV3_Gyro, modeEV3Gyro_RateAndAngle)
#pragma config(Sensor, S3,     colorSensor,    sensorEV3_Color, modeEV3Color_Color)
#pragma config(Sensor, S4,     sonarSensor,    sensorEV3_Ultrasonic)
#pragma config(Motor,  motorA,          armMotor,      tmotorEV3_Large, PIDControl, encoder)
#pragma config(Motor,  motorB,          leftMotor,     tmotorEV3_Large, PIDControl, driveLeft, encoder)
#pragma config(Motor,  motorC,          rightMotor,    tmotorEV3_Large, PIDControl, driveRight, encoder)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

/*------------------------------------------------------------------------------------------------
  This program will move your robot forward for 2 seconds. At the end of the program, all motors
  will shut down automatically and turn off.

                            ROBOT CONFIGURATION: LEGO EV3 REM Bot
    MOTORS & SENSORS:
    [I/O Port]          [Name]              [Type]                			[Location]
    MotorC        			leftMotor           LEGO EV3 Motor		      Left side motor
    MotorB       				rightMotor          LEGO EV3 Motor		      Right side motor (reversed)
------------------------------------------------------------------------------------------------*/
//
// Using the setMotorSyncTime command in the function moveRobot
//

//Function to drive forward
void drive(long nMotorRatio, long dist, long power)
{
	setMotorSyncEncoder (leftMotor, rightMotor, nMotorRatio, dist, power);
	sleep(1000);
	waitUntilMotorStop (rightMotor);
	waitUntilMotorStop (leftMotor);
} //drive(0, 1000, 50);

//Function to turn right
void turn90(long nMotorRatio, long dist, long power)
{
	setMotorSyncEncoder(leftMotor, rightMotor, nMotorRatio, dist, power );
	sleep(1000);
	waitUntilMotorStop (rightMotor);
	waitUntilMotorStop (leftMotor);
} //turn90(40, 500, 50);



task main()
{
		// setBlockBackButton(true);
	displayCenteredTextLine(1, "Pressed button:");
	// Loop forever
	while (true)
	{
	}
	return;

}
