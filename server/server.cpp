#include "server.h"

#include <QtGui>
#include <QtWidgets>
#include <QtNetwork>


Server::Server(int port, QWidget* widget)
    : QWidget(widget) {
        server = new QTcpServer(this);
        // listen has two parametrs:
        // first is IP
        // second is port
        if (!server->listen(QHostAddress::Any, port)) {
            QMessageBox::critical(this, tr("Server Erorr"),
                              tr("Unable to start the server: %1.")
                              .arg(server->errorString()));
            close();
            return;
        }
        connect(server, SIGNAL(newConnection()), this, SLOT(slot_new_connection()));

        output_log = new QTextEdit;
        output_log->setReadOnly(true);

        // layout setup
        QVBoxLayout* layout = new QVBoxLayout;
        layout->addWidget(new QLabel("server started"));
        layout->addWidget(output_log);
        setLayout(layout);

        available_bytes = 0;
}

void Server::slot_new_connection() {
    QTcpSocket* socket = server->nextPendingConnection();

    connect(socket, SIGNAL(disconnected()), socket, SLOT(deleteLater()));
    connect(socket, SIGNAL(readyRead()), this, SLOT(slot_get_turn()));

    send_to_client(socket, "Accept");
}

void Server::send_to_client(QTcpSocket* client, const QString& str) {
    QByteArray arrBlock;
    QDataStream out(&arrBlock, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_4_8);
    out << quint16(0) << QTime::currentTime() << str;
    out.device()->seek(0);
    out << (quint16(arrBlock.size()) - quint16(sizeof(quint16)));

    client->write(arrBlock);
}

void Server::slot_get_turn() {
    QTcpSocket* socket = (QTcpSocket*)sender();
    QDataStream in(socket);
    in.setVersion(QDataStream::Qt_4_8);
    for (;;) {
        if(available_bytes == 0) {
            if (socket->bytesAvailable() < sizeof(quint16)) {
                break;
            }
            in >> available_bytes;
        }

        if (socket->bytesAvailable() < available_bytes) {
            break;
        }

        QTime time; 
        QString str;
        in >> time >> str;

        QString message = time.toString() + " " + "Client has sent — " + str;
        output_log->append(message);
        available_bytes = 0;
        send_to_client(socket, "Recived");
    }
}


