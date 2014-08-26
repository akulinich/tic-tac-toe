#ifndef CPU_PLAYER_H
#define CPU_PLAYER_H


#include "playing_field.h"
#include "game_kernel.h"
#include "structurs.h"

#include <vector>
#include <string>
#include <iostream>

using std::vector;
using std::cout;
using std::endl;

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

};

class CPUplayer {
    typedef std::string Profile;

public:
    CPUplayer(const GameKernel& game, Side my_side);
    Position MakeDecision();
    void SetSide(Side side);

private:
    void CalculateAllValues() ;

    int ValueForCell(Position position, Side side);

    // variants of directions:
    // diaganals:
    // dx = dy = 1
    // dx = 1 dy = -1
    // non diaganals:
    // dx = 1 dy = 0
    // dx = 0 dy = 1
    int CalculateValueInDerection(int x, int y, int dx, int dy, Cell sign);

    // methodes for find combinations
    // * - any symbol
    // x - my symbol
    // o - opponent symbol
    // . - empty cell

    // xxxxx
    bool FindFiveInLine(const Profile& profile);

    // .xxxx.
    // x.xxx.x
    bool FindFourInLine(const Profile& profile);

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
    // if cell have my side then 1 put in vector
    // cel number 6 is (x,y) cell it is have 0 in any case
    Profile GetProfileOfDirection(int x, int y, int dx, int dy, Cell sign) ;
    
    

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