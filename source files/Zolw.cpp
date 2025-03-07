#include "Zolw.h"
#include "Swiat.h"
Organizm* Zolw::Rozmnazanie() {
	std::cout << "Zolw sie rozmnaza!" << std::endl;
	return new Zolw(*this);
}
Zolw::Zolw(Swiat &s, int x, int y) : Zwierze(2,1,x,y,s) {}

Zolw::~Zolw() {
	std::cout << "Zolw o polozeniu umiera: x: " << GetPolozenie_X() << " y: " << GetPolozenie_Y() << std::endl;
}
void Zolw::rysowanie() {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
	GetConsoleScreenBufferInfo(hConsole, &consoleInfo);
	WORD originalColors = consoleInfo.wAttributes;
	SetConsoleTextAttribute(hConsole, BACKGROUND_RED | BACKGROUND_GREEN);
	std::cout << " ";
	SetConsoleTextAttribute(hConsole, originalColors);
}
void Zolw::akcja() {
	int zmiana_polozenia = (std::rand() % 4) + 1;
	if (zmiana_polozenia == 2) {
		Zwierze::akcja();
	}
}
void Zolw::Wypisz(std::ostream& out) const {
	std::cout << "Zolw";
}
bool Zolw::CzyOdbilAtak(Organizm* atakujacy) {
	if (atakujacy->GetSila() < 5) return true;
	return false;
}
void Zolw::kolizja(Organizm* atakujacy) {
	if (this->CzyOdbilAtak(atakujacy) == true) {
		std::cout << *this << " odpiera atak " << *atakujacy << std::endl;
	}
	else {
		
		std::cout << *atakujacy << " zabija " << *this << std::endl;
		atakujacy->SetPolozenie_X(this->GetPolozenie_X());
		atakujacy->SetPolozenie_Y(this->GetPolozenie_Y());
		atakujacy->GetSwiat().usunOrganizm(this);
	}
}
bool Zolw::porownajGatunek(Organizm* org) {
	Zolw* drugi = dynamic_cast<Zolw*>(org);
	if (drugi != NULL) return true;
	return false;
}