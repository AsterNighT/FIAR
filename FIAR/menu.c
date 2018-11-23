#include "menu.h"
#include <stdio.h>
int displayDeveloperInfo() {
    clear();
    printf("\
    -------------------------------------------------------------------\n\
    FIAR, a simple demo of the game of five-in-a-row.\n\
    Developed with standard C, maybe our first and last project written in standard C.\n\
    Project leader: \033[47;35mAsterNighT\033[0m\n\
    Collaborator: \n\
    Released under GNU GPL 2.0, feel free to share or edit it. \n\
    Press enter to return to menu.\n\
    -------------------------------------------------------------------\n\
    ");
    pause();
    return 0;
}
int displayTutorial() {
    clear();
    printf("\
    -------------------------------------------------------------------\n\
    Name a coordinate to determine where to place your pieces.\n\
    For now, replay and game save&load are supported.\n\
    Both replay the save info are represented by strings encoded by ASCII, \n\
    just grab your code and save it to a text file or somewhere.\n\
    Press enter to return to menu.\n\
    -------------------------------------------------------------------\n\
    ");
    pause();
    return 0;
}
int displayMainMenu() {
    clear();
    printf("\
    -------------------------------------------------------------------\n\
    \033[47;30mWelcome to FIAR\033[0m\n\
    Type in an index and press enter:\n\
    \033[40;33m1: Single player\033[0m\n\
    \033[40;33m2: Local multi-player\033[0m\n\
    \033[40;33m3: Load game\033[0m\n\
    \033[40;33m4: Load replay\033[0m\n\
    \033[40;33m5: Tutorial\033[0m\n\
    \033[40;33m6: Developer info\033[0m\n\
    \033[40;33m7: Exit\033[0m\n\
    -------------------------------------------------------------------\n\
    ");
    int index = -1;
    while (index < 1 || index > 7) {
        printf("Please input index: \n");
        scanf_s("%d", &index);
    }
    return index;
}
int displaySettingMenu() {}

int displayExitInfo() {
    printf("Thank you for using. Program shutting down...\n");
    return 0;
}