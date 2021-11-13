#if 0
#include <iostream>
#include <string>
#include "henkilo.h"
#include "Paivays.h"
#include "Osoite.h"
using namespace std;


int main() {

	Osoite juhanOsoite("Teiskontie", "33540", "Tampere");

	Henkilo juha("Juha", 28, juhanOsoite);
	juha.tervehdi();

	Henkilo ville("Ville", 30, Osoite("Hämeenkatu 1", "33100", "Tampere"));
	ville.tervehdi();

	system("pause");
	return EXIT_SUCCESS;
}

#endif

#include <iostream>
#include <string>
#include "henkilo.h"
#include "Paivays.h"
#include "Osoite.h"
#include "Kalenterimerkinta.h"
using namespace std;


int main() {
	Kalenterimerkinta oppitunti("Ohjelmoinnin luennot", Paivays(30, 3, 2021), true);
	oppitunti.kysyTiedot();

	oppitunti.tulostaMerkinta();

	system("pause");
	return EXIT_SUCCESS;
}
