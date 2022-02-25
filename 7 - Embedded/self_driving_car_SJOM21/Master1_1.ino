//watchdogin kirjaston lisäys
#include<avr/wdt.h>
#include<avr/io.h>
//SPI kirjaston lisäys
#include <SPI.h>

//asetetaan echopinnni pinni vasemmalle ultraäänisensorille
#define echoPin1 A4 
//asetetaan triggeri pinni vasemmalle ultraäänisensorille
#define trigPin1 A5 
//asetetaan echopinnni pinni keskimmäiselle etu ultraäänisensorille
#define echoPin2 A2 
//asetetaan triggeri pinni keskimmäiselle etu ultraäänisensorille
#define trigPin2 A3 
//asetetaan echopinnni pinni oikealle ultraäänisensorille
#define echoPin3 A0 
//asetetaan triggeri pinni oikealle ultraäänisensorille
#define trigPin3 A1 

//asetetaan digitaali pinnit moottoreiden ohjaukselle
//vasen moottori eteenpäin
const int leftMotorF = 6;
//oikeamoottori eteenpäin
const int rightMotorF = 5;
//vasenmoottori taaksepäin
const int leftMotorR = 9;
//oikeamoottori taakseppäin
const int rightMotorR = 3;

//ajon käynnistys ja lopetusnapin digitaali pinni
const int startButtonPin = 2;
//
bool start = false;

//muuttuja ultraääni sensoreille 
long duration = 0;
//muuttujat etäisyyksille
int distanceLeft = 0;
int distanceRight = 0;
int distanceFront = 0;

//muuttujat joilla valitaan etäisyydet joilla auton kääntymistä määritellään
//luvut cm etäisyyksiä
//etuetäisyys
int distanceToleranceFront = 30;
// vasen etäisyys
int distanceToleranceLeft = 30;
//oikea etäisyys
int distanceToleranceRight = 30;

//vaihteiden muuttujat
int gear0 = 0;
int gear1 = (255 / 4);
int gear2 = (255 / 2);
int gear3 = (255 / 4 * 3);
int gear4 = 255;     
//valitun vaihteen muuttuja
int chosenGear = gear0;

//muuttujat SPI:n avulla slave arduinosta saaduille arvoille
// vaihteen numeron muuttuja 0-4 vaihteille
int gearNumber = 0;
//ajoajan pituus 30, 60, 90, 120 sekuntia
int runTime = 0;

//ajon aloitus ajalle muuttuja
long startTime = 0;

void setup (void)
{
  Serial.begin (115200);
  //Serial.println (); //debuggausta varten

  //asetetaan SS high tilaan SPI data siirtoa varten 
  //jolla asetetaan tämä arduino masteriksi
  digitalWrite(SS, HIGH);  

  //asetetaan SCK, MOSI, SS ulostuloiksi 
  //SCK, MOSI, LOW tilassa
  //aloitetaan SPI master tilassa
  SPI.begin ();

  // hidastetaan masteria
  SPI.setClockDivider(SPI_CLOCK_DIV8);

  //moottorien ohjauspinnit 9, 3, 5, 6
  //asetetaan ulostuloiksi
  pinMode(9, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);

  //asetetaan sensorien triggerpinnit A5, A3, A1 ulostuloiksi
  // ja sensorien echopinnit A0, A2, A4 sisääntuloiksi
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
  
  //innitialisoitaan peruutus timer1 ja timer2 rekistereillä
  reverseTimersInit();

  //asetetaan moottorit asentoon 0
  setMotorsTo0();
  
  //enabloi globaalit interruptit
  sei();

}  // end of setup

//datan siirto funktio SPI avulla
byte transferAndWait (const byte what)
{
  //luodaan byte muuttuja ja tehdään SPI data siirto
  byte a = SPI.transfer (what);
  delayMicroseconds (20);
  return a;
} // end of transferAndWait

void loop (void)
{
//luodaan byte muuttujat SPI siirron vastaan ottoa varten
  byte a, b;

  if (start == true) {

    // enabloidaan slave select
    digitalWrite(SS, LOW);
    // tehdään SPI siirto ja annetaan slavelle että halutaan 
    //vaihteen numero
    transferAndWait ('g');  
    // annetaan slavelle turhaa dataa jolla ei tehdä mitään
    transferAndWait (00);
    // lähetetään turhaa dataa ja vastaan otetaan haluttu data
    // vaihteiston numero
    a = transferAndWait (00);

    // disabloidaan slave select
    digitalWrite(SS, HIGH);
    Serial.println ("Adding results:");
    Serial.println (a, DEC);
    delay(60);
    // enabloidaan slave select
    digitalWrite(SS, LOW);

    // siirretään tieto slavelle että halutaan ajoaika
    transferAndWait ('t');  
    // annetaan turhaa dataa slavelle jolla ei tehdä mitään
    transferAndWait ('t');
    //läheteään turhaa dataa ja vastaanotetaan ajoaika
    b = transferAndWait (00);



    // disabloidaan slave select
    digitalWrite(SS, HIGH);
    Serial.println ("Subtracting results:");
    Serial.println (b, DEC);
    //muutetaan ajoaika ja vaihteisto bytet inteiksi
    gearNumber = a;
    runTime = b;
    Serial.println(gearNumber);
    Serial.println(runTime);

    //valitaann vaihde slavelta saadun vaihteen mukaiseksi
    //jos saatu vaihde on 0 asetetaan start falseksi
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

    //otetaan tämän hetken millis jonka avulla ajoaika määritellään
    startTime = millis();
    Serial.println(chosenGear);
    //luodaan tämänhetken millis aika jolla katsotaan kuinka kauan ajettu
    unsigned long currentTime = millis();
    //aktivoidaan watchdog
    setWatchdog();
    //auto ajossa kun start on true ja ajo aikaa jäljellä
    while ((currentTime - startTime) < (runTime * 1000) && start == true)
    {
      //aktivoidaan ajo
      drive();
      //tullaan ajosta ulos ja resetoidaan watchdog aika
      wdt_reset();
      //otetaan ajettu aika
      currentTime = millis();
    }
    //asetetaan moottorit 0 tilaan
    setMotorsTo0();
    //disabloidaan watchdog
    wdt_disable();
    //muutetaan start false tilaan jolloin ei auto voi olla ajossa
    start = false;
  }


}  // end of loop

//start napin interrupt service jolla aloitetaan ajo ja voidaan keskeyttää se
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

//funktio jolla tarkastetaan edessä olevien esteiden etäisyys
int checkFront()
{
  //  Serial.println("in checkfront");
  // puhdistetaan trigpin
  digitalWrite(trigPin2, LOW);
  delayMicroseconds(2);
  // asetetaan trigPin HIGH (ACTIVE) 15 mikrosekunniksi
  digitalWrite(trigPin2, HIGH);
  delayMicroseconds(15);
  digitalWrite(trigPin2, LOW);
  // luetaan echoPin, palauttaa äänen kulkeman ajan mikrosekunneissa
  duration = pulseIn(echoPin2, HIGH);
 
  //for debug
  // Displays the distance on the Serial Monitor 
  //  Serial.print("Etäisyys etu ");
  //  Serial.print(distanceFront);
  //  Serial.print(" cm");
  //  Serial.println();
  
  delay(10); 
  
  // lasketaan etäisyys ja palautetaann se
  return (duration / 58);
}

//funktio jolla tarkastetaan vasemmalla olevien esteiden etäisyys
int checkLeft()
{
  //Serial.println("in checkLeft");
  // puhdistetaan trigpin
  digitalWrite(trigPin1, LOW);
  delayMicroseconds(2);
  // asetetaan trigPin HIGH (ACTIVE) 15 mikrosekunniksi
  digitalWrite(trigPin1, HIGH);
  delayMicroseconds(15);
  digitalWrite(trigPin1, LOW);
  // luetaan echoPin, palauttaa äänen kulkeman ajan mikrosekunneissa
  duration = pulseIn(echoPin1, HIGH);
 
  //for debug
  // Displays the distance on the Serial Monitor
  // Serial.print("Etäisyys vasen ");
  //  Serial.print(distanceLeft);
  //  Serial.print(" cm");
  //  Serial.println();
  
  delay(10);
  
  // lasketaan etäisyys ja palautetaann se
  return (duration / 58);
}

//funktio jolla tarkastetaan oikealla olevien esteiden etäisyys
int checkRight()
{
  //  Serial.println("in checkright");
  // puhdistetaan trigpin
  digitalWrite(trigPin3, LOW);
  delayMicroseconds(2);
  // asetetaan trigPin HIGH (ACTIVE) 15 mikrosekunniksi
  digitalWrite(trigPin3, HIGH);
  delayMicroseconds(15);
  digitalWrite(trigPin3, LOW);
  // luetaan echoPin, palauttaa äänen kulkeman ajan mikrosekunneissa
  duration = pulseIn(echoPin3, HIGH);
 
  //for debug
  // Displays the distance on the Serial Monitor
  //  Serial.print("Etäisyys oikea ");
  //  Serial.print(distanceRight);
  //  Serial.print(" cm");
  //  Serial.println();
  
  delay(10);
  
  // lasketaan etäisyys ja palautetaann se
  return (duration / 58);
}

//ajo funktio
void drive() {
  //testausta varten
  //Serial.println("in drive");

  //tarkastetaan etäisyydet
  distanceFront = checkFront();
  distanceLeft = checkLeft();
  distanceRight = checkRight();

  //aloitetaan ajaminen
  driveForward(chosenGear);

  //etäisyyksien mukaan käännytään jos tarvitsee
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
    turnRight();

  }
  else if (distanceRight < distanceToleranceRight)
  {
    turnLeft();

  }

}

//vasemmalle kääntymisen funktio
void turnLeft()
{
  //asetetaan moottorit 0 tilaan
  setMotorsTo0();
  //sammutetaan oikea peruutus
  reverseRightMotorOff();
  //sammutetaan vasen eteenpäin ajo
  analogWrite(leftMotorF, gear0);
  //käynnistetään vasemmanmoottorin peruutus
  reverseLeftMotorOn();
  //aktivoidaan oikeanmoottorin ajo
  analogWrite(rightMotorF, gear4);
  //ajetaan 0,5 sekuntia
  delay (500);
  //asetetaan moottorit 0 tilaan
  setMotorsTo0();
}

void turnRight()
{
  //asetetaan moottorit 0 tilaan
  setMotorsTo0();
  //sammutetaan oikea eteenpäin ajo
  analogWrite(rightMotorF, gear0);
  //sammutetaan vasen peruutus
  reverseLeftMotorOff();
  //aktivoidaan oikeanmoottorin peruutus
  reverseRightMotorOn();
  //aktivoidaan vaemmanmoottorin ajo
  analogWrite(leftMotorF, gear4);  
  //ajetaan 0,5 sekuntia
  delay(500);
  //asetetaan moottorit 0 tilaan
  setMotorsTo0();
}

//peruutuksen initoinit funktio
void reverseTimersInit()
{
  //timer1 initiointi rekistereillä
  //puhdistetaan OC1A vertailu ja aktivoidaan PWM phase correct 8 bitti muodossa
  TCCR1A = B10000001;
  //valitaan kello /64
  TCCR1B = B00000011;
  //asetetaan ulos tulo tilaan 0
  OCR1A = 0;

  //timer2 aktivointi rekistereillä
  //puhdistetaan OC2B vertailu ja aktivoidaan PWM phase correction
  TCCR2A = B00100001;
  //valitaan kello /64
  TCCR2B = B00000100;
  //asetetaan ulos tulo tilaan 0
  OCR2B = 0;

}

//vasemman moottorin peruutus aktivointi
void reverseLeftMotorOn()
{
  Serial.println("reverselefton");

  OCR1A = 255;
}

//vasen moottori peruutus sammutus
void reverseLeftMotorOff()
{
  Serial.println("reverseleftoff");

  OCR1A = 0;
}

//oikeamoottori peruutus aktivointi
void reverseRightMotorOn()
{
  Serial.println("reverserighton");
  OCR2B = 255;
}

//oikeamoottori peruutus sammutus
void reverseRightMotorOff()
{
  Serial.println("reverserightoff");

  OCR2B = 0;
}

//moottoreiden sammutus kaikki ulos tulot asentoon 0
void setMotorsTo0()
{
  OCR1A = 0;
  OCR2B = 0;
  analogWrite(leftMotorF, 0);
  analogWrite(rightMotorF, 0);
}

//eteenpäin ajo
void driveForward(int gears)
{
  Serial.println("in drive forward");
  Serial.println(gears);
  //asetetaan ajo nopeus
  analogWrite(leftMotorF, gears);
  analogWrite(rightMotorF, gears);
}

//watchdogin luonti
void setWatchdog()
{
  // resetoidaan watchdogin aika
  wdt_reset();
  // resetoidaan flagit
  MCUSR = 0;
  // aloitetaan ajastettu resetti
  WDTCSR |= (1 << WDCE) | (1 << WDE);
  // asetetaan watchdogin reset aika 8s
  WDTCSR = (1 << WDE) | (1 << WDP3) | (1 << WDP0);

}
