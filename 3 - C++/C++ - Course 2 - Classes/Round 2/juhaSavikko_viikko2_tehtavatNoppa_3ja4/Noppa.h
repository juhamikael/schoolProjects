#pragma once
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

class Noppa
{
public:
	Noppa();
	Noppa(int aNoppienMaara);
	~Noppa();

	int getViimeisinLukema();
	int getNoppienMaara();
	void kerroViimeisenHeitonLukema();
	void heitäNoppaa();
	void setNoppienMaara(int aNoppienMaara);
	void setViimeinenLukema(int aViimeinenLukema);


private:
	int mViimeinenLukema;
	int mNoppienMaara = 1;
	int mTulos = 1;

};

