#pragma once

#include "Roslina.h"

class Guarana : public Roslina {

public:
	Guarana(Swiat& s, int x, int y);
	~Guarana() override;
	void rysowanie() override;
	void kolizja(Organizm* atakujacy) override;
	Organizm* Rozmnazanie() override;
	bool porownajGatunek(Organizm* org) override;
	void Wypisz(std::ostream& out) const override;
};