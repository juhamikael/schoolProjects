#include <iostream>
using namespace std;

struct Aika {
	int tunnit;
	int minuutit;
	int sekunnit;
};

void sekunnitAjaksi(int& sekunnit);
void aikaSekunniksi(int& sekunnit, int& minuutit, int& tunnit);
int Vuorokausi_Sekunteina();

int main() {
	int userInput;
	int vuorokaudenSekunnit = Vuorokausi_Sekunteina();
	cout << "Anna sekunti maara: ";
	cin >> userInput;
	sekunnitAjaksi(userInput);
	return 0;
}


int Vuorokausi_Sekunteina() {
	int const MINUUTTEJA_TUNNISSA = 60;
	int const TUNTEJA_PÄIVÄSSÄ = 24;
	int const SEKUNTEJA_MINUUTISSA = 60;
	int const vuorokausiSekunteina = ((MINUUTTEJA_TUNNISSA * SEKUNTEJA_MINUUTISSA) * TUNTEJA_PÄIVÄSSÄ);
	return vuorokausiSekunteina;
}


void aikaSekunniksi(int& sekunnit, int& minuutit, int& tunnit) {
	cout << tunnit << " tuntia ";
	cout << minuutit << " minuuttia ";
	cout << sekunnit << " sekuntia on ";
}

void sekunnitAjaksi(int& sekunnit) {
	Aika a;
	int kokonaisSekunnit = sekunnit;
	a.sekunnit = kokonaisSekunnit % 60;
	a.minuutit = kokonaisSekunnit / 60;
	a.tunnit = a.minuutit / 60;
	a.minuutit = a.minuutit % 60;

	aikaSekunniksi(a.sekunnit, a.minuutit, a.tunnit);

	cout << kokonaisSekunnit << " sekuntia on ";
	cout << a.tunnit << " tuntia ";
	cout << a.minuutit << " minuuttia ";
	cout << a.sekunnit << " sekuntia";

}

