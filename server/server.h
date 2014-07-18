#ifndef SERVER_H
#define SERVER_H

#include <QtGui>
#include <QtWidgets>
#include <QtNetwork>

// discribe package:
// info of package:
//
// 1 - player number info: one int 
//   (number)
//     1 - you first player
//     2 - you second player
//
// 2 - user info: 
//     1 - turn info: four int
//       (x) (y) 
//           line and column
//       (side)
//         1 - you tick side
//         2 - you toe side
//       (player)
//         1 - turn from first player
//         2 - turn from second player
//     2 - new_game_info: one int
//       (decision)
//         1 - yes, 2 - no  
// 3 - end game (no data)
// 4 - disconnection     
//
//

struct UserInfo {
    int type_of_package, x, y, side, player, decision;
    UserInfo(int x, int y, int side, int player) : x(x), y(y), side(side), player(player) {}
    UserInfo(int decision) : decision(decision) {}
    UserInfo() {}
};


enum ServerState {
    PLAYERS_NOT_SETED,

    PLAYERS_SETED,
    SEND_SPLAYER_NUMBER_INFO,

    REDIRECT_USER_INFO // every turn or end game info, but if this info is end_all_games_info then clear players and PLAYERS_NOT_SETED
};


struct Turn {
    int x;
    int y;
    int side;
    int player;

    Turn(int x, int y, int side, int player) 
        : x(x), y(y), side(side), player(player) {}
};

struct NetPlayer {
    QTcpSocket* socket;
    QString name;

    NetPlayer(QTcpSocket* socket, const QString& name) : socket(socket), name(name) {}
    NetPlayer() {}
};



class Server : public QWidget {
Q_OBJECT

private:
    QTcpServer* server;

    QVector<NetPlayer> sockets;
    QVector<NetPlayer> choosen_sockets;
    
    NetPlayer player_one;
    NetPlayer player_two;

    ServerState state;

    void sendPlayerNumber(QTcpSocket* socket, int number);
    void sendUserInfo(QTcpSocket* socket, UserInfo info);
    void sendEndGame(QTcpSocket* socket);
    void sendPlayerDisconnected(QTcpSocket* socket);

    void readPlayerNumber(QTcpSocket* socket);
    void readUserInfo(QTcpSocket* socket);
    void readEndGame(QTcpSocket* socket);


// gui
    QPushButton* set_players; // -> cliced() -> setNewPlayers();
    QPushButton* clear_players;

    QListWidget* all_avaliable_players;
    QListWidget* choosen_players;

    QLabel* server_state_info;

    void redrawLists();

private slots:

    void slotNewConnection();
    void slotLoseConnection();

    void slotSetNewPlayers();
    void slotResetPlayers();

    void slotReadInfo();

    void slotAddPlayerInChoosenList(QListWidgetItem*);

public:
    Server(int port, QWidget* widget = 0);   
};


#endif