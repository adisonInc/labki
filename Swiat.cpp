#include "Swiat.h"
#include "Organizm.h"
#include <ncurses.h>
#include <string>

int Swiat::instance = 0;

Swiat::Swiat() : N(0), M(0) {}

Swiat::~Swiat() {
    for (auto &row : grid) {
        for (Organizm *org : row) {
            delete org;
        }
    }
}

Swiat *Swiat::createSwiat() {
    if (instance == 0) {
        instance++;
        return new Swiat();
    }
    return nullptr;
}

void Swiat::setGrid(int n, int m) {
    this->N = n;
    this->M = m;

    grid.resize(N);
    for (int i = 0; i < N; ++i) {
        grid[i].resize(M, nullptr);
    }
}

void Swiat::paintGrid() {
    clear();
    mvprintw(N + 1, 0, "Wymiary: %dx%d", M, N);
    int lines = 1;
    int wilki = 0;
    int owce = 0;
    int lis = 0;
    for (Organizm *c : inicjatywy) {
        if (c->rysowanie() == 'W') {
            wilki++;
        }
        if (c->rysowanie() == 'L') {
            lis++;
        } else {
            owce++;
        }
        lines++;
    }

    // mvprintw(N + 2, 0, "owce: %d", owce);
    // mvprintw(N + 4, 0, "lis: %d", lis);
    // mvprintw(N + 3, 0, "wilki: %d", wilki);

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {

            move(i, j);

            if (grid[i][j] != nullptr) {
                char x = grid[i][j]->rysowanie();
                printw("%c", x);
            } else {
                printw(".");
            }
        }
    }
    wypiszLogi();

    refresh();
}

int Swiat::getGridN() { return N; }
int Swiat::getGridM() { return M; }

bool Swiat::sprawdzCzyWGrid(Punkt &p) {
    return (p.x >= 0 && p.x < M && p.y >= 0 && p.y < N);
}

bool Swiat::sprawdzPole(Punkt &p) {
    if (grid[p.y][p.x] == nullptr) {
        return false;
    }
    return true;
}
Organizm *Swiat::ktoTutaj(Punkt &p) { return grid[p.y][p.x]; }

void Swiat::wykonajTure() {
    sortInicjatywa();
    std::vector<Organizm *> kopia = inicjatywy;
    for (Organizm *o : kopia) {
        if (o->getZyje()) {
            o->akcja();
            std::string s = " ";
            s[0] = o->rysowanie();
            s += " Wiek: ";
            s += std::to_string(o->getWiek());
            dodajLogi("ruch: " + s);
            o->incWiek();
        }
    }
    refresh();
}
void Swiat::sortInicjatywa() {
    std::sort(inicjatywy.begin(), inicjatywy.end(),
              [](Organizm *a, Organizm *b) {
                  if (a->getInicjatywa() != b->getInicjatywa()) {
                      return a->getInicjatywa() > b->getInicjatywa();
                  }
                  return a->getWiek() > b->getWiek();
              });
};

void Swiat::zmienPoz(Punkt stary, Punkt nowy, Organizm *org) {
    grid[stary.y][stary.x] = nullptr;
    grid[nowy.y][nowy.x] = org;
}

void Swiat::dodajLogi(std::string s) { this->logi.push_back(s); }
void Swiat::wypiszLogi() {
    int row = 0;
    mvprintw(row++, M + 5, "--- DZIENNIK ZDARZEN ---");
    for (const auto &log : logi) {
        if (row < N + 10) {
            mvprintw(row++, M + 5, "%s", log.c_str());
        }
    }
    czyscLogi();
}

void Swiat::czyscLogi() { logi.clear(); }
