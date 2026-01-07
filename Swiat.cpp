#include "Swiat.h"
#include "Organizm.h"
#include <ncurses.h>

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

    for (int i = 0; i < N; ++i) {     // i = wiersze (Y)
        for (int j = 0; j < M; ++j) { // j = kolumny (X)

            move(i, j);

            if (grid[i][j] != nullptr) {
                char x = grid[i][j]->rysowanie(); // Tu jest organizm
                printw("%c", x);
            } else {
                printw("."); // Puste pole
            }
        }
    }

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
    std::vector<Organizm *> kopia = inicjatywy;
    for (Organizm *o : kopia) {
        if (o->getZyje()) {
            o->akcja();
        }
    }
}

void Swiat::zmienPoz(Punkt stary, Punkt nowy, Organizm *org) {
    grid[stary.y][stary.x] = nullptr;
    grid[nowy.y][nowy.x] = org;
}
