#include "LoEWCTServer/Server.h"
#include "Utilities/serialize.h"
#include "LoEWCTServer/MessageMgr.h"

void Server::udpProcessPendingDatagram()
{
    while (server->hasPendingDatagrams())
    {
        QHostAddress rAddr;
        quint16 rPort;
        QByteArray datagram;
        qint64 dataRead = 0;
        int datagramSize = server->pendingDatagramSize();

        datagram.resize(datagramSize);

        while(dataRead < datagram.size())
        {
            qint64 readNow = server->readDatagram(datagram.data()+dataRead, datagramSize, &rAddr, &rPort);

            if (readNow != -1)
            {
                dataRead += readNow;
                if (datagramSize > (datagram.size() - dataRead))
                    datagramSize = (datagram.size() - dataRead);
            }
            else
            {
                return;
            }
        }


    }
}
