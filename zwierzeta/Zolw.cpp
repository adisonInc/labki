#include "Zolw.h"
char Zolw::rysowanie() { return 'Z'; }

void Zolw::urodzDziecko(Punkt p) { world->dodajOrganizm<Zolw>(p); }
void Zolw::akcja() {
    int los = rand() % 4;
    if (los == 0) {
        idz();
    }
}

void Zolw::kolizja(Organizm *napastnik) {
    if (dynamic_cast<Zolw *>(napastnik)) {
        this->rozmnoz(this->polozenie);
    } else if (napastnik->getSila() < 5) {
        Zwierzeta *z = dynamic_cast<Zwierzeta *>(napastnik);
        if (z) {
            z->wroc();
        }
        world->dodajLogi("Zolw odpiera atak!");
    } else {
        if (napastnik->getSila() > this->getSila()) {
            world->dodajLogi("Wilk (lub inny silny) zjada Zolwia");
            this->setZyje(false);

            Punkt staraPozNapastnika = napastnik->getPolozenie();
            Punkt pozycjaZolwia = this->getPolozenie();

            world->zmienPoz(staraPozNapastnika, pozycjaZolwia, napastnik);
            napastnik->setPolozenie(pozycjaZolwia);
        }

        else {
            napastnik->setZyje(false);
            world->zmienPoz(napastnik->getPolozenie(),
                            napastnik->getPolozenie(), nullptr);
        }
    }
}
