# FIAR development document

> 由于大家都是萌新，这个doc估计会更得很慢。惨兮兮。

## Board Part
---
The `Board` should be a struct. During the whole lifetime of the program, only one Board should present at a time.

Following methods should be supported.

> `int clearBoard(Board* board)`  //YU

Clear a board, return 0 for success.

> `int displayBoard(Board* board)` //Xuan

Display the board in the console, return 0 for success.

> `int placePieceBoard(Board* board,int cordx,int cordy)` //Aster

Place a piece on the board at (cordx,cordy). Color of the piece should be judged automatically. Return the next player's id (1 or 2) if the game goes on, the negation of id if one of the player wins, 0 for an invalid move, 3 for a draw.

> `int undoBoard(Board* board)`  //YU

Undo last move. Return 0 for success, 1 if the board is empty. 

> `int checkStatusBoard(Board* board)` //Xuan

Return the next player's id (1 or 2) if the game still goes on, the negation of id if one of the player wins, 3 for a draw.

> `char* saveBoard(Board* board)`  //Zhu

Return a string recording the current status of the board.

> `int loadBoard(Board* board, char* saveData)` //Zhu

Load from a given data string. Return 0 for success, 1 for invalid saveData

> `char* saveReplayBoard(Board* board)` //Aster

Return a string recording the replay of the game.

> `int playReplayBoard(Board* board, char* replayData) // To be polished` //Aster

Play replay from a given data string. Return 0 for success, 1 for invalid replayData.

## Menu part 
---
This part will be finished later, as we hasn't got our wheels yet.

But pot will be carried by @AsterNighT