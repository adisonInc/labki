#include "Swiat.h"
#include <ncurses.h>

int Swiat::instance = 0;

Swiat::Swiat() : N(0), M(0) {}

Swiat::~Swiat() {
    for (auto& row : grid) {
        for (Organizm* org : row) {
            delete org;
        }
    }
}

Swiat* Swiat::createSwiat() {
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

    for (int i = 0; i < N; ++i) {     // i = wiersze (Y)
        for (int j = 0; j < M; ++j) { // j = kolumny (X)
            
            move(i, j);

            if (grid[i][j] != nullptr) {
                printw("O"); // Tu jest organizm
            } else {
                printw("."); // Puste pole
            }
        }
    }
    
    mvprintw(N + 1, 0, "Wymiary: %dx%d", M, N);
    refresh();
}

int Swiat::getGridN() { return N; }
int Swiat::getGridM() { return M; }