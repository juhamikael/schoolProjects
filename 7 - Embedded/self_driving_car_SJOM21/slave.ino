#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 20, 4); // set the LCD address to 0x27 for a 16 chars and 2 line display

const int Up_buttonPin = 3;
const int Down_buttonPin = 2;

int counter = 0;
int up_buttonState = 0;
int up_lastButtonState = 0;
int down_buttonState = 0;
int down_lastButtonState = 0;

byte sendTime;
byte sendGear;

int led_1 = 4;
int led_2 = 5;
int led_3 = 6;
int led_4 = 7;

int potValue = 0;
int potPin = A6;
bool bPress = false;

int timer = 0;

int drive_time = 0;
int temp1 = 0;
int temp2 = 1;

volatile byte command = 0;

void setup(void)
{

  pinMode(Up_buttonPin, INPUT_PULLUP);
  pinMode(Down_buttonPin, INPUT_PULLUP);
  // have to send on master in, *slave out*
  pinMode(MISO, OUTPUT);

  pinMode(led_1, OUTPUT);
  pinMode(led_2, OUTPUT);
  pinMode(led_3, OUTPUT);
  pinMode(led_4, OUTPUT);

  pinMode(potPin, INPUT);

  lcd.init(); // initialize the lcd
  lcd.backlight();
  // turn on SPI in slave mode
  SPCR |= _BV(SPE);

  // turn on interrupts
  SPCR |= _BV(SPIE);

} // end of setup

// SPI interrupt routine
ISR(SPI_STC_vect)
{
  byte c = SPDR;

  switch (command)
  {
  // no command? then this is the command
  case 0:
    command = c;
    SPDR = 0;
    break;

  // add to incoming byte, return result
  case 'g':
    SPDR = counter; // add 15
    break;

  // subtract from incoming byte, return result
  case 't':
    SPDR = drive_time; // subtract 8
    break;

  } // end of switch

} // end of interrupt service routine (ISR) SPI_STC_vect

void loop(void)
{

  potValue = analogRead(potPin);
  drive_time = driveTime(potValue);
  if (drive_time > 100)
  {
    temp1 = 1;
  }
  else if ((drive_time < 100) && (temp1 == 1))
  {
    temp2 = 0;
  }
  if ((temp2 == 0) && (temp1 == 1))
  {
    lcd.clear();
    temp2 = 1;
    temp1 = 0;
  }
  lcd.setCursor(0, 0);
  lcd.print("Speed(1-4): ");
  lcd.print(counter);
  lcd.setCursor(0, 1);
  lcd.print("Time:");
  lcd.print(drive_time);

  countUp();
  countDown();

  turn_led_on(counter, led_1, 1);
  turn_led_on(counter, led_2, 2);
  turn_led_on(counter, led_3, 3);
  turn_led_on(counter, led_4, 4);

  Serial.print("potentiometri ");
  Serial.print(drive_time);
  Serial.println();

  if (counter > 4)
  {
    counter = 4;
  }
  else if (counter < 0)
  {

    counter = 0;
  }

  // if SPI not active, clear current command
  sendTime = 30;
  if (digitalRead(SS) == HIGH)
    command = 0;
} // end of loop

void countUp()
{
  up_buttonState = digitalRead(Up_buttonPin);
  // compare the buttonState to its previous state
  if (up_buttonState != up_lastButtonState)
  {
    // if the state has changed, increment the counter
    if (up_buttonState == LOW)
    {
      bPress = true;
      // if the current state is HIGH then the button went from off to on:
      counter++;
      Serial.println("on");
      Serial.print("number of button pushes: ");
      Serial.println(counter);
    }
    else
    {
      // if the current state is LOW then the button went from on to off:
      Serial.println("off");
    }
    // Delay a little bit to avoid bouncing
    delay(50);
  }
  // save the current state as the last state, for next time through the loop
  up_lastButtonState = up_buttonState;
}

void countDown()
{
  down_buttonState = digitalRead(Down_buttonPin);
  // compare the buttonState to its previous state
  if (down_buttonState != down_lastButtonState)
  {
    // if the state has changed, increment the counter
    if (down_buttonState == LOW)
    {
      bPress = true;
      // if the current state is HIGH then the button went from off to on:
      counter--;
      Serial.println("on");
      Serial.print("number of button pushes: ");
      Serial.println(counter);
    }
    else
    {
      // if the current state is LOW then the button went from on to off:
      Serial.println("off");
    }
    // Delay a little bit to avoid bouncing
    delay(50);
  }
  // save the current state as the last state, for next time through the loop
  down_lastButtonState = down_buttonState;
}

void turn_led_on(int counter_value, int led, int turn_on_value)
{
  if (counter_value != turn_on_value)
  {
    digitalWrite(led, LOW);
  }
  else
  {
    digitalWrite(led, HIGH);
  }
}

int driveTime(int potValue)
{

  if (potValue < 200)
  {
    timer = 30;
  }
  else if ((potValue >= 200) && (potValue < 400))
  {
    timer = 60;
  }
  else if ((potValue >= 400) && (potValue < 600))
  {
    timer = 90;
  }
  else if ((potValue >= 600))
  {
    timer = 120;
  }
  return timer;
}
