#include <stdlib.h>
#include <stdio.h>
#include "../headers/boardgame.h"

# define BLACK 0
# define WHITE 1
# define BLACK_QUEEN 2 
# define WHITE_QUEEN 3

typedef struct {
	int line;
	int col;
} cell;

typedef struct {
	cell init;
	cell fin;
} move;

typedef struct {
	char* name;
	int type;
	int color;
} player;

typedef struct {
	int board[10][10];
	int nb_black;
	int nb_white;
} boardgame;


void initBoard(boardgame* board){
	board->nb_black = 20;
	board->nb_white = 20;
	int i = 0;
	int j = 0;
	
	for(i = 0; i < 10; i++){
		for(j = 0; j < 10; j++) {
			board->board[i][j] = 0;
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

void printLine(int i, int board[10][10]){
	int j = 0;
	printf(" %2d ", i+1);

	for(j = 0; j < 10; j++) {
		switch(board[i][j]) {
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
				printf("| ");
				break;
		}
	}
	printf(" %2d\n", i+1);
	printf(" |-------------------------------------------|\n");
}

void printBoard(int board[10][10]){
	int i = 0;
	printf("  A   B   C   D   E   F   G   H   I   J  \n");
	printf(" |----------------------------------------|\n")
	for(i = 0; i < 10; i++){
		printLine(i, board);
	}
	printf("  A   B   C   D   E   F   G   H   I   J  \n");
}





