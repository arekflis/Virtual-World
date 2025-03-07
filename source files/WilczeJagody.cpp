#include "WilczeJagody.h"
#include "Swiat.h"
Organizm* WilczeJagody::Rozmnazanie() {
	std::cout << "Wilcze Jagody sie rozprzestrzeniaja!" << std::endl;
	return new WilczeJagody(*this);
}
WilczeJagody::WilczeJagody(Swiat& s, int x, int y) : Roslina(99, 0, x, y, s) {};
WilczeJagody::~WilczeJagody() {
	std::cout << "Wilcze Jagody o polozeniu umiera: x: " << GetPolozenie_X() << " y: " << GetPolozenie_Y() << std::endl;
};
void WilczeJagody::rysowanie() {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
	GetConsoleScreenBufferInfo(hConsole, &consoleInfo);
	WORD originalColors = consoleInfo.wAttributes;
	SetConsoleTextAttribute(hConsole, BACKGROUND_RED | BACKGROUND_BLUE | BACKGROUND_INTENSITY);
	std::cout << " ";
	SetConsoleTextAttribute(hConsole, originalColors);
}
void WilczeJagody::Wypisz(std::ostream& out) const {
	std::cout << "WilczeJagody";
}
void WilczeJagody::kolizja(Organizm* atakujacy) {
	std::cout << *this << " zabija " << *atakujacy << std::endl;
	this->s.usunOrganizm(atakujacy);
}
bool WilczeJagody::porownajGatunek(Organizm* org) {
	WilczeJagody* drugi = dynamic_cast<WilczeJagody*>(org);
	if (drugi != NULL) return true;
	return false;
}