#pragma once
#include "Zwierze.h"

class Lis : public Zwierze {

public:
	Lis(Swiat& s, int x, int y);
	void akcja() override;
	~Lis() override;
	void rysowanie() override;
	Organizm* Rozmnazanie() override;
	bool porownajGatunek(Organizm* org) override;
	void Wypisz(std::ostream& out) const override;
};
