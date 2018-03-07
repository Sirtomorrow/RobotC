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

void stopMotor(long time, long motorpower)
{
    setMotorSpeed(leftMotor, motorpower);  //Set the leftMotor (motor1) to half power (50)
    setMotorSpeed(rightMotor, motorpower);  //Set the rightMotor (motor6) to half power (50)
    sleep(time);  //Wait for 1 secondsbefore continuing on in the program.
}

task main()
{
	int threshold = 55; //Light Val = 100, Dark Val = 10

	while (true)
	{

		while (SensorValue[colorSensor] < threshold)
		{
			stopMotor (0, 0);
			sleep (1000);

		}

		 drive(0, 25);

	}


}
