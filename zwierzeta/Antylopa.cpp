#include "Antylopa.h"
char Antylopa::rysowanie() { return 'A'; }
void Antylopa::urodzDziecko(Punkt p) { world->dodajOrganizm<Antylopa>(p); }
void Antylopa::akcja() {
    idz();
    if (this->getZyje()) {
        idz();
    }
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
        idz(world->pustySasiad(this->polozenie));
    } else {
        walka(inny);
    }
}
