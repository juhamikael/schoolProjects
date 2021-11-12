//Tehtävä 2
#include <iostream>	
#include <cmath>
using namespace std;

int main() {
	double luku;
	cout << "Anna luku: ";
	cin >> luku;
	int ceiledNumber = ceil(luku);
	int flooredNumber = floor(luku);

	cout << "Luku " << luku << " sisaltyy valille [ " << flooredNumber << ", " << ceiledNumber << " ].\n";

	return 0;
}

