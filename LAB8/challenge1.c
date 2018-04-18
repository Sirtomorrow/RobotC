#pragma config(Sensor, S1,     touchSensor,    sensorEV3_Touch)
#pragma config(Sensor, S2,     gyroSensor,     sensorEV3_Gyro, modeEV3Gyro_RateAndAngle)
#pragma config(Sensor, S3,     colorSensor,    sensorEV3_Color, modeEV3Color_Reflected)
#pragma config(Sensor, S4,     sonarSensor,    sensorEV3_Ultrasonic)
#pragma config(Motor,  motorA,          armMotor,      tmotorEV3_Large, PIDControl, encoder)
#pragma config(Motor,  motorB,          leftMotor,     tmotorEV3_Large, PIDControl, driveLeft, encoder)
#pragma config(Motor,  motorC,          rightMotor,    tmotorEV3_Large, PIDControl, driveRight, encoder)

int selectDestination () //select the destination of the user
{
	int val = 1;
	displayCenteredBigTextLine(2, "Select start");

	while (getButtonPress(buttonEnter) == 0)
	{
		if (getButtonPress(buttonUp))
		{
			val = 1;
			displayCenteredBigTextLine(2, "Start is 1, 1");
		}

		if (getButtonPress(buttonDown))
		{
			val = 2;
			displayCenteredBigTextLine(2, "Start is 5, 5");
		}

		if (getButtonPress(buttonLeft))
		{
			val = 3;
			displayCenteredBigTextLine(2, "Start is 6, 6");
		}

		if (getButtonPress(buttonRight))
		{
			val = 4;
			displayCenteredBigTextLine(2, "Start is 1, 6");
		}

		wait1Msec(300);

		} //end while

	return val;
} //end main

void turnright() //turnright program
{
	wait1Msec (500);
	resetGyro (gyroSensor);
	wait1Msec (2000);
	motor (motorB) = 10;
	motor (motorC) = -10;
	waitUntil(abs(getGyroDegrees(gyroSensor))> 88);

	motor (motorB) = 0;
	motor (motorC) = 0;
	wait1Msec (500);

} //end turnright()

void turnleft() //turnright program
{
	wait1Msec (500);
	resetGyro (gyroSensor);
	wait1Msec (2000);
	motor (motorB) = -10;
	motor (motorC) = 10;
	waitUntil(abs(getGyroDegrees(gyroSensor))> 88);

	motor (motorB) = 0;
	motor (motorC) = 0;
	wait1Msec (500);


} //end turnleft()

task main()
{
	int dest;
	int destx;
	int desty;
	int yoffset;
	int xoffset;
	int curry;
	int currx;

	destx = 5;
	desty = 5;
	dest = selectDestination();

	//Start position 1,1
	if (dest == 1)
	{
		curry = 1;
		currx = 1;

		yoffset = desty - curry;
		turnright ();

		for (int i=0; i<yoffset; i++)
		{
			setLEDColor (ledGreenFlash);
			setMotorSyncEncoder (leftMotor, rightMotor, 0, 320,	 10);
			waitUntilMotorStop (motorB);
			displayCenteredBigTextLine (2, "X=%d, Y=%d", currx, i+1);
			sleep (500);
		}

		xoffset = destx - currx;
		turnleft ();


		for (int i=0; i<xoffset; i++)
		{
			setLEDColor (ledGreenFlash);
			setMotorSyncEncoder (leftMotor, rightMotor, 0, 320,	 10);
			waitUntilMotorStop (motorB);
			displayCenteredBigTextLine (2, "X=%d, Y=%d", i+2, curry);
			sleep (500);
		}
			playSound(soundBeepBeep);

	} //end if

	//Start position 5,5
	if (dest == 2)
	{
		curry = 5;
		currx = 5;

		playSound(soundBeepBeep);
		sleep(500);

	} //end if

	//Start position 6,6
	if (dest == 3)
	{
		curry = 6;
		currx = 6;
		destx = 5;
		desty = 5;

		yoffset = abs(desty - curry);
		turnleft ();

		for (int i=0; i<yoffset; i++)
		{
			setLEDColor (ledGreenFlash);
			setMotorSyncEncoder (leftMotor, rightMotor, 0, 320,	 10);
			waitUntilMotorStop (motorB);
			displayCenteredBigTextLine (2, "X=%d, Y=%d", currx, i+1);
			sleep (500);
		}

		turnleft ();
		xoffset = currx - destx;

		for (int i=0; i<xoffset; i++)
		{
			setLEDColor (ledGreenFlash);
			setMotorSyncEncoder (leftMotor, rightMotor, 0, 320,	 10);
			waitUntilMotorStop (motorB);
			displayCenteredBigTextLine (2, "X=%d, Y=%d", currx, i+1);
			sleep (500);
		}

	} //end if

	//Start position 1,6
	if (dest == 4)
	{
		curry = 6;
		currx = 1;
		destx = 5;
		desty = 5;

		xoffset = abs(destx - currx);

		for (int i=0; i<xoffset; i++)
		{
			setLEDColor (ledGreenFlash);
			setMotorSyncEncoder (leftMotor, rightMotor, 0, 320,	 10);
			waitUntilMotorStop (motorB);
			sleep (500);
		}

		yoffset = abs(desty - curry);
		turnleft ();

		for (int i=0; i<yoffset; i++)
		{
			setLEDColor (ledGreenFlash);
			setMotorSyncEncoder (leftMotor, rightMotor, 0, 320,	 10);
			waitUntilMotorStop (motorB);
			sleep (500);
		}

		playSound(soundBeepBeep);

	} //end if



} //end main()
