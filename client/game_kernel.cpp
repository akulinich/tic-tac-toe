#include "structurs.h"
#include "game_kernel.h"

#include <algorithm>

const int LENGHT_LINE_TO_WIN = 5;

GameKernel::GameKernel(int size_of_field) : field(size_of_field) {
    game_state = NOT_STARTED;
}
    
void GameKernel::start(Side player_one_side, Side player_two_side) {
    player_one_side_ = player_one_side;
    player_two_side_ = player_two_side;
    if (player_one_side == TICK_SIDE) {
        game_state = PLAYER_ONE_TURN;
    } else {
        game_state = PLAYER_TWO_TURN;
    }
}

bool GameKernel::playerDecision(Position pos, Player player) {
    if (player == PLAYER_ONE && game_state == PLAYER_ONE_TURN) {
        if (player_one_side_ == TICK_SIDE) {
            field.setTick(pos);
        } else {
            field.setToe(pos);
        }
        game_state = PLAYER_TWO_TURN;
        gameOver();
        return true;
    }

    if (player == PLAYER_TWO && game_state == PLAYER_TWO_TURN) {
        if (player_two_side_ == TICK_SIDE) {
            field.setTick(pos);
        } else {
            field.setToe(pos);
        }
        game_state = PLAYER_ONE_TURN;
        gameOver();
        return true;
    }
    return false;
}

GameState GameKernel::state() const {
    return game_state;
}



bool GameKernel::possiblyDecision(Position pos) {
    return field[pos] == EMPTY;
}

int GameKernel::sizeOfField() {
    return field.size();
}

Side GameKernel::getPlayerSide(Player player) {
    if (player == PLAYER_ONE) {
        return player_one_side_;
    } else {
        return player_two_side_;
    }
}

void GameKernel::resetGame() {
    field.clear();
    game_state = NOT_STARTED;
}

void GameKernel::print() const {
    field.print();
}

bool GameKernel::winPosition(const Position& position) const {
    bool left_result = true;
    bool diaganal_result = true;
    bool top_result = true;
    bool second_diaganal_result = true;
    
    for (int line = 1; line < LENGHT_LINE_TO_WIN; ++line) {
        if (position.x_cor - LENGHT_LINE_TO_WIN + 1 >= 0) {
            if (field[Position(position.x_cor - line, position.y_cor)] !=
                field[Position(position.x_cor - line + 1, position.y_cor)]) {
                left_result = false;
            }
        } else {
            left_result = false;
        }
        
        if (position.x_cor - LENGHT_LINE_TO_WIN + 1 >= 0 &&
            position.y_cor - LENGHT_LINE_TO_WIN + 1 >= 0) {
            if (field[Position(position.x_cor - line, position.y_cor - line)] !=
                field[Position(position.x_cor - line + 1, 
                    position.y_cor - line + 1)]) {
                diaganal_result = false;
            }
        } else {
            diaganal_result = false;
        }
        
        if (position.y_cor - LENGHT_LINE_TO_WIN + 1 >= 0) {
            if (field[Position(position.x_cor, position.y_cor - line)] !=
                field[Position(position.x_cor, position.y_cor - line + 1)]) {
                top_result = false;
            }
        } else {
            top_result = false;
        }

        if (position.x_cor + LENGHT_LINE_TO_WIN + 1 < field.size() &&
            position.y_cor - LENGHT_LINE_TO_WIN + 1 >= 0) {
            if (field[Position(position.x_cor + line, position.y_cor - line)] !=
                field[Position(position.x_cor + line - 1, 
                    position.y_cor - line + 1)]) {
                second_diaganal_result = false;
            }
        } else {
            second_diaganal_result = false;
        }
    }
    return top_result || left_result || diaganal_result || second_diaganal_result;
}

void GameKernel::gameOver() {
    bool empty_cell_exist = false;
    for (int x = 0; x < field.size(); ++x) {
        for (int y = 0; y < field.size(); ++y) {
            if (field[Position(x, y)] == EMPTY) {
                empty_cell_exist = true;
                continue;
            }
            if (winPosition(Position(x, y))) {
                if (field[Position(x, y)] == TICK) {
                    game_state = player_one_side_ == TICK_SIDE ? 
                        PLAYER_ONE_WIN : PLAYER_TWO_WIN;
                }
                if (field[Position(x, y)] == TOE) {
                    game_state = player_one_side_ == TOE_SIDE ? 
                        PLAYER_ONE_WIN : PLAYER_TWO_WIN;
                }
                break;
            }  
        }
    }
    if (!empty_cell_exist) {
        game_state = DRAW;
    }
}

int GameKernel::size() const {
    return field.size();
}

Cell GameKernel::operator()(int x_cor, int y_cor) {
    return field[Position(x_cor, y_cor)];
}



