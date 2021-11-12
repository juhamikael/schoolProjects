#pragma once
#include <iostream>
#include <string>
using namespace std;

//M‰‰ritell‰‰n class P‰iv‰ys
class Paivays {
public:
	void setPaiva(int aPaiva);
	void setKuukausi(int aKuukausi);
	void setVuosi(int aVuosi);
	int getPaiva();
	int getKuukausi();
	int getVuosi();
	void tulostaPaivays();
	void paivaysKysely();
	void kasvata();

private:
	int paiva;
	int kuukausi;
	int vuosi;
};
