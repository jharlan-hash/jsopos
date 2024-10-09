#include "../../lib.c"
#include "registerterm.c"
#include "voidpurchase.c"
#include <ncurses.h>

void registermenu(){
    menu menulist[] = {
        {"actual register part", registertermmenu},
        {"void sales", voidpurchasemenu},
        {NULL, NULL},
    };

    create_menu(menulist);
}
