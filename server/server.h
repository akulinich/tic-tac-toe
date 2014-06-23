#ifndef SERVER_H
#define SERVER_H

#include <QtGui>
#include <QtWidgets>
#include <QtNetwork>


class Server : public QWidget {
Q_OBJECT

private:
    QTcpServer* server;
    QTextEdit* output_log;

    quint16 available_bytes;

    // void send_turn_to_client(QTcpSocket* client);
    void send_to_client(QTcpSocket* client, const QString& str);

private slots:
    
    void slot_new_connection();
    void slot_get_turn();

public:
    Server(int port, QWidget* widget = 0);   


};


#endif