#ifndef PLAYING_FIELD_H
#define PLAYING_FIELD_H

#include <vector>

using std::vector;

enum Player {
    TICK,
    TOE,
    EMPTY
};

enum GameStatus {
    TICK_WIN,
    TOE_WIN,
    DRAW,
    IN_PROGRESS
};

struct Position {
    int x_cor;
    int y_cor;
    
    Position(int x_cor, int y_cor);
};

class PlayingField {
    vector<vector<Player>> field;
    Player turn;

    bool check_positon_to_win(const Position& position);
    
public:
    explicit PlayingField(int size_of_field);
    void do_turn(const Position& position, Player player);
    GameStatus end_game_check();
    
    void reset_game();
    Player get_turn();

    void print_game();

};


#endif