 #pragma config(Sensor, S1,     touchSensor,    sensorEV3_Touch)
#pragma config(Sensor, S2,     gyroSensor,     sensorEV3_Gyro, modeEV3Gyro_RateAndAngle)
#pragma config(Sensor, S3,     colorSensor,    sensorEV3_Color, modeEV3Color_Reflected)
#pragma config(Sensor, S4,     sonarSensor,    sensorEV3_Ultrasonic)
#pragma config(Motor,  motorA,          armMotor,      tmotorEV3_Large, PIDControl, encoder)
#pragma config(Motor,  motorB,          leftMotor,     tmotorEV3_Large, PIDControl, driveLeft, encoder)
#pragma config(Motor,  motorC,          rightMotor,    tmotorEV3_Large, PIDControl, driveRight, encoder)

void turnright() //turnright program
{
	wait1Msec (1000);
	resetGyro (gyroSensor);
	wait1Msec (2000);
	motor (motorB) = 10;
	motor (motorC) = -10;
	waitUntil(abs(getGyroDegrees(gyroSensor))> 88);

	motor (motorB) = 0;
	motor (motorC) = 0;
	wait1Msec (1000);

}

void turnleft() //turnleft program
{
	wait1Msec (1000);
	resetGyro (gyroSensor);
	wait1Msec (2000);
	motor (motorB) = -10;
	motor (motorC) = 10;
	waitUntil(abs(getGyroDegrees(gyroSensor))> 88);

	motor (motorB) = 0;
	motor (motorC) = 0;
	wait1Msec (1000);

}

task main()
{
	int destx;
	int desty;
	int yoffset;
	int curry;
	int currx;

	destx = 3;
	desty = 7;
	currx = 3;
	curry = 1;


	//turns right
	yoffset = abs(desty - curry);
	turnright ();

	//goes down from y ([3,1] to [3,7])
	for (int i= 1; i<=yoffset; i++)
	{
		setLEDColor (ledGreenFlash);
		setMotorSyncEncoder (leftMotor, rightMotor, 0, 330,	 30);
		waitUntilMotorStop (motorB);
		sleep (500);
	}

	//turns left
	yoffset = abs(curry - desty);
	turnleft ();

}
