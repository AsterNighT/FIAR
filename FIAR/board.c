#pragma once
#include "board.h"
#include <stdlib.h>
#include <string.h>
// Class for game board

struct Board* newBoard() {
    struct Board* board = malloc(sizeof(struct Board));
    memset(board->board, 0, sizeof(board->board));
    board->currentPlayer = 1;
    board->gameStatus    = 0;
    board->movesCount    = 0;
    return board;
}

int placePieceBoard(struct Board* board, int cordx, int cordy) {
    if (board->board[cordx][cordy] != 0) return 0;
    board->board[cordx][cordy]             = board->currentPlayer;
    board->moves[board->movesCount].cordx  = cordx;
    board->moves[board->movesCount].cordy  = cordy;
    board->moves[board->movesCount].player = board->currentPlayer;
    board->movesCount++;
    board->currentPlayer = 1 + board->currentPlayer & 1;
    return checkStatusBoard(board);
}

struct CharPair encodeMove(struct Move move) {
    struct CharPair ret;
    int value = (move.cordx * 16 + move.cordy) + (move.player - 1) * 300;
    ret.fst   = 'a' + value / 26;
    ret.snd   = 'a' + value % 26;
    return ret;
}

struct Move decodeMove(struct CharPair code) {
    struct Move ret;
    int         value = (code.fst - 'a') * 26 + (code.snd - 'a');
    ret.player        = value / 300 + 1;
    ret.cordx         = (value % 300) / 16;
    ret.cordy         = (value % 300) % 16;
    return ret;
}

// Remember to free the memory afterwards!!!!!!!!!
char* saveReplayBoard(struct Board* board) {
    char* ret = malloc(512 * sizeof(char));
    for (int index = 0; index < board->movesCount; index++) {
        struct CharPair encodedMove = encodeMove(board->moves[index]);
        ret[index * 2]              = encodedMove.fst;
        ret[index * 2 + 1]          = encodedMove.snd;
    }
    return ret;
}

int playReplayBoard(struct Board* board, char* replayData) {
    clearBoard(board);
    int length = strlen(replayData);
    for (int index = 0; index < length; index += 2) {
        struct CharPair code     = {replayData[index], replayData[index + 1]};
        struct Move     moveTemp = decodeMove(code);
        int ret = placePieceBoard(board, moveTemp.cordx, moveTemp.cordy);
        if (ret != 1 && ret != 2) return 1;
    }
    return 0;
}