const byte port_led_red = A1;
const byte port_led_green = A2;
const byte port_led_blue = A3;

#define LED_RED 0
#define LED_GREEN 1
#define LED_BLUE 2
#define LED_CYAN 3
#define LED_YELLOW 4
#define LED_MAGENTA 5
#define LED_WHITE 6
#define LED_OFF 7

unsigned long led_t = 0;
byte led_b = 0;
byte curr_half_led = 7;

void setup() {
  pinMode(port_led_red, OUTPUT);
  pinMode(port_led_green, OUTPUT);
  pinMode(port_led_blue, OUTPUT);
}

void half_pwm_led(byte led) {
  if (millis() - led_t > 0 && curr_half_led != 7) {
    digitalWrite(led, !(++led_b % 20));
    led_t = millis();
  }
}

void loop() {
  delay(500);
  delay(500);
  half_pwm_led(port_led_b);  
  delay(500);
  delay(500);
  delay(500);
  delay(500);
}

void ledLight(byte color) {
  switch(color) {
    case LED_RED:
      digitalWrite(port_led_red, 1);
      digitalWrite(port_led_green, 0);
      digitalWrite(port_led_blue, 0);
      break;
    case LED_GREEN:
      digitalWrite(port_led_red, 0);
      digitalWrite(port_led_green, 1);
      digitalWrite(port_led_blue, 0);
      break;
    case LED_BLUE:
      digitalWrite(port_led_red, 0);
      digitalWrite(port_led_green, 0);
      digitalWrite(port_led_blue, 1);
      break;
    case LED_CYAN:
      digitalWrite(port_led_red, 0);
      digitalWrite(port_led_green, 1);
      digitalWrite(port_led_blue, 1);
      break;
    case LED_YELLOW:
      digitalWrite(port_led_red, 1);
      digitalWrite(port_led_green, 1);
      digitalWrite(port_led_blue, 0);
      break;
    case LED_MAGENTA:
      digitalWrite(port_led_red, 1);
      digitalWrite(port_led_green, 0);
      digitalWrite(port_led_blue, 1);
      break;
    case LED_WHITE:
      digitalWrite(port_led_red, 1);
      digitalWrite(port_led_green, 1);
      digitalWrite(port_led_blue, 1);
      break;
    case LED_OFF:
      digitalWrite(port_led_red, 0);
      digitalWrite(port_led_green, 0);
      digitalWrite(port_led_blue, 0);
      break;
  }
}
