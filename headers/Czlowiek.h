#pragma once
#include "Zwierze.h"

class Czlowiek : public Zwierze {
private:
	int moc = 10;

public:
	Czlowiek(Swiat& s, int x, int y);
	~Czlowiek() override;
	void akcja() override;
	void rysowanie() override;
	int GetMoc();
	void SetMoc(int moc);
	Organizm* Rozmnazanie() override;
	bool porownajGatunek(Organizm* org) override;
	void Wypisz(std::ostream& out) const override;
	void Sterowanie();
	void Up(int& y, int& flag);
	void Down(int& y, int& flag);
	void Right(int& x, int& flag);
	void Left(int& x, int& flag);
};