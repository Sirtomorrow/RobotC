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
	displayCenteredBigTextLine(2, "Select Dest");
	displayCenteredBigTextLine(6, "Press Enter to choose");
	while (getButtonPress(buttonEnter) == 0)
	{
		if (getButtonPress(buttonUp))
		{
			val = 1;
			displayCenteredBigTextLine (2 , "Dest is 4, 1");
		}

		if (getButtonPress(buttonDown))
		{
			val = 0;
			displayCenteredBigTextLine (2, "Dest is 5, 6");
		}

		wait1Msec(300);

	}

	return val;
}

void driveXforward (int squares) //drive forward
{
	displayCenteredBigTextLine (2, "X=1, Y=4");
	for (int i = 1; i <= squares; i++)
	{
		setLEDColor (ledGreenFlash);
		setMotorSyncEncoder (leftMotor, rightMotor, 0, 320, 10);
		waitUntilMotorStop (motorB);
		displayCenteredBigTextLine (2, "X=%d, Y=4", i+1);
		sleep (500);
	}
}

void turnright(int x, int y) //turnright program
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
	displayCenteredBigTextLine (2, "X=%d, Y=4", x);

}

void turnleft(int x, int y) //turnright program
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
	displayCenteredBigTextLine (2, "X=%d, Y=4", x);

}

task main()
{
	int dest = selectDestination(); //choose destination
	int x;
	int y;
	int xoffset;
	int yoffset;

	if (dest == 1)
	{
		x = 4;
		y = 1;
	}
	else
	{
		x = 5;
		y = 6;

	}

	setLEDColor(ledGreenFlash);
	xoffset	 = x - 1; //number of squares to move forward
	driveXforward (xoffset); //distance in squares to drive forward

	if (y > 4)
	{
		yoffset = y - 4;
		turnright (x, yoffset);
	}
	else if (y < 4)
	{
		yoffset = 4 - y;
		turnleft (x, yoffset);
	}

	for (int i=0; i<yoffset; i++)
	{
		setLEDColor (ledGreenFlash);
		setMotorSyncEncoder (leftMotor, rightMotor, 0, 320,	 10);
		waitUntilMotorStop (motorB);
		displayCenteredBigTextLine (2, "X=%d, Y=%d", x, i+1);
		sleep (500);

	}

}
