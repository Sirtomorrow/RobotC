#pragma config(Sensor, S1,     touchSensor,    sensorEV3_Touch)
#pragma config(Sensor, S2,     gyroSensor,     sensorEV3_Gyro, modeEV3Gyro_RateAndAngle)
#pragma config(Sensor, S3,     colorSensor,    sensorEV3_Color, modeEV3Color_Reflected)
#pragma config(Sensor, S4,     sonarSensor,    sensorEV3_Ultrasonic)
#pragma config(Motor,  motorA,          armMotor,      tmotorEV3_Large, PIDControl, encoder)
#pragma config(Motor,  motorB,          leftMotor,     tmotorEV3_Large, PIDControl, driveLeft, encoder)
#pragma config(Motor,  motorC,          rightMotor,    tmotorEV3_Large, PIDControl, driveRight, encoder)

void left(long time)
{
    setMotorSpeed(leftMotor, 0);  //Set the leftMotor (motor1) to half power (50)
    setMotorSpeed(rightMotor, 25);  //Set the rightMotor (motor6) to half power (50)
    sleep(time);  //Wait for 1 secondsbefore continuing on in the program.
}

void right(long time)
{
    setMotorSpeed(leftMotor, 25);  //Set the leftMotor (motor1) to half power (50)
    setMotorSpeed(rightMotor, 0);  //Set the rightMotor (motor6) to half power (50)
    sleep(time);  //Wait for 1 secondsbefore continuing on in the program.
}

void drive(long time)
{
    setMotorSpeed(leftMotor, 25);  //Set the leftMotor (motor1) to half power (50)
    setMotorSpeed(rightMotor, 25);  //Set the rightMotor (motor6) to half power (50)
    sleep(time);  //Wait for 1 secondsbefore continuing on in the program.
}

task main()
{
	int threshold = 55; //Light Val = 100, Dark Val = 10

	while (true)
	{
		while (SensorValue[colorSensor] > threshold)
		{
			left (0);

			while (SensorValue[sonarSensor] < 10)
			{
					left (0);

			}

		}

		while (SensorValue[colorSensor] < threshold)
		{
			right (0);

			while (SensorValue[sonarSensor] < 15)
			{
				left (1250);
				drive (750);
				right (1250);
				drive (2000);
				right (1250);
				drive (850);
				left (1250);

			}

		}

}
}
