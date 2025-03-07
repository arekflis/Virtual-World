#include "Swiat.h"
#include "Czlowiek.h"
Swiat::Swiat(std::vector<Organizm*> o) {
	this->organizmy = o;
}
Swiat::~Swiat() {
	for (int i = 0; i < this->organizmy.size();i++) {
		delete this->organizmy[i];
	}
}
void Swiat::dodajOrganizm(Organizm* o) {
	this->organizmy.push_back(o);
}
void Swiat::usunOrganizm(Organizm* o) {
	int i = 0;
	while (this->organizmy[i] != o) {
		i++;
	}
	auto it = this->organizmy.begin() + i;
	this->organizmy.erase(it);
}
void Swiat::kolejnoscOrganizmow() {
	for (int i = 0; i < this->organizmy.size(); i++) {
		for (int j = 0; j < this->organizmy.size() - 1; j++) {
			if (this->organizmy[j]->GetInicjatywa() < this->organizmy[j + 1]->GetInicjatywa()) {
				Organizm* temp = this->organizmy[j];
				this->organizmy[j] = this->organizmy[j + 1];
				this->organizmy[j + 1] = temp;
			}
		}
	}
}
Organizm* Swiat::znajdzOrganizm(int x, int y) {
	for (int i = 0; i < this->organizmy.size(); i++) {
		if (this->organizmy[i]->GetPolozenie_X() == x && this->organizmy[i]->GetPolozenie_Y() == y) {
			return this->organizmy[i];
		}
	}
	return NULL;
}
void Swiat::rysujSwiat() {
	std::cout << std::endl;
	for (int k = 0; k < 22; k++) {
		std::cout << "-";
	}
	std::cout << std::endl;
	for (int j = 0; j < 20; j++) {
		std::cout << "|";
		for (int i = 0; i < 20; i++) {
			Organizm* pomoc = znajdzOrganizm(i, j);
			if (pomoc == NULL) {
				std::cout << " ";
			}
			else {
				pomoc->rysowanie();
			}
		}
		std::cout << "|";
		std::cout << std::endl;
	}
	for (int k = 0; k < 22; k++) {
		std::cout << "-";
	}
	std::cout << std::endl;
}
void Swiat::wykonajTure() {
	kolejnoscOrganizmow();
	zerujRuchy();
	int size = this->organizmy.size();
	int i = 0;
	while (i < this->organizmy.size()) {
		if (this->organizmy[i]->GetRuch() == 0) {
			this->organizmy[i]->akcja();
		}
		if (size > this->organizmy.size()) {
			size = this->organizmy.size();
		}
		else if (size <= this->organizmy.size()) {
			i++;
			size = this->organizmy.size();
		}
		else {
			i++;
		}
	}
}
void Swiat::zerujRuchy() {
	for (int i = 0; i < this->organizmy.size();i++) {
		this->organizmy[i]->SetRuch(0);
	}
}
void Swiat::wypiszOrganizmy() {
	for (int i = 0; i < this->organizmy.size(); i++) {
		std::cout << *this->organizmy[i] << " ";
		this->organizmy[i]->rysowanie();
		std::cout << std::endl;
	}
}
void Swiat::menu() {
	std::cout << "WILK - czerwony" << std::endl;
	std::cout << "OWCA - ciemny niebieski" << std::endl;
	std::cout << "ANTYLOPA - fioletowy" << std::endl;
	std::cout << "ZOLW - pomaranczowy" << std::endl;
	std::cout << "LIS - niebieski" << std::endl;
	std::cout << "CZLOWIEK - bialy" << std::endl;
	std::cout << "TRAWA - ciemny zielony" << std::endl;
	std::cout << "GUARANA - jasny zielony" << std::endl;
	std::cout << "WILCZE JAGODY - rozowy" << std::endl;
	std::cout << "MLECZ - zolty" << std::endl;
	std::cout << "BARSZCZ SOSNOWSKIEGO - szary" << std::endl;
}
bool Swiat::czyKoniecGry() {
	for (int i = 0; i < organizmy.size(); i++) {
		Czlowiek* men = dynamic_cast<Czlowiek*> (this->organizmy[i]);
		if (men != NULL) {
			return false;
		}
	}
	return true;
}