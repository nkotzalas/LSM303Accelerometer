/*
	LSM303Accelerometer.h - Library for controlling an accelerometer sensor.

	Created by Nick Kotzalas, December 30, 2016
	Released into the public domain
*/

#ifndef LSM303Accelerometer_h
#define LSM303Accelerometer_h

#include "Arduino.h"

class LSM303Accelerometer
{
	public:
		LSM303Accelerometer(bool debug, int trigPin, int echoPin);

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