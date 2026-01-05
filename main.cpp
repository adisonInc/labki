#include <ncurses.h>
#include "Swiat.h"

int main() {

    initscr();
    noecho();
    curs_set(0);
    keypad(stdscr, TRUE);


    Swiat* kox = Swiat::createSwiat();

    if (kox) {
        kox->setGrid(10, 20);

        kox->paintGrid();

        mvprintw(12, 0, "Nacisnij dowolny klawisz aby wyjsc...");
        getch();

        delete kox;
    }

    endwin();
    return 0;
}