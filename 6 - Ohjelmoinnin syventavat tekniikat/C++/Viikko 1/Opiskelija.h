#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::cin;
using std::string;
#ifndef VIIKKO1_OPISKELIJA_H
#define VIIKKO1_OPISKELIJA_H

// Määritellään opiskelijan rajapinta (API)
class Opiskelija {
public:
    Opiskelija();

    Opiskelija(string aNimi, string aOpiskelijanumero);

    ~Opiskelija(); // Kutsutaan automaattisesti, kun olio vapautetaan
    // Metodit (API)
    void setNimi(string aNimi);

    void setOpiskelijanumero(string aOpiskelijanumero);

    void setOpintopisteet(int aOpintopisteet);

    void tulostaTiedot();

private:
    // Tietojäsenet (data, member variables, instance variables) privaatiksi
    string mNimi;
    string mOpiskelijanumero;
    int mOpintopisteet;


};


#endif //VIIKKO1_OPISKELIJA_H
