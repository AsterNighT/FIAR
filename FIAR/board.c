#pragma once
#include "board.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// Class for game board

struct Board* newBoard() {
    struct Board* board = malloc(sizeof(struct Board));
    memset(board->board, 0, sizeof(board->board));
    board->currentPlayer = 1;
    board->gameStatus    = 1;
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
    board->gameStatus    = checkStatusBoard(board);
    return board->gameStatus;
}

struct CharPair encodeMove(struct Move move) {
    struct CharPair ret;
    int             value = (move.cordx * 16 + move.cordy) + (move.player - 1) * 300;
    ret.fst               = 'a' + value / 26;
    ret.snd               = 'a' + value % 26;
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
int saveReplayBoard(struct Board* board) {
    char code[512]= {};
    for (int index = 0; index < board->movesCount; index++) {
        struct CharPair encodedMove = encodeMove(board->moves[index]);
        code[index * 2]              = encodedMove.fst;
        code[index * 2 + 1]          = encodedMove.snd;
    }
    printf("%s\n",code);
    return 0;
}

int playReplayBoard(struct Board* board, char* replayData) {
    clearBoard(board);
    int length = strlen(replayData);
    for (int index = 0; index < length; index += 2) {
        struct CharPair code     = {replayData[index], replayData[index + 1]};
        struct Move     moveTemp = decodeMove(code);
        int             ret      = placePieceBoard(board, moveTemp.cordx, moveTemp.cordy);
        if (ret != 1 && ret != 2) return 1;
        displayBoard(board);
    }
    return 0;
}
int startGameBoard(struct Board* board, int type) {
    while (1) {
        displayBoard(board);
        int param1, param2;
        scanf_s("%d", &param1);
        if (param1 > 16) {
            switch (param1) {
                case 17: saveBoard(board); break;
                case 18:
                    char* data;
                    scanf("%s", data);
                    loadBoard(board, data);
                    break;
                case 19: saveReplayBoard(board); break;
                case 20: return 0;
            }
        } else {
            if (board->gameStatus == 1 && board->gameStatus == 2) {
                scanf_s("%d", param2);
                int status = placePieceBoard(board, param1, param2);
                if (status == 0) printf("Invalid Move.\n");
                if (status < 0) printf("Player %d wins!\n", status - 1);
                if (status == 3) printf("It's a draw.");
                if (status == 1 || status == 2) printf("Next move: Player %d\n", status);
            } else {
                printf("The Game has ended.\n");
            }
        }
        printf("Awaiting your command: ...\n");
    }
}
