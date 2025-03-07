#pragma once

#include "Roslina.h"

class WilczeJagody : public Roslina {

public:
	WilczeJagody(Swiat& s, int x, int y);
	~WilczeJagody() override;
	void rysowanie() override;
	void kolizja(Organizm* atakujacy) override;
	Organizm* Rozmnazanie() override;
	bool porownajGatunek(Organizm* org) override;
	void Wypisz(std::ostream& out) const override;
};