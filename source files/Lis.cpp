#include "Lis.h"
#include "Swiat.h"

Organizm* Lis::Rozmnazanie() {
	std::cout << "Lis sie rozmnaza!" << std::endl;
	return new Lis(*this);
}
Lis::Lis(Swiat& s, int x, int y) : Zwierze(3, 7, x, y, s) {}
Lis::~Lis() {
	std::cout << "Lis o polozeniu umiera: x: " << GetPolozenie_X() << " y: " << GetPolozenie_Y() << std::endl;
}
void Lis::rysowanie() {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
	GetConsoleScreenBufferInfo(hConsole, &consoleInfo);
	WORD originalColors = consoleInfo.wAttributes;
	SetConsoleTextAttribute(hConsole, BACKGROUND_BLUE | BACKGROUND_INTENSITY);
	std::cout << " ";
	SetConsoleTextAttribute(hConsole, originalColors);
}
void Lis::akcja() {
	int wylosowana_liczba;
	int flag = 0;
	int x = this->polozenie_x;
	int y = this->polozenie_y;
	Organizm* pomoc;
	while (flag != 1) {
		wylosowana_liczba = (std::rand() % 4) + 1;
		if (wylosowana_liczba == 1 && x < 19) {
			pomoc = this->s.znajdzOrganizm(x+1, y);
			Lis* lisek = dynamic_cast<Lis*>(pomoc);
			if (pomoc == NULL || lisek!= NULL) {
				x += 1;
				flag = 1;
			}
			else {
				if (pomoc->GetSila() > this->sila) {
					flag = 0;
				}
			}
		}
		if (wylosowana_liczba == 2 && x > 0) {
			pomoc = this->s.znajdzOrganizm(x - 1, y);
			Lis* lisek = dynamic_cast<Lis*>(pomoc);
			if (pomoc == NULL || lisek != NULL) {
				x -= 1;
				flag = 1;
			}
			else {
				if (pomoc->GetSila() > this->sila) {
					flag = 0;
				}
			}
		}
		if (wylosowana_liczba == 3 && y > 0) {
			pomoc = this->s.znajdzOrganizm(x, y-1);
			Lis* lisek = dynamic_cast<Lis*>(pomoc);
			if (pomoc == NULL || lisek != NULL) {
				y -= 1;
				flag = 1;
			}
			else {
				if (pomoc->GetSila() > this->sila) {
					flag = 0;
				}
			}
		}
		if (wylosowana_liczba == 4 && y < 19) {
			pomoc = this->s.znajdzOrganizm(x, y + 1);
			Lis* lisek = dynamic_cast<Lis*>(pomoc);
			if (pomoc == NULL || lisek != NULL) {
				y += 1;
				flag = 1;
			}
			else {
				if (pomoc->GetSila() > this->sila) {
					flag = 0;
				}
			}
		}
	}
	pomoc = this->s.znajdzOrganizm(x, y);
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
void Lis::Wypisz(std::ostream& out) const {
	std::cout << "Lis";
}
bool Lis::porownajGatunek(Organizm* org) {
	Lis* drugi = dynamic_cast<Lis*>(org);
	if (drugi != NULL) return true;
	return false;
}