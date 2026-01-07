#pragma once
#include "../Organizm.h"
#include "../Swiat.h"
#include <cstdlib>

class Zwierzeta : public Organizm {

  protected:
    Zwierzeta(Swiat &swiat, Punkt p);
    ~Zwierzeta() {};
    static int losuj();
    void idz();
    void akcja() override;
};
