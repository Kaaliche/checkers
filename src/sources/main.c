#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../headers/boardgame.h"

int main(int argc, char** argv){
	struct boardgame* board;
	initBoard(board);
	printBoard(board->board[10][10]);
}
