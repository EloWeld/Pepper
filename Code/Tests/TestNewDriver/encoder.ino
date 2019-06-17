const char encoder_table[] = {0, -1, 1, 0, 1, 0, 0, -1, -1, 0, 0, 1, 0, 1, -1, 0};

byte enc_l;
byte enc_r;

void encoderSetup() {
  attachPCINT(digitalPinToPCINT(8), encoderInterrupt, CHANGE); // PB4
  attachPCINT(digitalPinToPCINT(9), encoderInterrupt, CHANGE); // PB5
  attachPCINT(digitalPinToPCINT(10), encoderInterrupt, CHANGE); // PB6
  attachInterrupt(digitalPinToInterrupt(7), encoderInterrupt, CHANGE); // PE6
}

void encoderInterrupt() {
  enc_l = enc_l << 2;
  enc_r = enc_r << 2;

  enc_l = enc_l | ((PINB & 0b00110000) >> 4);
  enc_r = enc_r | (((PINB & 0b1000000) >> 6) | ((PINE & 0b1000000) >> 5));

  encoder_left -= encoder_table[enc_l & 0b00001111];
  encoder_right += encoder_table[enc_r & 0b00001111];
}

void encoderClear() {
  encoder_left = 0;
  encoder_right = 0;
}

void encoderCheckEnd(int target) {
  encoder_end = ((encoder_right + (long)((float)encoder_left * 1.031955469)) / 2) > target;
}
void encoderClearEnd() {
  encoder_end = false;
}
