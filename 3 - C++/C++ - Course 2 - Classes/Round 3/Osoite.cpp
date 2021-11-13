#include "Osoite.h"
#include <iostream>
using namespace std;

Osoite::Osoite() : mKatuosoite("N/A"), mPostinumero("N/A"), mKunta("N/A")
{
	cout << "Osoite -luokan oletusrakentaja (parametriton rakentaja)\n";
}

Osoite::Osoite(string aKatuosoite, string aPostinumero, string aKunta)
	: mKatuosoite(aKatuosoite), mPostinumero(aPostinumero), mKunta(aKunta)
{
	cout << "Osoite -luoka 3 parametrinen rakentaja\n";
}

Osoite::~Osoite()
{
	cout << "Osoite -luokan purkaja\n";
}

string Osoite::getKatuosoite() const
{
	return mKatuosoite;
}

string Osoite::getPostinumero() const
{
	return mPostinumero;
}
string Osoite::getKunta() const
{
	return mKunta;
}

void Osoite::setKatuosoite(string aKatuosoite)
{
	mKatuosoite = aKatuosoite;
}

void Osoite::setPostinumero(string aPostinumero)
{
	mPostinumero = aPostinumero;
}

void Osoite::setKunta(string aKunta)
{
	mKunta = aKunta;
}

void Osoite::tulostaTiedot() const
{
	cout << "Katuosoite: " << mKatuosoite << endl;
	cout << "Postinumero: " << mPostinumero << endl;
	cout << "Kunta: " << mKunta << endl;
}









