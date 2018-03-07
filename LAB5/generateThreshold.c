#pragma config(Sensor, S1,     touchSensor,    sensorEV3_Touch)
#pragma config(Sensor, S2,     gyroSensor,     sensorEV3_Gyro, modeEV3Gyro_RateAndAngle)
#pragma config(Sensor, S3,     colorSensor,    sensorEV3_Color, modeEV3Color_Reflected)
#pragma config(Sensor, S4,     sonarSensor,    sensorEV3_Ultrasonic)
#pragma config(Motor,  motorA,          armMotor,      tmotorEV3_Large, PIDControl, encoder)
#pragma config(Motor,  motorB,          leftMotor,     tmotorEV3_Large, PIDControl, driveLeft, encoder)
#pragma config(Motor,  motorC,          rightMotor,    tmotorEV3_Large, PIDControl, driveRight, encoder)

task main()
{
	int black;
	int white;
	int threshold;

	while (true)
	{
	  	// Write the amount of reflected light to the screen between 0 -100
		displayBigTextLine(4, "Reflected: %d", SensorValue[colorSensor]);
		// Wait 20 ms to get 50 readings per second
		sleep(20);

		if (getButtonPress(ENTER_BUTTON)==1)
		{
			black = SensorValue[colorSensor];
			displayBigTextLine (2, "%d", black);
			sleep (500);
		}

		if (getButtonPress(DOWN_BUTTON)==1)
		{
			white = SensorValue[colorSensor];
			displayBigTextLine (2, "%d", white);
			sleep(500);
		}

		if (getButtonPress(UP_BUTTON)==1)
		{
			threshold = (black + white) / 2;
			displayBigTextLine (2, "%d", threshold);
			sleep(500);
		}

		if (getButtonPress(RIGHT_BUTTON)==1)
		{
			displayBigTextLine (6, "Dark:%d\n", black);
			displayBigTextLine (8, "Light:%d\n", white);
			displayBigTextLine (10, "Threshold:%d", threshold);
		}

	}

}
