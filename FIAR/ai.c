#include <stdlib.h>
#include <stdio.h>
#include "ai.h"
#include "board.h"
struct Move aiConsiderBoard(struct Board* board, int type) {
    int         player = board->currentPlayer;
    int         score[15][15];
    int         maxScore = 0;
    struct Move ret;
    memset(score, 0, sizeof(score));
    for (int x = 0; x < 15; x++) {
        for (int y = 0; y < 15; y++) {
            if (board->board[x][y] != 0)
                score[15][15] = -INF;
            else {
                int pointScore = 0;
                for (int dx = -1; dx <= 1; dx++) {
                    for (int dy = -1; dy <= 1; dy++) {
                        if (dx == 0 && dy == 0) continue;
                        int emptyPoints     = 0;
                        int opponentsPieces = 0;
                        int ownPieces       = 0;
                        for (int dis = 1; dis <= 4; dis++) {
                            if (x + dx * dis < 0 || x + dx * dis > 14 || y + dx * dis < 0 || y + dx * dis > 14) break;
                            int px = x + dx * dis;
                            int py = y + dx * dis;
                            if (board->board[px][py] == 0) {
                                emptyPoints++;
                                break;
                            }
                            if (board->board[px][py] == player) {
                                ownPieces++;
                                break;
                            }
                        }
                        for (int dis = -1; dis >= -4; dis--) {
                            if (x + dx * dis < 0 || x + dx * dis > 14 || y + dx * dis < 0 || y + dx * dis > 14) break;
                            int px = x + dx * dis;
                            int py = y + dx * dis;
                            if (board->board[px][py] == 0) {
                                emptyPoints++;
                                break;
                            }
                            if (board->board[px][py] == player) {
                                ownPieces++;
                                break;
                            }
                        }
                        switch (ownPieces) {
                            case 0: pointScore += 1; break;
                            case 1: pointScore += 2; break;
                            case 2:
                                if (emptyPoints == 0) pointScore += 2;
                                if (emptyPoints == 1) pointScore += 5;
                                if (emptyPoints == 2) pointScore += 30;
                                break;
                            case 3:
                                if (emptyPoints == 0) pointScore += 2;
                                if (emptyPoints == 1) pointScore += 50;
                                if (emptyPoints == 2) pointScore += 500;
                                break;
                            default: pointScore += 10000000;
                        }
                        emptyPoints = 0;
                        for (int dis = 1; dis <= 4; dis++) {
                            if (x + dx * dis < 0 || x + dx * dis > 14 || y + dx * dis < 0 || y + dx * dis > 14) break;
                            int px = x + dx * dis;
                            int py = y + dx * dis;
                            if (board->board[px][py] == 0) {
                                emptyPoints++;
                                break;
                            }
                            if (board->board[px][py] != player) {
                                opponentsPieces++;
                                break;
                            }
                        }
                        for (int dis = -1; dis >= -4; dis--) {
                            if (x + dx * dis < 0 || x + dx * dis > 14 || y + dx * dis < 0 || y + dx * dis > 14) break;
                            int px = x + dx * dis;
                            int py = y + dx * dis;
                            if (board->board[px][py] == 0) {
                                emptyPoints++;
                                break;
                            }
                            if (board->board[px][py] != player) {
                                opponentsPieces++;
                                break;
                            }
                        }
                        switch (opponentsPieces) {
                            case 0: pointScore += 1; break;
                            case 1: pointScore += 2; break;
                            case 2:
                                if (emptyPoints == 0) pointScore += 1;
                                if (emptyPoints == 1) pointScore += 5;
                                if (emptyPoints == 2) pointScore += 10;
                                break;
                            case 3:
                                if (emptyPoints == 0) pointScore += 2;
                                if (emptyPoints == 1) pointScore += 20;
                                if (emptyPoints == 2) pointScore += 100;
                                break;
                            default: pointScore += 100000;
                        }
                    }
                }
                score[x][y] = pointScore;
                if (pointScore > maxScore || (pointScore == maxScore && (rand() & 1))) {
                    maxScore   = pointScore;
                    ret.cordx  = x;
                    ret.cordy  = y;
                    ret.player = player;
                }
            }
        }
    }
    if (type == 1) { // Require the complete score matrix
        for (int x = 0; x < 14; x++) {
            for (int y = 0; y < 14; y++) {
                printf("%8d",score[x][y]);
            }
            putchar('\n');
        }
    }
    return ret;
}