/*
	AccelerometerSensor.h - Library for controlling an accelerometer sensor.

	Created by Nick Kotzalas, December 30, 2016
	Released into the public domain
*/

#include "Arduino.h"
#include "AccelerometerSensor.h"

#include <Adafruit_Sensor.h>
#include <Adafruit_LSM303_U.h>

bool debugEnabled = false;

/**
 * The accelerometer sensor definition
 */
Adafruit_LSM303_Mag_Unified mag;

/**
 * Constructor of the movement handler
 */
AccelerometerSensor::AccelerometerSensor(bool debug)
{
	debugEnabled = debug;

	mag = Adafruit_LSM303_Mag_Unified(10001);
}

/*
 * Setup the accelerometer (in case the system is unable to detect the accelerometer,
 * it will retry for 5 times with 5 seconds delay between them).
 */
void AccelerometerSensor::setup()
{
	if (debugEnabled) {
		Serial.println("Initializing the accelerometer sensor...");
	}

	delay(100);
	int attempts = 0;
	while (!mag.begin()) {
		attempts++;
		Serial.println("ERROR: Failed to detect the accelerometer!");
		if (attempts < 5) {
			Serial.println("Acceleremeter initialization will be retried in 5 seconds");
			delay(5000);
		} else {
			while(1);
		}
	}

	if (debugEnabled) {
		Serial.println("Acceleremeter sensor has been initialized");
	}
}

/*
 * Get A calculation of the orientation from the accelerometer. The outcome 
 * is a normalized range from 0 to 360
 */
float AccelerometerSensor::calculateOrientation()
{
	// Get a new calculation from the accelerometer
	sensors_event_t accelerometerEvent; 
	mag.getEvent(&accelerometerEvent);

	float Pi = 3.14159;

	// Calculate the angle of the vector y,x
	float heading = (atan2(accelerometerEvent.magnetic.y,accelerometerEvent.magnetic.x) * 180) / Pi;

	// Normalize to 0-360
	if (heading < 0) {
		heading = 360 + heading;
	}

	return heading;
}
