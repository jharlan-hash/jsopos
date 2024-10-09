#include <ctype.h>
#include <stdlib.h>
#include <ncurses.h>

#pragma once
typedef struct {
    char *name;
    void (*func)(char **);
} menu;


/* takes in an array of menu items and creates a curses menu for each entry in the array
 * returns 0 on success and 1 on error*/
int create_menu(menu* list){
    int i, row, col;
    char str[80];

    getmaxyx(stdscr, row, col);

    for(i = 0; list[i].name != NULL; i++){
        mvprintw(i * 2, 5, "%d. %s", i + 1, list[i].name);
    }

    mvgetstr(row - 1, 0, str);
    refresh();
    clear();

    if (!isdigit(atoi(str))){
        if (atoi(str) <= i){
            list[atoi(str)-1].func(NULL);
        mvprintw(1,0, "everything is good, size of list was %d", i);
        } else {
            mvprintw(1,0,"str is a digit but is larger than the size of the list");
            mvgetstr(row - 1, 0, str);
            refresh();
        }
    } else {
        printw("str is not a digit");
        mvgetstr(row - 1, 0, str);
        refresh();
        clear();
    }
    return 0;
}
