#include "Swiat.h"
#include "zwierzeta/Wilk.h"
#include <ncurses.h>

int main() {
    srand(321);
    initscr();
    noecho();
    curs_set(0);
    keypad(stdscr, TRUE);

    Swiat *kox = Swiat::createSwiat();

    if (kox) {
        kox->setGrid(3, 3);
        kox->wypelnijGrid<Wilk>(2);

        int klawisz;
        while (true) {
            kox->paintGrid();  // 1. Rysujemy obecny stan
            klawisz = getch(); // 2. Czekamy na ruch gracza

            if (klawisz == 'q' || klawisz == 'Q') {
                break; // Wyjście z gry
            }

            if (klawisz == ' ') { // Spacja wykonuje turę
                kox->wykonajTure();
            }

            // Możesz też dodać strzałki (wymaga keypad(stdscr, TRUE))
            if (klawisz == KEY_RIGHT) {
                kox->wykonajTure();
            }
        }
        kox->paintGrid();
        mvprintw(12, 0, "Nacisnij dowolny klawisz aby wyjsc...");
        getch();

        delete kox;
    }

    endwin();
    return 0;
}
