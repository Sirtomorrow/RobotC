#pragma config(Sensor, S1,     touchSensor,    sensorEV3_Touch)
#pragma config(Sensor, S2,     gyroSensor,     sensorEV3_Gyro, modeEV3Gyro_RateAndAngle)
#pragma config(Sensor, S3,     colorSensor,    sensorEV3_Color, modeEV3Color_Reflected)
#pragma config(Sensor, S4,     sonarSensor,    sensorEV3_Ultrasonic)
#pragma config(Motor,  motorA,          armMotor,      tmotorEV3_Large, PIDControl, encoder)
#pragma config(Motor,  motorB,          leftMotor,     tmotorEV3_Large, PIDControl, driveLeft, encoder)
#pragma config(Motor,  motorC,          rightMotor,    tmotorEV3_Large, PIDControl, driveRight, encoder)

void drive(long speed)
{
    setMotorSpeed(leftMotor, speed);  //Set the leftMotor (motor1) to half power (50)
    setMotorSpeed(rightMotor, speed);  //Set the rightMotor (motor6) to half power (50)

}

task main()
{
	resetGyro(S2);

	while (true)
	{
		while(getGyroDegrees(S2) >= 45)
		{
			drive (25);
		}

		while(getGyroDegrees(S2) <= -45)
		{
			drive (-25);
		}

		drive(0);

	}

}
