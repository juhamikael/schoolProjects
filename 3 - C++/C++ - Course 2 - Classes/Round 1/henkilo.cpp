#include "henkilo.h"


void Henkilo::setNimi(string aNimi){
	nimi = aNimi;
}

void Henkilo::setIka(int aIka) {
	ika = aIka;
}

string Henkilo::getNimi()
{
	return nimi;
}

int Henkilo::getIka()
{
	return ika;
}

void Henkilo::tulostaHenkilonTiedot()
{
	cout << "Henkilon '" << nimi << "' tiedot" << endl;
	cout << "Nimi: " << nimi << endl;
	cout << "Ika: " << ika << endl;
}

void Henkilo::kasva()
{
	cout << "\nSyntymapaiva! \n" << endl;
	ika++;
}
