#include "henkilo.h"

Henkilo::Henkilo() :
	mNimi("tuntematon"), mIka(0)
{
	cout << "Henkilo -luokan parametriton rakentaja\n";
}
Henkilo::Henkilo(string aNimi, int aIka) :
	mNimi(aNimi), mIka(aIka)
{
	cout << "Henkilo -luokan 2 parametrinen rakentaja\n";
}
Henkilo::Henkilo(string aNimi, int aIka, Osoite aOsoite)
	: mNimi(aNimi), mIka(aIka), mOsoite(aOsoite)
{
	cout << "Henkilo -luokan 3 parametrinen rakentaja\n";
}
Henkilo::~Henkilo()
{
	cout << "Henkilo -luokan purkaja" << endl;
}
Henkilo::Henkilo(const Henkilo& aHenkilo)
	:mNimi(aHenkilo.mNimi), mIka(aHenkilo.mIka), mOsoite(aHenkilo.mOsoite)
{
	cout << "Henkilo -luokan kopiorakentaja " << endl;
}

void Henkilo::setNimi(string aNimi)
{
	mNimi = aNimi;
}
void Henkilo::setIka(int aIka)
{
	mIka = aIka;
}
void Henkilo::setOsoite(Osoite aOsoite)
{
	mOsoite = aOsoite;
}
Osoite Henkilo::getOsoite() const
{
	return mOsoite;
}
string Henkilo::getNimi() const
{
	return mNimi;
}
int Henkilo::getIka() const
{
	return mIka;
}
void Henkilo::tulostaHenkilonTiedot() const
{
	cout << "Henkilon '" << mNimi << "' tiedot" << endl;
	cout << "Nimi: " << mNimi << endl;
	cout << "Ika: " << mIka << endl;
	mOsoite.tulostaTiedot();
}
void Henkilo::tervehdi() const
{
	cout << "Hei nimeni on " << mNimi << endl;
	cout << "Olen " << mIka << " vuotias." << endl;
	cout << "Osoitteeni on " << endl;
	mOsoite.tulostaTiedot();
}

void Henkilo::kasva()
{
	cout << "\nSyntymapaiva! \n" << endl;
	mIka++;
}
