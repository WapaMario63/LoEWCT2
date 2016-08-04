#include "Player.h"

Player::Player()
{
    id = 0;
    IP = "";
    port = "0";
    name = "";
    currentRoom = new Room();
    oldRoom = new Room();
}

bool Player::ChangeRoom(int id)
{

}

bool Player::ChangeRoom(Room room)
{

}

Player* Player::findPlayer(QList<Player *> &players, QString uIP, quint16 uPort)
{

}

Player* Player::findPlayer(QList<Player *> &players, QString uname)
{

}
