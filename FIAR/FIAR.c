// Main Program
#pragma once
#include <stdio.h>
#include "board.h"
#include "menu.h"
int main() {
    setvbuf(stdout, NULL, _IOFBF, 4096);
    struct Board* gameBoard = newBoard();
    char          data[512];
    while (1) {
        clearBoard(gameBoard);
        int index, ret = 0;
        index = displayMainMenu();
        switch (index) {
            case 1: ret = startGameBoard(gameBoard, 0); break;
            case 2: ret = startGameBoard(gameBoard, 1); break;
            case 3:
                scanf_s("%s", data, 512);
                loadBoard(gameBoard, data);
                startGameBoard(gameBoard, 0);
                break;
            case 4:
                scanf_s("%s", data, 512);
                playReplayBoard(gameBoard, data);
                break;
            case 5: ret = displayTutorial(); break;
            case 6: ret = displayDeveloperInfo(); break;
            case 7: displayExitInfo(); return 0;
        }
        if (ret == -1) { printf("An error occurred in program %d", index); }
    }
}
