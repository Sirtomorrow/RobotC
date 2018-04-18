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
	displayCenteredBigTextLine(2, "Dest: 3, 1");
	wait1Msec(300);


	return val;
}

void turnright(int x, int y) //turnright program
{
	wait1Msec (1000);
	resetGyro (gyroSensor);
	wait1Msec (2000);
	motor (motorB) = 10;
	motor (motorC) = -10;
	waitUntil(abs(getGyroDegrees(gyroSensor))> 90);

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
	waitUntil(abs(getGyroDegrees(gyroSensor))> 90);

	motor (motorB) = 0;
	motor (motorC) = 0;
	wait1Msec (1000);
	displayCenteredBigTextLine (2, "X=%d, Y=4", x);

}

task main()
{
	int dest; //choose destination
	int destx;
	int desty;
	int yoffset;
	int curry;
	int currx;

	dest = selectDestination();
	destx = 3;
	desty = 7;
	currx = 3;
	curry = 1;

	yoffset = desty - curry;
	turnright (destx, yoffset);


	for (int i=0; i<yoffset; i++)
	{
		setLEDColor (ledGreenFlash);
		setMotorSyncEncoder (leftMotor, rightMotor, 0, 320,	 10);
		waitUntilMotorStop (motorB);
		displayCenteredBigTextLine (2, "X=%d, Y=%d", destx, i+1);
		sleep (500);
	}

	yoffset = curry - desty;
	turnleft (destx, yoffset);

}
