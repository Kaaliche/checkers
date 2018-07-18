#include <stdlib.h>
#include <stdio.h>
#include <memory.h>
#include "../headers/boardgame.h"

# define EMPTY 0
# define BLACK 1
# define WHITE 3
# define BLACK_QUEEN 2
# define WHITE_QUEEN 6

/*
 *
 * Init the board with global values
 *
 */
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

/*
 *
 * Print each line
 *
 */
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

/*
 *
 * Print the whole board on call
 *
 */
void printBoard(boardgame* board){
	int i = 0;
	printf("  A   B   C   D   E   F   G   H   I   J  \n");
	printf(" |------------------------------------------|\n");
	for(i = 0; i < 10; i++){
		printLine(i, board);
	}
	printf("  A   B   C   D   E   F   G   H   I   J  \n");
}

/*
 *
 * Print the command lists
 *
 */
void printHelp() {

	printf("Commands list :\n");
	printf("Board : Print board\n");
	printf("Quit : Quit the game\n");
	printf("A move is made like this : [col][line] [col][line]\n");
	printf("\n");
}

/*
 *
 * Function which permits to move a pawn
 *
 */
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

/*
 *
 * Function to test is a move is correct
 *
 */
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
 *
 * Function to test if the given cell exists
 *
 */
int testCell(cell c) {
	if(c.line<1 || c.line > 10 || c.col > 10 || c.col < 0) {
		return 1;
	}
	return 0;
}

/*
 *
 * Function which reads a move
 * -1 for a wrong move
 * 0 for a good move
 * Checks if a command has been sent
 *
 */
int readMove(move* m,boardgame* board) {

	char start[10], end[5];

	printf("Enter column then line :\n");
	fflush(stdin);
	scanf("%s",start);

	if(strcmp(start,"help") == 0)
		printHelp();
	if(strcmp(start,"board") == 0)
		printBoard(board);

	scanf("%s", end);

	if('a' > start[0] || start[0] > 'j' || 'a' > end[0] || end[0] > 'j')
		return -1;

	if('1' > start[1] || start[1] > '10' || '1' > end[1] || end[1] > '10')
		return -1;

	m->init.col = start[0] - 'a';
	m->init.line = start[1] - '1';

	m->fin.col = end[0] - 'a';
	m->fin.line = end[1] - '1';

	if(start[1] == '1') {
		if(start[2] == '0')
			m->init.line = 9;
	}

	if(end[1] == '1') {
		if(end[2] == '0')
			m->fin.line = 9;
	}
	return 0;
}

/*
 *
 * Function which manages the turn of a player
 * -1 if a player ragequits
 * 1 if a move is made
 *
 */
int selectPawn(int color, boardgame* board) {

	int i = 0;
	int queen = 0;
	int taken = 0;

	move m;

	do {
		queen = 0;
		switch(readMove(&m, board)) {
			case -1:
				printf("Wrong move !\n");
				break;
			case 0:
				if(board->board[m.init.line][m.init.col] == color) {
					if((taken = testMove(color, m, board)) == -1) {
						printf("Can't move pawn from [%c,%d] to [%c,%d] !\n", m.init.col + 'a', m.init.line + 1, m.fin.col + 'a', m.fin.line + 1);
					}
					else {
						i = 1;
					}
				}
				if(board->board[m.init.line][m.init.col] == color * 2) {
					if((taken = testMoveQueen(board, color, m)) == -1)
						printf("Can't move the queen !\n");
					else {
						i = 1;
						queen=1;
					}
				}
				break;
			case 3:
				return -1;
			default:
				break;
		}

	} while(i == 0);

	if(queen == 1) {
		moveQueen(board, color, m, 0, m.init);
	} else {
		movePawn(color, m, taken, board);
	}

	return 1;
}

/*
 *
 * Function which executes a move
 *
 */
void makeMove(listCells clone, int color, boardgame* board) {

	listCells rafle;
	move m;
	cell taken;
	cell tab[10];
	int i, j ,ind = 0;
	rafle = clone;

	while(rafle->next != 0) {
		m.init = rafle->c;
		m.fin = rafle->next->c;
		if(board->board[m.init.line][m.fin.col] == color)
			movePawn(color, m, 1, board);
		else {
			if(m.init.line > m.fin.line) {
				taken.line = m.init.line - 1;
				i = -1;
			}
			else {
				taken.line = m.init.line + 1;
				i = 1;
			}
			if(m.init.col > m.fin.col) {
				taken.col = m.init.col - 1;
				j = -1;
			}
			else {
				taken.col = m.init.col + 1;
				j = 1;
			}

			moveQueen(board, color, m, 1, taken);
		}
		rafle = rafle->next;
	}
	if(board->board[m.fin.line][m.fin.col] == color * 2) {
		ind = 0;
		printBoard(board);
		m.init = m.fin;
		tab[0] = m.init;
		m.fin.line += i;
		m.fin.col += j;

		while(m.fin.line >= 0 && m.fin.line <10 && m.fin.col >= 0 && m.fin.col <10 && board->board[m.fin.line][m.fin.col] == EMPTY) {
			ind++;
			tab[ind] = m.fin;

			m.fin.line+=i;
			m.fin.col+=j;
		}
		do {
			printf("Where do you want the queen to go ?\n");
			for(i=0;i<=ind;i++)
				printf("%d. %c%d ", i+1, tab[i].col + 'a', tab[i].line + 1);
			printf("\n");
			scanf("%d",&j);
		} while(j<1 || j>ind+1);

		m.fin = tab[j-1];
		moveQueen(board, color, m, 0, m.init);
	}
}

/*
 *
 * Print the rafle
 *
 */
void printRafle(listCells rafle) {
	listCells clone = rafle;

	while(clone != 0) {
		printf("%c,%d ->", clone->c.col + 'a', clone->c.line + 1);
		clone = clone->next;
	}
	printf("\n");
}

/*
 *
 * Print the possible moves
 *
 */
void printMove(listCells* rafle, int a, int color, boardgame* board) {
	int b = 0, i = 0;

	do {
		fflush(stdin);
		printf("Multiple moves are possible %d:\n", a);
		for(i = 0; i < a; i++) {
			printf("%d : ",i+1);
			printRafle(rafle[i]);

		}
		if(scanf("%d", &i) == 1 && i > 0 && i <= a) {
			makeMove(rafle[i-1], color, board);
			b = 1;
		}
	}while(b == 0);
}

/*
 *
 * Function to manage the turn of a player
 *
 */
int playerTurn(boardgame* board, int* color, int n, listCells* rafle, int move) {
	if(move > 0) {
		printMove(rafle, n, *color, board);
	} else {
		if(selectPawn(*color, board) == -1)
			return -1;
	}
	return 0;
}
#endif


/*
 *
 * Function to copy the actual board for testing purpose
 * in other functions
 *
 */
struct boardgame* copy(boardgame* board) {
	struct boardgame* board2 = malloc(sizeof(boardgame));
	int i, j = 0;

	board2->nb_white = board->nb_white;
	board2->nb_black = board->nb_black;

	for(i = 0; i < 10; i++){
		for(j = 0; j < 10; j++) {
			board2->board[i][j] = board->board[i][j];
		}
	}

	return board2;
}

/*
 *
 * Function to check if there are pawns that can be taken
 *
 */
int checkTakenPawn(int col, int line, int color, boardgame* board, cell* tab){
    int cnt = 0;
    if(line - 2 >= 0 && col - 2 >= 0 && board->board[line-2][col-2] == EMPTY) {
        if(board->board[line-1][col-1] == -color || board->board[line-1][col-1] == -color*2) {
            (tab + cnt)->line = line - 2;
            (tab + cnt)->col = col - 2;
            cnt++;
        }
    }

    if(line - 2 >= 0 && col + 2 < 10 && board->board[line-2][col+2] == EMPTY) {
        if(board->board[line-1][col+1] == -color || board->board[line-1][col+1] == -color*2) {
            (tab + cnt)->line = line - 2;
            (tab + cnt)->col = col + 2;
            cnt++;
        }
    }

    if(line + 2 < 10 && col - 2 >= 0 && board->board[line+2][col-2] == EMPTY ) {
        if(board->board[line+1][col-1] == -color || board->board[line+1][col-1] == -color*2) {
            (tab + cnt)->line = line + 2;
            (tab + cnt)->col = col - 2;
            cnt++;
        }
    }

    if(line + 2 < 10 && col + 2 < 10 && board->board[line+2][col+2] == EMPTY) {
        if(board->board[line+1][col+1] == -color || board->board[line+1][col+1] == -color*2) {
            (tab + cnt)->line = line + 2;
            (tab + cnt)->col = col + 2;
            cnt++;
        }
    }
    return cnt;
}

/*
 *
 * Function to calculate the maximum number of pawns
 * that can be taken in one move (rafle)
 *
 */
int maxTakenPawns(cell c, int color, boardgame* board, listCells* maxRafle, int* a){
    int taken = 0;
    int maxTaken = 0;
    int maxFoundTaken = 0;
    int np = 0;
    int nb = 0;
    int i, j, k = 0;
    cell n_cell[4];
    move move;
    boardgame* boardTwo;
    listCells* b;

    if((nb = checkTakenPawn(c.col, c.line, color, board, n_cell)) != 0){
        boardTwo = copy(board);
        taken++;

        for(i = 0; i < nb; i++) {
            np = 1;
            b = (listCells*) malloc(sizeof(listCells));
            b[0] = (listCells) malloc(sizeof(struct element));
            move.fin = n_cell[i];
            move.init = c;

            movePawn(color, move, 1, boardTwo);

            maxTaken = maxTakenPawns(n_cell[i], color, boardTwo, b, &np);

            if(maxTaken == maxFoundTaken && maxTaken > 0) {
                for(j = 0;j <np; j++) {
                    maxRafle[k] = (listCells) malloc(sizeof(struct element));
                    maxRafle[k]->next = b[j];
                    maxRafle[k]->c = c;
                    k++;
                }
                k--;
                *a = *a + np;
            }
            if(maxTaken == 0 && maxFoundTaken==0) {
                b[0]->c = n_cell[i];
                b[0]->next = 0;
                maxRafle[k] = (listCells) malloc(sizeof(struct element));
                maxRafle[k]->next = b[0];
                maxRafle[k]->c = c;
                k++;
                *a = k;
            }

            if(maxTaken > maxFoundTaken) {
                *a = np;
                maxFoundTaken = maxTaken;
                for(k = 0; k < np; k++) {
                    maxRafle[k] = (listCells) malloc(sizeof(struct element));
                    maxRafle[k]->next = b[k];
                    maxRafle[k]->c = c;
                }

            }
        }

    }
    else {
        for( j = 0; j < k; j++)
            maxRafle[j]->next = 0;
    }
    return taken + maxFoundTaken;
}


/*
 *
 * Function to promote a regular pawn to a Queen
 *
 */
void promotePawn(boardgame* board, int color){
	int i = 0, j = 0;
	if(color == BLACK) {
		i = 9;
		j = 0;
	} else {
		i = 0;
		j = 1;
	}
	for(j ; j < 10; j += 2) {
		if(board->board[i][j] == color)
			board->board[i][j] = 2 * color;
	}
}

/*
 *
 * Function to test is selected pawn is a Queen and its move
 *
 */
int testMoveQueen(boardgame* board, int color, move m){
	int i = m.init.line;
	int j = m.init.col;

	if(board->board[i][j] != color * 2) {
		printf("This pawn is not a Queen !\n");
		return -1;
	}

	while(i != m.fin.line || j != m.fin.col) {
		if(m.fin.line > m.init.line) {
			i++;
		} else {
			i--;
		}
		if(m.fin.col > m.init.col) {
			j++;
		} else {
			j--;
		}
		if(board->board[i][j] != EMPTY) {
			printf("The position you're trying to reach is not empty !");
			return -1;
		}
	}
	return 1;
}

/*
 *
 * Function to execute the movement of the queen
 *
 */
void moveQueen(boardgame* board, int color, move m, int i, cell taken) {
	if(m.init.line == m.fin.line && m.init.col == m.fin.col) {
		return;
	}
	board->board[m.init.line][m.init.col] = EMPTY;
	board->board[m.fin.line][m.fin.col] = 2 * color;

	if(i == 1 && (board->board[taken.line][taken.col]==-color || board->board[taken.line][taken.col] == -color * 2)) {
		board->board[taken.line][taken.col] = EMPTY;

		if(color == WHITE) {
			board->nb_black = board->nb_black - 1;
		} else {
			board->nb_white = board->nb_white - 1;
		}
	}
}