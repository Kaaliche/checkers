#include <stdlib.h>
#include <stdio.h>
#include "../headers/boardgame.h"

# define EMPTY 0
# define BLACK 1
# define WHITE 2
# define BLACK_QUEEN 3
# define WHITE_QUEEN 4

void initBoard(boardgame* board){
	board->nb_black = 20;
	board->nb_white = 20;
	int i = 0;
	int j = 0;
	
	for(i = 0; i < 10; i++){
		for(j = 0; j < 10; j++) {
			board->board[i][j] = EMPTY;
		}
	}

	for(i = 0; i < 4; i++){
		if(i % 2 == 0) {
			j = 1;
		} else {
			j = 0;
		}
		for(j; j < 10; j += 2){
			board->board[i][j] = BLACK;
		}
	}

	for(i = 6; i < 10; i++){
		if(i % 2 == 0){
			j = 1;
		} else {
			j = 0;
		}
		for(j; j < 10; j += 2) {
			board->board[i][j] = WHITE;
		} 
	}
}

void printLine(int i, boardgame* board){
	int j = 0;
	printf(" %2d ", i+1);

	for(j = 0; j < 10; j++) {
		switch(board->board[i][j]) {
			case BLACK:
				printf("| B ");
				break;
			case WHITE:
				printf("| W ");
				break;
			case BLACK_QUEEN:
				printf("| [B] ");
				break;
			case WHITE_QUEEN:
				printf("| [W] ");
				break;
			default:
				printf("|  ");
				break;
		}
	}
	printf(" %2d\n", i+1);
	printf(" |-------------------------------------------|\n");
}

void printBoard(boardgame* board){
	int i = 0;
	printf("  A   B   C   D   E   F   G   H   I   J  \n");
	printf(" |------------------------------------------|\n");
	for(i = 0; i < 10; i++){
		printLine(i, board);
	}
	printf("  A   B   C   D   E   F   G   H   I   J  \n");
}

void movePawn(int color, move move, int taken, boardgame* board) {
    board->board[move.init.line][move.init.col] = EMPTY;
    board->board[move.fin.line][move.fin.col] = color;

    if(taken == 1) {
        if(color == WHITE) {
            board->nb_black--;
        } else {
            board->nb_white--;
        }
    }

    board->board[(move.fin.line + move.init.line) / 2][(move.fin.col + move.init.col) / 2] = EMPTY;
}

int testMove(int color, move move, boardgame* board) {
    if(board->board[move.init.line][move.init.col] != color) {
        return -1;
    }

    if(board->board[move.fin.line][move.fin.col != EMPTY]) {
        return -1;
    }

    if(move.fin.line != (move.init.line - color)) {
        return -1;
    }

    if(move.fin.col != (move.init.col + 1) && move.fin.col != (move.init.col -1)){
        return -1;
    }

    return 0;
}
/*
int maxTakenPawns(cell c, int color, boardgame* board, listCells* maxRafle, int* a){
    int taken = 0;
    int maxTaken = 0;
    int maxFTaken = 0;
    int np = 0;
    int nb = 0;
    int i, j, k = 0;
    cell n_cell[4];
    move move;
    boardgame boardTwo;
    listCells* b;
}
 */

