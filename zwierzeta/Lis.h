#pragma once

#include "Zwierzeta.h"
class Lis : public Zwierzeta {
  public:
    Lis(Swiat &swiat, Punkt p) : Zwierzeta(swiat, p) {
        this->sila = 3;
        this->inicjatywa = 7;
    }
    ~Lis() {};

    void kolizja(Organizm *org) override;
    char rysowanie() override;
    void akcja() override;

    void urodzDziecko(Punkt p) override { world->dodajOrganizm<Lis>(p); }
};
