#include "Wilk.h"

char Wilk::rysowanie() { return 'W'; }

void Wilk::kolizja(Organizm *inny) {
    if (dynamic_cast<Wilk *>(inny)) {
        this->rozmnoz(this->getPolozenie());
        return;
    }
    walka(inny);
}
