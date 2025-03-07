#pragma once
#include "Zwierze.h"

class Owca : public Zwierze {

public:
	Owca(Swiat& s, int x, int y);
	~Owca() override;
	void rysowanie() override;
	Organizm* Rozmnazanie() override;
	bool porownajGatunek(Organizm* org) override;
	void Wypisz(std::ostream& out) const override;
};
