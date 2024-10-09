#include "lib.c"
#include <ncurses.h>
#include "menus/register/register.c"

void itemmenu(){
    printw("item has been called");
}

void inventorymenu(){
    printw("inventory has been called");
}

void spoiloutmenu(){
    printw("spoilout has been called");
}

void testingmenu(){
    printw("testing has been called");
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
        {"test", testingmenu},
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
