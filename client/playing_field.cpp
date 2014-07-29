#include "structurs.h"
#include "playing_field.h"
#include <iostream>
#include <vector>

using std::vector;
using std::cout;
using std::endl;

PlayingField::PlayingField(int size) : size_(size) {
    field = vector<vector<Cell>>(size,
                   vector<Cell>(size, EMPTY));
}

void PlayingField::clear() {
    field = vector<vector<Cell>>(size_,
                   vector<Cell>(size_, EMPTY));
}

void PlayingField::setTick(Position pos) {
    field[pos.x_cor][pos.y_cor] = TICK;
}

void PlayingField::setToe(Position pos) {
    field[pos.x_cor][pos.y_cor] = TOE;
}
void PlayingField::setTick(int x, int y) {
    field[x][y] = TICK;
}
void PlayingField::setToe(int x, int y) {
    field[x][y] = TOE;
}

Cell PlayingField::operator[](Position pos) const {
    return field[pos.x_cor][pos.y_cor];
}

int PlayingField::size() const {
    return size_;
}

void PlayingField::print() const {
    for (int x = 0; x < static_cast<int>(field.size()); ++x) {
        for (int y = 0; y < static_cast<int>(field.size()); ++y) {
            if (field[x][y] == TICK) {
                cout << "X";
            }
            if (field[x][y] == TOE) {
                cout << "O";
            }
            if (field[x][y] == EMPTY) {
                cout << ".";
            }
        }
        cout << endl;
    }
    cout << endl;
}
