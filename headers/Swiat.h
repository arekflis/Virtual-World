#pragma once

#include "Organizm.h"


class Swiat {

private:
	std::vector<Organizm*> organizmy;
public:	
	Swiat(std::vector<Organizm*> o);
	void dodajOrganizm(Organizm* o);
	void usunOrganizm(Organizm* o);
	Organizm* znajdzOrganizm(int x, int y);
	void kolejnoscOrganizmow();
	void wykonajTure();
	void rysujSwiat();
	void wypiszOrganizmy();
	void menu();
	void zerujRuchy();
	bool czyKoniecGry();
	~Swiat();
};