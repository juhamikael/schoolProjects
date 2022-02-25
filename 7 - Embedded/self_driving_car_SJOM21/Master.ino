
//#include<avr/wdt.h>
#include <avr/io.h>

#include <SPI.h>

#define echoPin1 A4 // attach pin D2 Arduino to pin Echo of HC-SR04
#define trigPin1 A5 //attach pin D3 Arduino to pin Trig of HC-SR04
#define echoPin2 A2 // attach pin D4 Arduino to pin Echo of HC-SR04
#define trigPin2 A3 //attach pin D5 Arduino to pin Trig of HC-SR04
#define echoPin3 A0 // attach pin D6 Arduino to pin Echo of HC-SR04
#define trigPin3 A1 //attach pin D7 Arduino to pin Trig of HC-SR04

const int leftMotorF = 6;
const int rightMotorF = 5;
const int leftMotorR = 9;
const int rightMotorR = 3;

const int startButtonPin = 2;
bool start = false;

long duration = 0;
int distanceLeft = 0;
int distanceRight = 0;
int distanceFront = 0;

int distanceToleranceFront = 30;
int distanceToleranceLeft = 30;
int distanceToleranceRight = 30;

int gear0 = 0;
int gear1 = (255 / 4);     //
int gear2 = (255 / 2);     //
int gear3 = (255 / 4 * 3); //
int gear4 = 255;           //
int chosenGear = gear0;
int gearNumber = 0;
int runTime = 0;

long startTime = 0;

void setup(void)
{
  Serial.begin(115200);
  Serial.println();

  digitalWrite(SS, HIGH); // ensure SS stays high for now

  // Put SCK, MOSI, SS pins into output mode
  // also put SCK, MOSI into LOW state, and SS into HIGH state.
  // Then put SPI hardware into Master mode and turn SPI on
  SPI.begin();

  // Slow down the master a bit
  SPI.setClockDivider(SPI_CLOCK_DIV8);
  pinMode(9, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);

  pinMode(A5, OUTPUT);
  pinMode(A4, INPUT);
  pinMode(A3, OUTPUT);
  pinMode(A2, INPUT);
  pinMode(A1, OUTPUT);
  pinMode(A0, INPUT);

  //aseta startbuttonpin inpputiksi pull-upilla
  DDRD &= ~(1 << startButtonPin);
  PORTD |= (1 << startButtonPin);

  //laskeva sivu INT0 generoi interruptinn
  EICRA |= (1 << ISC01);
  EICRA &= ~(1 << ISC00);

  //enabloi globaalit interruptit INT0
  EIMSK |= (1 << INT0);
  reverseTimersInit();
  setMotorsTo0();
  //enabloi globaalit interruptit

  sei();

} // end of setup

byte transferAndWait(const byte what)
{
  byte a = SPI.transfer(what);
  delayMicroseconds(20);
  return a;
} // end of transferAndWait

void loop(void)
{
  /*while(1){OCR2B = 255;
delay(1000);
OCR2B = 0;
delay(1000);}*/

  byte a, b;

  if (start == true)
  {

    // enable Slave Select
    digitalWrite(SS, LOW);

    transferAndWait('g'); // add command
    transferAndWait(00);
    a = transferAndWait(00);

    // disable Slave Select
    digitalWrite(SS, HIGH);
    Serial.println("Adding results:");
    Serial.println(a, DEC);
    delay(60);
    // enable Slave Select
    digitalWrite(SS, LOW);

    transferAndWait('t'); // subtract command
    transferAndWait('t');
    b = transferAndWait(00);

    // disable Slave Select
    digitalWrite(SS, HIGH);
    Serial.println("Subtracting results:");
    Serial.println(b, DEC);
    gearNumber = a;
    runTime = b;
    Serial.println(gearNumber);
    Serial.println(runTime);

    if (gearNumber == 4)
    {
      chosenGear = gear4;
    }
    else if (gearNumber == 3)
    {
      chosenGear = gear3;
    }
    else if (gearNumber == 2)
    {
      chosenGear = gear2;
    }
    else if (gearNumber == 1)
    {
      chosenGear = gear1;
    }
    else if (gearNumber == 0)
    {
      chosenGear = gear0;
      start = false;
    }

    startTime = millis();
    Serial.println(chosenGear);
    unsigned long currentTime = millis();

    while ((currentTime - startTime) < (runTime * 1000) && start == true)
    {
      wdt_enable(WDTO_8S); //käynnistetään watchdog
      drive();
      wdt_reset();
      currentTime = millis();
    }
    setMotorsTo0();
    wdt_disable(); //disabloidaan watchdog

    start = false;
  }

} // end of loop

ISR(INT0_vect)
{
  if (start)
  {
    start = false;
  }
  else
  {
    start = true;
  }
}

ISR(WDT_vect)
{
}

int checkFront()
{
  //  Serial.println("in checkfront");

  // Clears the trigPin condition
  digitalWrite(trigPin2, LOW);
  delayMicroseconds(2);
  // Sets the trigPin HIGH (ACTIVE) for 10 microseconds
  digitalWrite(trigPin2, HIGH);
  delayMicroseconds(15);
  digitalWrite(trigPin2, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin2, HIGH);
  // Calculating the distance
  // Speed of sound wave divided by 2 (go and back)
  // Displays the distance on the Serial Monitor

  //  Serial.print("Etäisyys etu ");
  //  Serial.print(distanceFront);
  //  Serial.print(" cm");
  //  Serial.println();
  delay(10);
  return (duration / 58);
}

int checkLeft()
{
  //Serial.println("in checkLeft");
  // Clears the trigPin condition
  digitalWrite(trigPin1, LOW);
  delayMicroseconds(2);
  // Sets the trigPin HIGH (ACTIVE) for 10 microseconds
  digitalWrite(trigPin1, HIGH);
  delayMicroseconds(15);
  digitalWrite(trigPin1, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin1, HIGH);
  // Calculating the distance
  // Speed of sound wave divided by 2 (go and back)
  // Displays the distance on the Serial Monitor
  // Serial.print("Etäisyys vasen ");
  //  Serial.print(distanceLeft);
  //  Serial.print(" cm");
  //  Serial.println();
  delay(10);
  return (duration / 58);
}

int checkRight()
{
  //  Serial.println("in checkright");

  // Clears the trigPin condition
  digitalWrite(trigPin3, LOW);
  delayMicroseconds(2);
  // Sets the trigPin HIGH (ACTIVE) for 10 microseconds
  digitalWrite(trigPin3, HIGH);
  delayMicroseconds(15);
  digitalWrite(trigPin3, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin3, HIGH);
  // Calculating the distance
  // Speed of sound wave divided by 2 (go and back)
  // Displays the distance on the Serial Monitor

  //  Serial.print("Etäisyys oikea ");
  //  Serial.print(distanceRight);
  //  Serial.print(" cm");
  //  Serial.println();
  delay(10);
  return (duration / 58);
}

void drive()
{
  //Serial.println("in drive");
  distanceFront = checkFront();
  distanceLeft = checkLeft();
  distanceRight = checkRight();

  driveForward(chosenGear);

  if (distanceFront < distanceToleranceFront)
  {
    setMotorsTo0();
    if (distanceLeft < distanceRight)
    {
      turnRight();
    }
    else if (distanceRight < distanceLeft)
    {
      turnLeft();
    }
    else if (distanceRight == distanceLeft)
    {
      turnLeft();
    }
  }
  else if (distanceLeft < distanceToleranceLeft)
  {
    setMotorsTo0();
    turnRight();
  }

  else if (distanceRight < distanceToleranceRight)
  {
    setMotorsTo0();
    turnLeft();
  }
}

void turnLeft()
{
  setMotorsTo0();
  reverseRightMotorOff();
  analogWrite(leftMotorF, gear0);
  reverseLeftMotorOn();
  analogWrite(rightMotorF, gear4);
  delay(500);
  setMotorsTo0();
}

void turnRight()
{
  setMotorsTo0();
  analogWrite(rightMotorF, gear0);
  reverseLeftMotorOff();
  reverseRightMotorOn();
  analogWrite(leftMotorF, gear4);
  delay(500);
  setMotorsTo0();
}

void reverseTimersInit()
{
  TCCR1A = B10000001;
  TCCR1B = B00000011;
  OCR1A = 0;

  TCCR2A = B00100001;
  TCCR2B = B00000100;
  OCR2B = 0;
}

void reverseLeftMotorOn()
{
  Serial.println("reverselefton");

  OCR1A = 255;
}
void reverseLeftMotorOff()
{
  Serial.println("reverseleftoff");

  OCR1A = 0;
}

void reverseRightMotorOn()
{
  Serial.println("reverserighton");
  OCR2B = 255;
}

void reverseRightMotorOff()
{
  Serial.println("reverserightoff");

  OCR2B = 0;
}

void setMotorsTo0()
{
  OCR1A = 0;
  OCR2B = 0;
  analogWrite(leftMotorF, 0);
  analogWrite(rightMotorF, 0);
}

void driveForward(int gears)
{
  Serial.println("in drive forward");
  Serial.println(gears);
  analogWrite(leftMotorF, gears);
  analogWrite(rightMotorF, gears);
}
