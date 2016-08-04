#include "LoEWCTServer/Server.h"

Server::Server(int maximunRooms, int serverPort, int mainRoomPort, int maximunPlayers, QString roomHost, QObject *parent)
    : QObject(parent)
{
    MaximunRooms = maximunRooms;
    ServerPort = serverPort;
    MainRoomPort = mainRoomPort;
    RoomHost = roomHost;
    MaximumPlayers = maximunPlayers;

    server = new QUdpSocket(this);

    connect(server, SIGNAL(readyRead()), this, SLOT(udpProcessPendingDatagram()));
}

void Server::Initialize()
{
    server->bind(ServerPort, QUdpSocket::ReuseAddressHint | QUdpSocket::ShareAddress);

    printf("Starting LoEWCT2 Server...\n");
}

void Server::AddRoom(int id)
{

}

void Server::RemoveRoom(Room room)
{

}

bool Server::GetRoom(int id, Room room)
{

}

void Server::UpdateRoomsOfNewRoom(Room room)
{

}

void Server::AddPlayer(Player *player)
{

}

void Server::RemovePlayer(Player *player)
{

}

Player* Server::GetPlayer(int id)
{
    for (int i=0; i<sPlayers.size(); i++)
    {

    }
}

void Server::sendMessage(Player *player, MessageTypes type, QByteArray data)
{

}

void Server::receiveMessage(Player *player)
{

}
