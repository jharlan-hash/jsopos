#include <stdlib.h>
#include <ncurses.h>

typedef struct {
    char *name;
    void (*func)(char **);
} menu;

/* takes in an array of menu items and creates a curses menu for each entry in the array
 * returns 0 on success and 1 on error*/
int create_menu(menu* list){
    int i, row, col;
    char str[80];



    for(i = 0; list[i].name != NULL; i++){
        mvprintw(i * 2, 5, "%d. %s", i + 1, list[i].name);
    }

    getmaxyx(stdscr, row, col);

    mvgetstr(row - 1, 0, str);
    refresh();

    clear();

    list[atoi(str)-1].func(NULL);
    return 0;
}
