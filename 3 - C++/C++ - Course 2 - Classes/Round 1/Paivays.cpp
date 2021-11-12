#include <iostream>
#include <string>
#include "Paivays.h"
using namespace std;

void Paivays::setPaiva(int aPaiva)
{
	paiva = aPaiva;
}

void Paivays::setKuukausi(int aKuukausi)
{
	kuukausi = aKuukausi;
}

void Paivays::setVuosi(int aVuosi)
{
	vuosi = aVuosi;
}

int Paivays::getPaiva()
{
	return paiva;
}

int Paivays::getKuukausi()
{
	return kuukausi;
}

int Paivays::getVuosi()
{
	return vuosi;
}

void Paivays::tulostaPaivays()
{
	//Oletetaan että kuukaudessa on aina 28 päivää
	//ja tiedetään että vuodessa on 12 kuukautta.

	//Vuoden vaihto
	
	if (paiva > 28) {
		paiva = 1;
		kuukausi++;
		if (kuukausi > 12) {
			kuukausi = 1;
			paiva = 1;
			vuosi++;
		}
	}
	cout << "Paivamaara: " << paiva << "." << kuukausi << "." << vuosi << endl;
}

void Paivays::paivaysKysely()
{
	// kPaiva = kysyttyPaiva etc.
	int kPaiva;
	int kKuukausi;
	int kVuosi;

	cout << "\nSyota paiva: " << endl;
	cin >> kPaiva;
	cout << "Syota kuukausi: " << endl;
	cin >> kKuukausi;
	cout << "Syota vuosi: " << endl;
	cin >> kVuosi;

	paiva = kPaiva;
	kuukausi = kKuukausi;
	vuosi = kVuosi;

}

void Paivays::kasvata()
{
	cout << "\nKasvatetaan paivaa." << endl;
	paiva++;
}




