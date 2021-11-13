#include "Kalenterimerkinta.h"
#include <iostream>
#include <string>
using namespace std;

Kalenterimerkinta::Kalenterimerkinta(): mPaivays(), mAsia(), mMuistutus(false)
{
	cout << "Kalenterimerkinta -luokan parametriton rakentaja\n";
}

Kalenterimerkinta::Kalenterimerkinta(string aAsia, Paivays aPaivays, bool aMuistutus):
	mPaivays(aPaivays), mAsia(aAsia), mMuistutus(aMuistutus)
{
	cout << "Kalenterimerkinta -luokan 3 parametrinen rakentaja" << endl;
}

Kalenterimerkinta::~Kalenterimerkinta()
{
	cout << "Kalenterimerkinta -luokan purkaja" << endl;
}

void Kalenterimerkinta::setAsia(string aAsia)
{
	mAsia = aAsia;
}

void Kalenterimerkinta::setMuistutus(bool aMuistutus)
{
	mMuistutus = aMuistutus;
}

void Kalenterimerkinta::setPaivays(Paivays aPaivays)
{
	aPaivays = mPaivays;
}

string Kalenterimerkinta::getAsia() const
{
	return mAsia;
}

bool Kalenterimerkinta::getMuistutus() const
{
	return mMuistutus;
}

Paivays Kalenterimerkinta::getPaivays() const
{
	return mPaivays;
}
void Kalenterimerkinta::kysyTiedot()
{
	cout << "Muistutuksen asia? ";
	cin >> mAsia;

	mPaivays.kysyPaiva();

	char vastaus;
	cout << "Asetetaanko muistutus (K/E): ";
	cin >> vastaus;
	if (vastaus == 'k' || vastaus == 'K') {
		mMuistutus = true;
	}
	else {
		mMuistutus = false;
	}
}
void Kalenterimerkinta::tulostaMerkinta() const
{
	cout << "Asia: " << mAsia << endl;
	mPaivays.tulostaPaivays();
	if (mMuistutus) {
		cout << "Muistutus asetettu\n";
	}
	else {
		cout << "Ei muistutusta\n";
	}
}


