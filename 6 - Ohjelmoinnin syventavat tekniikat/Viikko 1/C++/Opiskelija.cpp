#include "Opiskelija.h"

Opiskelija::Opiskelija() : mNimi("Tuntematon"), mOpiskelijanumero("00000000"), mOpintopisteet(0){
    cout << "Opiskelijan oletusrakentaja" << endl;
}
Opiskelija::Opiskelija(string aNimi, string aOpiskelijanumero) : mNimi(aNimi), mOpiskelijanumero(aOpiskelijanumero), mOpintopisteet(0){
    cout << "Opiskelijan 2 parametrinen rakentaja"<< endl;
}
Opiskelija::~Opiskelija(){
    cout << "Opiskelija " << mNimi << " vapautettu muistista "<< endl;
}
void Opiskelija::setNimi(string aNimi) {
   mNimi = aNimi;
}
void Opiskelija::setOpiskelijanumero(string aOpiskelijanumero) {
    mOpiskelijanumero = aOpiskelijanumero;
}
void Opiskelija::setOpintopisteet(int aOpintopisteet) {
    mOpintopisteet = aOpintopisteet;
}
void Opiskelija::tulostaTiedot() {
    cout << "Nimi: " << mNimi << endl;
    cout << "Opiskelijanumero: " << mOpiskelijanumero << endl;
    cout << "Opintopisteet: " << mOpintopisteet << endl;
}


