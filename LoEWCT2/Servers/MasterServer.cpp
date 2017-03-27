#include "MasterServer.h"
#include "MessageInfo.h"
#include "Utilities/serialize.h"

MasterServer::MasterServer()
{
    id = 1; // Master servers will always have an ID of 1
    port = 1039;
    socket = new QUdpSocket();
    CreateMapServersFromVortex();
}

MasterServer::~MasterServer()
{
    stopServer();
    //delete socket;
}

void MasterServer::startServer()
{
    logMessage("Starting Master Server on port: "+QString().setNum(port));
    if (!socket->bind(port, QUdpSocket::ReuseAddressHint | QUdpSocket::ShareAddress))
    {
        logErrMessage("Failed to start Master server. Details: \n"+socket->errorString());
        stopServer();
        return;
    }

    connect(socket, SIGNAL(readyRead()), this, SLOT(processPendingDatagrams()));
}

void MasterServer::stopServer()
{
    logMessage("Stopping Master server..");

    for (auto i=0; i<mapRooms.size(); i++)
        mapRooms[i]->stopServer();

    // TODO: Disconnect all players. Free players from memory.

    socket->close();

    disconnect(socket, SIGNAL(readyRead()), this, SLOT(processPendingDatagrams()));
    socket->deleteLater();
}

void MasterServer::CreateMapServersFromVortex()
{
    // TODO: Read Map Vortex files and create map servers for each map.
}

void MasterServer::processPendingDatagrams()
{
    QHostAddress pAddress;
    quint16 pPort;
    QByteArray datagram;
    qint64 dataRead = 0;
    qint64 datagramSize = socket->pendingDatagramSize();
    datagram.resize(static_cast<int>(datagramSize));

    while (dataRead < datagram.size())
    {
        qint64 readNow = socket->readDatagram(datagram.data()+dataRead, datagramSize, &pAddress, &pPort);
        if (readNow != -1)
        {
            dataRead += readNow;
            if (datagramSize > (datagram.size() - dataRead))
                datagramSize = (datagram.size() - dataRead);
        }
        else
        {
            logErrMessage("Socket Error : "+socket->errorString());
            return;
        }
    }

    if ((unsigned char)datagram[0] == MsgConnect && (unsigned char)datagram[1]==0
            && (unsigned char)datagram[2]==0 && datagram.size()>=22)
    {
        QString name = dataToString(datagram.right(datagram.size()-22))+name.size();
        int nameFullSize = getVUint32Size(datagram.right(datagram.size()-22))+name.size();
        QString sessKey = dataToString(datagram.right(datagram.size()-22-nameFullSize));

        logMessage("Client connection detected, information: ");
        logMessage("Name: "+name+"\nSession Key: "+sessKey+"\nData was: "+datagram.toHex());

        bool isSessKeyValid = true;

        // TODO: Create Session Key validation
        // Mainly when a way to load configuration files is created.

        if (isSessKeyValid)
        {
            logMessage("Session key token accepted from client ("+name+").");

            Player* newPlayer; // TODO: Create a Player Manager class
        }

    }
}
