#include "Zwierze.h"
#include "Swiat.h"
void Zwierze::akcja() {
	int wylosowana_liczba;
	int flag = 0;
	int x = this->polozenie_x;
	int y = this->polozenie_y;
	while (flag != 1) {
		wylosowana_liczba = (std::rand() % 4) + 1;
		if (wylosowana_liczba == 1 && x<19) {
			x++;
			flag = 1;
		}
		if (wylosowana_liczba == 2 && x > 0) {
			x--;
			flag = 1;
		}
		if (wylosowana_liczba == 3 && y > 0) {
			y--;
			flag = 1;
		}
		if (wylosowana_liczba == 4 && y < 19) {
			y++;
			flag = 1;
		}
	}
	Organizm* pomoc = this->s.znajdzOrganizm(x, y);
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
void Zwierze::Wypisz(std::ostream& out) const {
	std::cout << "Zwierze";
}
bool Zwierze::CzyOdbilAtak(Organizm* atakujacy) {
	if (this->sila > atakujacy->GetSila()) return true;
	return false;
}
void Zwierze::kolizja(Organizm* atakujacy) {
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
void Zwierze::powstaniePotomka(Organizm* pomoc, int x, int y) {
	int flag = 0;
	Organizm* potomek = this->Rozmnazanie();
	int pom = 0;
	int x1, y1;
	if (this->GetPolozenie_Y() == pomoc->GetPolozenie_Y()) {
		if (this->GetPolozenie_X() > pomoc->GetPolozenie_X()) {
			x1 = pomoc->GetPolozenie_X();
			y1 = this->GetPolozenie_Y();
		}
		else {
			x1 = this->GetPolozenie_X();
			y1 = this->GetPolozenie_Y();
		}
		this->rozmnozeniepomoc1(x, y, y1, x1, pom, pomoc, potomek);
		if (pom == 0) {
			this->rozmnozeniepomoc2(x, y, y1, x1, pom, pomoc, potomek);
		}
	}
	else {
		if (this->GetPolozenie_Y() < pomoc->GetPolozenie_Y()) {
			x1 = pomoc->GetPolozenie_X();
			y1 = this->GetPolozenie_Y();
		}
		else {
			x1 = pomoc->GetPolozenie_X();
			y1 = pomoc->GetPolozenie_Y();
		}
		this->rozmnozeniepomoc3(x, y, y1, x1, pom, pomoc, potomek);
		if (pom == 0) {
			this->rozmnozeniepomoc4(x, y, y1, x1, pom, pomoc, potomek);
		}
	}
	if (pom == 0) {
		this->SetRuch(1);
		std::cout << "Rozmnozenie nie powiodlo sie!" << std::endl;
	}
}
void Zwierze::rozmnozeniepomoc1(int x, int y, int y1, int x1, int &pom, Organizm* pomoc, Organizm* potomek) {
	for (int i = y1 - 1; i < y1 + 3; i += 2) {
		if (pom == 1) break;
		for (int j = x1 - 1; j < x1 + 4; j += 3) {
			if (i >= 0 && i <= 19 && j >= 0 && j <= 19) {
				pomoc = this->s.znajdzOrganizm(j, i);
				if (pomoc == NULL) {
					potomek->SetPolozenie_X(j);
					potomek->SetPolozenie_Y(i);
					this->s.dodajOrganizm(potomek);
					pomoc = this->s.znajdzOrganizm(x, y);
					pomoc->SetRuch(1);
					this->SetRuch(1);
					potomek->SetRuch(1);
					pom = 1;
				}
			}
			if (pom == 1) break;
		}
	}
}
void Zwierze::rozmnozeniepomoc2(int x, int y, int y1, int x1, int &pom, Organizm*pomoc, Organizm*potomek) {
	for (int i = y1 - 1; i < y1 + 2; i++) {
		if (pom == 1) break;
		for (int j = x1 - 1; j < x1 + 3; j++) {
			if (i >= 0 && i <= 19 && j >= 0 && j <= 19) {
				pomoc = this->s.znajdzOrganizm(j, i);
				if (pomoc == NULL) {
					potomek->SetPolozenie_X(j);
					potomek->SetPolozenie_Y(i);
					this->s.dodajOrganizm(potomek);
					pomoc = this->s.znajdzOrganizm(x, y);
					pomoc->SetRuch(1);
					this->SetRuch(1);
					potomek->SetRuch(1);
					pom = 1;
				}
			}
			if (pom == 1) break;
		}
	}
}
void Zwierze::rozmnozeniepomoc3(int x, int y, int y1, int x1, int &pom, Organizm* pomoc, Organizm* potomek) {
	for (int i = y1 - 1; i < y1 + 4; i += 3) {
		if (pom == 1) break;
		for (int j = x1 - 1; j < x1 + 3; j += 2) {
			if (i >= 0 && i <= 19 && j >= 0 && j <= 19) {
				pomoc = this->s.znajdzOrganizm(j, i);
				if (pomoc == NULL) {
					potomek->SetPolozenie_X(j);
					potomek->SetPolozenie_Y(i);
					this->s.dodajOrganizm(potomek);
					pomoc = this->s.znajdzOrganizm(x, y);
					pomoc->SetRuch(1);
					this->SetRuch(1);
					potomek->SetRuch(1);
					pom = 1;
				}
			}
			if (pom == 1) break;
		}
	}
}
void Zwierze::rozmnozeniepomoc4(int x, int y, int y1, int x1, int& pom, Organizm* pomoc, Organizm* potomek) {
	for (int i = y1 - 1; i < y1 + 3; i++) {
		if (pom == 1) break;
		for (int j = x1 - 1; j < x1 + 2; j++) {
			if (i >= 0 && i <= 19 && j >= 0 && j <= 19) {
				pomoc = this->s.znajdzOrganizm(j, i);
				if (pomoc == NULL) {
					potomek->SetPolozenie_X(j);
					potomek->SetPolozenie_Y(i);
					this->s.dodajOrganizm(potomek);
					pomoc = this->s.znajdzOrganizm(x, y);
					pomoc->SetRuch(1);
					this->SetRuch(1);
					potomek->SetRuch(1);
					pom = 1;
				}
			}
			if (pom == 1) break;
		}
	}
}