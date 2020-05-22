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

int runStepX = 0;
int ruSpeedX = 0;

int runStepY = 0;
int ruSpeedY = 0;

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

#define LINE_BUFFER_LENGTH 512
// Servo position for Up and Down
const int penZUp = 65;
const int penZDown = 90;

/* Structures, global variables    */
struct point {
  float x;
  float y;
  float z;
};
// Current position of plothead
struct point actuatorPos;
//  Drawing settings, should be OK
int StepDelay = 0;
int LineDelay = 0;
int penDelay = 50;
// Motor steps to go 1 millimeter.
// Use test sketch to go 100 steps. Measure the length of line.
// Calculate steps per mm. Enter here.
float StepsPerMillimeterX = 80.0;
float StepsPerMillimeterY = 80.0;
// Drawing robot limits, in mm
// OK to start with. Could go up to 50 mm if calibrated well.
float Xmin = 0;
float Xmax = 300;
float Ymin = 0;
float Ymax = 300;
float Zmin = 0;
float Zmax = 1;
float Xpos = Xmin;
float Ypos = Ymin;
float Zpos = Zmax;
// Set to true to get debug output.
boolean verbose = false;
//  Needs to interpret
//  G1 for moving
//  G4 P300 (wait 150ms)
//  M300 S30 (pen down)
//  M300 S50 (pen up)
//  Discard anything with a (
//  Discard any other command!
/**********************
   void setup() - Initialisations
 ***********************/

void processIncomingLine( char* line, int charNB ) {
  int currentIndex = 0;
  char buffer[ 64 ];                                 // Hope that 64 is enough for 1 parameter
  struct point newPos;
  newPos.x = 0.0;
  newPos.y = 0.0;
  //  Needs to interpret
  //  G1 for moving
  //  G4 P300 (wait 150ms)
  //  G1 X60 Y30
  //  G1 X30 Y50
  //  M300 S30 (pen down)
  //  M300 S50 (pen up)
  //  Discard anything with a (
  //  Discard any other command!
  while ( currentIndex < charNB ) {
    switch ( line[ currentIndex++ ] ) {              // Select command, if any
      case 'U':
        penUp();
        break;
      case 'D':
        penDown();
        break;
      case 'G':
        buffer[0] = line[ currentIndex++ ];          // /!\ Dirty - Only works with 2 digit commands
        //      buffer[1] = line[ currentIndex++ ];
        //      buffer[2] = '\0';
        buffer[1] = '\0';
        switch ( atoi( buffer ) ) {                  // Select G command
          case 0:                                   // G00 & G01 - Movement or fast movement. Same here
          case 1:
            // /!\ Dirty - Suppose that X is before Y
            char* indexX = strchr( line + currentIndex, 'X' ); // Get X/Y position in the string (if any)
            char* indexY = strchr( line + currentIndex, 'Y' );
            if ( indexY <= 0 ) {
              newPos.x = atof( indexX + 1);
              newPos.y = actuatorPos.y;
            }
            else if ( indexX <= 0 ) {
              newPos.y = atof( indexY + 1);
              newPos.x = actuatorPos.x;
            }
            else {
              newPos.y = atof( indexY + 1);
              // indexY = '\0';
              newPos.x = atof( indexX + 1);
            }
            // drawLine(newPos.x, newPos.y );
            moveTo(newPos.x, newPos.y);
            //        Serial.println("ok");
            actuatorPos.x = newPos.x;
            actuatorPos.y = newPos.y;
            break;
        }
        break;
      case 'M':
        buffer[0] = line[ currentIndex++ ];        // /!\ Dirty - Only works with 3 digit commands
        buffer[1] = line[ currentIndex++ ];
        buffer[2] = line[ currentIndex++ ];
        buffer[3] = '\0';
        switch ( atoi( buffer ) ) {
          case 300:
            {
              char* indexS = strchr( line + currentIndex, 'S' );
              float Spos = atof( indexS + 1);
              //         Serial.println("ok");
              if (Spos == 30) {
                penDown();
              }
              if (Spos == 50) {
                penUp();
              }
              break;
            }
          case 114:                                // M114 - Repport position
            Serial.print( "Absolute position : X = " );
            Serial.print( actuatorPos.x );
            Serial.print( "  -  Y = " );
            Serial.println( actuatorPos.y );
            break;
          default:
            Serial.print( "Command not recognized : M");
            Serial.println( buffer );
        }
    }
  }
}
/*********************************
   Draw a line from (x0;y0) to (x1;y1).
   int (x1;y1) : Starting coordinates
   int (x2;y2) : Ending coordinates
 **********************************/
void drawLine(float x1, float y1) {
  if (verbose)
  {
    Serial.print("fx1, fy1: ");
    Serial.print(x1);
    Serial.print(",");
    Serial.print(y1);
    Serial.println("");
  }
  //  Bring instructions within limits
  if (x1 >= Xmax) {
    x1 = Xmax;
  }
  if (x1 <= Xmin) {
    x1 = Xmin;
  }
  if (y1 >= Ymax) {
    y1 = Ymax;
  }
  if (y1 <= Ymin) {
    y1 = Ymin;
  }
  if (verbose)
  {
    Serial.print("Xpos, Ypos: ");
    Serial.print(Xpos);
    Serial.print(",");
    Serial.print(Ypos);
    Serial.println("");
  }
  if (verbose)
  {
    Serial.print("x1, y1: ");
    Serial.print(x1);
    Serial.print(",");
    Serial.print(y1);
    Serial.println("");
  }
  //  Convert coordinates to steps
  x1 = (int)(x1 * StepsPerMillimeterX);
  y1 = (int)(y1 * StepsPerMillimeterY);
  float x0 = Xpos;
  float y0 = Ypos;
  //  Let's find out the change for the coordinates
  long dx = abs(x1 - x0);
  long dy = abs(y1 - y0);
  /*
  int sx = x0 < x1 ? StepInc : -StepInc;
  int sy = y0 < y1 ? StepInc : -StepInc;
  */
  int sx = x0 < x1 ? 1 : 0;
  int sy = y0 < y1 ? 1 : 0;
  long i;
  long over = 0;
  stepperEnable(true);
  digitalWrite(STEPX_DIR_PIN, sx);
  digitalWrite(STEPY_DIR_PIN, sy);
  if (dx > dy) {
    for (i = 0; i < dx; ++i) {
      // myStepperX.onestep(sx, STEP);
      moveMotorXOneStep(sx);
      over += dy;
      if (over >= dx) {
        over -= dx;
        // myStepperY.onestep(sy, STEP);
        moveMotorYOneStep(sy);
      }
      // delay(StepDelay);
    }
  }
  else {
    for (i = 0; i < dy; ++i) {
      // myStepperY.onestep(sy, STEP);
      moveMotorYOneStep(sy);
      over += dx;
      if (over >= dy) {
        over -= dy;
        // myStepperX.onestep(sx, STEP);
        moveMotorXOneStep(sx);
      }
      // delay(StepDelay);
    }
  }
  // stepperEnable(false);
  if (verbose)
  {
    Serial.print("dx, dy:");
    Serial.print(dx);
    Serial.print(",");
    Serial.print(dy);
    Serial.println("");
  }
  if (verbose)
  {
    Serial.print("Going to (");
    Serial.print(x0);
    Serial.print(",");
    Serial.print(y0);
    Serial.println(")");
  }
  //  Delay before any next lines are submitted
  delay(LineDelay);
  //  Update the positions
  Xpos = x1;
  Ypos = y1;
}
//  Raises pen
void penUp() {
  servoWrite(penZUp);
  delay(penDelay);
  Zpos = Zmax;
  if (verbose) {
    Serial.println("Pen up!");

  }
}
//  Lowers pen
void penDown() {
  servoWrite(penZDown);
  delay(penDelay);
  Zpos = Zmin;
  if (verbose) {
    Serial.println("Pen down.");
  }
}

void moveTo(float x, float y) {
  static float beforeX = 0;
  static float beforeY = 0;

  x = x > Xmax ? Xmax : x;
  x = x < Xmin ? Xmin : x;
  y = y > Ymax ? Ymax : y;
  y = y < Ymin ? Ymin : y;

  int stepX = abs(beforeX - x) * StepsPerMillimeterX;
  int stepY = abs(beforeY - y) * StepsPerMillimeterY;

  int sx = beforeX < x ? 1 : 0;
  int sy = beforeY < y ? 1 : 0;

  stepperEnable(true);
  digitalWrite(STEPX_DIR_PIN, sx);
  digitalWrite(STEPY_DIR_PIN, sy);

  taskENTER_CRITICAL();
  if (stepX > stepY) {
    for (int i=0;i<stepX;i++) {
      moveMotorXOneStep(sx);
      if (i < stepY) {
        moveMotorYOneStep(sy);
      }
      // delay(StepDelay);
    }
  } else {
    for (int i=0;i<stepY;i++) {
      moveMotorYOneStep(sy);
      if (i < stepX) {
        moveMotorXOneStep(sx);
      }
      // delay(StepDelay);
    }
  }
  taskEXIT_CRITICAL();
  // stepperEnable(false);
  
  //  Delay before any next lines are submitted
  delay(LineDelay);
  //  Update the positions
  beforeX = x;
  beforeY = y;
}
