// Библиотеки
#include <PinChangeInterrupt.h>

// Константы
#define DEBUG_FREQ 9600

const char ENC_TABLE[] = {0, -1, 1, 0, 1, 0, 0, -1, -1, 0, 0, 1, 0, 1, -1, 0};

// Порты
#define port_enc_left_1   8
#define port_enc_left_2   9
#define port_enc_right_1 10
#define port_enc_right_2 11

// Переменные
volatile long encoder_left = 0;
volatile long encoder_right = 0;


// Функции
void encoderSetup() {
  attachPCINT(digitalPinToPCINT(port_enc_left_1), encoderInterrupt, CHANGE);
  attachPCINT(digitalPinToPCINT(port_enc_left_2), encoderInterrupt, CHANGE);
  attachPCINT(digitalPinToPCINT(port_enc_right_1), encoderInterrupt, CHANGE);
  attachPCINT(digitalPinToPCINT(port_enc_right_2), encoderInterrupt, CHANGE);
}

void encoderInterrupt() {
  static byte enc_l;
  static byte enc_r;

  enc_l = enc_l << 2;
  enc_r = enc_r << 2;

  enc_l = enc_l | ((PINB & 0b00110000) >> 4));
  enc_r = enc_r | ((PINB & 0b11000000) >> 6));

  encoder_left -= ENC_TABLE[enc_l & 0b00001111];
  encoder_right -= ENC_TABLE[enc_r & 0b00001111];
}
