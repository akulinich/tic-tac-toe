#ifndef STRUCTURS
#define STRUCTURS


enum Cell {
    TICK = 1,
    TOE = 2,
    EMPTY = 3
};

enum GameState {
    NOT_STARTED,
    PLAYER_ONE_TURN,
    PLAYER_TWO_TURN,
    PLAYER_ONE_WIN,
    PLAYER_TWO_WIN,
    DRAW
};


enum Side {
    TICK_SIDE,
    TOE_SIDE
};

enum Player {
    PLAYER_ONE,
    PLAYER_TWO
};

struct Position {
    int x_cor;
    int y_cor;
    
    Position() {};
    Position(int x_cor, int y_cor) : x_cor(x_cor), y_cor(y_cor) {}
};

/* game must return winers */
struct Turn {
    Position pos;
    Side side;
    Player player;

    Turn(Position pos, Side side, Player player) 
        : pos(pos), side(side), player(player) {}
};


#endif