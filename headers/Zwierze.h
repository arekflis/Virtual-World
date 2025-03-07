#pragma once

#include "Organizm.h"

class Zwierze : public Organizm {

public:
	Zwierze(int sila, int inicjatywa, int x, int y, Swiat& s) : Organizm(sila, inicjatywa, x, y, s){};
	virtual void akcja() override;
	virtual void kolizja(Organizm* atakujacy) override;
	virtual bool CzyOdbilAtak(Organizm* atakujacy) override;
	virtual bool porownajGatunek(Organizm* org) = 0;
	virtual void rysowanie() override = 0;
	virtual Organizm* Rozmnazanie() override = 0;
	virtual void Wypisz(std::ostream& out) const override;
	void powstaniePotomka(Organizm* pomoc, int x, int y);
	void rozmnozeniepomoc1(int x, int y, int y1, int x1, int& pom, Organizm* pomoc, Organizm* potomek);
	void rozmnozeniepomoc2(int x, int y, int y1, int x1, int& pom, Organizm* pomoc, Organizm* potomek);
	void rozmnozeniepomoc3(int x, int y, int y1, int x1, int& pom, Organizm* pomoc, Organizm* potomek);
	void rozmnozeniepomoc4(int x, int y, int y1, int x1, int& pom, Organizm* pomoc, Organizm* potomek);
};