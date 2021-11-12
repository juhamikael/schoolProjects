#include <iostream>
#include <string>
#include "henkilo.h"
using namespace std;


//Tehtävä tehty samaan tahtiin opettajan kanssa

int main() {

	Henkilo pekka;
	Henkilo kalle;
	
	pekka.setNimi("Pekka");
	pekka.setIka(20);
	pekka.tulostaHenkilonTiedot();

	kalle.setNimi("Kalle");
	//Kalle on pekkaa 5v vanhempi
	kalle.setIka(pekka.getIka() + 5);
	kalle.tulostaHenkilonTiedot();


	return 0;
}
