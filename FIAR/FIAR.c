// Main Program
#pragma once
#include "board.h"
#include "menu.h"

int main() {
    while (1) {
        int index, ret = 0;
        index = displayMainMenu();
        switch (index) {
            case 1: break;
            case 2: break;
            case 3: break;
            case 4: break;
            case 5: ret = displayTutorial(); break;
            case 6: ret = displayDeveloperInfo(); break;
            case 7: return 0;
        }
        if (ret == -1) { printf("An error occured in program %d", index); }
    }
}