#pragma once

#include "Roslina.h"

class BarszczSosnowskiego : public Roslina {

public:
	BarszczSosnowskiego(Swiat& s, int x, int y);
	~BarszczSosnowskiego() override;
	void rysowanie() override;
	void akcja() override;
	Organizm* Rozmnazanie() override;
	void kolizja(Organizm* atakujacy) override;
	bool porownajGatunek(Organizm* org) override;
	void Wypisz(std::ostream& out) const override;
};