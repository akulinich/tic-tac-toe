#ifndef GAME_KERNEL_H
#define GAME_KERNEL_H

#include <vector>

#include "structurs.h"
#include "playing_field.h"

using std::vector;





/*
describe process of one game

methodes playerOneDecision ans playerTwoDecision aplly om line
the first turn make player who have side == tick

if game is over then turns don't allows until start don't use again.
*/
class GameKernel {
public:
    explicit GameKernel(int size_of_field);
    
    void start(Side player_one_side, Side player_two_side);

    bool playerDecision(Position pos, Player player);

    GameState state() const;
    
    bool possiblyDecision(Position pos);
    int sizeOfField();
    Side getPlayerSide(Player player);

    void resetGame();


    void print() const;
    int size() const;

    Cell operator()(int x_cor, int y_cor);

private:
    bool winPosition(const Position& position) const;
    void gameOver();
    

    PlayingField field;
    GameState game_state;
    Side player_one_side_;
    Side player_two_side_;

};












#endif