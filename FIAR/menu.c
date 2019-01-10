#include "menu.h"
#include <conio.h>
#include <ctype.h>
#include <stdio.h>
int displayDeveloperInfo() {
    clear();
    printf("\
    -------------------------------------------------------------------\n\
    FIAR, a simple demo of the game of five-in-a-row.\n\
    Developed with standard C, maybe it'll be our first and last project written in standard C.\n\
    Project leader: \033[47;35mAsterNighT\033[0m\n\
    Collaborator: \033[47;35mEdwin-Yu\033[0m   \033[47;35mJusterizon\033[0m   \033[47;35mzbq0313\033[0m\n\
    Released under GNU GPL 2.0. Do feel free to share or modify it. \n\
    Press any key to return to menu.\n\
    -------------------------------------------------------------------\n\
    ");
    fflush(stdout);
    pause();
    return 0;
}
int displayTutorial() {
    clear();
    printf("\
    -------------------------------------------------------------------\n\
    Use arrow keys to determine where to place your pieces.\n\
    Press enter to confirm.\n\
    For now, replay and game save&load are supported.\n\
    Both replay the save info are represented by strings encoded by ASCII, \n\
    just grab your code and save it to a text file or somewhere.\n\
    Press any key to return to menu.\n\
    -------------------------------------------------------------------\n\
    ");
    fflush(stdout);
    pause();
    return 0;
}
int displayMainMenu() {
    clear();
    printf("\
    -------------------------------------------------------------------\n\
    \033[47;30mWelcome to FIAR\033[0m\n\
    Press an index:\n\
    \033[40;33m1: Single player\033[0m\n\
    \033[40;33m2: Local multi-player\033[0m\n\
    \033[40;33m3: Load game\033[0m\n\
    \033[40;33m4: Load replay\033[0m\n\
    \033[40;33m5: Tutorial\033[0m\n\
    \033[40;33m6: Developer info\033[0m\n\
    \033[40;33m7: Exit\033[0m\n\
    -------------------------------------------------------------------\n\
    ");
    fflush(stdout);
    int c = 0;
    while (!isdigit(c = _getch()));
    return c - '0';
}
int displaySettingMenu() {}

int displayExitInfo() {
    printf("Thank you for using. Program shutting down...\n");
    fflush(stdout);
    return 0;
}
