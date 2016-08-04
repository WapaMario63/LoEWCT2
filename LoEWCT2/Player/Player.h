#ifndef PLAYER_H
#define PLAYER_H

#include <LoEWCTRoom/Room.h>
#include <QString>

class Room;

class Player
{
public:
    Player();

    int id;
    QString IP;
    QString port;
    QString name;

    bool ChangeRoom(int id);
    bool ChangeRoom(Room room);

    Player* findPlayer(QList<Player*>& players, QString uname);
    Player* findPlayer(QList<Player*>& players, QString uIP, quint16 uPort);

private:
    Room* currentRoom;
    Room* oldRoom;
};

#endif // PLAYER_H
