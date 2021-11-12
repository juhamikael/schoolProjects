#include <iostream>
using namespace std;

struct Aika {
	int tunnit;
	int minuutit;
	int sekunnit;
};
void sekunnitAjaksi(int &sekunnit);
int Vuorokausi_Sekunteina();
int main() {
	Aika aika;
	int userInput;
	int vuorokaudenSekunnit = Vuorokausi_Sekunteina();
	cout << "Tulostetaan alkuun vuorokauden sekunnit:\n";
	sekunnitAjaksi(vuorokaudenSekunnit);
	cout << "\n\nAnna sekunti maara: ";
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
void sekunnitAjaksi(int &sekunnit) {
	Aika a;
	int kokonaisSekunnit = sekunnit;
	a.sekunnit = kokonaisSekunnit % 60;
	a.minuutit = kokonaisSekunnit / 60;
	a.tunnit = a.minuutit / 60;
	a.minuutit = a.minuutit % 60;
	cout << kokonaisSekunnit << " sekuntia on ";
	cout << a.tunnit << " tuntia ";
	cout << a.minuutit << " minuuttia ";
	cout << a.sekunnit << " sekuntia"; 
}

