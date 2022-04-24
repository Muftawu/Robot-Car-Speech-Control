uint8_t Pwm1 = D1; //Nodemcu PWM pin
uint8_t Pwm2 = D2; //Nodemcu PWM pin

int a0 = 15;  //Gpio-15 of nodemcu esp8266
int a1 = 13;  //Gpio-13 of nodemcu esp8266
int a2 = 12;  //Gpio-12 of nodemcu esp8266
int a3 = 14;  //Gpio-14 of nodemcu esp8266

String command;
int led = D3;
int moveDelay = 950;
int stopDelay = 950;

void moveForward();
void moveBack();
void turnLeft();
void turnRight();
void serialEvent();

void setup () {
  Serial.begin(115200);
  Serial.setTimeout(5);

  pinMode(a0, OUTPUT);
  pinMode(a1, OUTPUT);
  pinMode(a2, OUTPUT);
  pinMode(a3, OUTPUT);

}

void loop () {
  //  moveForward();
}

void serialEvent() {
  command = Serial.readString();
  
  if (command == "forward") {
    moveForward();
  }

  if (command == "reverse") {
    moveBack();
  }

  if (command == "left") {
    turnLeft();
  }

  if (command == "right") {
    turnRight();
  }
}

void moveForward() {
  digitalWrite(Pwm1, HIGH);
  digitalWrite(Pwm2, HIGH);

  digitalWrite(a0, HIGH);
  digitalWrite(a2, HIGH);

  digitalWrite(a1, LOW);
  digitalWrite(a3, LOW);
  delay(moveDelay);

  digitalWrite(Pwm1, LOW);
  digitalWrite(Pwm2, LOW);
  digitalWrite(a0, LOW);
  digitalWrite(a2, LOW);
}


void moveBack() {
  digitalWrite(Pwm1, HIGH);
  digitalWrite(Pwm2, HIGH);

  digitalWrite(a0, LOW);
  digitalWrite(a2, LOW);

  digitalWrite(a1, HIGH);
  digitalWrite(a3, HIGH);
  delay(moveDelay);

  digitalWrite(Pwm1, LOW);
  digitalWrite(Pwm2, LOW);
  digitalWrite(a1, LOW);
  digitalWrite(a3, LOW);
}


void turnRight() {
  digitalWrite(Pwm1, HIGH);
  digitalWrite(Pwm2, HIGH);

  digitalWrite(a0, HIGH);
  digitalWrite(a2, LOW);

  digitalWrite(a1, LOW);
  digitalWrite(a3, LOW);
  delay(moveDelay);

  digitalWrite(Pwm1, LOW);
  digitalWrite(Pwm2, LOW);
  digitalWrite(a0, LOW);
  digitalWrite(a2, LOW);
}


void turnLeft() {
  digitalWrite(Pwm1, HIGH);
  digitalWrite(Pwm2, HIGH);

  digitalWrite(a0, LOW);
  digitalWrite(a2, HIGH);

  digitalWrite(a1, LOW);
  digitalWrite(a3, LOW);
  delay(moveDelay);

  digitalWrite(Pwm1, LOW);
  digitalWrite(Pwm2, LOW);
  digitalWrite(a0, LOW);
  digitalWrite(a2, LOW);
}
