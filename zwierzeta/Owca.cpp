#include "Owca.h"

char Owca::rysowanie() { return 'O'; }

void Owca::kolizja(Organizm *inny) {
    if (dynamic_cast<Owca *>(inny)) {
        this->rozmnoz(this->getPolozenie());
        return;
    }
    walka(inny);
}
