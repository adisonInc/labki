#pragma once
#include "../Organizm.h"
#include "../Swiat.h"
#include <cstdlib>

class Zwierzeta : public Organizm {

  protected:
    Punkt ostatniaPozycja;
    Zwierzeta(Swiat &swiat, Punkt p);
    ~Zwierzeta() {};
    static int losuj();
    void idz();
    void idz(Punkt p);
    void akcja() override;
    void walka(Organizm *inny);

  public:
    void wroc();
};
