#include "Room.h"

Room::Room()
{

}

Room::Room(QString roomid, QString Address, quint16 port, QObject *parent)
    : QObject(parent)
{

}

void Room::sendMessage(Player* player, MessageTypes msgtype, QByteArray data)
{

}

void Room::receiveMessage(Player* player)
{

}
