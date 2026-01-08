#include "Antylopa.h"
char Antylopa::rysowanie() { return 'A'; }
void Antylopa::urodzDziecko(Punkt p) { world->dodajOrganizm<Antylopa>(p); }
void Antylopa::akcja() {
    idz();
    idz();
}

void Antylopa::kolizja(Organizm *inny) {

    if (dynamic_cast<Antylopa *>(inny)) {
        this->rozmnoz(this->getPolozenie());
        return;
    }
    int proby = 0;
    int los = rand() % 2;
    if (los == 1) {
        world->dodajLogi("ucieczka");
        while (proby < 10) {
            proby++;
            int rx = rand() % 3 - 1 + getPolozenie().x;
            int ry = rand() % 3 - 1 + getPolozenie().y;
            Punkt rnd = Punkt(rx, ry);
            if (world->sprawdzCzyWGrid(rnd) == true &&
                world->ktoTutaj(rnd) == nullptr) {
                this->urodzDziecko(rnd);
                return;
            }
        }
        idz();
    } else {
        walka(inny);
    }
}
