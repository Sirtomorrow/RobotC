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
	waitUntil(abs(getGyroDegrees(gyroSensor))> 86);

	motor (motorB) = 0;
	motor (motorC) = 0;
	wait1Msec (1000);

}

void turnleft() //turnright program
{
	wait1Msec (1000);
	resetGyro (gyroSensor);
	wait1Msec (2000);
	motor (motorB) = -10;
	motor (motorC) = 10;
	waitUntil(abs(getGyroDegrees(gyroSensor))> 86);

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

	//display starting point
	displayCenteredBigTextLine (2, "X=%d, Y=%d", currx, curry);

	//turns right
	yoffset = desty - curry;
	turnright ();

	//goes down from y ([3,1] to [3,7])
	for (int i= 1; i<=yoffset; i++)
	{
		setLEDColor (ledGreenFlash);
		setMotorSyncEncoder (leftMotor, rightMotor, 0, 330,	 30);
		waitUntilMotorStop (motorB);
		displayCenteredBigTextLine (2, "X=%d, Y=%d", currx, i+1);
		sleep (500);

		if (i == 7)
		{
			curry = 7;
		}
	}

	//turns left
	yoffset = curry - desty;
	turnleft ();

	//wait for 5 seconds and beep
	waitUntilMotorStop (motorB);
	waitUntilMotorStop (motorC);
	//insert annoying sound here
	sleep (500);

	//turn 180
	yoffset = desty - curry;
	turnright ();
	turnright ();

	//new destination set to [1,1]
	destx = 1;
	desty = 1;

	//go forward 2 squares
	for (int i= 0; i<=2; i++)
	{
		setLEDColor (ledGreenFlash);
		setMotorSyncEncoder (leftMotor, rightMotor, 0, 330,	 30);
		waitUntilMotorStop (motorB);
		displayCenteredBigTextLine (2, "X=%d, Y=%d", currx-i, curry);
		sleep (500);

		if (i == desty)
		{
			curry = desty;
		}
	}

	//turn right
	turnright ();

	//goes from y ([1,7] to [1,1])
	for (int i=0; i<=7; i++)
	{
		setLEDColor (ledGreenFlash);
		setMotorSyncEncoder (leftMotor, rightMotor, 0, 330,	 30);
		waitUntilMotorStop (motorB);
		displayCenteredBigTextLine (2, "X=%d, Y=%d", currx, curry-i);
		sleep (500);
	}
}
