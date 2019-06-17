// Библиотеки
#include <Wire.h>

const int sensor_count = 11;

// Функции
void lineSetup() {
  Wire.begin();
}

byte *readFrontSensor() {
  byte *input = new byte[11];
  Wire.requestFrom(4, 11);
  for(int i = 0; i < sensor_count; i++) {
    input[i] = Wire.read();
  }
  return input;
}

byte *readBackSensor() {
  byte *input = new byte[11];
  Wire.requestFrom(5, 11);
  for(int i = 0; i < sensor_count; i++) {
    input[i] = Wire.read();
  }
  return input;
}
