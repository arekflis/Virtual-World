#pragma once
#include "Zwierze.h"

class Wilk : public Zwierze {

public:
	Wilk(Swiat& s, int x, int y);
	~Wilk() override;
	void rysowanie() override;
	Organizm* Rozmnazanie() override;
	bool porownajGatunek(Organizm* org) override;
	void Wypisz(std::ostream& out) const override;
};