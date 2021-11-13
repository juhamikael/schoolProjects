Ohjelmoinnin edistyneet piirteet -- OSA II -- Harjoitukset 3

**Tehtävä 1 (1p). Const --sana luokkarajapinnoissa.** Muuta aiemmin
harjoituksissa tekemiesi luokkien (Henkilö ja Päiväys) rajapintoja
siten, että käytät const --sanaa siellä, missä sitä tulisi käyttää. Ts.
määrittelet sellaiset metodit constiksi, jotka eivät muuta luokan
tietojäsenten arvoa.

**Tehtävä 2 (2p). Olio olion tietojäsenenä.** Toteuta Henkilö --luokan
yhteyteen Osoite -- luokka siten, että "Henkilöllä on Osoite", kuten
Tabulassa löytyvässä verkkoluennossa. Voit käyttää mallina verkkoluennon
koodia ja toteuttaa samalla tavalla.

![](media/image1.jpeg){width="3.4138888888888888in"
height="1.9256944444444444in"}

Luo pääohjelmassasi kaksi henkilöä, joista toiselle annat osoitteen heti
rakentajan yhteydessä ja toiselle vasta myöhemmin (setOsoite). Tulosta
henkilöiden tiedot esim. käyttämällä tervehdi() tai tulostaTiedot()
--metodia (kumman vain olet toteuttanut).

**Tehtävä 3 (2p). Olio olion tietojäsenenä.** Tee luokka
*Kalenterimerkinta*, jossa on seuraavat attribuutit:

-   päiväys (edellisen viikkoharjoituksen Paivays-luokan olio -
    composition)

-   asia (merkkijono string, #include \<string> ja using std::string)

-   muistutus (päällä tai ei päällä)

Luokassa ovat myös: oletusrakentaja, parametrillinen rakentaja, purkaja,
getterit ja setterit sekä metodit:

> void tulostaMerkinta();// tulostaa kalenterimerkkinnän näytölle void
> kysyTiedot(); // kysyy tiedot käyttäjältä

Kokeile toimintaa luomalla pääohjelmassa KalenteriMerkinta-olioita
oletusrakentajalla ja parametrillisella rakentajalla.
