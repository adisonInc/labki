#include "Zwierzeta.h"

int Zwierzeta::losuj() { return rand() % 3 - 1; }

void Zwierzeta::idz() {
    bool wykonanoRuch = false;

    while (!wykonanoRuch) {
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

void Zwierzeta::akcja() { idz(); }

Zwierzeta::Zwierzeta(Swiat &swiat, Punkt p) : Organizm(swiat, p) {}
