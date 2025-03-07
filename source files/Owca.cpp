#include "Owca.h"

Organizm* Owca::Rozmnazanie() {
	std::cout << "Owca sie rozmnaza!" << std::endl;
	return new Owca(*this);
}
Owca::Owca(Swiat& s, int x, int y) : Zwierze(4, 4, x, y, s) {}
Owca::~Owca() {
	std::cout << "Owca o polozeniu umiera: x: " << GetPolozenie_X() << " y: " << GetPolozenie_Y() << std::endl;
}
void Owca::rysowanie() {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
	GetConsoleScreenBufferInfo(hConsole, &consoleInfo);
	WORD originalColors = consoleInfo.wAttributes;
	SetConsoleTextAttribute(hConsole, BACKGROUND_BLUE);
	std::cout << " ";
	SetConsoleTextAttribute(hConsole, originalColors);
}
void Owca::Wypisz(std::ostream& out) const {
	std::cout << "Owca";
}
bool Owca::porownajGatunek(Organizm* org) {
	Owca* drugi = dynamic_cast<Owca*>(org);
	if (drugi != NULL) return true;
	return false;
}