#include "Trawa.h"

Organizm* Trawa::Rozmnazanie() {
	std::cout << "Trawa sie rozprzestrzenia!" << std::endl;
	return new Trawa(*this);
}
Trawa::Trawa(Swiat& s, int x, int y) : Roslina(0,0, x, y, s) {};
Trawa::~Trawa() {
	std::cout << "Trawa o polozeniu umiera: x: " << GetPolozenie_X() << " y: " << GetPolozenie_Y() << std::endl;
};
void Trawa::rysowanie() {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
	GetConsoleScreenBufferInfo(hConsole, &consoleInfo);
	WORD originalColors = consoleInfo.wAttributes;
	SetConsoleTextAttribute(hConsole, BACKGROUND_GREEN);
	std::cout << " ";
	SetConsoleTextAttribute(hConsole, originalColors);
}
void Trawa::Wypisz(std::ostream& out) const {
	std::cout << "Trawa";
}
bool Trawa::porownajGatunek(Organizm* org) {
	Trawa* drugi = dynamic_cast<Trawa*>(org);
	if (drugi != NULL) return true;
	return false;
}