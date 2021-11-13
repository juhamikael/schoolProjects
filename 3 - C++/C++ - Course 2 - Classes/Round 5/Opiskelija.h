#pragma once
#include "henkilo.h"
#include <vector>
class Opiskelija : public Henkilo {
public:

	Opiskelija(const string& aNimi, int aIka, int aOpintoPisteet);

	void lisaaKurssi(const string& aKurssi);
	void meneillaanOlevatKurssit(const string& aKurssi);


	void suoritaKurssi(const string& aSuoritetutKurssit);
	void suoritetutKurssit() const;

	void tulostaOpiskelijanTiedot() const;

	void setOpintopisteet(const int& aOpintoPisteet);
	int getOpintopisteet() const;

	void poistaKurssi(const string& aOpintoPisteet);


private:
	string mOpNro;
	vector<string> mSuoritetutKurssit;
	vector<string> mMeneillaanOlevatKurssit;

	int mOpintoPisteet;
};

