Ohjelmoinnin edistyneet piirteet -- OSA II -- Harjoitukset 1

**Tehtävä 1 (2p). Henkilo --luokan toteutus ja käyttö.** Luo projekti,
jossa on kolme tiedostoa

Henkilo.h

Henkilo.cpp

main.cpp

Kirjoita Henkilo-luokan esittely (Henkilo.h), jossa on kaksi
jäsenmuuttujaa (atribuuttia):

> nimi (string) ika (int)

Luokassa on jäsenfunktioina (metodeina) seuraavat:

> *setNimi*, joka saa yhden kokonaislukuparametrin: nimi *setIka*, joka
> saa kokonaislukuparametrina iän
>
> *getNimi*, joka palauttaa nimen
>
> *getIka,* joka palauttaa kuukauden
>
> *tulostaHenkilonTiedot, joka tulostaa ruudulle henkilön nimen ja iän
> esimerkiksi seuraavaan tyyliin:*

*Nimi: Kalle*

*Ikä: 20*

Kirjoita pääohjelma (main.cpp), jossa luot kaksi henkilöä ja aseta
jäsenfunktioita (metodeja) käyttämällä henkilölle nimen ja iän ja
tulostat henkilön tiedot.

**Tehtävä 2 (2p). Päiväys --luokan toteutus ja käyttö.** Luo projekti,
jossa on kolme tiedostoa

Paivays.h

Paivays.cpp

mainPaivays.cpp

Kirjoita Paivays-luokan esittely (Paivays.h), jossa on kolme
jäsenmuuttujaa (atribuuttia):

> paiva
>
> kuukausi vuosi

Luokassa on jäsenfunktioina (metodeina) seuraavat:

> *setPaiva*, joka saa yhden kokonaislukuparametrin: paiva
>
> *setKuukausi*, joka saa kokonaislukuparametrina kuukauden *setVuosi*,
> , joka saa kokonaislukuparametrina vuoden
>
> *getPaiva*, joka palauttaa päivän
>
> *getKuukausi,* joka palauttaa kuukauden *getVuosi,* joka palauttaa
> vuoden
>
> *tulostaPaivays*, joka tulostaa näytölle paivayksen päivän, kuukauden
> ja vuoden pistein eroteltuna.

Toteuta Paivays-luokka (Paivays.cpp).

Kirjoita pääohjelma (mainPaivays.cpp), jossa luot kaksi päiväysoliota:
tanaan ja huomenna. Aseta olioiden tilat sopiviin arvoihin. Tulosta
lopuksi päiväykset näytölle käyttämällä olion jäsenfunktiota (metodia).

**Tehtävä 3 (1p).** Laajenna nyt *Paivays* luokkaa siten, että

> voit kysyä käyttäjältä päivämäärää (uusi metodi). Metodin sisällä
> kysyt käyttäjältä päivän, kuukauden ja vuoden ja asetat olion
> tietojäsenille uuden arvon.
>
> lisätä päivämäärään yhden päivän (uusi metodi). Huomoi myös kuukausien
> ja vuosien ja tuntien päivittäminen tarvittaessa. Testaa laajennusten
> toimintaa pääohjelmalla.
