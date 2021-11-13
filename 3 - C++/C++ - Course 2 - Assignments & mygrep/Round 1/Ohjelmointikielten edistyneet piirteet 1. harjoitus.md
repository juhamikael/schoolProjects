# Ohjelmointikielten edistyneet piirteet

## Ensimmäiset viikkoharjoitukset

1.  Perusosoitintehtävä: tee ohjelma jonka ohjelmakoodista löytyy
    seuraavat toimenpiteet kerrotussa järjestyksessä:

    a.  Tee osoitinmuuttuja kokonaislukutyyppiseen tietoon ja sijoita
        siihen toisen tekemäsi kokonaislukutyyppisen muuttujan osoite.

    b.  Sijoita jälkimmäiseen muuttujaan arvo 7 käyttäen hyväksi
        ainoastaan siihen osoittavaa osoitinmuuttujaa.

    c.  Tulosta edellä mainittujen osoitinmuuttujan että
        kokonaislukumuuttujan osoitteet ja sisällöt: mitä havaintoja
        teet ?

    d.  Totea ohjelmakoodin avulla että osoittimiin liittyvät
        operaattorit \* ja & kumoavat toistensa vaikutuksen.

    e.  Tulosta jokaisen tekemäsi muuttujan koot tavuina.

    f.  Aja tämän jälkeen ohjelmaasi eteenpäin lause kerrallaan
        debuggerin avulla ja seuraa muuttujien arvojen kehittymistä sekä
        ohjelman tulostamia arvoja.

    g.  Tee toinen kokonaislukumuuttujaan osoittava osoitinmuuttuja ja
        jätä se alustamatta.

    h.  Kokeile koodissasi tämän jälkeen ko. muuttujan avulla sen
        osoittamaan sisältöön viittaaminen. Onnistuuko tämä ?

    i.  Kokeile vielä sijoittaa tähän jälkimmäiseen osoitinmuuttujaan
        arvo nullptr ja kokeile viitata tämän jälkeen ko.
        osoitinmuuttujan avulla osoitettuun sisältöön.

> Alla esimerkki siitä mitä tämä ohjelma voisi tulostaa:
>
> muuttuja_p = 0x7ffeef4549f8
>
> muuttuja = 7
>
> &muuttuja_p = 0x7ffeef4549f0
>
> &muuttuja = 0x7ffeef4549f8
>
> \*&muuttuja = 7
>
> &\*muuttuja_p = 0x7ffeef4549f8
>
> sizeof(muuttuja) = 4
>
> sizeof(muuttuja_p) = 8
>
> Segmentation fault: 11
>
> Ohjelman tulosteet eivät siten ole avainjuttu tässä tehtävässä vaan
> osoitinten pyydetyn mukainen pyörittely. Voit ajaa ohjelmaasi vaikka
> debuggerilla rivi kerrallaan ja varmistua siten siitä että se tekee
> pyydetyt asiat.

2.  Tee aliohjelma swap, joka saa parametrikseen kaksi int-tyyppistä
    arvoa ja vaihtaa parametrien sisällöt keskenään. Vaihtamisen tulos
    pitää näkyä kutsujassa; kun kutsussa annetaan kaksi int-muuttujaa
    parametreina niiden arvojen pitää vaihtua.

> Tee tästä aliohjelmasta kaksi versiota, joista ensimmäisessä käytät
> viittausparametrimekanismia ja toisessa osoitinparametrimekanismia.
> Tee myös pääohjelma josta kutsut em. aliohjelmia ja toteat niiden
> toimivuuden tulostamalla muuttujien arvot ennen ja jälkeen vaihtojen.
>
> Ohjelman tulostus voisi olla seuraava:
>
> yksi = 1, kaksi = 2 ennen swap1:ia.
>
> yksi = 2, kaksi = 1 jälkeen swap1:in.
>
> kolme = 3, nelja = 4 ennen swap2:ia.
>
> kolme = 4, nelja = 3 jälkeen swap2:in.
>
> Tämä ohjelma vaihtaa muuttujien yksi ja kaksi sekä kolme ja nelja
> arvot päittäin keskenään. Jälleen tulostuksen muoto ei ole oleellinen;
> pääasia on että pystyt ohjelmaa ajamalla vakuuttumaan siitä että
> aliohjelmasi toimivat.

3.  Tee aliohjelma, jolle annetaan parametrina 10-alkioinen
    kokonaislukutaulukko. Aliohjelma kasvattaa sisällään parametrina
    saamansa taulukon jokaisen lokeron arvoa yhdellä. Tee tästä
    aliohjelmasta kaksi varianttia: ensimmäinen pohjautuu
    perustaulukkokäsittelyyn ja indeksointiin ja toinen
    osoitinaritmetiikkaan (jälkimmäisessä ei saa esiintyä indeksointia).

> Tee myös pääohjelma josta löytyy 10-lokeroinen kokonaislukutaulukko.
> Alusta se 0-arvoilla ja välitä sen jälkeen parametrina edellä
> tekemällesi aliohjelmalle. Tulosta taulukon sisältö pääohjelmassa
> aliohjelman kutsumisen jälkeen ja totea alkioiden kasvaminen yhdellä.
>
> Ohjelmasi tulostus voisi olla seuraavankaltainen:
>
> taulukko ennen aliohjelmakutsua 1: 0 0 0 0 0 0 0 0 0 0
>
> taulukko aliohjelmakutsun 1 jalkeen: 1 1 1 1 1 1 1 1 1 1
>
> taulukko ennen aliohjelmakutsua 2: 0 0 0 0 0 0 0 0 0 0
>
> taulukko aliohjelmakutsun 2 jalkeen: 1 1 1 1 1 1 1 1 1 1
>
> Jälleen oleellista ei ole tulostuksen muoto vaan se että pystyt sen
> avulla vakuuttumaan että molemmat aliohjelmavarianttisi toimivat.

4.  Tee pääohjelma, johon teet 10-lokeroisen kokonaislukutaulukon.
    Alusta taulukon sisältö siten että jokaisen solun arvo on yhtä
    isompi kuin solua vastaavan indeksi arvo ihan
    perustaulukkokäsittelyä hyväksikäyttäen (indeksointia). Käännä
    lopuksi taulukon sisältö päinvastaiseksi siten että lokeron 0 (=
    indeksi) sisältö tulee lokeroon 9 ja täällä vastaavasti aiemmin
    ollut sisältö tulee lokeroon 0.

> Sisältö pitää kääntää osoitinaritmetiikkaa käyttäen (indeksointia ei
> saa käyttää) ja siinä tulee hyödyntää tehtävän 2 swap-aliohjelman
> jompaakumpaa versiota.
>
> Ohjelman tulostus voisi olla seuraava:
>
> taulukko kaannettyna: 10 9 8 7 6 5 4 3 2 1
>
> Jälleen tärkeää ei ole tulostuksen muoto vaan se että pystyt
> vakuuttumaan sen avulla aliohjelmasi oikeasta toiminnasta.

Palautukset: palauta moodleen kunkin tekemäsi kotitehtävän ratkaisu
omana **erillisenä** lähdekooditiedostona jonka nimessä on mukana
tehtävän viikkonumero ja tehtävän numero tyyliin:
ratkaisu_vko2_teht1.cpp. Jos palautat useampia lähdekooditiedostoja
yhden tehtävän ratkaisuna (yksi ratkaisu on ohjelmoitu useampaan
lähdekooditiedostoon jostain syystä) palauta ne kaikki yhden pakatun
.zip-tiedoston sisällä jonka **nimeät samalla tavalla kuin edellä
sanotaan**; esim. ratkaisu_vko2_teht2.zip.
