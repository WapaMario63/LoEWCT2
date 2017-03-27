#include "Server.h"
#include <iostream>
#include <QDateTime>

Server::Server()
{
    maxPlayers = 512;
}

Server::~Server()
{

}

void Server::logMessage(QString msg)
{
    QString logTime = QDateTime::currentDateTime().toString("[hh:mm:ss AP] ");
    std::cout << logTime.toStdString() << "[INFO] " << msg.toStdString() << std::endl;
}

void Server::logErrMessage(QString msg)
{
    QString logTime = QDateTime::currentDateTime().toString("[hh:mm:ss AP] ");
    std::cerr << logTime.toStdString() << "[ERROR] " << msg.toStdString() << std::endl;
}
