#pragma config(Sensor, S1,     touchSensor,    sensorEV3_Touch)
#pragma config(Sensor, S2,     gyroSensor,     sensorEV3_Gyro, modeEV3Gyro_RateAndAngle)
#pragma config(Sensor, S3,     colorSensor,    sensorEV3_Color, modeEV3Color_Reflected)
#pragma config(Sensor, S4,     sonarSensor,    sensorEV3_Ultrasonic)
#pragma config(Motor,  motorA,          armMotor,      tmotorEV3_Large, PIDControl, encoder)
#pragma config(Motor,  motorB,          leftMotor,     tmotorEV3_Large, PIDControl, driveLeft, encoder)
#pragma config(Motor,  motorC,          rightMotor,    tmotorEV3_Large, PIDControl, driveRight, encoder)

void turnright()
{
			setMotorSpeed(armMotor, 5);
}

void turnleft()
{
			setMotorSpeed(armMotor, -5);
}

task main()
{
	resetGyro(gyroSensor);

	while (true)
	{
			displayBigTextLine(4,"%d", SensorValue(gyroSensor));
			sleep(1500);

			while(getGyroDegrees(S2) < 50)
			{
				setMotorSpeed (armMotor, 5);
				setMotorSpeed (leftMotor, getGyroDegrees(S2)+ 60);
				setMotorSpeed (rightMotor, getGyroDegrees(S2)+ 60);
			}


			while(getGyroDegrees(S2) > -50)
			{
				setMotorSpeed (armMotor, -5);
				setMotorSpeed (leftMotor, getGyroDegrees(S2) + 50);
				setMotorSpeed (rightMotor, getGyroDegrees(S2) + 50);

			}

	}

}
