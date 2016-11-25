#include "ACS712.h"

/*
  This examples shows how to measure power consumption
  of devices in 230V electrical system
  or any other system with alternative current
*/

// We have 30 amps version sensor connected to A1 pin of arduino
// Replace with your version if needed
ACS712 sensor(ACS712_30A, A1);

void setup() {
  Serial.begin(9600);

  // This method calibrates zero point of sensor,
  // It's not necessary, but may positively affect the accuracy
  // Ensure that no current flows through the sensor at this moment
  sensor.calibrate();
}

void loop() {
  // We use 230V because it is the common standard in European countries
  // Change to your local, if needed
  float U = 230;

  // To measure current we need to know the frequency of current
  // By default 50Hz is used, but you can specify own, if needed
  float I = sensor.getCurrentAC();

  // To calculate the power we need voltage multiplied by current
  float P = U * I;

  Serial.println(String("P = ") + P + " Watts");

  delay(1000);
}