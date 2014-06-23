#include "game.h"
#include "game_kernel.h"
#include <exception>
#include <iostream>

using std::cout;
using std::endl;

const int LENGHT_LINE_TO_WIN = 5;


Position::Position(int x_cor, int y_cor) : x_cor(x_cor), y_cor(y_cor) {}



GameKernel::GameKernel(int size_of_field) {
    field = vector<vector<Cell>>(size_of_field,
                                vector<Cell>(size_of_field, EMPTY));
    status_ = TICK_TURN;
}

void GameKernel::makeTurn(const Position& position) {
    if (status_ == TICK_WIN || status_ == TOE_WIN || status_ == DRAW) {
        throw std::logic_error("game ended");
    }

    if (field[position.x_cor][position.y_cor] == EMPTY) {
        if (status_ == TICK_TURN) {
            field[position.x_cor][position.y_cor] = TICK;
            status_ = TOE_TURN;
        } else {
            field[position.x_cor][position.y_cor] = TOE;
            status_ = TICK_TURN;
        }
        checkEndGame();
    } else {
        throw std::logic_error("wrong turn");
    }
}

bool GameKernel::isWinPosition(const Position& position) const {
    bool left_result = true;
    bool diaganal_result = true;
    bool top_result = true;
    bool second_diaganal_result = true;
    
    for (int line = 1; line < LENGHT_LINE_TO_WIN; ++line) {
        if (position.x_cor - LENGHT_LINE_TO_WIN + 1 >= 0) {
            if (field[position.x_cor - line][position.y_cor] !=
                field[position.x_cor - line + 1][position.y_cor]) {
                left_result = false;
            }
        } else {
            left_result = false;
        }
        
        if (position.x_cor - LENGHT_LINE_TO_WIN + 1 >= 0 &&
            position.y_cor - LENGHT_LINE_TO_WIN + 1 >= 0) {
            if (field[position.x_cor - line][position.y_cor - line] !=
                field[position.x_cor - line + 1][position.y_cor - line + 1]) {
                diaganal_result = false;
            }
        } else {
            diaganal_result = false;
        }
        
        if (position.y_cor - LENGHT_LINE_TO_WIN + 1 >= 0) {
            if (field[position.x_cor][position.y_cor - line] !=
                field[position.x_cor][position.y_cor - line + 1]) {
                top_result = false;
            }
        } else {
            top_result = false;
        }

        if (position.x_cor + LENGHT_LINE_TO_WIN + 1 < field.size() &&
            position.y_cor - LENGHT_LINE_TO_WIN + 1 >= 0) {
            if (field[position.x_cor + line][position.y_cor - line] !=
                field[position.x_cor + line - 1][position.y_cor - line + 1]) {
                second_diaganal_result = false;
            }
        } else {
            second_diaganal_result = false;
        }
    }
    return top_result || left_result || diaganal_result || second_diaganal_result;
}

GameStatus GameKernel::status() const {
    return status_;
}

void GameKernel::checkEndGame() {
    bool empty_cell_exist = false;
    for (int x = 0; x < field.size(); ++x) {
        for (int y = 0; y < field.size(); ++y) {
            if (field[x][y] == EMPTY) {
                empty_cell_exist = true;
                continue;
            }
            if (isWinPosition(Position(x, y))) {
                if (field[x][y] == TICK) {
                    status_ = TICK_WIN;
                }
                if (field[x][y] == TOE) {
                    status_ = TOE_WIN;
                }
                break;
            }  
        }
    }
    if (!empty_cell_exist) {
        status_ = DRAW;
    }
}

void GameKernel::reset() {
    int size_of_field = static_cast<int>(field.size());
    field.assign(size_of_field, vector<Cell>(size_of_field, EMPTY));
    status_ = TICK_TURN;
}

void GameKernel::print() const {
    for (int x = 0; x < field.size(); ++x) {
        for (int y = 0; y < field.size(); ++y) {
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

int GameKernel::size() const {
    return field.size();
}

bool GameKernel::emptyCell(const Position& position) const {
    return field[position.x_cor][position.y_cor] == EMPTY;
}

