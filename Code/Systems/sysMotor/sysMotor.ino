// Порты
#define port_motor_left_dir ?
#define port_motor_left_pwm ?

#define port_motor_right_dir ?
#define port_motor_right_pwm ?

// Константы
#define MAX_SPEED 100

// Функции
void motorSetup() {
  pinMode(port_motor_right_pwm, OUTPUT);
  pinMode(port_motor_right_dir, OUTPUT);
  pinMode(port_motor_left_pwm, OUTPUT);
  pinMode(port_motor_left_dir, OUTPUT);

  // Выключаем моторы
  digitalWrite(port_motor_right_dir, HIGH);
  digitalWrite(port_motor_right_pwm, LOW);

  digitalWrite(port_motor_left_dir, HIGH);
  digitalWrite(port_motor_left_pwm, LOW);
}
