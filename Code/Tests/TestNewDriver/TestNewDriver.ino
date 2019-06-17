#include <DRV8833.h>

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
  Serial.begin(9600);
  //while(!Serial && millis() < 4000) {}
  Serial.println("Ready!");
}

void loop() {
  //moveAcs(50, 120);
  //moveForwardEnc(50, 675);
  //moveSlowEnc(50, 160);
  motorWriteBoth(50, 50);
  delay(1000);
  motorWriteBoth(-50, -50);
  delay(1000);
  motorWriteBoth(-50, 50);
  delay(1000);
  motorWriteBoth(50, -50);
  delay(1000);
 // while (true) {}
}
