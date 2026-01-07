#include "Organizm.h"
#include "Swiat.h"
Organizm::Organizm(Swiat &swiat, Punkt p) {
    this->world = &swiat;
    this->polozenie = p;
    this->zyje = true;
    this->wiek = 0;
};
Organizm::~Organizm() {};

int Organizm::getSila() { return this->sila; };
void Organizm::setSila(int x) { this->sila = x; };

int Organizm::getInicjatywa() { return this->inicjatywa; };
void Organizm::setInicjatywa(int x) { this->inicjatywa = x; };

Punkt Organizm::getPolozenie() { return this->polozenie; };
void Organizm::setPolozenie(Punkt P) {
    this->polozenie.x = P.x;
    this->polozenie.y = P.y;
};

bool Organizm::getZyje() { return this->zyje; };
void Organizm::setZyje(bool x) { this->zyje = x; };

void Organizm::rozmnoz(Punkt p) {
    bool znaleziono = false;
    int proby = 0;
    while (proby < 10) {
        proby++;
        int rx = rand() % 3 - 1 + p.x;
        int ry = rand() % 3 - 1 + p.y;
        Punkt rnd = Punkt(rx, ry);
        if (world->sprawdzCzyWGrid(rnd) == true &&
            world->ktoTutaj(rnd) == nullptr) {
            this->urodzDziecko(rnd);
            znaleziono = true;
            return;
        }
    }
}
