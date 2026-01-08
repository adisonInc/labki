#include "Swiat.h"
#include "zwierzeta/Antylopa.h"
#include "zwierzeta/Lis.h"
#include "zwierzeta/Owca.h"
#include "zwierzeta/Wilk.h"
#include "zwierzeta/Zolw.h"
#include <ctime>
#include <ncurses.h>

int main() {
    srand(time(NULL));
    initscr();
    noecho();
    curs_set(0);
    keypad(stdscr, TRUE);
    start_color();
    use_default_colors();

    init_pair(1, COLOR_WHITE, -1);  // default
    init_pair(2, COLOR_RED, -1);    // Wilk
    init_pair(3, COLOR_GREEN, -1);  // Owca
    init_pair(4, COLOR_YELLOW, -1); // Lis

    Swiat *kox = Swiat::createSwiat();

    if (kox) {
        kox->setGrid(4, 3);
        kox->wypelnijGrid<Wilk>(1);
        // kox->wypelnijGrid<Owca>(1);
        //  kox->wypelnijGrid<Lis>(3);
        kox->wypelnijGrid<Antylopa>(1);
        // kox->wypelnijGrid<Zolw>(1);

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
