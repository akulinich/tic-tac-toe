#ifndef PLAYING_FIELD_H
#define PLAYING_FIELD_H

#include <vector>
#include "structurs.h"

using std::vector;

/*
describe field wich will contains tickes and toes
*/
class PlayingField {
public:
    explicit PlayingField(int size);

    void clear();
    bool setTick(Position pos);
    bool setToe(Position pos);
    bool setTick(int x, int y);
    bool setToe(int x, int y);
    Cell operator[](Position pos) const;
    int size() const;

    void print() const;

private:
    vector<vector<Cell>> field;
    int size_;
};

#endif 