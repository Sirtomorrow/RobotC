#pragma config(Sensor, S1,     touchSensor,    sensorEV3_Touch)
#pragma config(Sensor, S2,     gyroSensor,     sensorEV3_Gyro, modeEV3Gyro_RateAndAngle)
#pragma config(Sensor, S3,     colorSensor,    sensorEV3_Color, modeEV3Color_Reflected)
#pragma config(Sensor, S4,     sonarSensor,    sensorEV3_Ultrasonic)
#pragma config(Motor,  motorA,          armMotor,      tmotorEV3_Large, PIDControl, encoder)
#pragma config(Motor,  motorB,          leftMotor,     tmotorEV3_Large, PIDControl, driveLeft, encoder)
#pragma config(Motor,  motorC,          rightMotor,    tmotorEV3_Large, PIDControl, driveRight, encoder)

int selectPosition () //select the starting point of the user
{
	int val = 1;
	displayCenteredBigTextLine(2, "Select start");

	while (getButtonPress(buttonEnter) == 0) //while enter is not pressed
	{
		if (getButtonPress(buttonUp))
		{
			val = 1;
			displayCenteredBigTextLine(2, "Start is 1, 1");
			displayCenteredBigTextLine(2, "Dest is 5, 5");
		}

		if (getButtonPress(buttonDown))
		{
			val = 2;
			displayCenteredBigTextLine(2, "Start is 5, 5");
			displayCenteredBigTextLine(2, "Dest is 1, 1");
		}

		if (getButtonPress(buttonLeft))
		{
			val = 3;
			displayCenteredBigTextLine(2, "Start is 6, 6");
			displayCenteredBigTextLine(2, "Dest is 1, 6");
		}

		if (getButtonPress(buttonRight))
		{
			val = 4;
			displayCenteredBigTextLine(2, "Start is 1, 6");
			displayCenteredBigTextLine(2, "Dest is 7, 1");
		}

		wait1Msec(300);

		} //end while

	return val;

} //end selectPosition


void turnright() //turn right
{
	wait1Msec (500);
	resetGyro (gyroSensor);
	wait1Msec (2000);
	motor (motorB) = 10;
	motor (motorC) = -10;
	waitUntil(abs(getGyroDegrees(gyroSensor))> 86);

	motor (motorB) = 0;
	motor (motorC) = 0;
	wait1Msec (500);

} //end turnright()

void turnleft() //turn left
{
	wait1Msec (500);
	resetGyro (gyroSensor);
	wait1Msec (2000);
	motor (motorB) = -10;
	motor (motorC) = 10;
	waitUntil(abs(getGyroDegrees(gyroSensor))> 86);

	motor (motorB) = 0;
	motor (motorC) = 0;
	wait1Msec (500);


} //end turnleft()

void drive (int squares, void detectObject) //drive forward
{
		for (int i=0; i<squares; i++) //forward by amount of squares
		{
				if(SensorValue[sonarSensor]<25)
				{
					detectObject();
				}

			setMotorSyncEncoder (leftMotor, rightMotor, 0, 320,	 10);
			waitUntilMotorStop (motorB);
			sleep (500);
		} //end for()

} //end drive()

void detectObject (int currp, int destp, int offset)
{
	if (currp > destp)
	{
		//go around object
		turnleft ();
		drive (1);
		turnright ();
		drive (2);
		turnright ();
		drive (1);
		turnleft();

		//cover up the remaining offset
		offset = offset - 2;
		drive (offset);

	}
	else
	{
		//go around object
		turnright ();
		drive (1);
		turnleft ();
		drive (2);
		turnleft ();
		drive (1);
		turnright ();

		//cover up the remaining offset
		offset = offset - 2;
		drive (offset);
	}

} //end detectObject()

task main()
{
	int position;
	int destx;
	int desty;
	int yoffset; //y distance between starting point and destination
	int xoffset; //x distance between starting point and destination
	int curry;
	int currx;

	position = selectPosition();

	if (position == 1) // [1,1] start, [5,5] destination
	{
		currx = 1;
		curry = 1;
		destx = 5;
		desty = 5;

		yoffset = abs(desty - curry); //find the y offset
		xoffset = abs(destx - currx); //find the x offset

		if (curry > desty) //if the current y is more than the destination y, turn left
		{
			turnleft();
			drive (yoffset);
			detectObject(currx, destx, yoffset);


		} //end if()
		else //if the current y is less than the destination x, turn right
		{
			turnright();
			drive (yoffset);
			detectObject(currx, destx, yoffset);

		} //end else()

		if (currx > destx) //if the current x is more than the destination x, turn left
		{
			turnright();
			drive (xoffset);
			detectObject(curry, desty, xoffset);

		}
		else //if the current x is less than the destination x, turn left
		{
			turnleft();
			drive (xoffset);
			detectObject(curry, desty, xoffset);

		}


	} //end postion1

	if (position == 2) // [5,5] start, [1,1] destination
	{
		currx = 5;
		curry = 5;
		destx = 1;
		desty = 1;

				yoffset = abs(desty - curry); //find the y offset
		xoffset = abs(destx - currx); //find the x offset

		if (curry > desty) //if the current y is more than the destination y, turn left
		{
			turnleft();
			drive (yoffset);
			detectObject(currx, destx, yoffset);


		} //end if()
		else //if the current y is less than the destination x, turn right
		{
			turnright();
			drive (yoffset);
			detectObject(currx, destx, yoffset);

		} //end else()

		if (currx > destx) //if the current x is more than the destination x, turn left
		{
			turnright();
			drive (xoffset);
			detectObject(curry, desty, xoffset);

		}
		else //if the current x is less than the destination x, turn left
		{
			turnleft();
			drive (xoffset);
			detectObject(curry, desty, xoffset);

		}

	} //end postion2

	if (position == 3) // [6,6] start, [1,6] destination
	{
		currx = 6;
		curry = 6;
		destx = 1;
		desty = 6;

				yoffset = abs(desty - curry); //find the y offset
		xoffset = abs(destx - currx); //find the x offset

		if (curry > desty) //if the current y is more than the destination y, turn left
		{
			turnleft();
			drive (yoffset);
			detectObject(currx, destx, yoffset);


		} //end if()
		else //if the current y is less than the destination x, turn right
		{
			turnright();
			drive (yoffset);
			detectObject(currx, destx, yoffset);

		} //end else()

		if (currx > destx) //if the current x is more than the destination x, turn left
		{
			turnright();
			drive (xoffset);
			detectObject(curry, desty, xoffset);
			displayCenteredBigTextLine(2, "ERROR");
			playSound(soundBeepBeep);

		}
		else //if the current x is less than the destination x, turn left
		{
			turnleft();
			drive (xoffset - 1);
			detectObject(curry, desty, xoffset);
			displayCenteredBigTextLine(2, "ERROR");
			playSound(soundBeepBeep);

		}

	} //end postion3

	if (position == 4) // [1,6] start, [7,1] destination
	{
		currx = 1;
		curry = 6;
		destx = 7;
		desty = 1;

				yoffset = abs(desty - curry); //find the y offset
		xoffset = abs(destx - currx); //find the x offset

		if (curry > desty) //if the current y is more than the destination y, turn left
		{
			turnleft();
			drive (yoffset);
			detectObject(currx, destx, yoffset);


		} //end if()
		else //if the current y is less than the destination x, turn right
		{
			turnright();
			drive (yoffset);
			detectObject(currx, destx, yoffset);

		} //end else()

		if (currx > destx) //if the current x is more than the destination x, turn left
		{
			turnright();
			drive (xoffset);
			detectObject(curry, desty, xoffset);

		}
		else //if the current x is less than the destination x, turn left
		{
			turnleft();
			drive (xoffset);
			detectObject(curry, desty, xoffset);

		}

	} //end postion4
} //end main()
