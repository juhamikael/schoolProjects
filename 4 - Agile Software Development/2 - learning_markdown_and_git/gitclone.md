# **git clone**

Komento *git clone* luo paikallisen kopion projektista, joka on git repossa. Kopio sisältää kaikki projektin tiedostot, historian ja haarat. 

Komentoon voi vaihtoehtoisesti lisätä lisä optioita, jotka muokkaavat, miten se toimiii.

Esimerkiksi: git clone *linkkirepoon* luo kopion siitä reposta, jonka linkki syötetään.

---

## Lisäkomentoja

1. git clone *repo* "kansion nimi" luo kopion reposta haluttuun kansioon.

2. git clone -branch luo kopion halutusta haarasta eikä siitä, mihin repon *HEAD* osoittaa.

### Jos repo on laaja ja sisältää paljon *committeja*, niin *matalalla* kopiolla voidaan säästää levytilaa tai jos halutaan vain tietyt commitit.

1. Esimerkki matalasta kopiosta: git clone -depth=1 *repo*, tagi -depth=1 tarkoittaa, että kopioidaan vaan tietyt *commitit*, joka tarkoittaa viimeisimpiä.
