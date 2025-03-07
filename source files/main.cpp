#include <iostream>
#include <Windows.h>
#include "Swiat.h"
#include "Organizm.h"
#include "Wilk.h"
#include "Antylopa.h"
#include "Owca.h"
#include "Zolw.h"
#include "Zwierze.h"
#include "Roslina.h"
#include "Lis.h"
#include "BarszczSosnowskiego.h"
#include "Guarana.h"
#include "Mlecz.h"
#include "Trawa.h"
#include "WilczeJagody.h"
#include "Czlowiek.h"
#include "conio2.h"

int main()
{
    std::vector<Organizm*> organizmy;
    Swiat s1(organizmy);

    Wilk* w1 = new Wilk(s1, 19, 1);
    Wilk* w2 = new Wilk(s1, 19, 13);
    Wilk* w6 = new Wilk(s1, 19,18);
    Wilk* w3 = new Wilk(s1, 18, 1);
    Wilk* w4 = new Wilk(s1, 19, 2);
    Wilk* w5 = new Wilk(s1, 19, 19);
    Lis* l1 = new Lis(s1, 6, 6);
    Lis* l2 = new Lis(s1, 6, 7);
    Lis* l3 = new Lis(s1, 19, 3);
    Lis* l4 = new Lis(s1, 0, 0);
    Lis* l5 = new Lis(s1, 0, 1);
    Lis* l6 = new Lis(s1, 1, 1);
    Mlecz* m1 = new Mlecz(s1, 18, 3);
    Guarana* g1 = new Guarana(s1,14, 15);
    Trawa* t1 = new Trawa(s1, 18, 19);
    WilczeJagody* wj1 = new WilczeJagody(s1, 3, 3);
    Czlowiek* men = new Czlowiek(s1, 15, 15);

    s1.dodajOrganizm(w1);
    s1.dodajOrganizm(w2);
    s1.dodajOrganizm(w3);
    s1.dodajOrganizm(w4);
    s1.dodajOrganizm(w5);
    s1.dodajOrganizm(l1);
    s1.dodajOrganizm(l2);
    s1.dodajOrganizm(l3);
    s1.dodajOrganizm(l4);
    s1.dodajOrganizm(l5);
    s1.dodajOrganizm(l6);
    s1.dodajOrganizm(m1);
    s1.dodajOrganizm(w6);
        s1.dodajOrganizm(g1);
    s1.dodajOrganizm(t1);
    s1.dodajOrganizm(wj1);
    s1.dodajOrganizm(men);

    s1.kolejnoscOrganizmow();    
   
    
    int i=0;
    while (i != 1) {
        system("cls");
        std::cout << "ARKADIUSZ FLISIKOWSKI 193496" << std::endl;
        s1.menu();
        s1.rysujSwiat();
        s1.wykonajTure();
        s1.rysujSwiat();
        std::cout << "Przejdz do nastepnej rundy" << std::endl;
        char ch;
        bool flag = false;
        while (flag != true) {
            ch = getch();
            if (ch == '\r') {
                flag = true;
            }
            if (ch == 'q') {
                return 1;
            }
        }
        
        if (s1.czyKoniecGry() == true) return 1;
    }
    return 0;
}
