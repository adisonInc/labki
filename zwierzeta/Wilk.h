#pragma once

#include "Zwierzeta.h"
class Wilk : public Zwierzeta {
  public:
    Wilk(Swiat &swiat, Punkt p) : Zwierzeta(swiat, p) {
        this->sila = 9;
        this->inicjatywa = 5;
    }
    ~Wilk() {};

    void kolizja(Organizm *org) override;
    char rysowanie() override;

    void urodzDziecko(Punkt p) override { world->dodajOrganizm<Wilk>(p); }
};
