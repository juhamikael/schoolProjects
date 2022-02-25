## **Harjoitustyö**

## _5G00ET65-3003 Sulautetun järjestelmän ohjelmointi ja mikrokontrollerit_

#### [@Juha Mikael](https://github.com/juhamikael)

#### [@Joonas T](https://github.com/JoonasTontti)

#### [@Petri S](https://github.com/e6psuomi)

---


Keskeytys palveluina on ulkopuolinen keskeytys käynnistys/sammutus nappi. sisäisenä keskeytyksenä on watchdog. tietoa siirretään SPI:n kautta slavelta masterille ja TWI/I2C:llä lcd-monitorille.

Etummaisin painonappi on start ja stop nappi sillä aloitetaan ajaminen ja voidaan keskeyttää se minä hetkenä hyvänsä, jolloin auto lopettaa ajamisen heti kun mahdollista. Punaisista painonapeista etummainen muuttaa vaihdetta suuremmaksi ja taaempi pienemmäksi.

Potentiometrillä säädetään ajoaika 30 sekunnin välein. 30, 60, 90 ja 120 sekunnin ajoaikojen väliltä. Monitorissa näytetään vaihde, joka valittu ja ajo aika, joka valittu. Auton takana 4 lediä jotka kertovat vaihteen suuruuden vasemmalta katsottuna jos ensimmäinen ledi on päällä vaihde on 1 seuraava kertoo vaihteen2 kolmas vaihteen 3 ja viimeinen päällä vaihde on 4. 

Moottoreita ohjataan H-sillan avulla master arduinolla. Slave arduinolla otetaan vastaan ajoaika ja vaihteisto sekä tulostetaan lcd-monitorille niiden antamat arvot.
Master arduinolla otetaan vastaan anturien antamat datat, pyydetäään slavelta vaihde ja ajoaika käyttämällä SPI IO-lohkoa, masterilla ohjataan autoa.


## **Funktiot**

### **Master (Arduino #1)**

- byte transferAndWait (const byte what)
- ISR(INT0_vect)
- int checkFront()
- int checkLeft()
- int checkRight()
- void drive()
- void turnLeft()
- void turnRight()
- void reverseTimersInit()
- void reverseLeftMotorOn()
- void reverseLeftMotorOff()
- void reverseRightMotorOn()
- void reverseRightMotorOff()
- void setMotorsTo0()

### **Slave (Arduino #2)**

- countUp()
- countDown()
- turn_led_on(int counter_value, int led, int turn_on_value)
- int driveTime(int potValue)
- ISR (SPI_STC_vect)


