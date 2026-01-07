#include "Owca.h"
#include <cstddef>
#include <cstdlib>

char Owca::rysowanie() { return 'O'; }

void Owca::kolizja(Organizm *inny) {
    if (dynamic_cast<Owca *>(inny)) {
        this->rozmnoz(this->getPolozenie());
        return;
    }

    if (this->getSila() >= inny->getSila()) {
        inny->setZyje(false);
        world->zmienPoz(this->getPolozenie(), inny->getPolozenie(), this);
        this->setPolozenie(inny->getPolozenie());
    } else {
        this->setZyje(false);
        world->zmienPoz(this->getPolozenie(), this->getPolozenie(), nullptr);
    }
}
