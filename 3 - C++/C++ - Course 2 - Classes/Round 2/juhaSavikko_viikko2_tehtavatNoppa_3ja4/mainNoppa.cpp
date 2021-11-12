#include <iostream>
#include "Noppa.h"
using namespace std;

int main() {

	cout << "Luodaan monopoli nopat" << endl;
	Noppa monopoli(2);
	monopoli.heitäNoppaa();
	monopoli.getViimeisinLukema();
	monopoli.kerroViimeisenHeitonLukema();

	cout << "\nLuodaan yazty nopat" << endl;
	Noppa yazty(5);
	yazty.heitäNoppaa();
	yazty.getViimeisinLukema();
	yazty.kerroViimeisenHeitonLukema();

	cout << "\nLuodaan kayttajan maarittama maara noppia. \n";
	cout << "Monta noppaa haluat kayttaa? " << endl;
	int lukumaara;
	cin >> lukumaara;
	Noppa satunnainen(lukumaara);
	satunnainen.heitäNoppaa();
	satunnainen.getViimeisinLukema();
	satunnainen.kerroViimeisenHeitonLukema();
	cout << "\n";


	return 0;
}