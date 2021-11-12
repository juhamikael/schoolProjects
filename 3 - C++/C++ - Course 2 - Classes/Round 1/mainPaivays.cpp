#include <iostream>
#include <string>
#include "Paivays.h"
using namespace std;


int main() {

	Paivays tanaan;
	Paivays huomenna;
	Paivays eiMaaritelty;

	tanaan.setPaiva(9);
	tanaan.setKuukausi(3);
	tanaan.setVuosi(2021);

	cout << "Paivamaara tanaan: " << endl;
	tanaan.tulostaPaivays();

	huomenna.setPaiva(tanaan.getPaiva() + 1);
	huomenna.setKuukausi(tanaan.getKuukausi());
	huomenna.setVuosi(tanaan.getVuosi());

	cout << "Paivamaara huomenna: " << endl;
	huomenna.tulostaPaivays();

	eiMaaritelty.paivaysKysely();
	eiMaaritelty.tulostaPaivays();
	eiMaaritelty.kasvata();
	eiMaaritelty.tulostaPaivays();




	return 0;

}



