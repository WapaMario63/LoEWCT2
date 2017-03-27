#ifndef ROOMSERVER_H
#define ROOMSERVER_H

#include "Server.h"
#include "Players/Pony.h"

class RoomServer
{
public:
    /**
     * @brief Room name
     *
     * Unique room name shown in-game.
     */
    QString name;
    /**
     * @brief Room ID
     *
     * Not to be confused from the server's ID, this is an unique ID that the map
     * server can identify easily. It is also the alternative value for the room name.
     */
    quint32 roomId;
    QList<Pony> players;

    RoomServer();

};

#endif // ROOMSERVER_H
