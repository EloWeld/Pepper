const byte port_motor_left_fwd = 6;
const byte port_motor_left_bwd = 13;
const byte port_motor_right_fwd = 11;
const byte port_motor_right_bwd = 5;

void motorSetup() {
  pinMode(port_motor_left_fwd, OUTPUT);
  pinMode(port_motor_left_bwd, OUTPUT);
  pinMode(port_motor_right_fwd, OUTPUT);
  pinMode(port_motor_right_bwd, OUTPUT);

  digitalWrite(port_motor_left_fwd, LOW);
  digitalWrite(port_motor_left_bwd, LOW);
  digitalWrite(port_motor_right_fwd, LOW);
  digitalWrite(port_motor_right_bwd, LOW);
}


void motorWriteBoth(int power_left, int power_right) {
  if (power_left > 255) {
    power_left = 255;
  }
  if (power_left < -255) {
    power_left = -255;
  }

  if (power_right > 255) {
    power_right = 255;
  }
  if (power_right < -255) {
    power_right = -255;
  }
  
  if (power_left > 0) {
    analogWrite(port_motor_left_fwd, power_left);
    digitalWrite(port_motor_left_bwd, LOW);
  }
  else {
    analogWrite(port_motor_left_bwd, -power_left);
    digitalWrite(port_motor_left_fwd, LOW);
  }

  if (power_right > 0) {
    analogWrite(port_motor_right_fwd, power_right);
    digitalWrite(port_motor_right_bwd, LOW);
  }
  else {
    analogWrite(port_motor_right_bwd, -power_right);
    digitalWrite(port_motor_right_fwd, LOW);
  }
}

void motorStopBoth() {
  digitalWrite(port_motor_left_fwd, HIGH);
  digitalWrite(port_motor_left_bwd, HIGH);
  digitalWrite(port_motor_right_fwd, HIGH);
  digitalWrite(port_motor_right_bwd, HIGH);
}
