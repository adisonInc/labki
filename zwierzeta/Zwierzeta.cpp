#include "Zwierzeta.h"

int Zwierzeta::losuj() { return rand() % 3 - 1; }

void Zwierzeta::idz() {
    bool wykonanoRuch = false;
    int proby = 0;
    while (!wykonanoRuch && proby < 10) {
        proby++;
        Punkt v = Punkt(losuj(), losuj());
        if (v.x == 0 && v.y == 0) {
            continue;
        }
        Punkt cel = polozenie + v;
        if (world->sprawdzCzyWGrid(cel)) {
            if (!world->sprawdzPole(cel)) {
                world->zmienPoz(polozenie, cel, this);
                polozenie = cel;
                wykonanoRuch = true;
            } else {
                this->kolizja(world->ktoTutaj(cel));
                wykonanoRuch = true;
            }
        }
    }
}

void Zwierzeta::idz(Punkt cel) {
    this->ostatniaPozycja = this->polozenie;
    if (world->sprawdzCzyWGrid(cel)) {
        if (!world->sprawdzPole(cel)) {
            world->zmienPoz(polozenie, cel, this);
            polozenie = cel;
        } else {
            this->kolizja(world->ktoTutaj(cel));
        }
    }
}

void Zwierzeta::akcja() { idz(); }

Zwierzeta::Zwierzeta(Swiat &swiat, Punkt p) : Organizm(swiat, p) {}
void Zwierzeta::walka(Organizm *inny) {
    if (this->getSila() >= inny->getSila()) {
        inny->setZyje(false);

        Punkt nowaPoz = inny->getPolozenie();
        Punkt staraPoz = this->getPolozenie();

        world->zmienPoz(staraPoz, nowaPoz, this);
        this->setPolozenie(nowaPoz);
    } else {
        this->setZyje(false);
        world->zmienPoz(this->getPolozenie(), this->getPolozenie(), nullptr);
    }
}
void Zwierzeta::wroc() {
    world->zmienPoz(this->polozenie, this->ostatniaPozycja, this);
    this->polozenie = this->ostatniaPozycja;
}
