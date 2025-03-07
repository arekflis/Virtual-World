#include "Antylopa.h"
#include "Swiat.h"
Organizm* Antylopa::Rozmnazanie() {
	std::cout << "Antylopa sie rozmnaza!" << std::endl;
	return new Antylopa(*this);
}

Antylopa::Antylopa(Swiat &s, int x, int y) : Zwierze(4,4,x,y,s) {}
Antylopa::~Antylopa() {
	std::cout << "Antylopa o polozeniu umiera: x: " << GetPolozenie_X() << " y: " << GetPolozenie_Y() << std::endl;
}
void Antylopa::rysowanie() {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
	GetConsoleScreenBufferInfo(hConsole, &consoleInfo);
	WORD originalColors = consoleInfo.wAttributes;
	SetConsoleTextAttribute(hConsole, BACKGROUND_BLUE | BACKGROUND_RED);
	std::cout << " ";
	SetConsoleTextAttribute(hConsole, originalColors);
}
void Antylopa::akcja() {
	int wylosowana_liczba;
	int flag = 0;
	int x = this->polozenie_x;
	int y = this->polozenie_y;
	while (flag != 1) {
		wylosowana_liczba = (std::rand() % 4) + 1;
		if (wylosowana_liczba == 1 && x < 18) {
			x+=2;
			flag = 1;
		}
		if (wylosowana_liczba == 2 && x > 1) {
			x-=2;
			flag = 1;
		}
		if (wylosowana_liczba == 3 && y > 1) {
			y-=2;
			flag = 1;
		}
		if (wylosowana_liczba == 4 && y < 18) {
			y+=2;
			flag = 1;
		}
	}
	Organizm* pomoc = this->s.znajdzOrganizm(x, y);
	if (pomoc == NULL) {
		this->SetPolozenie_X(x);
		this->SetPolozenie_Y(y);
		this->SetRuch(1);
	}
	else {
		if (this->porownajGatunek(pomoc) == true) {
			this->powstaniePotomka(pomoc, x, y);
		}
		else {
			this->SetRuch(1);
			pomoc->kolizja(this);
		}
	}
}
void Antylopa::Wypisz(std::ostream& out) const {
	std::cout << "Antylopa";
}
bool Antylopa::CzyOdbilAtak(Organizm* atakujacy) {
	int wylosowana_liczba = (std::rand() % 100) + 1;
	if (wylosowana_liczba <= 50) {
		std::cout << "Antylopa ucieka przed walka!" << std::endl;
		atakujacy->SetPolozenie_X(this->GetPolozenie_X());
		atakujacy->SetPolozenie_Y(this->GetPolozenie_Y());
		int flag = 0;
		int x = this->polozenie_x;
		int y = this->polozenie_y;
		while (flag != 1) {
			wylosowana_liczba = (std::rand() % 4) + 1;
			if (wylosowana_liczba == 1 && x < 19) {
				x += 1;
				flag = 1;
			}
			if (wylosowana_liczba == 2 && x > 0) {
				x -= 1;
				flag = 1;
			}
			if (wylosowana_liczba == 3 && y > 0) {
				y -= 1;
				flag = 1;
			}
			if (wylosowana_liczba == 4 && y < 19) {
				y += 1;
				flag = 1;
			}
			Organizm* pomoc = this->s.znajdzOrganizm(x, y);
			if (pomoc == NULL) {
				this->SetPolozenie_X(x);
				this->SetPolozenie_Y(y);
				return true;
			}
			else {
				flag = 0;
			}
		}
	}
	return false;
}
void Antylopa::kolizja(Organizm* atakujacy) {
	if (this->CzyOdbilAtak(atakujacy) == true) {
		std::cout << "Antylopa ucieka przed walka z " << *atakujacy << std::endl;
	}
	else {
		if (this->sila > atakujacy->GetSila()) {
			std::cout << *this << " zabija " << *atakujacy << std::endl;
			this->s.usunOrganizm(atakujacy);
		}
		else {
			std::cout << *atakujacy << " zabija " << *this << std::endl;
			atakujacy->SetPolozenie_X(this->GetPolozenie_X());
			atakujacy->SetPolozenie_Y(this->GetPolozenie_Y());
			atakujacy->GetSwiat().usunOrganizm(this);
		}
		
	}
}
bool Antylopa::porownajGatunek(Organizm* org) {
	Antylopa* drugi = dynamic_cast<Antylopa*>(org);
	if (drugi != NULL) return true;
	return false;
}