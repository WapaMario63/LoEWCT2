#include "LoEWCTServer/Server.h"
#include "Utilities/serialize.h"

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

        // Add Player
        if ((unsigned char)datagram[0]==MsgConnect && (unsigned char)datagram[1]==0
                && (unsigned char)datagram[2]==0 && datagram.size()>=22)
        {
            QString name = dataToString(datagram.right(datagram.size()-22));
            int nameFullSize = getVUint32Size(datagram.right(datagram.size()-22))+name.size();
            QString sesskey = dataToString(datagram.right(datagram.size()-22-nameFullSize));

            bool isSessKeyValid = true;

            if (isSessKeyValid)
            {

            }
        }
    }
}
