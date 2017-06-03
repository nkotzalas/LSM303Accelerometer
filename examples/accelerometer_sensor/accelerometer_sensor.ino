/* Example sketch that uses the AccelerometerSensor library */
#include <AccelerometerSensor.h>

// Debug logs are enabled (switch to false to disable)
const bool debug = true;

// Create the instance of the accelerometerSensor
AccelerometerSensor accelerometerSensor = AccelerometerSensor(debug);

void setup() {
  Serial.begin(9600);

  // Initialize the accelerometer sensor
  accelerometerSensor.setup();
}

/*
 * Calculates the orientation every 1 second and prints it to the Serial monitor
 */
void loop() {
  float orientation = accelerometerSensor.calculateOrientation();
  Serial.print("Orientation = ");
  Serial.println(orientation);
  
  delay(1000);
}