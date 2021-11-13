## **git pull**

Komennolla *git pull* voidaan "vetää" repossa olevat päivitykset, jotka eivät ole paikallisessa tiedostossa tai kansiossa.

git pull on kombinaatio komennoista git fetch ja git merge.

---

## Lisäoptioita

Komennolle voidaan syöttää lisäoptioita, jotka vaikuttavat sen toimintaan.

1. git pull <*remote*>, komento hakee tietyn etäisen kopion sen hetkisestä haarasta ja luo kopion paikallisesti.

2. git pull --no-commit <*remote*> sama komento kuin edellinen, mutta ei luo uutta *merge committia*

3. git pull --verbose, antaa tiedon siitä, mitä tiedostoja ladataan ja niiden yhdistystiedot.