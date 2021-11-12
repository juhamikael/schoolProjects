#include "henkilo.h"


Henkilo::Henkilo() :
	mNimi("tuntematon"), mIka(0)
{
	cout << "Luodaan henkilo (parametriton rakentaja)" << endl;
}
Henkilo::Henkilo(string aNimi, int aIka) :
	mNimi(aNimi), mIka(aIka)
{
	cout << "Luodaan henkilo (2 parametrinen rakentaja) " << endl;
}

Henkilo::~Henkilo()
{
	cout << "Henkilo -luokan purkaja" << endl;
}


void Henkilo::setNimi(string aNimi){
	mNimi = aNimi;
}

void Henkilo::setIka(int aIka) {
	mIka = aIka;
}

string Henkilo::getNimi()
{
	return mNimi;
}

int Henkilo::getIka()
{
	return mIka;
}

void Henkilo::tulostaHenkilonTiedot()
{
	cout << "Henkilon '" << mNimi << "' tiedot" << endl;
	cout << "Nimi: " << mNimi << endl;
	cout << "Ika: " << mIka << endl;
}

void Henkilo::kasva()
{
	cout << "\nSyntymapaiva! \n" << endl;
	mIka++;
}
