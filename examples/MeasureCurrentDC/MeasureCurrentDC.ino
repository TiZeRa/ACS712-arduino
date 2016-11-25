#include "ACS712.h"

ACS712 sensor(ACS712_30A, A1);

void setup() {
  Serial.begin(115200);
  sensor.calibrate();
}

void loop() {
  Serial.println(String("I = ") + sensor.getCurrentDC() + "A");
  delay(1000);
}