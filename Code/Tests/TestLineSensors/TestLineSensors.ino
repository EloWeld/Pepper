// Библиотеки
#include <Wire.h>

// Функции
void setup() {
  Wire.begin();
  digitalWrite(A0, HIGH);// Turn On RED led
}

void loop() {
  // Read from front sensor
  Serial.println("======================================================");
  Wire.requestFrom(4, 11);
  for(int i = 0; i < 11; i++) {
    Serial.print(Wire.read() + " ");
    if (i == 9) Serial.print("ColorSens: ");
  }
  Serial.println("======================================================");
  ////////////////////////////////////////////////////////////////////////
  Serial.println("======================================================");
  // Read from back sensor
  Wire.requestFrom(5, 11);
  for(int i = 0; i < 11; i++) {
    Serial.print(Wire.read() + " ");
    if (i == 9) Serial.print("   ColorSens: ");
  }
  Serial.println("======================================================");
  
  Serial.println();
  Serial.println();
  delay(500);
}
