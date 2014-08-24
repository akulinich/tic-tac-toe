#ifndef CPU_PLAYER_H
#define CPU_PLAYER_H


#include "playing_field.h"
#include "game_kernel.h"
#include "structurs.h"

#include <vector>
#include <array>

using std::vector;
using std::array;

// enum class ? Read about it!
// may be i must recombine it in order?
enum TypeOfProfile {
    FiveInLine = 1,

    FourInLineOpen = 2,
    FourInLineClosed = 3,
    FourInLineOneHole = 4,

    ThreeInLineOpen = 5,
    ThreeInLineClosed = 6,
    ThreeInLineOneHole = 7,

    TwoInLineOpen

}

class CPUplayer {
public:
    CPUplayer(const GameKernel& game, Side my_side) : game(game), my_side(my_side) {
        my_values = vector<vector<int>>(game.size(), vecotr<int>(game.size()));
        opponent_values = vector<vector<int>>(game.size(), 
            vecotr<int>(game.size()));
        opponent_side = my_side == TICK_SIDE ? TOE_SIDE : TICK_SIDE;
    }

    Position MakeDecision() {
        CalculateAllValues();
        double max_value = 0;
        Position best_position;
        for (int x = 0; x < game.size(); ++x) {
            for (int y = 0; y < game.size(); ++y) {
                double new_value = my_values[x][y] + 
                    aggression * opponent_values[x][y];
                if (max_value < new_value) {
                    max_value = new_value;
                    best_position = Position(x,y);
                }
            }
        }
        return best_position;
    }

private:
    void CalculateAllValues() {
        for (int x  = 0; x < game.size(); ++x) {
            for (int y = 0; y < game.size(); ++y) {
                my_values[x][y] = ValueForCell(Position(x,y), my_side);
                opponent_values[x][y] = ValueForCell(Position(x,y), opponent_side);
            }
        }
    }

    int ValueForCell(Position position, Side side) {
        int x = position.x_cor;
        int y = position.y_cor; 
        Cell sign = side == TICK_SIDE ? TICK : TOE;
        if (game(x,y) == TICK || game(x,y) == TOE) {
            return 0;
        }
        return CalculateValueInDerection(x, y, 1, 1, sign) +
             CalculateValueInDerection(x, y, 1, -1, sign) +
             CalculateValueInDerection(x, y, 1, 0, sign) +
             CalculateValueInDerection(x, y, 0, 1, sign);
    }

    // variants of directions:
    // diaganals:
    // dx = dy = 1
    // dx = 1 dy = -1
    // non diaganals:
    // dx = 1 dy = 0
    // dx = 0 dy = 1
    int CalculateValueInDerection(int x, int y, int dx, int dy, Cell sign) {

    }

    // methodes for find combinations
    // * - any symbol
    // x - my symbol
    // o - opponent symbol
    // . - empty cell

    // xxxxx
    bool FindFiveInLine(const Profile& profile);

    // .xxxx.
    // x.xxx.x
    bool FindFourInLIne(const Profile& profile);

    // TODO : четверки типа x.xxx. сильнее x.xxxo
    // oxxxx.
    // x.xxx
    // xx.xx
    // xxx.x
    // .xxxxo
    bool FindFourInLineClosed(const Profile& profile);

    // x.x.x.x
    bool FindFork(const Profile& profile);

    // TODO : она будет считать профили типа o.xxx.o троками
    // .xxx.
    // .x.xx.
    // .xx.x.
    bool FindThreeInLine(const Profile& profile);

    // .xxxo
    // .x.xxo
    // .xx.xo
    // oxxx.
    // oxx.x.
    // ox.xx.
    bool FindThreeInLineClosed(const Profile& profile);

    // TODO анализ возможности размещения пятерки
    // .xx.
    // .x.x.
    bool FindTwoInLine(const Profile& profile);

    // return vector size of 13, we analize 6 cell in one hand and 6 cells in 
    // another hand.
    // if cell not exist or have opponet side then -1 put in vector
    // if cell is empty then put in vector 0
    // if cell have opponent side then 1 put in vector
    // cel number 7 is (x,y) cell it is have 0 in any case
    Profile GetProfileOfDirection(int x, int y, int dx, int dy, Cell sign) {
        int x_start = x - dx * 6;
        int y_start = y - dy * 6;
        Profile profile;
        for (int step = 0; step < size_of_profile; ++step) {
            if (x_start >= 0 && x_start < game.size() 
                    && y_start >= 0 && y_start < game.size()) {
                if (game(x,y) == sign) {
                    profile[step] = 1;
                } else if (gam(x,y) == EMPTY) {
                    profile[step] = 0;
                } else {
                    profile[step] = -1;
                }
            } else {
                profile[step] = -1;
            }

            x_start += dx;
            y_start += dy;
        }
        return profile;
    }
    
    typedef array<int, size_of_profile> Profile;

    const int size_of_profile = 13;
    const double aggression = 1.0;

    const int five_in_line = 100;
    const int four_in_line = 20;
    const int four_in_line_closed = 10;
    const int fork = 10;
    const int three_in_line = 10;
    const int three_in_line_closed = 5;
    const int two_in_line = 5;

    Side my_side;
    Side opponent_side;
    vector<vector<int>> my_values;
    vector<vector<int>> opponent_values;

    const GameKernel& game;
};






#endif