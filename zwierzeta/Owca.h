#pragma once

#include "Zwierzeta.h"
class Owca : public Zwierzeta {
  public:
    Owca(Swiat &swiat, Punkt p) : Zwierzeta(swiat, p) {
        this->sila = 4;
        this->inicjatywa = 4;
    }
    ~Owca() {};

    void kolizja(Organizm *org) override;
    char rysowanie() override;

    void urodzDziecko(Punkt p) override { world->dodajOrganizm<Owca>(p); }
};
