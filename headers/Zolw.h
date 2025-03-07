#pragma once
#include "Zwierze.h"

class Zolw : public Zwierze {

public:
	Zolw(Swiat& s, int x, int y);
	void akcja() override;
	~Zolw() override;
	void rysowanie() override;
	Organizm* Rozmnazanie() override;
	bool CzyOdbilAtak(Organizm* atakujacy) override;
	void kolizja(Organizm* atakujacy) override;
	bool porownajGatunek(Organizm* org) override;
	void Wypisz(std::ostream& out) const override;
};
