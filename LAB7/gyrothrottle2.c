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
	int gyrorate = 0;

	while (true)
	{
			displayBigTextLine(4,"%d", SensorValue(gyroSensor));
			sleep(1500);
			gyrorate = SensorValue[gyroSensor];

			if(gyrorate > 50)
			{
				turnright();
				setLEDColor(ledOrange);
				setMotorSpeed (leftMotor, gyrorate * 2);
				setMotorSpeed (rightMotor, gyrorate * 2);
			}


			if(gyrorate < -50)
			{
				turnleft();
				setLEDColor(ledRed);
				setMotorSpeed (leftMotor, gyrorate + 50);
				setMotorSpeed (rightMotor, gyrorate + 50);
			}

	}

}
