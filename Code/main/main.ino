#include <PinChangeInterrupt.h>

#define LED_RED 0
#define LED_GREEN 1
#define LED_BLUE 2
#define LED_CYAN 3
#define LED_YELLOW 4
#define LED_MAGENTA 5
#define LED_WHITE 6
#define LED_OFF 7

volatile long encoder_left = 0;
volatile long encoder_right = 0;

bool encoder_end = false;

void setup() {
  ledSetup();
  encoderSetup();
  motorSetup();
  delay(1500);
}

void loop() {
  moveAcs(64, 120);
  moveForwardEnc(64, 675);
  moveSlowEnc(64, 160);
  while (true) {}
}
