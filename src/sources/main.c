#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../headers/boardgame.h"

int main(int argc, char** argv){
	struct boardgame* board = malloc(sizeof(boardgame));
	initBoard(board);
	printBoard(board);
	free(board);
	return 0;
}