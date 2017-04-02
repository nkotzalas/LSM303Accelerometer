/* Example sketch that uses the LSM303Accelerometer library */
#include <LSM303Accelerometer.h>

// Debug logs are enabled (switch to false to disable)
const bool debug = true;

// Create the instance of the LSM303Accelerometer
LSM303Accelerometer lsm303Accelerometer = LSM303Accelerometer(debug);

void setup() {
  Serial.begin(9600);

  // Initialize the accelerometer sensor
  lsm303Accelerometer.setup();
}

/*
 * Calculates the orientation every 1 second and prints it to the Serial monitor
 */
void loop() {
  float orientation = lsm303Accelerometer.calculateOrientation();
  Serial.print("Orientation = ");
  Serial.println(orientation);
  
  delay(1000);
}