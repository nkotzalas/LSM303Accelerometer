/*
	AccelerometerSensor.h - Library for controlling an accelerometer sensor.

	Created by Nick Kotzalas, December 30, 2016
	Released into the public domain
*/

#ifndef AccelerometerSensor_h
#define AccelerometerSensor_h

#include "Arduino.h"

class AccelerometerSensor
{
	public:
		AccelerometerSensor(bool debug, int trigPin, int echoPin);

		/*
		 * Get A calculation of the orientation from the accelerometer. The outcome 
		 * is a normalized range from 0 to 360
		 */
		float calculateOrientation();

		/*
		 * Setup the sensor
		 */
		void setup();
};

#endif