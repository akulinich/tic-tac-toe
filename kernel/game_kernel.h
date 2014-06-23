#ifndef PLAYING_FIELD_H
#define PLAYING_FIELD_H

#include <vector>

using std::vector;

enum Cell {
    TICK = 1,
    TOE = 2,
    EMPTY = 3
};

enum GameStatus {
    TICK_TURN,
    TOE_TURN,
    TICK_WIN,
    TOE_WIN,
    DRAW
};

struct Position {
    int x_cor;
    int y_cor;
    
    Position() {};
    Position(int x_cor, int y_cor);
};

class GameKernel {
public:
    explicit GameKernel(int size_of_field);
    void makeTurn(const Position& position);
    GameStatus status() const;
    void reset();
    int size() const; // size of field
    bool emptyCell(const Position& position) const;

    void print() const; // for console

private:
    vector<vector<Cell>> field;
    GameStatus status_;

    bool isWinPosition(const Position& position) const;
    void checkEndGame();
};


#endif