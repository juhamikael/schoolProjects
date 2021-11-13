#pragma once
#include "henkilo.h"
#include <vector>
// Opettaja on Henkilö
// Opettaja on kaikki henkiln ominaisuudet ja metodit
class Opettaja : public Henkilo
{
	Opettaja(const string& aNimi, int aIka, const string& aKoulutusala);
	string getKoulutusala() const;
	void setKoulutusala(const string& aKoulutusala);
	void lisaaKurssi(const string& aKurssi);

	void tulostaOpettajanTiedot() const;

private:
	string mKoulutusala;
	vector<string> mKurssit;
};

/*

class Opiskelija : public Henkilo {
public:
	void tulostaTiedot() const;



private:
	string mOpNro;
	vector<string> mhenkilot;
	int mOpintoPisteet;
};

*/
