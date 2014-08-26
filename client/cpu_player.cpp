#include "cpu_player.h"



CPUplayer::CPUplayer(const GameKernel& game, Side my_side) : my_side(my_side), game(game) {
    my_values = vector<vector<int>>(game.size(), vector<int>(game.size()));
    opponent_values = vector<vector<int>>(game.size(), 
        vector<int>(game.size()));
    opponent_side = my_side == TICK_SIDE ? TOE_SIDE : TICK_SIDE;
}

Position CPUplayer::MakeDecision() {
    CalculateAllValues();
    double max_value = 0;
    Position best_position;
    for (int x = 0; x < game.size(); ++x) {
        for (int y = 0; y < game.size(); ++y) {
            double new_value = my_values[x][y] + 
                aggression * opponent_values[x][y];
            if (!game.possiblyDecision(Position(x,y))) {
                new_value = -1;
            }
            cout << x << " " << y << " val : " << new_value << endl;
            if (max_value < new_value) {
                max_value = new_value;
                best_position = Position(x,y);
            }
        }
    }
    return best_position;
}


void CPUplayer::CalculateAllValues() {
    for (int x  = 0; x < game.size(); ++x) {
        for (int y = 0; y < game.size(); ++y) {
            my_values[x][y] = ValueForCell(Position(x,y), my_side);
            opponent_values[x][y] = ValueForCell(Position(x,y), opponent_side);
        }
    }
}

int CPUplayer::ValueForCell(Position position, Side side) {
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
int CPUplayer::CalculateValueInDerection(int x, int y, int dx, int dy, Cell sign) {
    Profile profile = GetProfileOfDirection(x, y, dx, dy , sign);
    if (FindFiveInLine(profile)) {
        return  five_in_line;
    }
    if (FindFourInLine(profile)) {
        return four_in_line;
    }
    if (FindFork(profile)) {
        return fork;
    }
    if (FindFourInLineClosed(profile)) {
        return four_in_line_closed;
    }
    if (FindThreeInLine(profile)) {
        return three_in_line;
    }
    if (FindTwoInLine(profile)) {
        return two_in_line;
    }
    if (FindThreeInLineClosed(profile)) {
        return three_in_line_closed;
    }
    return 0;
}

// methodes for find combinations
// * - any symbol
// x - my symbol
// o - opponent symbol
// . - empty cell

// xxxxx
bool CPUplayer::FindFiveInLine(const Profile& profile) {
    int occerence = profile.find("xxxxx", 2);
    return !(occerence == -1 || occerence > 6);
}

// .xxxx.
// x.xxx.x
bool CPUplayer::FindFourInLine(const Profile& profile) {
    //.xxxx.
    int occerence = profile.find(".xxxx.", 2);
    if (occerence != -1 && occerence < 6) {
        return true;
    }
    // x.xxx.x
    occerence = profile.find("x.xxx.x", 0);
    return occerence != -1;
}

// TODO : четверки типа x.xxx. сильнее x.xxxo
// oxxxx.
// x.xxx
// xx.xx
// xxx.x
// .xxxxo
bool CPUplayer::FindFourInLineClosed(const Profile& profile) {
    int occerence = profile.find("oxxxx.", 2);
    if (occerence != -1 && occerence < 6) {
        return true;
    }
    occerence = profile.find("x.xxx", 2);
    if (occerence != -1 && occerence < 7) {
        return true;
    }
    occerence = profile.find("xx.xx", 2);
    if (occerence != -1 && occerence < 7) {
        return true;
    }
    occerence = profile.find("xxx.x", 2);
    if (occerence != -1 && occerence < 7) {
        return true;
    }
    occerence = profile.find(".xxxxo", 2);
    if (occerence != -1 && occerence < 6) {
        return true;
    }
    return false;
}

// x.x.x.x
bool CPUplayer::FindFork(const Profile& profile) {
    int occerence = profile.find("x.x.x.x", 0);
    if (occerence != -1) {
        return true;
    }
    return false;
}

// TODO : она будет считать профили типа o.xxx.o троками
// .xxx.
// .x.xx.
// .xx.x.
bool CPUplayer::FindThreeInLine(const Profile& profile) {
    int occerence = profile.find(".xxx.", 3);
    if (occerence != -1 && occerence < 6) {
        return true;
    }
    occerence = profile.find(".x.xx.", 2);
    if (occerence != -1 && occerence < 6) {
        return true;
    }
    occerence = profile.find(".xx.x.", 2);
    if (occerence != -1 && occerence < 6) {
        return true;
    }
    return false;
}

// .xxxo
// .x.xxo
// .xx.xo
// oxxx.
// oxx.x.
// ox.xx.
bool CPUplayer::FindThreeInLineClosed(const Profile& profile) {
    int occerence = profile.find(".xxxo", 3);
    if (occerence != -1 && occerence < 6) {
        return true;
    }
    occerence = profile.find(".x.xxo", 2);
    if (occerence != -1 && occerence < 6) {
        return true;
    }
    occerence = profile.find(".xx.xo", 2);
    if (occerence != -1 && occerence < 6) {
        return true;
    }
    occerence = profile.find("oxxx.", 3);
    if (occerence != -1 && occerence < 6) {
        return true;
    }
    occerence = profile.find("oxx.x.", 2);
    if (occerence != -1 && occerence < 6) {
        return true;
    }
    occerence = profile.find("ox.xx.", 2);
    if (occerence != -1 && occerence < 6) {
        return true;
    }
    return false;
}

// TODO анализ возможности размещения пятерки
// .xx.
// .x.x.
bool CPUplayer::FindTwoInLine(const Profile& profile) {
    int occerence = profile.find(".xx.", 4);
    if (occerence != -1 && occerence < 6) {
        return true;
    }
    occerence = profile.find(".x.x.", 3);
    if (occerence != -1 && occerence < 6) {
        return true;
    }
    return false;
}

// return vector size of 13, we analize 6 cell in one hand and 6 cells in 
// another hand.
// if cell not exist or have opponet side then -1 put in vector
// if cell is empty then put in vector 0
// if cell have my side then 1 put in vector
// cel number 6 is (x,y) cell it is have 0 in any case
CPUplayer::Profile CPUplayer::GetProfileOfDirection(int x, int y, int dx, int dy, Cell sign) {
    int x_start = x - dx * 6;
    int y_start = y - dy * 6;
    Profile profile;
    for (int step = 0; step < size_of_profile; ++step) {
        if (x_start >= 0 && x_start < game.size() 
                && y_start >= 0 && y_start < game.size()) {
            if (game(x_start,y_start) == sign) {
                profile += 'x';
            } else if (game(x,y) == EMPTY) {
                profile += '.';
            } else {
                profile += 'o';
            }
        } else {
            profile += 'o';
        }

        x_start += dx;
        y_start += dy;
    }
    profile[6] = 'x';
    return profile;
}

void CPUplayer::SetSide(Side side) {
    my_side = side;
}

