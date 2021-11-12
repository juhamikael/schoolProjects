//Tehtävä 1
#include <iostream>	
using namespace std;

int onKolmiollinen(int kateetti1, int kateetti2, int hypotenuusa);
enum kolmionTyyppi : const int {
	negative = 0, 
	tasaSivu = 1, 
	tasaKylki = 2, 
	suoraKulma = 3 
};

int onKolmiollinen(int kateetti1, int kateetti2, int hypotenuusa) {
	if ((kateetti1 + kateetti2 <= hypotenuusa) or (kateetti1 + hypotenuusa <= kateetti2) or (kateetti2 + hypotenuusa <= kateetti1)) {
		return negative;
	}
	else if (kateetti1 == kateetti2 and kateetti2 == hypotenuusa) {
		return tasaSivu;
	}
	else if ((kateetti1 == kateetti2) or (kateetti1 == hypotenuusa) or (kateetti2 == hypotenuusa)) {
		return tasaKylki;
	}
	else if ((pow(kateetti1, 2) + pow(kateetti2, 2)) == pow(hypotenuusa, 2)) {
		return suoraKulma;
	}
}
<
int main() {
	int a;
	int b;
	int c;

	cout << "Anna 1. Kateetin pituus: \n";
	cin >> a;
	cout << "Anna 2. Kateetin pituus: \n";
	cin >> b;
	cout << "Anna Hypotenuusan pituus: \n";
	cin >> c;

	onKolmiollinen(a, b, c);

	if (onKolmiollinen(a, b, c) == 0) {
		cout << "Annetuista sivuista ei voida muodostaa kolmiota.";
	}
	else if (onKolmiollinen(a, b, c) == 1) {
		cout << "Annetuista sivuista voidaan muodostaa tasasivuinen kolmio.";
	}
	else if (onKolmiollinen(a, b, c) == 2) {
		cout << "Annetuista sivuista voidaan muodostaa tasakylkinen kolmio.";
	}
	else if (onKolmiollinen(a, b, c) == 3) {
		cout << "Annetuista sivuista voidaan muodostaa suorakulmainen kolmio";
	}
	return 0;
}
