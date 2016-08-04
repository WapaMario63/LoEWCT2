#ifndef ROOM_H
#define ROOM_H

#include "LoEWCTServer/Server.h"
#include "Player/Player.h"
#include "MessageInfo.h"

#include <QObject>
#include <QUdpSocket>

class Player;

class Room : public QObject
{
    Q_OBJECT
public:
    Room();
    Room(QString roomid, QString Address, quint16 port, QObject *parent = 0);

    QString Id;
    QString Address;
    quint16 port;
    int maxPlayers;
    int tickRate;
    QList<Player*> players;

    bool running;

    QUdpSocket* roomServer;
    QString dispatcherAddress; // Master Server
    QString dispatchedPort;

    void sendMessage(Player* player, MessageTypes msgtype, QByteArray data);
    void receiveMessage(Player* player);

};

#endif // ROOM_H
