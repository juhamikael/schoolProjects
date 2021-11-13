#include <iostream>
#include <fstream>
#include <string>
using namespace std;
void Error();
void Error() {
	cout << "Error while opening the file!";
}
int main(int argc, char** argv) {
	string input;		// Käyttäjän antamaa syötettä
	string searchStr;	// Haettava teksti
	string readFile;	// Muuttuja tiedoston nimelle 
	size_t found;		// Muuttuja, jonka arvo >= 0 jos hakusana löytyi, else -1. Kertoo sijainnin riviltä
	size_t line = 1;	// Rivinumero
	int occurrence = 0; // Muuttuja joka kertoo, kuinka monta kertaa hakusana esiintyy tiedostossa
	ifstream dfile;
	int i = 0;
	if (argc <= 1) {
		cout << "Give a string from which to search for: \n";
		getline(cin, input);
		cout << "\nGive search string:\n";
		getline(cin, searchStr);
		found = input.find(searchStr);
		if (found != string::npos) {
			cout << '"' << searchStr << '"';
			cout << " found in ";
			cout << '"' << input << '"';
			cout << " in position " << int(found) << endl;
		}
		else {
			cout << searchStr << " Not found in " << input;
		}
	}
	if (argc >= 2 && argc <= 3) {
		searchStr = argv[1];
		readFile = argv[2];
		dfile.open(readFile);
		if (!dfile.is_open()) {
			Error();
			return 0;
			}
		else {
			while (getline(dfile, input)) {
				found = input.find(searchStr);
				if (found != string::npos) {
					cout << input << endl;
				}
			}
		}
	}
	if (argc >= 3) {
		searchStr = argv[2];
		readFile = argv[3];
		ifstream dfile;
		dfile.open(readFile);
		if (!dfile.is_open()) {
			Error();
			return 0;
		}
		else {
			while (getline(dfile, input)) {
				found = input.find(searchStr);
				if (found != string::npos) {
					for (i = 0; i < argc; i++){
						if (string(argv[i]) == "-ol") {
							cout << line << ": ";
							cout << input << endl;
						}
						if (string(argv[i]) == "-oo") {
							cout << input << endl;
							occurrence++;
						}
						if (string(argv[i]) == "-olo") {
							cout << line << ": " << input << endl;
							occurrence++;
						}
					}
				}
				line++;
			}
			if (occurrence > 0) {
				cout << "Occurrences of lines containing " << "'" << searchStr << "'" << ": " << occurrence << endl;
			}
		}
		dfile.close();
	}
}
