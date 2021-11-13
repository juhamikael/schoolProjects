#pragma once
#include <iostream>
#include <string>
#include "osoite.h"

using namespace std;

class Henkilo {
public:
	Henkilo();
	Henkilo(string aNimi, int aIka);
	Henkilo(string aNimi, int aIka, Osoite aOsoite); ~Henkilo();
	void setNimi(string aNimi);
	void setIka(int aIka);
	void setOsoite(Osoite aOsoite);
	Osoite getOsoite() const;
	string getNimi() const;
	int getIka() const;
	void tervehdi() const;
	void tulostaHenkilonTiedot() const;
	void kasva();

private:
	Osoite mOsoite;
	string mNimi;
	int mIka;

};
