#pragma once
#include <string>
#include <iostream>
using namespace std;
class Osoite
{
public:
	Osoite();
	Osoite(string aKatuosoite, string aPostinumero, string aKunta); ~Osoite();
	string getKatuosoite() const;
	string getPostinumero() const;
	string getKunta() const;
	void setKatuosoite(string aKatuosoite);
	void setPostinumero(string aPostinumero);
	void setKunta(string aKunta);
	void tulostaTiedot() const;

private:
	string mKatuosoite;
	string mPostinumero;
	string mKunta;
};




