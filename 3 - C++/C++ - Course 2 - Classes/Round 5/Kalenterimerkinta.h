#pragma once
#include <iostream>
#include <string>
#include "Paivays.h"
using namespace std;

class Kalenterimerkinta
{
public:
	Kalenterimerkinta();
	Kalenterimerkinta(string aAsia, Paivays aPaivays, bool aMuistutus);
	~Kalenterimerkinta();

	void setAsia(string aAsia);
	void setMuistutus(bool aMuistutus);
	void setPaivays(Paivays aPaivays);

	string getAsia() const;
	bool getMuistutus() const;
	Paivays getPaivays() const;

	void tulostaMerkinta() const;
	void kysyTiedot();


private:
	Paivays mPaivays;
	string mAsia;
	bool mMuistutus;

};


