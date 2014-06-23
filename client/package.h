#ifndef PACKAGE_H
#define PACKAGE_H

#include "playing_field.h"

struct SideInfo {
    Player side;
};

struct Turn {
    Player player;
    Position decision;
};

struct EndGame {
    bool new_game;
};



#endif