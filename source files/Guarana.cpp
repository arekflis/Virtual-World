#include "Guarana.h"
#include "Swiat.h"
Organizm* Guarana::Rozmnazanie() {
	std::cout << "Guarana sie rozprzestrzenia!" << std::endl;
	return new Guarana(*this);
}
Guarana::Guarana(Swiat& s, int x, int y) : Roslina(0, 0, x, y, s) {};
Guarana::~Guarana() {
	std::cout << "Guarana o polozeniu umiera: x: " << GetPolozenie_X() << " y: " << GetPolozenie_Y() << std::endl;
};
void Guarana::rysowanie() {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
	GetConsoleScreenBufferInfo(hConsole, &consoleInfo);
	WORD originalColors = consoleInfo.wAttributes;
	SetConsoleTextAttribute(hConsole, BACKGROUND_GREEN | BACKGROUND_INTENSITY);
	std::cout << " ";
	SetConsoleTextAttribute(hConsole, originalColors);
}
void Guarana::Wypisz(std::ostream& out) const {
	std::cout << "Guarana";
}
void Guarana::kolizja(Organizm* atakujacy) {
	if (this->CzyOdbilAtak(atakujacy) == true) {
		std::cout << *this << " zabija " << *atakujacy << std::endl;
		this->s.usunOrganizm(atakujacy);
	}
	else {
		std::cout << *atakujacy << " zabija i zwieksza sile o 3 " << *this << std::endl;
		atakujacy->SetPolozenie_X(this->GetPolozenie_X());
		atakujacy->SetPolozenie_Y(this->GetPolozenie_Y());
		std::cout << "Sila przed: " << atakujacy->GetSila();
		atakujacy->SetSila(atakujacy->GetSila() + 3);
		std::cout << " Sila po: " << atakujacy->GetSila() << std::endl;
		atakujacy->GetSwiat().usunOrganizm(this);
	}
}
bool Guarana::porownajGatunek(Organizm* org) {
	Guarana* drugi = dynamic_cast<Guarana*>(org);
	if (drugi != NULL) return true;
	return false;
}