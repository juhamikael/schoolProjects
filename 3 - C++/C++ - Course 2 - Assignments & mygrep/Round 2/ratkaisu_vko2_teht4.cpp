#include <iostream>
using namespace std;


bool isPrime(int userInput);
bool primeAll();
bool prime_square_root();



bool isPrime(int userInput) {
	bool primeCheck = true;
	if (userInput == 0 or userInput == 1) {
		primeCheck = false;
	}
	else {
		for (int i = 2; i <= userInput / 2; i++) {
			if (userInput % i == 0) {
				primeCheck = false;
				break;
			}
		}
	}
	return primeCheck;
}

int main() {


	int userInput;
	int i;
	bool primeCheck;
	bool primeCheck_2;

	//a)
	//:::::::::::::::::::::::::::::::::
	cout << "Enter positive integer: ";
	cin >> userInput;
	primeCheck = isPrime(userInput);
	if (primeCheck == true) {
		cout << userInput << " is prime number";
	}
	else {
		cout << userInput << " is not prime number";
	}
	//:::::::::::::::::::::::::::::::::

	//b)
	//:::::::::::::::::::::::::::::::::

	for (int x = 2; x < 10000; x++) {
		// isPrime will be true for prime numbers
		primeCheck_2 = isPrime(x);
		if (primeCheck_2 == true)
			cout << x << " ";
	
	}

	//:::::::::::::::::::::::::::::::::


	//:::::::::::::::::::::::::::::::::
	//c)




	//:::::::::::::::::::::::::::::::::
	return 0;
}


