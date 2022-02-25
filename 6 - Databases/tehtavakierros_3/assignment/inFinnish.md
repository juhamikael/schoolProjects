Tehtävä 0. Tutustu oheisiin tiedostoihin, joista erityisesti db.sql tiedostoon, joka on SQL-tiedosto kurssilla jatkossa käytettävästä tietokannasta.

- tallenna tiedosto omalle koneellesi ja kopioi oheiset tiedostot (db, db.sql, docker-compose.yml) uuteen (viikon 8) kansioon. Sammuta tarvittaessa viime viikon kontit: docker stop $(docker ps -a -q)
    - WSL2 mount-aseman löydät Windowsin file explorerilla kohteesta \\wsl$\...
- siirry viikko 8 kansioon ja käynnistä Adminer-työkalu dockerin kautta ja mene osoitteeseen localhost:8080
- kirjaudu viikon 6 tunnuksilla Admineriin
- valitse adminerissa import-toiminto ja osoita levyltä aiemmin tallennettu db.sql. Suorita import execute-napilla
- tutustu tuotuun dataan

Tehtävä 1. Poista tietokannasta osasto, jonka id on 2. Mitä tapahtuu [ja miksi]?  Tarkista tilanne SQL selectillä (myös select * from employee) ennen ja jälkeen osaston poiston.

Tehtävä 2. Päivitä työntekijä id=2 osastolle 6 töihin.  Mitä tapahtuu [ja miksi]? Päivitä sama työntekijä nyt osastolle 5. Onko ok?

Tehtävä 3. Poista tietokannasta työntekijä id=4. Mitä muutoksia tapahtuu [ja miksi]?

Tehtävä 4. Lisää uusia työntekijöitä INSERT INTO -komennolla. Kokeile lisätä sellaiselle osastolle, jota ei ole. Lisää nyt uusi osasto, ja ja lisää sinne työntekijä. 

Tehtävä 5.* Anna työntekijä id 11 (Taavi Tanakka) 10 % palkan korotus. Anna sitten kaikille työntekijöille 5 % palkankorotus. Palauta arvot takaisin, ts. peruuta palkan korotus, ja muuta se 5.5 % korotukseksi.

Tehtävä 6.* Päivitä osaston id:t siten, että ne on 10 x alkuperäinen. Mitä tapahtuu työntekijätaulussa [, ja miksi]?

Tehtävä 7. Päivitä työntekijän id 12 (Maija Mainio) sukunimeksi 'Mäkinen'.

Tehtävä 8. Poista Make Myyjältä toinen puhelinnumero (phone2).

Tehtävä 9.* Lisää uusi osa: Pelikone, joka koostuu:

2 x SSD 512
2 x 16 GB muisti
microATX-kotelo
Intel Core i7 -suoritin
NVIDIA GeForce -näytönohjain
Lisää myös tarvittavat osat.

Tehtävä 10. Anna komento: DELETE FROM employee.  Mitä muutoksia tapahtuu [ja miksi]? Tarkastele kaikkia tauluja!



*Tehtävä 11. Muokkaa db.sql -tiedostoa (nimeä toisella nimellä) s.e. kaikki mahdolliset (Mieti!) 'ON UPDATE CASCADE' onkin korvattu 'ON UPDATE SET NULL'. Tee sen jälkeen tehtävät 2, 3, 4, 6 ja 10 uusiksi. Mikä muuttuu [ja miksi]?