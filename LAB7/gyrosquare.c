#pragma config(Sensor, S1,     touchSensor,    sensorEV3_Touch)
#pragma config(Sensor, S2,     gyroSensor,     sensorEV3_Gyro, modeEV3Gyro_RateAndAngle)
#pragma config(Sensor, S3,     colorSensor,    sensorEV3_Color, modeEV3Color_Reflected)
#pragma config(Sensor, S4,     sonarSensor,    sensorEV3_Ultrasonic)
#pragma config(Motor,  motorA,          armMotor,      tmotorEV3_Large, PIDControl, encoder)
#pragma config(Motor,  motorB,          leftMotor,     tmotorEV3_Large, PIDControl, driveLeft, encoder)
#pragma config(Motor,  motorC,          rightMotor,    tmotorEV3_Large, PIDControl, driveRight, encoder)

void drive(long time)
{
		setLEDColor(ledRed);
    setMotorSpeed(leftMotor, 25);  //Set the leftMotor (motor1) to half power (50)
    setMotorSpeed(rightMotor, 25);  //Set the rightMotor (motor6) to half power (50)
    sleep(time);  //Wait for 1 secondsbefore continuing on in the program.
}

void right()
{
		setLEDColor(ledOrange);
		resetGyro(S2);

		repeatUntil(getGyroDegrees(S2) > 90)
		{
			//Turn to the left
			setMotorSpeed(motorC, -25);
			setMotorSpeed(motorB, 25);
		}

			//Stop the motors at the end of the turn
			setMotorSpeed(motorB, 0);
			setMotorSpeed(motorC, 0);

}

task main()
{
	while (true)
	{
		//Choose the distance of the vehicle
		displayBigTextLine(2, "Left = 10",);
		displayBigTextLine(5, "Right = 20",);
		displayBigTextLine(8, "Down = 30",);
		displayBigTextLine(11, "Up = 40",);
		// Wait 20 ms to get 50 readings per second
		sleep(20);

			if (getButtonPress(LEFT_BUTTON)==1)
			{
				drive(900);
				right();
				drive(900);
				right();
				drive(900);
				right();
				drive(900);
				right();
			}

			if (getButtonPress(RIGHT_BUTTON)==1)
			{
				drive(1800);
				right();
				drive(1800);
				right();
				drive(1800);
				right();
				drive(1800);
				right();
			}

			if (getButtonPress(DOWN_BUTTON)==1)
			{
				drive(2700);
				right();
				drive(2700);
				right();
				drive(2700);
				right();
				drive(2700);
				right();
			}

			if (getButtonPress(UP_BUTTON)==1)
			{
				drive(3600);
				right();
				drive(3600);
				right();
				drive(3600);
				right();
				drive(3600);
				right();
			}

	}
}
