// Порты
#define port_motor_left_dir ?
#define port_motor_left_pwm ?

#define port_motor_right_dir ?
#define port_motor_right_pwm ?

// Константы
#define MAX_SPEED 100

// Функции
void setup() {
  digitalWrite(A0, HIGH); // Turn on RED led
  
  // Инициализируем
  pinMode(port_motor_right_pwm, OUTPUT);
  pinMode(port_motor_right_dir, OUTPUT);
  pinMode(port_motor_left_pwm, OUTPUT);
  pinMode(port_motor_left_dir, OUTPUT);

  // Выключаем моторы
  digitalWrite(port_motor_right_dir, HIGH);
  digitalWrite(port_motor_right_pwm, LOW);

  digitalWrite(port_motor_left_dir, HIGH);
  digitalWrite(port_motor_left_pwm, LOW);


  

  // Вперёд
  analogWrite(port_motor_right_pwm, MAX_SPEED);
  analogWrite(port_motor_left_pwm, MAX_SPEED);
  delay(1000);
  
  // Поворот вправо
  digitalWrite(port_motor_right_dir, LOW);
  delay(1000);
  
  // Назад
  digitalWrite(port_motor_right_dir, LOW);
  digitalWrite(port_motor_right_dir, LOW);
  delay(1000);
  
  // Поворот влвео
  digitalWrite(port_motor_right_dir, HIGH);
  digitalWrite(port_motor_left_dir, LOW);
  delay(1000);

  // Остановка
  analogWrite(port_motor_right_pwm, 0);
  analogWrite(port_motor_left_pwm, 0);
  delay(1000);
}

void loop() {
  
}
