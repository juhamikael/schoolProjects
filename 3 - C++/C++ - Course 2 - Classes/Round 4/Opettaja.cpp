#include "Opettaja.h"
#include <iostream>

Opettaja::Opettaja(const string& aNimi, int aIka, const string& aKoulutusala) 
    :Henkilo(aNimi , aIka), mKoulutusala(aKoulutusala)
{
    cout << "Opettaja -luokan rakentaja" << endl;
}

string Opettaja::getKoulutusala() const
{
    return mKoulutusala;
}

void Opettaja::setKoulutusala(const string& aKoulutusala)
{
    mKoulutusala = aKoulutusala;
}

void Opettaja::lisaaKurssi(const string& aKurssi)
{
    mKurssit.push_back(aKurssi);
}

void Opettaja::tulostaOpettajanTiedot() const
{
    tulostaHenkilonTiedot();
    cout << "Koulutusala: " << mKoulutusala << endl;
    // Tulostetaan kurssit (vektorin sisältö)
    for (string s : mKurssit) {
        cout << s << endl;
    }

}
