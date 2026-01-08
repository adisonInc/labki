#include "Lis.h"
char Lis::rysowanie() { return 'L'; }

void Lis::kolizja(Organizm *inny) {
    if (dynamic_cast<Lis *>(inny)) {
        this->rozmnoz(this->getPolozenie());
        return;
    }
    walka(inny);
}
void Lis::akcja() {

    for (int i = 0; i < 10; i++) {
        Punkt v = Punkt(losuj(), losuj());
        if (v.x == 0 && v.y == 0)
            continue;

        Punkt cel = polozenie + v;

        if (world->sprawdzCzyWGrid(cel)) {
            Organizm *ofiara = world->ktoTutaj(cel);

            if (ofiara == nullptr || ofiara->getSila() <= this->sila) {
                idz(cel);
                return;
            }
        }
    }
}
