#include <iostream>
#include "Opiskelija.h"

using std::cout;
using std::endl;
using std::cin;
using std::string;

// Prosessin suoritus alkaa main() -funktiosta
int main() {
    int a = 10;
    // Luodaan opiskelija stackiin (automaattisesti vapautettava)
    Opiskelija kalle = Opiskelija("Kalle", "123456");
    kalle.tulostaTiedot();

    // Luodaan opiskelija heapiin
    // new tekee muistinvarauksen
    Opiskelija *ville = new Opiskelija("Ville", "3134435");
    ville->tulostaTiedot();
    // ville vapautetaan tässä
    delete ville;

    cout << "Testi!" << endl;
    return EXIT_SUCCESS;
} // a vapautetaan muistista
