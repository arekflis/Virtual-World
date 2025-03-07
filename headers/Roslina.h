#pragma once

#include "Organizm.h"

class Roslina : public Organizm {

public:
	Roslina(int sila, int inicjatywa, int x, int y, Swiat& s) : Organizm(sila, inicjatywa, x, y, s) {};
	virtual void akcja() override;
	virtual void rysowanie() override = 0;
	virtual void kolizja(Organizm* atakujacy) override;
	virtual bool CzyOdbilAtak(Organizm* atakujacy) override;
	virtual bool porownajGatunek(Organizm* org) = 0;
	virtual Organizm* Rozmnazanie() override = 0;
	virtual void Wypisz(std::ostream& out) const override;
};
