#include "Wilk.h"

Organizm* Wilk::Rozmnazanie() {
	std::cout << "Wilk sie rozmnaza!" << std::endl;
	return new Wilk(*this);
}
Wilk::Wilk(Swiat &s, int x, int y) : Zwierze(9,5,x,y,s) {}
Wilk::~Wilk() {
	std::cout << "Wilk o polozeniu umiera: x: " << GetPolozenie_X() << " y: " << GetPolozenie_Y() << std::endl;
}
void Wilk::rysowanie() {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
	GetConsoleScreenBufferInfo(hConsole, &consoleInfo);
	WORD originalColors = consoleInfo.wAttributes;
	SetConsoleTextAttribute(hConsole, BACKGROUND_RED);
	std::cout << " ";
	SetConsoleTextAttribute(hConsole, originalColors);
}
void Wilk::Wypisz(std::ostream& out) const {
	std::cout << "Wilk";
}
bool Wilk::porownajGatunek(Organizm* org) {
	Wilk* drugi = dynamic_cast<Wilk*>(org);
	if (drugi != NULL) return true;
	return false;
}