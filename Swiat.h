#pragma once
#include "Organizm.h"
#include "algorithm"
#include <iostream>
#include <string>
#include <vector>
class Swiat {
  private:
    int N;
    int M;
    static int instance;

    std::vector<std::vector<Organizm *>> grid;
    std::vector<Organizm *> inicjatywy;

    std::vector<std::string> logi;

    Swiat();

    Swiat(const Swiat &other) = delete;
    void operator=(const Swiat &other) = delete;

  public:
    ~Swiat();
    static Swiat *createSwiat();

    void setGrid(int n, int m);
    void paintGrid();

    int getGridN();
    int getGridM();

    void rysujSwiat();
    void wykonajTure();
    void sortInicjatywa();

    void zmienPoz(Punkt stary, Punkt nowy, Organizm *org);
    template <typename T> void wypelnijGrid(int ilosc) {
        for (auto i = 0; i < ilosc; i++) {

            bool znaleziono = false;
            while (!znaleziono) {
                int rx = rand() % M;
                int ry = rand() % N;
                Punkt rnd = Punkt(rx, ry);
                if (!sprawdzPole(rnd)) {
                    T *org = new T(*this, rnd);
                    inicjatywy.push_back(org);
                    grid[ry][rx] = org;
                    znaleziono = true;
                };
            }
        }
    };

    template <typename T> void dodajOrganizm(Punkt p) {
        T *nowy = new T(*this, p);

        grid[p.y][p.x] = nowy;

        inicjatywy.push_back(nowy);
    }

    bool sprawdzPole(Punkt &p);

    Organizm *ktoTutaj(Punkt &p);
    bool sprawdzCzyWGrid(Punkt &p);
    Punkt losujPole();

    void dodajLogi(std::string s);
    void wypiszLogi();
    void czyscLogi();
};
