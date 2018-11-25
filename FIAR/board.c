#pragma once
#include "board.h"
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ai.h"
// Class for game board

struct Board* newBoard() {
    struct Board* board = malloc(sizeof(struct Board));
    memset(board->board, 0, sizeof(board->board));
    board->currentPlayer = 1;
    board->gameStatus    = 1;
    board->movesCount    = 0;
    board->currentCordY  = 0;
    board->currentCordX  = 0;
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
    char code[512];
    memset(code, 0, sizeof(code));
    for (int index = 0; index < board->movesCount; index++) {
        struct CharPair encodedMove = encodeMove(board->moves[index]);
        code[index * 2]             = encodedMove.fst;
        code[index * 2 + 1]         = encodedMove.snd;
    }
    printf("%s\n", code);
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
    displayBoard(board);
    char data[512];
    int  aiPlayer = 0;
    if (type == 0) {
        printf("Are you going first?(y/n)");
        int op = 0;
        while (op != 'y' && op != 'n') op = _getch();
        aiPlayer = 1 + (op == 'y');
    }
    while (1) {
        if (board->currentPlayer == aiPlayer && (board->gameStatus == 1 || board->gameStatus == 2)) {
            struct Move move = aiConsiderBoard(board, 0);
            placePieceBoard(board, move.cordx, move.cordy);
        } else {
            int op = _getch();
            switch (op) {
                case 13: // enter
                    if (board->gameStatus == 1 || board->gameStatus == 2) {
                        int status = placePieceBoard(board, board->currentCordX, board->currentCordY);
                        displayBoard(board);
                        if (status == 0) printf("Invalid Move.\n");
                        if (status < 0) printf("Player %d wins!\n", status - 1);
                        if (status == 3) printf("It's a draw.");
                        if (status == 1 || status == 2) printf("Next move: Player %d\n", status);
                    } else {
                        displayBoard(board);
                        printf("The Game has ended.\n");
                    }
                    break;
                case 224: // arrows id
                    op = _getch();
                    switch (op) {
                        case 75:
                            board->currentCordX = board->currentCordX > 0 ? board->currentCordX - 1 : 0; // left
                            break;
                        case 72: // up
                            board->currentCordY = board->currentCordY > 0 ? board->currentCordY - 1 : 0;
                            break;
                        case 80: // down
                            board->currentCordY = board->currentCordY < 14 ? board->currentCordY + 1 : 14;
                            break;
                        case 77: // right
                            board->currentCordX = board->currentCordX < 14 ? board->currentCordX + 1 : 14;
                            break;
                    }
                    displayBoard(board);
                    break;
                case 58: // :
                    printf("Waiting for the second key...");
                    op = _getch();
                    switch (op) {
                        case 113: saveBoard(board); break; // q
                        case 119:                          // w
                            scanf_s("%s", data, 512);
                            loadBoard(board, data);
                            break;
                        case 97: saveReplayBoard(board); break; // a
                        case 115:                               // s
                            scanf_s("%s", data, 512);
                            playReplayBoard(board, data);
                            break;
                        case 114: aiConsiderBoard(board, 1); break;
                        default: displayBoard(board);
                    }
                    break;
            }
        }
    }
}

int clearBoard(struct Board* board) {}
int displayBoard(struct Board* board) {}
int undoBoard(struct Board* board) {}
int checkStatusBoard(struct Board* board) {}
int saveBoard(struct Board* board) {}
int loadBoard(struct Board* board, char* saveData) {}