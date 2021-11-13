#include "Opiskelija.h"
#include <iostream>

Opiskelija::Opiskelija(const string& aNimi, int aIka, int aOpintoPisteet)
	:Henkilo(aNimi, aIka), mOpintoPisteet(aOpintoPisteet)
{
	cout << "Opiskelija -luokan rakentaja" << endl;
}

void Opiskelija::lisaaKurssi(const string& aKurssi)
{
	mMeneillaanOlevatKurssit.push_back(aKurssi);
}

void Opiskelija::meneillaanOlevatKurssit(const string& aKurssi)
{
	for (string kurssit : mMeneillaanOlevatKurssit) {
		cout << kurssit << endl;
	}
}

void Opiskelija::suoritaKurssi(const string& aSuoritaKurssi)
{
	mSuoritetutKurssit.push_back(aSuoritaKurssi);
}

void Opiskelija::suoritetutKurssit() const
{
	for (string kurssit : mSuoritetutKurssit) {
		cout << kurssit << endl;
	}
}

void Opiskelija::tulostaOpiskelijanTiedot() const
{
	tulostaHenkilonTiedot();
	cout << "Opintopisteet: " << mOpintoPisteet << endl;
	cout << "Meneillaan olevat kurssit: \n";
		for (string kurssitNyt : mMeneillaanOlevatKurssit) {
			cout << kurssitNyt << endl;
		}
	cout << "Suoritetut kurssit: \n";
		for (string kurssitDone : mSuoritetutKurssit) {
		cout << kurssitDone << endl;
		}
}

void Opiskelija::setOpintopisteet(const int& aOpintoPisteet)
{
	mOpintoPisteet = aOpintoPisteet;
}

int Opiskelija::getOpintopisteet() const
{
	return mOpintoPisteet;
}

