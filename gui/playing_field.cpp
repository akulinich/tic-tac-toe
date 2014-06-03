#include "playing_field.h"
#include <exception>
#include <iostream>

using std::cout;
using std::endl;

const int LENGHT_LINE_TO_WIN = 5;


Position::Position(int x_cor, int y_cor) : x_cor(x_cor), y_cor(y_cor) {}



PlayingField::PlayingField(int size_of_field) {
    field = vector<vector<Player>>(size_of_field,
                                   vector<Player>(size_of_field, EMPTY));
    turn = TICK;
}

void PlayingField::do_turn(const Position& position, Player player) {
    if (field[position.x_cor][position.y_cor] == EMPTY) {
        field[position.x_cor][position.y_cor] = player;
    } else {
        throw std::logic_error("wrong turn");
    }
    turn = player == TICK ? TOE : TICK;
}

Player PlayingField::get_turn() {
    return turn;
}

bool PlayingField::check_positon_to_win(const Position& position) {
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

GameStatus PlayingField::end_game_check() {
    GameStatus result = IN_PROGRESS;
    
    bool empty_cell_exist = false;
    for (int x = 0; x < field.size(); ++x) {
        for (int y = 0; y < field.size(); ++y) {
            if (field[x][y] == EMPTY) {
                empty_cell_exist = true;
                continue;
            }
            if (check_positon_to_win(Position(x, y))) {
                if (field[x][y] == TICK) {
                    result = TICK_WIN;
                }
                if (field[x][y] == TOE) {
                    result = TOE_WIN;
                }
                break;
            }  
        }
    }
    if (!empty_cell_exist) {
        result = DRAW;
    }
    return result;
}

void PlayingField::reset_game() {
    int size_of_field = static_cast<int>(field.size());
    field.assign(size_of_field, vector<Player>(size_of_field, EMPTY));
    turn = TICK;
}

void PlayingField::print_game() {
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

