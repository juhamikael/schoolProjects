# **git branch**

Komennolla *git branch* saadaan näkyviin git repon kaikki haarat ja se haara, missä komennon syöttöhetkellä ollaan on merkittynä tähdellä.

Esimerkkinä:
 
git branch

*jh

main

## Lisäkomentoja

Komentoon git branch voidaan lisätä paljon lisäelementtejä, jotka antavat komennolle lisävaihtoehtoja tai ohjeita.

Esimerkiksi: 

git branch branch luo repoon haaran, jonka nimeksi tulee branch.

git branch -d branch poistaa haaran *"turvallisesti"*, mutta git ei anna suorittaa komentoa jos haarassa on muutoksia.

git branch -D branch toimii samalla periaatteella kuin linuxin komento **rm -rf**, joka poistaa tiedoston tai kansion väkisin.
Komento samalla poistaa kaikki *commitit*.

git branch -a Listaa kaikki haarat.
