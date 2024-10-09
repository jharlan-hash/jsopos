#include "lib.c"
#include <ncurses.h>

void registermenu(){
    printw("register has been calle");
}

void itemmenu(){
    printw("item has been calle");
}

void inventorymenu(){
    printw("inventory has been calle");
}

void spoiloutmenu(){
    printw("spoilout has been calle");
}

int init_curses(){
    raw();
    noecho();
    keypad(stdscr, TRUE);
    initscr();
    return 0;
}

int end_curses(){
    endwin();
    return 0;
}

int home_screen(){
    menu menulist[] = { // create a menulist with a name and a function pointer
        {"register", registermenu},
        {"items", itemmenu},
        {"inventory", inventorymenu},
        {"spoilout", spoiloutmenu},
        {NULL, NULL}
    };

    create_menu(menulist);

    return 0;
}

int main() {
    if (init_curses()){
        fprintf(stderr, "error initializing curses");
    }

    if (home_screen()){
        fprintf(stderr, "error showing the home menu");
    }

    getch();

    if (end_curses()){
        fprintf(stderr, "Error ending curses");
    }
    return 0;
}
