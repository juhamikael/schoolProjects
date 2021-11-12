#include <iostream>
#include <string>
#include"omaKirjasto.h"
using namespace std;


float Alentaja() {
	float discount = 1;													// Tehd��n ja m��ritell��n discount muuttuja
	int satunnaisLuku = rand() % 3 + 1;									// Arvotaan satunnaisluku v�lilt� 1 - 3
	if (satunnaisLuku == 1) {											// Jos satunnaisluku on 1
		discount = 0;													// discount on 0
	}																	//
	else if (satunnaisLuku == 2) {										// Jos satunnaisluku on 2
		discount = 0.1;											// discount on 0,1 eli 0,1*100 = 10%
	}
	else if (satunnaisLuku == 3) {										// Jos satunnaisluku on 3
		discount = 0.2;											// discount on 0,2 eli 0,2*100 = 20%
	}
	return discount;;											// Palautetaan discount p��ohjelmaan
}

int Tarkistaja() {														// Sy�tteen tarkastus
	int luku;															// Kokonaisluku muuttuja
	bool virhe;															// Totuusarvo muuttuja joko Tosi tai Ep�tosi
	do																	// Tarkistetaan toistoehto ainakin kerran
	{
		virhe = false;													// Totuusarvomuuttuja virhe on ep�tosi
		cin >> luku;													// Sy�tet��n luku
		if (!cin.good())												// Jos sy�te ei ole hyv� (sis�lt�� kirjaimia)
		{
			virhe = true;												// Virhe on tosi
			cin.clear();												// Pyyhit��n sy�te pois
			cin.ignore(INT_MAX, '\n');									// Ei oteta sy�tett� huomioon
			cout << "Sy�te on virheellinen, anna uusi sy�te!" << endl;	// Pyydet��n uusi sy�te
		}
	} while (virhe == true);											// Toistetaan silmukkaa niin pitk��n kun virhe on tosi
	//Tarkistetaan ett� sy�te ei ole 0 tai negatiivinen luku
	if (luku < 1) {														// Jos sy�te on v�hemm�n kuin 1
		while (true) {													// Hyp�t��n silmukkaan
			if (luku >= 1) {											// Jos sy�te on suurempi tai 1
				break;													// Poistutaan silmukasta
			}
			else {														// Muussa tapauksessa
				cout << "Sy�te on virheellinen, anna uusi sy�te!\n";	// Ilmoitus virheellisest� sy�tteest�
				luku = Tarkistaja();									// Ajetaan luku oman funktion l�pi ja tarkistetaan ett� sy�te ei ole kirjain
				continue;												// Jatketaan silmukkaa
			}
		}
	}
	return luku;														// Palautetaan luku
}
// Satunnaisluku generaattori huonem��r�lle
int VapaitaHuoneita() {
	int satunnaisLuku = rand() % (80 - 40) + 40;						// Arpoo satunnaisluvun v�lilt� 40 - 80
	if (satunnaisLuku % 2 != 0) {										// Jos satunnaisluku on pariton
		satunnaisLuku = satunnaisLuku + 1;								// Satunnaisluku += 1
	}
	return satunnaisLuku;												// Palauttaa satunnaisluvun jota k�ytet��n p��ohjelmassa kokonaishuonem��r�n m��rittelyyn
}
// Y�m��r�n m��ritys
int yoMaara() {
	int yoMaara;														// Tehd��n y�m��r�lle muuttuja 
	cout << "Anna �iden m��r�: ";										// Pyydet��n y�m��r�
	yoMaara = Tarkistaja();												// M��ritet��n yom��r� = Tarkistaja, Tarkistajassa sy�tteen kysyminen
	return yoMaara;														// Palautetaan y�m��r�
}

//Funktiot jotka palauttavat ainoastaan teksti�
//V�hemm�n cout k�ytt�� p��ohjelmassa
void AlennuksenMaara(int alennus) {
	cout << "Saat varauksesta " << alennus << "% alennuksen" << "\n";
}
void EiOleValittavissa() {
	cout << "Huonetta ei ole olemassa." << endl;
}
string Euroa() {
	string euro = " Euroa!";
	return euro;
}
// Ilmoittaa kaikki hotellihuoneet ja otetaan vastaan js sy�tetty huonem��r� p��ohjelmasta
void HotellinHuoneet(int huoneMaara) {									// Satunnaisluku jonka "VapaitaHuoneita();" funktio meille antoi
	int vapaita1hh = huoneMaara / 2;									// Vapaita 1hh on Huonem��r� / 2
	int vapaita2hh = vapaita1hh + 1;									// Vapaita 2hh on vapaita 1hh + 1
	cout << "Vapaana olevat huoneet: " << huoneMaara << endl;			// Tulostaa kaikki huoneet
	cout << "Vapaana olevat 1 henkil�n huoneet: 1 - " << vapaita1hh;	// Tulostaa vapaana olevat 1hh v�lilt� 1-n
	cout << "\n";														// Tyhj� rivi
	cout << "Vapaana olevat 2 henkil�n huoneet: " << vapaita2hh;		// Tulostaa vapaana olevat 2hh alarajan
	cout << " - " << huoneMaara << endl;								// - ja yl�rajan
	cout << "\n";														// Tyhj� rivi
}
void LiianSuuri() {
	cout << "V��r� sy�te\nHuonetta ei ole olemassa!\n";
}
void Lopetus() {
	cout << "Mit� haluat tehd� seuraavaksi?" << endl;
	Viiva();
	cout << "Painamalla 1 (Lopeta)" << endl;
	cout << "Painamalla 2 (Jatka)" << endl;
	cout << "Painamalla 3 (Tulosta lista vapaista huoneista ja jatka varaamista)\n\n";
}
void LoppuSumma(int loppuSumma) {
	cout << "Ole hyv� ja maksa loppu laskusi: " << loppuSumma << Euroa() << "\nKiitos! " << endl;

}
void Negatiivinen() {
	cout << "V��r� sy�te, sy�tteen� negatiivinen tai nolla";
}
void Tyhj�Rivi() {
	cout << endl;
}
void UusiSyote() {
	cout << "Anna sy�te uudestaan!" << endl;
}
void VarausInfo() {
	cout << "Jos Saatavuus on 0, Huone on varattu\n";
	cout << "Jos Saatavuus on 1, Huone on vapaana\n";
	Tyhj�Rivi();
	cout << "Huoneen Numero" << "		--------" << "	 Saatavuus\n";
	Tyhj�Rivi();

}
void Viiva() {
	cout << "----------------------" << endl;
}
void ToinenViiva() {
	cout << "		--------";
}
void Tab() {
	cout << "       ";
}
void Virhe() {
	cout << "Sy�te on virheellinen, anna uusi sy�te!" << endl;
}