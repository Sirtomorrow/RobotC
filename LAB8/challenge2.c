#pragma config(Sensor, S1,     touchSensor,    sensorEV3_Touch)
#pragma config(Sensor, S2,     gyroSensor,     sensorEV3_Gyro, modeEV3Gyro_RateAndAngle)
#pragma config(Sensor, S3,     colorSensor,    sensorEV3_Color, modeEV3Color_Reflected)
#pragma config(Sensor, S4,     sonarSensor,    sensorEV3_Ultrasonic)
#pragma config(Motor,  motorA,          armMotor,      tmotorEV3_Large, PIDControl, encoder)
#pragma config(Motor,  motorB,          leftMotor,     tmotorEV3_Large, PIDControl, driveLeft, encoder)
#pragma config(Motor,  motorC,          rightMotor,    tmotorEV3_Large, PIDControl, driveRight, encoder)

int selectStarting () //select the destination of the user
{
	int val = 1;
	displayCenteredBigTextLine(2, "Select start");

	while (getButtonPress(buttonEnter) == 0)
	{
		if (getButtonPress(buttonUp))
		{
			val = 1;
			displayCenteredBigTextLine(2, "Dest is 1, 1");
		}

		if (getButtonPress(buttonDown))
		{
			val = 2;
			displayCenteredBigTextLine(2, "Dest is 5, 5");
		}

		if (getButtonPress(buttonLeft))
		{
			val = 3;
			displayCenteredBigTextLine(2, "Dest is 6, 6");
		}

		if (getButtonPress(buttonRight))
		{
			val = 4;
			displayCenteredBigTextLine(2, "Dest is 1, 6");
		}

		wait1Msec(300);

		} //end while

	return val;

} //end selectStarting

int selectDestination () //select the destination of the user
{
	int val = 1;
	displayCenteredBigTextLine(2, "Select dest");

	while (getButtonPress(buttonEnter) == 0)
	{
		if (getButtonPress(buttonUp))
		{
			val = 1;
			displayCenteredBigTextLine(2, "Dest is 1, 1");
		}

		if (getButtonPress(buttonDown))
		{
			val = 2;
			displayCenteredBigTextLine(2, "Dest is 5, 5");
		}

		if (getButtonPress(buttonLeft))
		{
			val = 3;
			displayCenteredBigTextLine(2, "Dest is 7, 1");
		}

		if (getButtonPress(buttonRight))
		{
			val = 4;
			displayCenteredBigTextLine(2, "Dest is 1, 6");
		}

		wait1Msec(300);

		} //end while

	return val;

} //end selectDestination

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
	int startp;

	startp = selectStarting();
	dest = selectDestination();

	if(startp == 1) // [1,1] as starting function
	{


	if(startp == 2) // [5,5] as starting function

	if(startp == 3) // [6,6] as starting function

	if(startp == 4) // [1,6] as starting function

	if(dest == 1) // [1,1] as starting function

	if(dest == 2) // [5,5] as starting function

	if(dest == 3) // [7,1] as starting function

	if(dest == 4) // [1,6] as starting function

} //end main()
