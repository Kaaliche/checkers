typedef struct cell {
    int line;
    int col;
} cell;

typedef struct move {
    cell init;
    cell fin;
} move;

typedef struct element *listCells;

struct element {
    cell c;
    listCells next;
};

typedef struct player {
    char* name;
    int type;
    int color;
} player;

typedef struct boardgame {
    int board[10][10];
    int nb_black;
    int nb_white;
} boardgame;

void initBoard(struct boardgame*);
void printLine(int, struct boardgame*);
void printBoard(struct boardgame*);
void printHelp();
void movePawn(int, struct move, int, struct boardgame*);
int testMove(int, struct move, struct boardgame*);
int testCell(struct cell);
int readMove(struct move*, struct boardgame*);
struct boardgame* copy(struct boardgame*);
int checkTakenPawn(int, int, int, struct boardgame*, cell[]);
int maxTakenPawns(struct cell, int, struct boardgame*, listCells*, int*);
void printMove(listCells*, int, int, struct boardgame*);
int playerTurn(struct boardgame*, int*, int, listCells*, int);
int selectPawn(int, boardgame*);
void makeMove(listCells, int, struct boardgame*);
void promotePawn(struct boardgame*, int);