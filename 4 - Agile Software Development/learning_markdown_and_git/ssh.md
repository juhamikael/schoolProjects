# SSH Avaimen yhdistäminen käyttäen WSL 

## Aloitetaan avaamalla Terminal ja linux ikkuna


1. Syötä alla oleva komento:
```
ssh-keygen -t rsa -b 4096
```

```
Generating public/private rsa key pair.
Enter file in which to save the key (/home/juhamikael/.ssh/id_rsa):
```
2. Tässä kohtaa painetaan vain enter ja kopioidaan osio `/home/juhamikael/.ssh/id_rsa` ja lisätään perään `.pub` kuten seuraavassa osiossa nähdään

3. Kaiutetaan public avain näytölle:
``` 
$ cat /home/juhamikael/.ssh/id_rsa.pub 
```
- ***KORVAA 'juhamikael' OMAKSI KÄYTTÄJÄKSI***

4. Kopioi kaiutettu public avain ja käy lisäämässä se Githubin avaimiin
```
1. Klikkaa oikeasta yläkulmasta omaa profiili kuvaa ->
2. Settings ->
3. Vasemmassa sarakkeessa 'SSH and GPG keys'
4. Ylhäällä keskellä paina 'New SSH key'
5. Lisää title esim 'Omanimi - WSL Linux
6. Liitä avain 'key' osioon 
7. Paina Add SSH key
8. Valmis 
```

## [**LISÄÄ AIHEESTA: *SSH-avaimen lisääminen***](https://www.atlassian.com/git/tutorials/git-ssh)

