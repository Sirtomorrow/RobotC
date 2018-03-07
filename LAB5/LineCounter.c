#pragma config(Sensor, S1,     touchSensor,    sensorEV3_Touch)
#pragma config(Sensor, S2,     gyroSensor,     sensorEV3_Gyro, modeEV3Gyro_RateAndAngle)
#pragma config(Sensor, S3,     colorSensor,    sensorEV3_Color, modeEV3Color_Reflected)
#pragma config(Sensor, S4,     sonarSensor,    sensorEV3_Ultrasonic)
#pragma config(Motor,  motorA,          armMotor,      tmotorEV3_Large, PIDControl, encoder)
#pragma config(Motor,  motorB,          leftMotor,     tmotorEV3_Large, PIDControl, driveLeft, encoder)
#pragma config(Motor,  motorC,          rightMotor,    tmotorEV3_Large, PIDControl, driveRight, encoder)

void drive(long time, long motorpower)
{
    setMotorSpeed(leftMotor, motorpower);  //Set the leftMotor (motor1) to half power (50)
    setMotorSpeed(rightMotor, motorpower);  //Set the rightMotor (motor6) to half power (50)
    sleep(time);  //Wait for 1 secondsbefore continuing on in the program.
}


task main()
{
	int threshold = 55; //Light Val = 100, Dark Val = 10
	int counter = 0;

	while (true)
	{
		displayBigTextLine(2, "Lines: %d", counter);


		while (SensorValue[colorSensor] < threshold)
		{
			displayBigTextLine(2, "Lines: %d", counter);
			drive (0, 0);
			sleep (500);

			if (SensorValue[colorSensor] < threshold)
			{
				counter++;
				drive (400,25)
			}

		}

		drive(0, 25);


	}


}
