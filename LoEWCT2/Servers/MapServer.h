#ifndef MAPSERVER_H
#define MAPSERVER_H

#include "Server.h"
#include "RoomServer.h"

/**
 * @brief The MapServer class
 */
class MapServer : public Server
{
public:
    QString masterAddress;
    quint16 masterPort;
    QList<RoomServer> rooms;
    QList<Pony*> players;

    MapServer();

    void CreateRoom(QString name, int roomId);
    void RemoveRoom(QString name);
    void RemoveRoom(int roomId);
    void UpdateRoomsOfNewRoom(int roomId);
    void UpdateRoomsOfNewRoom(QString name);

};

#endif // MAPSERVER_H
