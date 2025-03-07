#include "Czlowiek.h"
#include "Swiat.h"
#include "conio2.h"

Organizm* Czlowiek::Rozmnazanie() {
    return NULL;
}
Czlowiek::Czlowiek(Swiat& s, int x, int y) : Zwierze(5, 4, x, y, s) {}
Czlowiek::~Czlowiek() {
	std::cout << "Czlowiek o polozeniu umiera: x: " << GetPolozenie_X() << " y: " << GetPolozenie_Y() << std::endl;
}
void Czlowiek::rysowanie() {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
	GetConsoleScreenBufferInfo(hConsole, &consoleInfo);
	WORD originalColors = consoleInfo.wAttributes;
	SetConsoleTextAttribute(hConsole, 0b01110000);
	std::cout << " ";
	SetConsoleTextAttribute(hConsole, originalColors);
}
void Czlowiek::akcja() {
	int flag = 0;
    int x = this->polozenie_x;
    int y = this->polozenie_y;
    this->Sterowanie();
    std::cout << "Sila czlowieka  wynosi " << this->sila << std::endl;
	while (flag != 1) {
        char ch;
        flag = 0;
        ch = getch();
        if (ch == 72) { // strza³ka w górê
            this->Up(y, flag);
        }
        else if (ch == 80) { // strza³ka w dó³
            this->Down(y, flag);
        }
        else if (ch == 75) { // strza³ka w lewo
            this->Left(x, flag);
        }
        else if (ch == 77) { // strza³ka w prawo
            this->Right(x, flag);
        }
        else if (ch == 'm' && this->moc==10) {
            this->sila = 10;
            std::cout << "Wlaczono moc" << std::endl;
            this->moc--;
        }
        else if(ch!=0) {
            std::cout << "Wcisnieto nieodpowiedni znak!" << std::endl;
        }
    }
    Organizm* pomoc = this->s.znajdzOrganizm(x, y);
	if (pomoc == NULL) {
		this->SetPolozenie_X(x);
		this->SetPolozenie_Y(y);
        this->SetRuch(1);
	}
	else {
            this->SetRuch(1);
			pomoc->kolizja(this);
            
	}
}
void Czlowiek::Wypisz(std::ostream& out) const {
	std::cout << "Czlowiek";
}
bool Czlowiek::porownajGatunek(Organizm* org) {
    return false;
}
int Czlowiek::GetMoc() {
    return this->moc;
}
void Czlowiek::SetMoc(int moc) {
    this->moc = moc;
}
void Czlowiek::Sterowanie() {
    std::cout << "Poruszaj sie za pomoca strzalek:" << std::endl;
    std::cout << "LEFT/RIGHT/UP/DOWN" << std::endl;
    if (this->moc == 10) {
        std::cout << "Mozesz wlaczyc moc za pomoca 'm'" << std::endl;
    }
    else if (this->moc >= 5) {
        this->moc--;
        this->sila--;
    }
    else if (this->moc > 0) {
        this->moc--;
    }
    else {
        this->moc = 10;
    }
}
void Czlowiek::Left(int &x, int &flag) {
    if (x > 0) {
        x--;
        flag = 1;
        std::cout << "LEFT" << std::endl;
    }
}
void Czlowiek::Right(int& x, int& flag) {
    if (x < 19) {
        x++;
        flag = 1;
        std::cout << "RIGHT" << std::endl;
    }
}
void Czlowiek::Up(int &y, int &flag) {
    if (y > 0) {
        y--;
        flag = 1;
        std::cout << "UP" << std::endl;
    }
}
void Czlowiek::Down(int& y, int& flag) {
    if (y < 19) {
        y++;
        flag = 1;
        std::cout << "DOWN" << std::endl;
    }
}