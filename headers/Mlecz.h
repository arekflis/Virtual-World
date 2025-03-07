#pragma once

#include "Roslina.h"

class Mlecz : public Roslina {

public:
	Mlecz(Swiat& s, int x, int y);
	~Mlecz() override;
	void rysowanie() override;
	void akcja() override;
	Organizm* Rozmnazanie() override;
	bool porownajGatunek(Organizm* org) override;
	void Wypisz(std::ostream& out) const override;
};