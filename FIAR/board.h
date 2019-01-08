#pragma once
// Class for game board

struct Move {
    int cordx, cordy;
    int player;
};
struct Board {
    int         board[15][15];
    struct Move moves[255];
    int         movesCount;
    int         currentPlayer;
    int         gameStatus;
    int         currentCordX;
    int         currentCordY;
};
struct CharPair {
    char fst, snd;
};
struct Board*   newBoard();
int             startGameBoard(struct Board* board, int type);
int             clearBoard(struct Board* board);
int             displayBoard(struct Board* board, int type);
int             placePieceBoard(struct Board* board, int cordx, int cordy);
int             undoBoard(struct Board* board);
int             checkStatusBoard(struct Board* board);
int             saveBoard(struct Board* board);
int             loadBoard(struct Board* board, char* saveData);
int             saveReplayBoard(struct Board* board);
int             playReplayBoard(struct Board* board, char* replayData);
struct CharPair encodeMove(struct Move move);
struct Move     decodeMove(struct CharPair code);