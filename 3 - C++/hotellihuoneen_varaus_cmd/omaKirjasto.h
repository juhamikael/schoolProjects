#pragma once
#include <iostream>
#include <string>
using namespace std;


struct Huone {											// Struct huone josta voimme hakea molempien tyyppien hinnan.
	int hinta;
};
float Alentaja();										// Satunnaisluku väliltä 1 - 3. Jos satunnaisluku on 1: Alennusprosentti = 0 -> 2: Alennusprosentti = 10% -> 3: Alennusprosentti = 20%.
int Tarkistaja();										// Syötteen tarkistaja. Käy syätteen läpi ja varmistaa että luku ei ole negatiivinen, nolla tai kirjain. 
int VapaitaHuoneita();									// Funktio arpoo satunnaisluvun väliltä 40 - 80 ja palauttaa sen pääohjelmaan.
int yoMaara();											// Käyttäjän syöttää yömäärän joka ajetaan syötteen tarkastuksesta läpi ja palauttaa hyväksytyn syötteen väliltä 1-n

														// Funktiot jotka palauttavat ainoastaan teksti�
														// Vähemmän cout:in käyttää pääohjelmassa

void AlennuksenMaara(int alennus);						// Kertoo alennusprosentin määrän ohjelman loputtua.
void EiOleValittavissa();								// Kertoo että huonetta ei ole olemassa
string Euroa();											// Palauttaa "Euroa!"
void HotellinHuoneet(int huoneMaara);					// Ilmoittaa kaikki vapaana olevat huoneet, 1hh ja 2hh. Tarvitsee sy�tteen "vapaitaHuoneita"
void LiianSuuri();										// Kertoo että syöte on väärä, huonetta ei ole olemassa
void Lopetus();											// Lopetus valikko
void LoppuSumma(int loppuSumma);						// Pyytää maksamaan laskun ja ilmoittaa loppusumman suuruuden
void Negatiivinen();									// Kertoo että syöte on negatiivinen tai 0
void Tab();												// Tyylitystä taulukon tulostamisessa - Noin Tabulaattorin välinen tyhjä tila
void Tyhj�Rivi();										// Tulostaa tyhjän rivin
void UusiSyote();										// Pyytää uuden syötteen
void VarausInfo();										// Tyylitystä taulukon tulostamisessa
void Viiva();											// Tyylitystä taulukon tulostamisessa
void ToinenViiva();										// Tyylitystä taulukon tulostamisessa
void Virhe();											// Ilmoittaa syötteen virheellisyydestä






