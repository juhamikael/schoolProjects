#include <iostream>
#include <string>
#include "Paivays.h"
using namespace std;

Paivays::Paivays() : 
	mPaiva(1),mKuukausi(1),mVuosi(2000)
{
	cout << "Luodaan paivays (parametriton rakentaja)" << endl;
}

Paivays::Paivays(int aPaiva, int aKuukausi, int aVuosi) 
	: mPaiva(aPaiva),mKuukausi(aKuukausi),mVuosi(aVuosi)
{
	cout << "Luodaan paivays (3 parametrinen rakentaja) " << endl;
}

Paivays::~Paivays()
{
	cout << "Paivays -luokan purkaja " << endl;
}

void Paivays::setPaiva(int aPaiva)
{
	if (aPaiva >= 1 && aPaiva <= tamanKuukaudenPituus()) {
		mPaiva = aPaiva;
	}
	else {
		//bugi jossain!
	}
}
void Paivays::setKuukausi(int aKuukausi)
{
	if (aKuukausi >= 1 && aKuukausi <= 12) {
		mKuukausi = aKuukausi;
	}
}
void Paivays::setVuosi(int aVuosi)
{
	mVuosi = aVuosi;
}
int Paivays::getPaiva()
{
	return mPaiva;
}
int Paivays::getKuukausi()
{
	return mKuukausi;
}
int Paivays::getVuosi()
{
	return mVuosi;
}
void Paivays::tulostaPaivays()
{
	cout << "Paivamaara: " << mPaiva << "/" << mKuukausi << "/" << mVuosi << endl;
	}
void Paivays::kysyPaiva()
{
	int syote;
	cout << "Syota vuosi: " << endl;
	cin >> syote;
	setVuosi(syote);

	cout << "Syota kuukausi: " << endl;
	cin >> syote;
	setKuukausi(syote);

	cout << "\nSyota paiva: " << endl;
	cin >> syote;
	setPaiva(syote);
}
void Paivays::kasvata()
{
	//cout << "\nKasvatetaan paivaa." << endl;
	if (mPaiva < tamanKuukaudenPituus()) {
		mPaiva++;
	}
	else {
		mPaiva = 1;
		if (mKuukausi < 12) {
			mKuukausi++;
		}
		else {
			mKuukausi = 1;
			mVuosi++;
		}
	}
}
int Paivays::tamanKuukaudenPituus() {
	if (mKuukausi == 4 || mKuukausi == 6 || mKuukausi == 9 || mKuukausi == 11) {
		return 30;
	}
	else if (mKuukausi == 2) {
		if (mVuosi % 4 == 0) {
			return 29;
		}
		return 28;
	}
	return 31;
}
