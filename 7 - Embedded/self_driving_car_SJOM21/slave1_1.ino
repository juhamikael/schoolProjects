//Wire kirjast I2C:tä varten
#include <Wire.h>
//kirjasto lcd monitorille
#include <LiquidCrystal_I2C.h>

//asetetaan lcd arvot
//osoitteeksi 0x27, 20 characteria, 4 riviä
LiquidCrystal_I2C lcd(0x27, 20, 4);

//vaihteiston vaihto pinnien asetus
const int  Up_buttonPin   = 3;
const int  Down_buttonPin = 2;

//vaihteiston vaihtoa varten muuttujat
int up_buttonState = 0;
int up_lastButtonState = 0;
int down_buttonState = 0;
int down_lastButtonState = 0;
bool bPress = false;
//vaihteen numero
int counter = 0;

//ledien digitaaliset pinnit
int led_1 = 4;
int led_2 = 5;
int led_3 = 6;
int led_4 = 7;

//ajoajan potentiaalipinnin muuttuja
int potValue = 0;
//ajoajan pinni
int potPin = A6;
//ajoajan muutoksen muuttuja
int timer = 0;
// ajoaika
int drive_time = 0;

//monitorin puhdistuksen avustus muuttujat
int temp1 = 0;
int temp2 = 1;

//komento jonka mukaan annetaan data masterille
volatile byte command = 0;

void setup (void)
{
  //asetetaan vaihteiden muuttajien pinnit sisäänntuloiksi
  pinMode( Up_buttonPin , INPUT_PULLUP);
  pinMode( Down_buttonPin , INPUT_PULLUP);

  // asetetaan master in slave out
  pinMode(MISO, OUTPUT);

  // asetetaan ledien pinnit ulostuloiksi
  pinMode( led_1, OUTPUT);
  pinMode( led_2, OUTPUT);
  pinMode( led_3, OUTPUT);
  pinMode( led_4, OUTPUT);

  //asetetaan potentiaali pinnni sisäänntuloksi
  //ajoaikaa varten
  pinMode(potPin, INPUT);

  //initioidaan lcd
  lcd.init();
  //asetetaan lcd:n takavalo
  lcd.backlight();

  //asetetaann SPI slve olotilan
  SPCR |= _BV(SPE);
  // käynnistetään interruptit
  SPCR |= _BV(SPIE);

}  // end of setup


// SPI keskeytys
ISR (SPI_STC_vect)
{
  //väliaikainen byte muuttuja
  byte c = SPDR;

  //komentojen mukaan toiminta
  switch (command)
  {
    // ei komentoa
    case 0:
      command = c;
      SPDR = 0;
      break;

    // vaihde komento
    case 'g':
      SPDR = counter;
      break;

    // aika komento
    case 't':
      SPDR = drive_time;
      break;

  } // end of switch

}  // end of interrupt service routine (ISR) SPI_STC_vect

void loop (void)
{

  //luetaan aika potentiometristä
  potValue = analogRead(potPin);
  //lasketaan ajoaika
  drive_time = driveTime(potValue);
  //clearataan lcd jos aika muuttuu suuremmasta
  //kuin 100 pienemmäksi kuin 100
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

  //asetetaan lcd:lle tiedot
  lcd.setCursor(0, 0);
  lcd.print("Speed(1-4): ");
  lcd.print(counter);
  lcd.setCursor(0, 1);
  lcd.print("Time:");
  lcd.print(drive_time);

  //otetaan vastaan vaihteen suureneminen
  countUp();
  //otetaan vastaan vaihten pieneneminen
  countDown();

  //ledien tila asetetaan vaihteen suuruuden mukaan
  turn_led_on(counter, led_1, 1);
  turn_led_on(counter, led_2, 2);
  turn_led_on(counter, led_3, 3);
  turn_led_on(counter, led_4, 4);


  Serial.print("potentiometri ");
  Serial.print(drive_time);
  Serial.println();

  // muutetaan vaihteen suuruutta jos parametrien ulkopuolella
  if (counter > 4) {
    counter = 4;
  }
  else if (counter < 0) {

    counter = 0;
  }


  // jos SPI ei aktiivinen, puhdistetaan komento
  if (digitalRead (SS) == HIGH)
    command = 0;
}  // end of loop

//vaihteen suurenemisen vastaan oton funtio
void countUp()
{
  up_buttonState = digitalRead(Up_buttonPin);
  // compare the buttonState to its previous state
  if (up_buttonState != up_lastButtonState) {
    // if the state has changed, increment the counter
    if (up_buttonState == LOW) {
      bPress = true;
      // if the current state is HIGH then the button went from off to on:
      counter++;
      Serial.println("on");
      Serial.print("number of button pushes: ");
      Serial.println(counter);
    } else {
      // if the current state is LOW then the button went from on to off:
      Serial.println("off");
    }
    // Delay a little bit to avoid bouncing
    delay(50);
  }
  // save the current state as the last state, for next time through the loop
  up_lastButtonState = up_buttonState;
}

//vaihteen pienenemisen funktio
void countDown()
{
  down_buttonState = digitalRead(Down_buttonPin);
  // compare the buttonState to its previous state
  if (down_buttonState != down_lastButtonState) {
    // if the state has changed, increment the counter
    if (down_buttonState == LOW) {
      bPress = true;
      // if the current state is HIGH then the button went from off to on:
      counter--;
      Serial.println("on");
      Serial.print("number of button pushes: ");
      Serial.println(counter);
    } else {
      // if the current state is LOW then the button went from on to off:
      Serial.println("off");
    }
    // Delay a little bit to avoid bouncing
    delay(50);
  }
  // save the current state as the last state, for next time through the loop
  down_lastButtonState = down_buttonState;
}

//ledien aktivointi ja deaktivointi
void turn_led_on(int counter_value, int led, int turn_on_value) {
  if (counter_value != turn_on_value) {
    digitalWrite(led, LOW);
  } else {
    digitalWrite(led, HIGH);
  }
}

//ajoajan laskenta funtio
int driveTime(int potValue) {

  if (potValue < 200) {
    timer = 30;
  } else if ((potValue >= 200 ) && ( potValue < 400)) {
    timer = 60;
  } else if ((potValue >= 400 ) && ( potValue < 600)) {
    timer = 90;
  } else if ((potValue >= 600)) {
    timer = 120;
  }
  return timer;
}
