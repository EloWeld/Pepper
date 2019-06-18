const byte port_led_red = A1;
const byte port_led_green = A2;
const byte port_led_blue = A3;

void ledSetup() {
  pinMode(port_led_red, OUTPUT);
  pinMode(port_led_green, OUTPUT);
  pinMode(port_led_blue, OUTPUT);

  ledLight(LED_GREEN);
}

void ledLight(int color) {
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
