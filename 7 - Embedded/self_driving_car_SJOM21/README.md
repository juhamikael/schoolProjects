## **Harjoitustyö**

## _5G00ET65-3003 Sulautetun järjestelmän ohjelmointi ja mikrokontrollerit_

#### [@Juha Mikael](https://github.com/juhamikael)

#### [@Joonas T](https://github.com/JoonasTontti)

#### [@Petri S](https://github.com/e6psuomi)

---

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


