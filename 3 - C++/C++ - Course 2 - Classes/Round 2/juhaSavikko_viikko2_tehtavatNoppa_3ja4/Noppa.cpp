#include "Noppa.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

Noppa::Noppa():
	mViimeinenLukema(1), mNoppienMaara(1)
{
}

Noppa::Noppa(int aNoppienMaara):
	mNoppienMaara(aNoppienMaara),mViimeinenLukema(1)
{
	if (aNoppienMaara > 5) {
		cout << "Maksimi maara ylittyi, asetetaan noppien maaraksi 5\n";
		mNoppienMaara = 5;
	}
	else mNoppienMaara = aNoppienMaara;

	//cout << "Luodaan noppa (";
	//cout << mNoppienMaara << " parametrinen rakentaja) " << endl;
}

Noppa::~Noppa()
{
	cout << "Purkaja kutsuttu" << endl;
}

int Noppa::getViimeisinLukema()
{
	return mViimeinenLukema;
}

int Noppa::getNoppienMaara()
{
	return mNoppienMaara;
}

void Noppa::kerroViimeisenHeitonLukema()
{
	cout << "Viimeisen heitto on " << mViimeinenLukema << "!\n";
}

void Noppa::setNoppienMaara(int aNoppienMaara)
{
	mNoppienMaara = aNoppienMaara;
}

void Noppa::setViimeinenLukema(int aViimeinenLukema)
{
	mViimeinenLukema = aViimeinenLukema;
}

void Noppa::heitäNoppaa()
{
	srand(time(0));
	int noppienMaara = getNoppienMaara();

	int noppa_1 = rand() % 6 + 1;
	int noppa_2 = rand() % 6 + 1;
	int noppa_3 = rand() % 6 + 1;
	int noppa_4 = rand() % 6 + 1;
	int noppa_5 = rand() % 6 + 1;
	int viimeinenHeitto;
	
	int tulos;
	if (noppienMaara == 1) {
		cout << "Noppa1: " << noppa_1;
		mTulos = noppa_1;
		cout << ", yhteensa " << mTulos << endl;
		setViimeinenLukema(noppa_1);
	}
	else if (noppienMaara == 2) {
		cout << "Noppa1: " << noppa_1;
		cout << ", noppa2: " << noppa_2;
		mTulos = noppa_1 + noppa_2;
		cout << ", yhteensa " << mTulos << endl;
		setViimeinenLukema(noppa_2);
	}
	else if (noppienMaara == 3) {
		cout << "Noppa1: " << noppa_1;
		cout << ", noppa2: " << noppa_2;
		cout << ", noppa3: " << noppa_3;
		mTulos = noppa_1 + noppa_2 + noppa_3;
		cout << ", yhteensa " << mTulos << endl;
		setViimeinenLukema(noppa_3);
	}
	else if (noppienMaara == 4) {
		cout << "Noppa1: " << noppa_1;
		cout << ", noppa2: " << noppa_2;
		cout << ", noppa3: " << noppa_3;
		cout << ", noppa4: " << noppa_4;
		mTulos = noppa_1 + noppa_2 + noppa_3 + noppa_4;
		cout << ", yhteensa " << mTulos << endl;
		setViimeinenLukema(noppa_4);
	}
	else if (noppienMaara == 5) {
		cout << "Noppa1: " << noppa_1;
		cout << ", noppa2: " << noppa_2;
		cout << ", noppa3: " << noppa_3;
		cout << ", noppa4: " << noppa_4;
		cout << ", noppa5: " << noppa_5;
		mTulos = noppa_1 + noppa_2 + noppa_3 + noppa_4 + noppa_5;
		cout << ", yhteensa " << mTulos << endl;
		setViimeinenLukema(noppa_5);
	}
}

