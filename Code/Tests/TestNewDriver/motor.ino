#define nSLOW_DECAY

 byte port_motor_left_fwd = 6;
const byte port_motor_left_bwd = 13;

const byte port_motor_right_fwd = 11;
const byte port_motor_right_bwd = 5;

const int motorSpeed = 60;

// Create an instance of the DRV8833:
DRV8833 driver = DRV8833();

void motorSetup() {
  driver.attachMotorA(port_motor_left_bwd, port_motor_left_fwd);
  driver.attachMotorB(port_motor_right_bwd, port_motor_right_fwd);
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
    driver.motorAForward(power_left);
  }
  else {
    driver.motorAReverse(-power_left);
  }

  if (power_right > 0) {
    driver.motorBForward(power_right);
  }
  else {
    driver.motorBReverse(-power_right);
  }
}

void motorStopBoth() {
  driver.motorAStop();
  driver.motorBStop();
}
