// Main Program
#pragma once
#include "board.h"
#include "menu.h"

int main() {
    struct Board* gameBoard = newBoard();
    while (1) {
        int index, ret = 0;
        index = displayMainMenu();
        switch (index) {
            case 1: ret = startGameBoard(gameBoard, 0); break;
            case 2: ret = startGameBoard(gameBoard, 1); break;
            case 3:
                char* data;
                scanf("%s", data);
                loadGameBoard(gameBoard, data);
                startGameBoard(gameBoard, 0);
                break;
            case 4:
                char* data;
                scanf("%s", data);
                playReplayBoard(gameBoard, data);
                break;
            case 5: ret = displayTutorial(); break;
            case 6: ret = displayDeveloperInfo(); break;
            case 7: displayExitInfo(); return 0;
        }
        if (ret == -1) { printf("An error occurred in program %d", index); }
    }
}