
#pragma once
#include <cstdlib>
#ifndef LABKI_ORGANIZM_H
#define LABKI_ORGANIZM_H

class Swiat;

struct Punkt {
    int x;
    int y;
    Punkt() : x{0}, y{0} {};
    Punkt(int x, int y) : x(x), y(y) {};
    bool operator==(const Punkt &o) const { return x == o.x && y == o.y; }
    Punkt operator+(const Punkt &o) { return Punkt(x + o.x, y + o.y); }
};

class Organizm {
  protected:
    int sila;
    int inicjatywa;
    Punkt polozenie;

    int wiek;
    bool zyje;

    Swiat *world;

    void rozmnoz(Punkt p);
    virtual void urodzDziecko(Punkt p) = 0;

  public:
    Organizm(Swiat &swiat, Punkt p);
    virtual ~Organizm() = 0;
    virtual void akcja() = 0;
    virtual void kolizja(Organizm *o) = 0;
    virtual char rysowanie() = 0;

    bool getZyje();
    void setZyje(bool x);

    int getSila();
    void setSila(int x);

    int getInicjatywa();
    void setInicjatywa(int x);

    Punkt getPolozenie();
    void setPolozenie(Punkt p);

    int getWiek();
    void incWiek();
};

#endif // LABKI_ORGANIZM_H
