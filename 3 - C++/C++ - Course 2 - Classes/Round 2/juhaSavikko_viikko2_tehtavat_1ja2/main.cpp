#include <iostream>
#include <string>
#include "henkilo.h"
#include "Paivays.h"
using namespace std;

void Viiva() {
	cout << "\n----------------------\n";
}
void LohkonAlku(string lohkonNimi) {
	Viiva();
	cout << "\n'" << lohkonNimi << "' lohkon alku\n\n";
}
void LohkonLoppu(string lohkonNimi) {
	cout << "\n'" << lohkonNimi << "' lohkon loppu\n";
}
void olioAliohjelmassa() 
{
	LohkonAlku("Aliohjelma");
	cout << "Luodaan olio aliohjelmassa" << endl;
	Henkilo kalle("Kalle", 10);
	kalle.tulostaHenkilonTiedot();
	return;
} // kalle vapautetaan tässä

int main() {
	//Opetuskerta 2, Tehtava 1 & 2
	//Tehtävää tehty valtaosa opettajan tahdissa 
	//*********************************//
	//1
	LohkonAlku("Main");
	{
		cout << "Luodaan olio mainissa" << endl;
		Henkilo kalle("Kalle", 30);
		kalle.tulostaHenkilonTiedot();
	}
	LohkonLoppu("Main");
	//*********************************//

	//*********************************//
	//2
	olioAliohjelmassa();
	LohkonLoppu("Aliohjelma");

	//*********************************//


	//*********************************//
	//3
	int luku = 1;
	LohkonAlku("While");
	while (true) {
		cout << "Luodaan olio "<< luku <<" 'While' loopissa" <<endl;
		Paivays joulu(luku, 12, 2021);
		joulu.tulostaPaivays();
		luku++;
		if (luku == 3) {
			break;
		}
		else {
			continue;
		}
	}
	LohkonLoppu("While");
	//*********************************//

	//*********************************//
	//4
	LohkonAlku("For");
	for(int i=0;i<3;i++) {
		cout << "Luodaan olio " << i << " 'for' loopissa" << endl;
		Paivays joulu(i, 12, 2021);
		joulu.tulostaPaivays();
	} //joulu vapautetaan muistista
	LohkonLoppu("For");

	//*********************************//

	//*********************************//
	//5
	LohkonAlku("Taulukko");
	{
		Henkilo henkilot[10];
		henkilot->tulostaHenkilonTiedot();
	}
	LohkonLoppu("Taulukko");

	//*********************************//


	//*********************************//
	//6
	{
		LohkonAlku("Heap");
		Henkilo* peksi = new Henkilo("Peksi", 30);
		peksi->tulostaHenkilonTiedot();
		delete peksi;
		LohkonLoppu("Heap");
		Viiva();


	}
	//*********************************//
	return 0;
} 
