const byte port_led[] = {A0, A1, A2};

#define RED     0
#define GREEN   1
#define BLUE    2
#define YELLOW  3
#define CYAN    4
#define PURPLE  5
#define BLACK   6
#define WHITE   7

void ledSetup() {
  pinMode(A0, OUTPUT);
  pinMode(A1, OUTPUT);
  pinMode(A2, OUTPUT);
}

void ledLight(int color_code) {
  switch(color_code) {
    case RED:
      digitalWrite(A0, HIGH);digitalWrite(A0,  LOW);digitalWrite(A0,  LOW);
      break;
    case GREEN:
      digitalWrite(A0,  LOW);digitalWrite(A0, HIGH); digitalWrite(A0,  LOW);
      break;
    case BLUE:
      digitalWrite(A0,  LOW);digitalWrite(A0,  LOW);digitalWrite(A0, HIGH);
      break;
    case YELLOW:
      digitalWrite(A0, HIGH);digitalWrite(A0, HIGH);digitalWrite(A0,  LOW);
      break;
    case CYAN:
      digitalWrite(A0,  LOW);digitalWrite(A0, HIGH);digitalWrite(A0, HIGH);
      break;
    case PURPLE:
      digitalWrite(A0, HIGH);digitalWrite(A0,  LOW);digitalWrite(A0, HIGH);
      break;
    case BLACK:
      digitalWrite(A0,  LOW);digitalWrite(A0,  LOW);digitalWrite(A0,  LOW);
      break;
    case WHITE:
      digitalWrite(A0, HIGH);digitalWrite(A0, HIGH);digitalWrite(A0, HIGH);
      break;
  }
}

void ledOff() {
  digitalWrite(A0,  LOW);digitalWrite(A0,  LOW);digitalWrite(A0,  LOW);
}
