#include "playing_field.h"
#include <iostream>
#include <exception>


using std::cin;
using std::cout;
using std::endl;


const int SIZE_OF_FIELD = 10;

int main(int argc, char const *argv[])
{
    PlayingField field = PlayingField(SIZE_OF_FIELD);
    field.print_game();
    int turn = 0;
    GameStatus status = IN_PROGRESS;
    while (status == IN_PROGRESS) {
        Player player;
        if (turn % 2) {
            cout << "seond player turn:" << endl;
            player = TOE;
        } else {
            cout << "first player turn:" << endl;
            player = TICK;
        }
        int x, y;
        cin >> x >> y;
        try {
            field.do_turn(Position(x,y), player);
        } catch (std::logic_error) {
            cout << "wrong input! try again!" << endl; 
            continue;
        }
        ++turn;
        field.print_game();
        status = field.end_game_check();
    }
    if (status == TICK_WIN) {
        cout << "first player win!" << endl;
    } 
    if (status == TOE_WIN) {
        cout << "second player win!" << endl;
    }
    if (status == DRAW) {
        cout << "draw!" << endl;
    }
    


    return 0;
}