// Библиотеки
#include <Servo.h> 

// Порты
#define port_pusher 12

// Переменные
Servo pusher;

// Константы
#define PUSHER_MIN_FREQ = 435;
#define PUSHER_MAX_FREQ = 1600 ;
#define PUSHER_SPEED_DELAY 1;

// Функции
void pusherSetup() {
  pusher.attach(port_pusher, PUSHER_MIN_FREQ, PUSHER_MAX_FREQ);
}

void pusherOut() {
  for(int i = 180; i >= 0; i--) {
      pusher.write(i);
      delay(PUSHER_SPEED_DELAY);
    }
}

void pusherIn() {
  for(int i = 0; i < 180; i++) {
      pusher.write(i);
      delay(PUSHER_SPEED_DELAY);
    }
}
