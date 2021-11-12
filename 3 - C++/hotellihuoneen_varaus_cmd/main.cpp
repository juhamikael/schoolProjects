#include <iostream>
#include <string>
#include <ctime>
#include"omaKirjasto.h"

using namespace std;


int main() {

	srand(time(NULL));
	setlocale(LC_ALL, "");
	int vapaitaHuoneita = VapaitaHuoneita();			// Vapaat huoneet v�lilt� 40-80
	// huonenumerot 1h: 1-n
	int alaraja1h = 1;									// 1
	int ylaraja1h = vapaitaHuoneita / 2;				// 1-40

	// huonenumerot 2h: (1hh ylaraja + 1) - n mutta v�lilt� 40-80
	int alaraja2h = ylaraja1h + 1;						// yl�raja1h - 80
	int ylaraja2h = vapaitaHuoneita;					// max 80

	int vapaita1hh = vapaitaHuoneita / 2;				// 1-40
	int vapaita2hh = (vapaitaHuoneita / 2) + 1;			// 40-80

	int huoneenNmro;									// K�ytt�j�n sy�tt�m� huone numero
	int yomaara;										// K�ytt�j�n sy�tt�m� y�m��r�

	Huone huone1hh;										// Tehd��n 1hh ja 2hh huoneet ja m��ritell��n molemmille hinta
	Huone huone2hh;										// Struct Huone l�ytyy omaKirjasto.h tiedostosta
	huone1hh.hinta = 100;
	huone2hh.hinta = 150;
	int loppuSumma = 0;								// M��ritell��n loppusumma ja v�lisumma mihin tallennetaan ohjelman py�riess� dataa eli t�ss� tapauksessa hinta joka kasvaa.
	int valiSumma = 0;									// Alkuarvo t�ytyy olla 0, jotta voimme taltioida sy�tett�mme sinne.
	float alennus = Alentaja();							// Tehd��n alennus muuttuja joka hakee satunnaisen Alennusprosentin loppusummalle "Alentaja" funktiosta.
	int alennuksenMaara = alennus * 100;				// Ep�m��r�inen muuttuja, n�ytt�� alennusprosentin todellisen suuruuden lopettaessamme ohjelman
	int alennusSumma;									// M��ritet��n my�hemmin -> alennusSumma = valiSumma * alennus; -> loppuSumma = loppuSumma - alennusSumma;

	int i = 0;											// Muuttuja i = muuttuja for looppien l�pik�ymiseen
	int vapaatHuoneet[80];								// Luodaan "Vapaat huoneet" lista ja sen maksimi kooksi 80
	for (int i = 0; i <= 79; i++) {						// M��ritell��n kaikki huoneet vapaiksi
		vapaatHuoneet[i] = 1;							// 1 kertoo ett� huone on vapaa
														// Tarkistus huoneille
														// cout << i + 1 << "------" << vapaatHuoneet[i] << endl;
														//
	}
	int varauksenLopetus;								// Kokonaisluku v�lilt� 1-3, m��ritt�� jatko tekemisemme 5 varauksen j�lkeen
	// Ilmoittaa vapaana olevat huoneet
	// Ilmoittaa vapaana olevat 1hh huoneet
	// Ilmoittaa vapaana olevat 2hh huoneet
	// Tarvitsee sy�tteen "vapaitaHuoneita"
	HotellinHuoneet(vapaitaHuoneita);

	// Hyp�t��n looppiin miss� k�ytt�j� varaa huoneita sek� antaa y�m��r�n
	// Looppi jatkuu niin pitk��n kun k�ytt�j� haluaa
	while (true) {										// K�ytt�j� antaa huoneita 5 kertaa ja jonka j�lkeen ohjelma hypp�� valikkoon
		for (int x = 0; x < 5; x++) {
			cout << "Anna toivomasi huoneen numero v�lilt�: 1 - " << vapaitaHuoneita << " : ";
			huoneenNmro = Tarkistaja();
			if (huoneenNmro > ylaraja2h) {				// Jos huoneen numero on suurempi kuin max huone m��r�
				EiOleValittavissa();					// Ohjelma ilmoittaa ett� huonetta ei ole olemassa
				while (true) {							// Hyp�t��n while looppiin joka jatkuu niin pitk��n kunnes k�ytt�j� sy�tt�� hyv�ksytyn numeron v�lilt� 1 - ylaraja
					if (huoneenNmro <= ylaraja2h) {		// Jos huoneen numero on pienempi kuin yl�raja, hyp�t��n loopista pois
						break;
					}
					else {								// Muussa tapauksessa jatketaan ja pyydet��n uutta sy�tett�
						Virhe();
						huoneenNmro = Tarkistaja();		// Ajetaan kuitenkin aina Tarkistajan l�pi, numero ei voi olla pienempi kuin 1 eik� kirjain.
						continue;						// Hypp�� while loopin alkuun
					}
				}
			}

			if (vapaatHuoneet[huoneenNmro] == 0) {		// Ajetaan huoneen numero taulukon l�pi ja tarkistetaan onko huone varattu
				while (true) {							// Hyp�t��n looppiin jos huone on varattu eli huoneNmro arvo = 0
					if (vapaatHuoneet[huoneenNmro] == 1 and huoneenNmro <= ylaraja2h) {
						break;							// Poistutaan loopista kun k�ytt�j� sy�tt�� huoneen mink� arvo on 1 (Eli vapaa)
					}
					else if (vapaatHuoneet[huoneenNmro] == 0) {
						// Jos huoneen numero on 0, huone on varattu
						cout << "Huone on varattu\nOle hyv� ja valitse toinen huone\n";
						huoneenNmro = Tarkistaja();		// Ajetaan my�s t�m� Tarkistajan l�pi jotta arvoksi ei tule < 0 tai kirjainta
						continue;						// Hypp�� while loopin alkuun
					}
					else {
						// Ohjelma jatkaa kysymist� niin pitk��n kunnes k�ytt�j� valitsee vapaan huoneen
						LiianSuuri();					// Tarkistaa ett� huoneen numero ei my�sk��n ole liian suuri luku
						UusiSyote();					// Jos on, 
						huoneenNmro = Tarkistaja();		// Tehd��n sy�tteen tarkastus
						continue;						// ja Hyp�t��n while loopin alkuun
					}
					continue;
				}
			}
			yomaara = yoMaara();						//Haetaan y�m��r� funktiosta

			// K�ytt�j� valitsee yhden hengen huoneen
			// Jos k�ytt�j�n valitsema huone on 1hh ala -ja yl�rajan sis�ll�
			if (huoneenNmro >= alaraja1h && huoneenNmro <= ylaraja1h) {
				valiSumma = yomaara * huone1hh.hinta;	// V�lisumma on y�m��r� * 100 �
				vapaatHuoneet[huoneenNmro] = 0;
				/*
				if (vapaatHuoneet[huoneenNmro] == 0) {	// Jos k�ytt�j�n valitseman huone on varattu
					cout << "Huone on varattu\n";		// Ohjelma ilmoittaa siit�
				}*/
			}
			// K�ytt�j� valitsee kahden hengen huoneen
			// Jos k�ytt�j�n valitsema huone on 2hh ala -ja yl�rajan sis�ll�
			if (huoneenNmro >= alaraja2h && huoneenNmro <= ylaraja2h) {
				valiSumma = yomaara * huone2hh.hinta;	// V�lisumma on y�m��r� * 150 �
				vapaatHuoneet[huoneenNmro] = 0;
				/*
				if (vapaatHuoneet[huoneenNmro] == 0) {	// Jos k�ytt�j�n valitseman huone on varattu
					cout << "Huone on varattu\n";		// Ohjelma ilmoittaa siit�
				}*/
			}
			if (huoneenNmro < alaraja1h) {
				Negatiivinen();							//  V��r� sy�te, sy�tteen� negatiivinen tai nolla
				UusiSyote();							// "Anna sy�te uudestaan!"
			}
			if (huoneenNmro > ylaraja2h) {				// Jos huoneen numero on suurempi kuin 2hh yl�raja
				LiianSuuri();							// Ohjelma ilmoittaa v��r�st� sy�tteeest�, liian suurest huonenumerosta, sek� siit�, ett� huonetta ei ole olemassa
				UusiSyote();							// "Anna sy�te uudestaan!"
			}
			valiSumma = loppuSumma + valiSumma;			// Lasketaan v�lisumma. V�lisumma on 0 + t�h�n menness� kerrytetty v�lisumma
			loppuSumma = valiSumma;						// Loppusumma on sama kuin v�lisumma
			//Ilmoittaa aina huoneen varauksen j�lkeen mik� on t�m�n hetkinen hinta koko varauksella.
			cout << "\nT�m�n hetkinen laskusi suuruus on " << loppuSumma << Euroa() << "\n\n";
		}
		// Lopetus valikko
		Lopetus();
		// Painamalla 1 = K�ytt�j� lopettaa huoneiden varaamisen ja tulostaa loppusumman
		// Painamalla 2 = K�ytt�j� jatkaa huoneiden varaamista
		// Painamalla 3 = K�ytt�j� tulostaa taulukon vapaista/varatuista huoneista ja jatkaa huoneiden varaamista uudet 5 kertaa
		varauksenLopetus = Tarkistaja();				// Ajetaan varauksen lopetus Tarkastaja l�pi. (Sy�tteen tarkastus)
		// Jos varauksen lopetus on suurempi kuin kolme 
		if (varauksenLopetus > 3) {
			while (true) {								// Hyp�t��n while looppiin
				if (varauksenLopetus <= 3 && varauksenLopetus >= 1) {
					break;								// Jos varauksen lopetus on pienempi tai kolme ja suurempi tai 1, lopetetaan looppi
				}
				else {									// Muussa tapauksessa
					Virhe();							// Ohjelma tulostaa virhe tekstin ja pyyt�� sy�tt�m��n uutta lukua niin pitk��n kunnes luku 1 - 3
					varauksenLopetus = Tarkistaja();	// Sy�tteen tarkastus
					continue;							// Palaa loopin alkuun
				}
			}
		}
		//Jos varauksen lopetus on pienempi kuin 1
		if (varauksenLopetus < 1) {
			while (true) {								// Hyp�t��n while looppiin
				if (varauksenLopetus <= 3 && varauksenLopetus >= 1) {
					break;								// Jos varauksen lopetus on pienempi tai kolme ja suurempi tai 1, lopetetaan looppi
				}
				else {									// Muussa tapauksessa
					Virhe();							// Ohjelma tulostaa virhe tekstin ja pyyt�� sy�tt�m��n uutta lukua niin pitk��n kunnes luku 1 - 3
					varauksenLopetus = Tarkistaja();	// Sy�tteen tarkastus
					continue;							// Palaa loopin alkuun
				}
			}
		}
		if (varauksenLopetus == 1) {					// Jos varauksen lopetus on 1, lopetetaan huoneiden varaaminen
			alennusSumma = valiSumma * alennus;			// Alennus-summa on v�lisumma * alennus
			loppuSumma = loppuSumma - alennusSumma;		// Loppusumma on Loppusumma - Alennus-Summa
			AlennuksenMaara(alennuksenMaara);			// Kertoo alennuksen suuruuden
			LoppuSumma(loppuSumma);						// Kertoo loppusumman suuruudeen alennuksen j�lkeen
			break;										// Lopetetaan huoneiden varaaminen
		}
		else if (varauksenLopetus == 2) {				// Jos varauksen lopetuksen sy�te on 2
			continue;									// Jatketaan huoneen varaamista
		}
		else if (varauksenLopetus == 3) {				// Jos varauksen lopetuksen sy�te on 3
			VarausInfo();								// Tulostetaan VarausInfo (3 rivi� ohjeita) ja taulukon alku tyylitys
			for (i = 1; i <= ylaraja2h; i++) {			// Tulostetaan Taulukko Huoneiden lukum��r�st�
				//Tarkistus huoneille
				Tab();									// Tulostetaan tyylitys (Tyhj� v�li)
				cout << i;								// Tulostetaan taulukon indexi (huone numero)
				ToinenViiva();							// Tulostetaan tyylitys (Viivoja) 
				cout << "	     ";						// Tulostetaan tyylitys (Tyhj� v�li) 
				cout << vapaatHuoneet[i] << endl;		// Tulostetaan n�kyviin huoneen saatavuus 1 tai 0
				continue;
			}
			Tyhj�Rivi();								// Tukostetaan tyhj� rivi
		}
	}
	return EXIT_SUCCESS;
}