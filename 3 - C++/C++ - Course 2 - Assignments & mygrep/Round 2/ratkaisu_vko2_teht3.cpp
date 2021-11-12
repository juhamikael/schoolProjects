//Tehtävä 3
#include <iostream>
#include <cmath>
using namespace std;

int First(int x, int y);
int Second(int x, int y, int z);
int Third(int x, int y, int z, int w);

int First(int x, int y) {
	if (x > y) {
		return y;
	}
	else {
		return x;
	}
}

int Second(int x, int y, int z) {
	if ((x < y) and (x < z)) {
		return x;
	}
	else if ((y < x) and (y < z)) {
		return y;
	}
	else {
		return z;
	}
}

int Third(int x, int y, int z, int w) {
	if ((x < y) and (x < z) and (x < w)) {
		return x;
	}
	else if ((y < x) and (y < z) and (y < w)) {
		return y;
	}
	else if ((z < x) and (z < y) and (z < w)){
		return z;
	}
	else {
		return w;
	}
}

int main() {
	int x, y, z, w;
	int first, second, third;
	int smallest;
	cout << "Aloitetaan syottamalla lukuja! \n";
	//------------

	cout << "Anna muuttujalle X arvo: \n";
	cin >> x;
	cout << "Anna muuttujalle Y arvo: \n";
	cin >> y;
	cout << "Anna muuttujalle Z arvo: \n";
	cin >> z;
	cout << "Anna muuttujalle W arvo: \n";
	cin >> w;

	//cout << "X:n " << x << " ja Y:n "<< y <<" valilta pienempi luku on: " << First(x, y) << endl;
	first = First(x, y);	
	//cout << "Verrataan lukuja X: " << x << " , Y: " << y << " ja Z: " << z << " keskenaan.\n";
	//cout << "Pienin luku oli " << Second(x, y, z) << "\n\n";
	
	second = Second(x, y, z);
	//cout << "Verrataan lukuja X: " << x << " , Y: " << y << " ja Z: " << z << " ja W: " << w << " keskenaan.\n";
	//cout << "Pienin luku oli " << Third(x, y, z, w) << "\n\n";

	third = Third(x, y, z, w);

	if ((first < second) and (first < third)) {
		smallest = first;
	}
	else if ((second < first) and (second < third)) {
		smallest = second;
	}
	else if ((first == second) and (first == third)) {
		smallest = first;
	}
	else {
		smallest = third;
	}

	cout << "Kaikista annetuista luvuista pienin arvo = " << smallest<< "\n\n";

}
