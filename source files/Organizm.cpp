#include <iostream>
#include "Organizm.h"


Organizm::Organizm(int sila, int inicjatywa, int polozenie_x, int polozenie_y, Swiat& s) : sila(sila), inicjatywa(inicjatywa), polozenie_x(polozenie_x), polozenie_y(polozenie_y), s(s) {}
void Organizm::SetSila(int sila) {
	this->sila = sila;
}
int Organizm::GetSila() {
	return this->sila;
}
void Organizm::SetInicjatywa(int inicjatywa) {
	this->inicjatywa = inicjatywa;
}
int Organizm::GetInicjatywa() {
	return this->inicjatywa;
}
void Organizm::SetPolozenie_X(int x) {
	this->polozenie_x = x;
}
int Organizm::GetPolozenie_X() {
	return this->polozenie_x;
}
void Organizm::SetPolozenie_Y(int y) {
	this->polozenie_y = y;
}
int Organizm::GetPolozenie_Y() {
	return this->polozenie_y;
}
void Organizm::SetRuch(int ruch) {
	this->ruch = ruch;
}
int Organizm::GetRuch() {
	return this->ruch;
}
Organizm::~Organizm() {
	
}
Swiat& Organizm::GetSwiat() {
	return this->s;
}
std::ostream& operator<<(std::ostream& os, const Organizm& org) {
	org.Wypisz(os);
	return os;
}