#include "BarszczSosnowskiego.h"
#include "Swiat.h"
#include "Zwierze.h"
Organizm* BarszczSosnowskiego::Rozmnazanie() {
	std::cout << "BarszczSosnowskiego sie rozprzestrzenil!" << std::endl;
	return new BarszczSosnowskiego(*this);
}
BarszczSosnowskiego::BarszczSosnowskiego(Swiat& s, int x, int y) : Roslina(10, 0, x, y, s) {};
BarszczSosnowskiego::~BarszczSosnowskiego() {
	std::cout << "Barszcz Sosnowskiego o polozeniu umiera: x: " << GetPolozenie_X() << " y: " << GetPolozenie_Y() << std::endl;
};
void BarszczSosnowskiego::rysowanie() {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
	GetConsoleScreenBufferInfo(hConsole, &consoleInfo);
	WORD originalColors = consoleInfo.wAttributes;
	SetConsoleTextAttribute(hConsole, BACKGROUND_INTENSITY);
	std::cout << " ";
	SetConsoleTextAttribute(hConsole, originalColors);
}
void BarszczSosnowskiego::akcja() {
	Roslina::akcja();
	Organizm* pomoc;
	if (this->polozenie_x < 19) {
		pomoc = this->s.znajdzOrganizm(this->polozenie_x + 1, this->polozenie_y);
		if (pomoc != NULL) {
			Zwierze* zw = dynamic_cast<Zwierze*> (pomoc);
			if (zw != NULL) {
				std::cout << "Barszcz Sosnowskiego zabil " << *pomoc << std::endl;
				this->s.usunOrganizm(pomoc);
			}
		}
	}
	if (this->polozenie_x > 0) {
		pomoc = this->s.znajdzOrganizm(this->polozenie_x - 1, this->polozenie_y);
		if (pomoc != NULL) {
			Zwierze* zw = dynamic_cast<Zwierze*> (pomoc);
			if (zw != NULL) {
				std::cout << "Barszcz Sosnowskiego zabil " << *pomoc << std::endl;
				this->s.usunOrganizm(pomoc);
			}
		}
	}
	if (this->polozenie_y < 19) {
		pomoc = this->s.znajdzOrganizm(this->polozenie_x, this->polozenie_y + 1);
		if (pomoc != NULL) {
			Zwierze* zw = dynamic_cast<Zwierze*> (pomoc);
			if (zw != NULL) {
				std::cout << "Barszcz Sosnowskiego zabil " << *pomoc << std::endl;
				this->s.usunOrganizm(pomoc);
			}
		}
	}
	if (this->polozenie_y > 0) {
		pomoc = this->s.znajdzOrganizm(this->polozenie_x, this->polozenie_y - 1);
		if (pomoc != NULL) {
			Zwierze* zw = dynamic_cast<Zwierze*> (pomoc);
			if (zw != NULL) {
				std::cout << "Barszcz Sosnowskiego zabil " << *pomoc << std::endl;
				this->s.usunOrganizm(pomoc);
			}
		}
	}
}
void BarszczSosnowskiego::Wypisz(std::ostream& out) const {
	std::cout << "Barszcz Sosnowskiego";
}
void BarszczSosnowskiego::kolizja(Organizm* atakujacy) {
	std::cout << *this << " zabija " << *atakujacy << std::endl;
	this->s.usunOrganizm(atakujacy);
}
bool BarszczSosnowskiego::porownajGatunek(Organizm* org) {
	BarszczSosnowskiego* drugi = dynamic_cast<BarszczSosnowskiego*>(org);
	if (drugi != NULL) return true;
	return false;
}