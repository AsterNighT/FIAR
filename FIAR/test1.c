int clearBoard(struct Board* board) {
	board->currentPlayer = 1;
	board->gameStatus = 1;
	board->movesCount = 0;
	board->currentCordY = 0;
	board->currentCordX = 0;
	return board;
}