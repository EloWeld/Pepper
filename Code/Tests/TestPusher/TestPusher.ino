// Библиотеки
#include <Servo.h> 

// Порты
#define port_pusher 12

// Переменные
Servo pusher;

// Константы
#define PUSHER_MIN_FREQ = 435;
#define PUSHER_MAX_FREQ = 1600 ;
 
// Функции
void setup() 
{
  pusher.attach(port_pusher, PUSHER_MIN_FREQ, PUSHER_MAX_FREQ);
} 
 
void loop() 
{
  pusher.Write(175);
  delay(2500);
  pusher.Write(5);
  delay(2500);
} 
