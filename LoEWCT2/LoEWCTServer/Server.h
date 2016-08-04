#ifndef SERVER_H
#define SERVER_H

#include "Player/Player.h"
#include "MessageInfo.h"
#include "LoEWCTRoom/Room.h"

#include <QString>
#include <QObject>
#include <QUdpSocket>
#include <QMap>
#include <QList>

class Player;
class Room;

class Server : public QObject
{
    Q_OBJECT
public:
    Server(int maximunRooms = 256, int serverPort = 1039, int MainRoomPort = 1038,
           int maximunPlayers = 50000, QString roomHost = "localhost",
           QObject *parent = 0);

    void Initialize();

public:
    int MaximunRooms;
    int MaximumPlayers;
    int ServerPort;
    int MainRoomPort;
    QString RoomHost;

    QList<Player*> sPlayers;
    QList<Room> rooms;

    QUdpSocket* server;

    void AddRoom(int id);
    void RemoveRoom(Room room);
    bool GetRoom(int id, Room room);
    void UpdateRoomsOfNewRoom(Room room);

    void AddPlayer(Player* player);
    void RemovePlayer(Player* player);
    Player* GetPlayer(int id);

    void sendMessage(Player* player, MessageTypes type, QByteArray data);
    void receiveMessage(Player* player);
public slots:
    void udpProcessPendingDatagram();

};

#endif // SERVER_H
