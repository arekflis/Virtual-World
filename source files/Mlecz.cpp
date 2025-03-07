#include "Mlecz.h"
#include "Swiat.h"

Organizm* Mlecz::Rozmnazanie() {
	std::cout << "Mlecz sie rozprzestrzenia!" << std::endl;
	return new Mlecz(*this);
}
Mlecz::Mlecz(Swiat& s, int x, int y) : Roslina(0, 0, x, y, s) {};
Mlecz::~Mlecz() {
	std::cout << "Mlecz o polozeniu umiera: x: " << GetPolozenie_X() << " y: " << GetPolozenie_Y() << std::endl;
};
void Mlecz::rysowanie() {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
	GetConsoleScreenBufferInfo(hConsole, &consoleInfo);
	WORD originalColors = consoleInfo.wAttributes;
	SetConsoleTextAttribute(hConsole, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_INTENSITY);
	std::cout << " ";
	SetConsoleTextAttribute(hConsole, originalColors);
}
void Mlecz::akcja() {
	for (int i = 0; i < 3; i++) {
		Roslina::akcja();
	}
}
void Mlecz::Wypisz(std::ostream& out) const {
	std::cout << "Mlecz";
}
bool Mlecz::porownajGatunek(Organizm* org) {
	Mlecz* drugi = dynamic_cast<Mlecz*>(org);
	if (drugi != NULL) return true;
	return false;
}