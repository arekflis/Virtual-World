#pragma once
#include "Zwierze.h"

class Antylopa : public Zwierze {

public:
	Antylopa(Swiat& s, int x, int y);
	void akcja() override;
	~Antylopa() override;
	void rysowanie() override;
	Organizm* Rozmnazanie() override;
	bool CzyOdbilAtak(Organizm* atakujacy) override;
	bool porownajGatunek(Organizm* org) override;
	void kolizja(Organizm* atakujacy) override;
	void Wypisz(std::ostream& out) const override;
};
