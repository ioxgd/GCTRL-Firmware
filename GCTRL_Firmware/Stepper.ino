#define STEPX_STEP_PIN 10         
#define STEPX_DIR_PIN  11
#define STEPX_EN_PIN   12

#define STEPY_STEP_PIN 8
#define STEPY_DIR_PIN  9
#define STEPY_EN_PIN   12

void stepperEnable(bool en) {
  digitalWrite(STEPX_EN_PIN, en ? LOW : HIGH);
  digitalWrite(STEPY_EN_PIN, en ? LOW : HIGH);
}

void setupStepper() {
  pinMode(STEPX_STEP_PIN, OUTPUT);
  pinMode(STEPX_DIR_PIN, OUTPUT);
  pinMode(STEPX_EN_PIN, OUTPUT);
  pinMode(STEPY_STEP_PIN, OUTPUT);
  pinMode(STEPY_DIR_PIN, OUTPUT);
  pinMode(STEPY_EN_PIN, OUTPUT);

  stepperEnable(false);
}

void moveMotorX(int speed, int dir, int step) {
  digitalWrite(STEPX_EN_PIN, LOW);
  digitalWrite(STEPX_DIR_PIN, dir);
  while (step--) {
    digitalWrite(STEPX_STEP_PIN, HIGH);
    delayMicroseconds(speed);
    digitalWrite(STEPX_STEP_PIN, LOW);
    delayMicroseconds(speed);
  }
  digitalWrite(STEPX_EN_PIN, HIGH);
}

void moveMotorY(int speed, int dir, int step) {
  digitalWrite(STEPY_EN_PIN, LOW);
  digitalWrite(STEPY_DIR_PIN, dir);
  while (step--) {
    digitalWrite(STEPY_STEP_PIN, HIGH);
    delayMicroseconds(speed);
    digitalWrite(STEPY_STEP_PIN, LOW);
    delayMicroseconds(speed);
  }
  digitalWrite(STEPY_EN_PIN, HIGH);
}

#define STEP_DELAY 100

void moveMotorXOneStep(int dir) {
  // digitalWrite(STEPX_DIR_PIN, dir);
  digitalWrite(STEPX_STEP_PIN, HIGH);
  delayMicroseconds(STEP_DELAY);
  digitalWrite(STEPX_STEP_PIN, LOW);
  delayMicroseconds(STEP_DELAY);
}

void moveMotorYOneStep(int dir) {
  // digitalWrite(STEPY_DIR_PIN, dir);
  digitalWrite(STEPY_STEP_PIN, HIGH);
  delayMicroseconds(STEP_DELAY);
  digitalWrite(STEPY_STEP_PIN, LOW);
  delayMicroseconds(STEP_DELAY);
}