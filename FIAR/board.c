#pragma once
#include "board.h"
#include <stdlib.h>
// Class for game board

struct Board* newBoard() {
    struct Board* board = malloc(sizeof(struct Board));
    memset(board->board, 0, sizeof(board->board));
    board->currentPlayer = 1;
    board->gameStatus    = 0;
    board->movesCount    = 0;
    return board;
}