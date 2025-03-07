#pragma once

#include "Roslina.h"

class Trawa : public Roslina {

public:
	Trawa(Swiat& s, int x, int y);
	~Trawa() override;
	void rysowanie() override;
	Organizm* Rozmnazanie() override;
	bool porownajGatunek(Organizm* org) override;
	void Wypisz(std::ostream& out) const override;
};