void moveEnc(int power) {
  int enc_error = (int)(encoder_right - (long)((float)encoder_left * 1.031955469));   
  if (enc_error > power) {
    enc_error = power;
  }
  if (enc_error < -power) {
    enc_error = -power;
  }
  int m_right = power - enc_error;
  int m_left = power + enc_error;
  motorWriteBoth(m_left, m_right);
}

void moveAcs(int power, int dist) {
  encoderClear();
  encoderClearEnd();
  while (!encoder_end) {
    moveEnc(40 + (encoder_right / 5));
    encoderCheckEnd(dist);
  }
}


// Езда на расстояние
void moveForwardEnc(int power, int dist) {
  encoderClear();
  encoderClearEnd();
  while (!encoder_end) {
    moveEnc(power);
    encoderCheckEnd(dist);
  }
}

// Останвока за расстояние
void moveSlowEnc(int power, int dist) {
  encoderClear();
  encoderClearEnd();
  int p_stop = dist / (power - 40);
  while (!encoder_end) {
    moveEnc(power - (encoder_right / p_stop));
    encoderCheckEnd(dist);
  }
  motorStopBoth();
}
