#pragma once

#include "Zwierzeta.h"
class Antylopa : public Zwierzeta {
  public:
    Antylopa(Swiat &swiat, Punkt p) : Zwierzeta(swiat, p) {
        this->sila = 4;
        this->inicjatywa = 4;
    }
    ~Antylopa() {};

    void kolizja(Organizm *org) override;
    char rysowanie() override;
    void akcja() override;

    void urodzDziecko(Punkt p) override;
};
