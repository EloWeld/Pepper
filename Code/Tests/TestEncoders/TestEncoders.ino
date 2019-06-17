// Библиотеки
#include <PinChangeInterrupt.h>

// Константы

const char enc_table[] = {0, -1, 1, 0, 1, 0, 0, -1, -1, 0, 0, 1, 0, 1, -1, 0};

// Переменные
volatile long encoder_left = 0;
volatile long encoder_right = 0;

// Функции
void setup() {
  digitalWrite(A0, HIGH); // Включаем светодиод
  
  attachPCINT(digitalPinToPCINT(8), encoderInterrupt, CHANGE); // PB4
  attachPCINT(digitalPinToPCINT(9), encoderInterrupt, CHANGE); // PB5
  attachPCINT(digitalPinToPCINT(10), encoderInterrupt, CHANGE); // PB6
  attachInterrupt(digitalPinToInterrupt(7), encoderInterrupt, CHANGE); // PE6

  Serial.begin(9600);
  while(!Serial) {}
}

void loop() {
  Serial.print("[ENCODERS]: LEFT - ");
  Serial.print(encoder_left);
  Serial.print("; RIGHT - ");
  Serial.println(encoder_right);
  Serial.print(";");
}

void encoderInterrupt() {
  enc_l = enc_l << 2;
  enc_r = enc_r << 2;

  enc_l = enc_l | ((PINB & 0b00110000) >> 4);
  enc_r = enc_r | (((PINB & 0b1000000) >> 6) | ((PINE & 0b1000000) >> 5));

  encoder_left -= encoder_table[enc_l & 0b00001111];
  encoder_right += encoder_table[enc_r & 0b00001111];
}
