#pragma once
#include <iostream>
#include <vector>
#include <Windows.h>

class Swiat;

class Organizm {

protected:
	int sila;
	int inicjatywa;
	int polozenie_x;
	int polozenie_y;
	int ruch = 0;
	Swiat& s;

public:
	Organizm(int sila, int inicjatywa, int polozenie_x, int polozenie_y, Swiat& s);
	void SetSila(int sila);
	int GetSila();
	void SetPolozenie_X(int x);
	int GetPolozenie_X();
	void SetPolozenie_Y(int y);
	int GetPolozenie_Y();
	void SetInicjatywa(int inicjatywa);
	int GetInicjatywa();
	void SetRuch(int ruch);
	int GetRuch();
	Swiat& GetSwiat();
	virtual ~Organizm();
	virtual void akcja() = 0;
	virtual void kolizja(Organizm* atakujacy) = 0;
	virtual bool CzyOdbilAtak(Organizm* atakujacy) = 0;
	virtual bool porownajGatunek(Organizm* org) = 0;
	virtual void rysowanie() = 0;
	virtual Organizm* Rozmnazanie() = 0;
	virtual void Wypisz(std::ostream& out) const = 0;
	friend std::ostream& operator<<(std::ostream& os, const Organizm& org);
};