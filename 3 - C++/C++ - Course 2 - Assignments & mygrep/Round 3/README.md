# Ohjelmointikielten edistyneet piirteet

## Kolmannet viikkoharjoitukset

**1.**  Kirjoita aliohjelma **sekunnit_ajaksi**, joka saa 1.
    parametrina sekunttien määrän vuorokauden alusta alkaen
    (kellonlyömästä 00:00:00 alkaen) ja palauttaa saman ajan tunteina,
    minuutteina ja sekunteina. Tee myös pääohjelma, jolla testaat em.
    aliohjelmaa. Esimerkiksi jos sekuntimäärä = 10000, niin vastaava
    aika tunteina, minuutteina ja sekunteina on 2 tuntia 46 minuuttia 40
    sekuntia. Huomaa, että aliohjelmasta pitää palauttaa useampia
    tietoja; sovella tässä viittausparametreja. 

#### 1. Ajoesimerkki: 
> **10000 sekuntia on 2 tuntia 46 minuuttia 40 sekuntia. **

---

**2.**  Tee 1 tehtävän aliohjelmalle käänteinen aliohjelma
    **aika_sekunneiksi**, joka saa parametreina tunnit, minuutit ja
    sekunnit vuorokauden alusta lukien ja palautaa paluuarvonaan
    parametreja vastaavan sekuntimäärän vuorokauden alusta lukien.
    Testaa aliohjelmasi toimintaa sopivalla pääohjelmalla; esimerkiksi
    voit kutsua pääohjelmassasi ensin **aika_sekunneiksi** --aliohjelmaa
    ja sen jälkeen aliohjelmaa **sekunnit_ajaksi** (= harjoituksen 2
    ratkaisu), jolle annat sekuntimääränä 1. aliohjelmakutsun
    palauttaman arvon. 2. aliohjelmakutsun palauttaman ajankohdan
    pitäisi olla sama kuin 1. aliohjelmakutsulle annettiin parametrina.

#### 2. Ajoesimerkki:
> **2 tuntia 46 minuuttia 40 sekuntia on 10000 sekuntia joka on puolestaan 2 tuntia 46 minuuttia 40 sekuntia.**

---

**3.**  Tee pääohjelma, josta löytyy seuraavat asiat / käsittelyt (tehtävä
    saattaa vaikuttaa pitkältä mutta ratkaisu ei sitä ole koska jokaista
    kysyttyä asiaa kohden tehdään suurinpiirtein yksi ohjelmalause!
    Pääasiana on treenata C++ -tietueiden käyttöä):

-   Ohjelman alussa luot tietuetyypin **aika_ty**, joka sisältää kentät
    ajankohdan tunneille, minuuteille ja sekunneille.

-   Tee pääohjelman alussa aikatietuetyyppiä oleva muuttuja.

-   Lue sisältö aikamuuttujaasi päätteeltä. Syöte ohjelmalle voidaan
    antaa vaikkapa seuraavasti:

**Anna tunnit: 12**

**Anna minuutit: 33**

**Anna sekunnit: 44**

missä käyttäjän syötteet on merkitty harmaalla taustavärillä.

-   Jos luetussa syötteessä oli virhe (tunnit ei välillä 0 -- 23 jne.) ,
    tästä annetaan virheilmoitus näytölle.

-   Mikäli ajankohdan tunnit, minuutit ja sekunnit olivat kunnossa,
    ohjelma tulostaa syötetyn ajankohdan päätteelle muodossa hh:mm:ss
    (hh = tunnit, mm = minuutit, ss = sekunnit)

-   Tee vielä osoitinmuuttuja, joka osoittaa aiemmin tekemääsi
    aikatietuemuuttujaan. Tulosta aikatietumuuttujan sisältö uudestaan
    näytölle käyttäen vain tätä osoitinmuuttujaa.

-   Tee ohjelmaasi kaksi uutta aikatietuemuuttujaa joista toiseen asetat
    arvoksi jonkin järkevän ajankohdan. Kopioi sitten tämän muuttujan
    arvo siihen toiseen tässä vaiheessa luomaasi aikatietumuuttujaan.
    Tee tämän jälkeen vertailulause jossa vertaat näiden kahden
    muuttujan sisältöä keskenään ja jos ne ovat samat (pitäisi olla)
    tulosta näytölle ilmoitus: "Sisällöt ovat samat."

4.  Tee aliohjelma **aikojen_erotus**, jolle välitetään parametreina
    kaksi ajankohtaa (tyyppiä **aika_ty**, ks. edellinen tehtävä).
    Aliohjelma laskee näiden kahden välitetyn ajankohdan erotuksen ja
    palauttaa sen paluuarvonaan (paluuarvo on myös tyyppiä **aika_ty**).
    Oletetaan parametrien arvojen olevan järkevät ja 2. parametrin
    ajankohta on suurempi tai yhtäsuuri kuin 1. parametrin; molemmat
    ajankohdat ovat saman vuorokauden sisällä.

> Tee myös pääohjelma, jolla testaat aliohjelman toiminnan. Pääohjelma
> kysyy käyttäjältä kahta ajankohtaa, joiden erotuksen aliohjelma
> laskee. Pääohjelma tulostaa sitten aliohjelman palauttaman erotuksen
> näytölle. Jälleen oletetaan käyttäjän syötteiden olevan järkevät.
>
> Vinkki: eräs vaihtoehto on muuntaa molemmat ajankohdat sekunneiksi,
> laskea erotus sekunteina ja muuntaa tämä erotus (sekunteina) jälleen
> tunneiksi, minuuteiksi ja sekunneiksi. Tässä kannattaa hyödyntää
> edellisen viikon **aika_sekunneiksi()**- ja **sekunnit_ajaksi()**
> --aliohjelmia.
