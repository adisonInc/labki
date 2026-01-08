#pragma once

#include "Zwierzeta.h"
class Zolw : public Zwierzeta {
  public:
    Zolw(Swiat &swiat, Punkt p) : Zwierzeta(swiat, p) {
        this->sila = 2;
        this->inicjatywa = 1;
    }
    ~Zolw() {};

    void kolizja(Organizm *org) override;
    char rysowanie() override;
    void akcja() override;
    void urodzDziecko(Punkt p) override;
};
