#pragma once
#include <iostream>
#include <string>
using namespace std;

class Henkilo {
public:
	Henkilo();
	Henkilo(string aNimi, int aIka);
	~Henkilo();

	void setNimi(string aNimi);
	void setIka(int aIka);
	string getNimi();
	int getIka();
	void tulostaHenkilonTiedot();
	void kasva();

private:
	string mNimi;
	int mIka;
};