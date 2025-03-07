#include "Roslina.h"
#include "Swiat.h"

void Roslina::akcja() {
	int wylosowana_liczba;
	int x = this->polozenie_x;
	int y = this->polozenie_y;
	Organizm* pomoc;
	this->SetRuch(1);
	wylosowana_liczba = (std::rand() % 100) + 1;
	if (wylosowana_liczba < 5) {
		wylosowana_liczba = (std::rand() % 15) + 1;
		if (x < 19 && wylosowana_liczba%5==0) {
			x++;
		}
		else if (x > 0 && wylosowana_liczba % 5 == 1) {
			x--;
		}
		else if (y > 0 && wylosowana_liczba % 5 == 2) {
			y--;
		}
		else if (y < 19 && wylosowana_liczba % 5 == 3) {
			y++;
		}
	}
	pomoc = this->s.znajdzOrganizm(x, y);
	if (pomoc == NULL) {
		Organizm* potomek = this->Rozmnazanie();
		potomek->SetPolozenie_X(x);
		potomek->SetPolozenie_Y(y);
		this->s.dodajOrganizm(potomek);
	}
}
void Roslina::Wypisz(std::ostream& out) const {
	std::cout << "Roslina";
}
bool Roslina::CzyOdbilAtak(Organizm* atakujacy) {
	if (this->sila > atakujacy->GetSila()) return true;
	return false;
}
void Roslina::kolizja(Organizm* atakujacy) {
	if (this->CzyOdbilAtak(atakujacy) == true) {
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