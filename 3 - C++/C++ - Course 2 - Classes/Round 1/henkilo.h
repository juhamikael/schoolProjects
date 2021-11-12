#pragma once
#include <iostream>
#include <string>
using namespace std;

class Henkilo {
public:
	void setNimi(string aNimi);
	void setIka(int aIka);
	string getNimi();
	int getIka();
	void tulostaHenkilonTiedot();
	void kasva();

private:
	string nimi;
	int ika;
};