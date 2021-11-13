#include <iostream>
#include <string>
#include <vector>
#include "henkilo.h"
#include "Paivays.h"
#include "Osoite.h"
#include "Kalenterimerkinta.h"
#include "Opettaja.h"
#include "Opiskelija.h"

using namespace std;

int main() {
	// Kalle on Opettaja, joten h�n on my�s henkil�
	/*

	Opettaja kalle("Kalle", 30, "Tietotekniikka");
	kalle.lisaaKurssi("Ohjelmoinnin jatkokurssi");
	kalle.tulostaOpettajanTiedot(); // Opettajan metodi

	*/
	// Pekka on Opiskelija, joten h�n on my�s henkil�
	Opiskelija pekka("Pekka", 30, 45);
	pekka.tulostaOpiskelijanTiedot();
	pekka.suoritaKurssi("Ohjelmointi peruskurssi");
	pekka.lisaaKurssi("Ohjelmointi Jatkokurssi");
	pekka.tulostaOpiskelijanTiedot();




	return EXIT_SUCCESS;
}
