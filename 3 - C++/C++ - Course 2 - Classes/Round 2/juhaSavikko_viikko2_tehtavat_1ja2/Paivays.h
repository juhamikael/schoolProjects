#pragma once
#include <iostream>
#include <string>
using namespace std;

//M‰‰ritell‰‰n class P‰iv‰ys
class Paivays {
public:
	// Rakentajat (constructors) == Metodi, joka alustaa olion
	// Rakentaja on metodi, jolla on luokan nimi ilman paluuarvoa
	// Jos emme kirjoita yht‰‰n rakentajaa, k‰‰nt‰j‰ tuottaa ns. Oletus rakentajan,
	// joka on parametriton rakentaja
	Paivays();
	Paivays(int aPaiva, int aKuukausi, int aVuosi);

	// Purkajat (destructor) == metodi, jota kutsutaan, kun olio siivotaan muistista (vapautuu)
	~Paivays();


	void setPaiva(int aPaiva);
	void setKuukausi(int aKuukausi);
	void setVuosi(int aVuosi);

	int getPaiva();
	int getKuukausi();
	int getVuosi();

	void tulostaPaivays();
	void kysyPaiva();
	void kasvata();

	int tamanKuukaudenPituus();

	

private:

	// luokalla voi olla yksityisi‰ metodeita, jotka ns. apumetodeita
	// luokan sis‰iseen k‰yttˆˆn. T‰llaisia ei voida kutsua muuten kuin luokan omasta koodista 

	int mPaiva;
	int mKuukausi;
	int mVuosi;



};
