Ohjelmoinnin edistyneet piirteet -- OSA II -- Harjoitukset 5

**Periytyminen**. Tutkitaan seuraavaa UML-luokkakaaviota

![](media/image1.jpeg){width="4.846527777777778in"
height="3.5368055555555555in"}

**Tehtävä 1-3.** Toteuta luokat Opettaja ja Opiskelija. Yllä olevasta
kuvasta puuttuvat getterit ja setterit, joten lisäile ne mukaan. Lisää
myös kaikkiin rakentajiin ja purkajiin tulostukset, esim: \"Henkilön
oletusrakentaja\". Muut lisättävät metodit:

**Opettaja**

tulostaTiedot() -- tulostaa opettajan kaikki tiedot mukaan lukien
kurssivektorin sisällön eli vastuukurssien niet (kuten videoluennossa)

poistaKurssi() -- poistaa kurssin kurssivektorista, saa parametrina
kurssin nimen (haku ja vektorin erase --metodi)

lisääKurssi() -- lisää uuden kurssin kurssivektoriin

**Opiskelija**

lisääKurssi() -- lisää uuden kurssin kurssivektoriin

tulostaTiedot()- tulostaa opiskelijan tiedot

lisääOpintopisteitä() -- saa parametrina opintopisteet (int) ja lisää
opiskelijan opintopistesaldoa

Tee myös pääohjelma, jossa luot opiskelijoita ja opettajia ja testaat
luokkien toimivuutta.

**Tehtävä 4.** Tee pääohjelma, jossa luot kolme oliota jokaisesta
luokasta siten, että kaytetään:

1)  oletusrakentaa

2)  parametrillista rakentajaa ja

3)  kopiorakentajaa

**Tehtävä 5 -- Erilaiset henkilöt yhteisessä, dynaamisessa
tietorakenteessa**

Lisää pääohjelmaan vektori, jonka sisältö on Henkilo -osoittimia:

vector\<Henkilo\*\>

Lisää henkilö --vektoriin (push_back) nyt dynaamisesti luotuja (new:llä)
Henkilöitä, Opiskelijoita ja Opiskelijoita. Voit luontevasti tehdä näin,
koska sekä Opiskelija että Opettaja ovat myös Henkilöitä (polymorfismi).
Katso, että Henkilo --luokaltasikin löytyy "tulostaTiedot() const"
--metodi, jossa tulostat henkilön tiedot.

Käy läpi vektoria ja katso, mitä metodeja voit vektorin kautta kutsua?
Käy vektori for - silmukalla läpi ja tulosta kaikkien tiedot
tulostaTiedot() --metodia kutsumalla.
