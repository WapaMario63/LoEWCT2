#include "MessageMgr.h"
#include "MessageInfo.h"

void ProcessMessage(QByteArray datagram)
{
    // Add Player
    if ((unsigned char)datagram[0]==MsgConnect && (unsigned char)datagram[1]==0
            && (unsigned char)datagram[2]==0 && datagram.size()>=22)
    {

        ProcessConnection(datagram,
           dataToString(datagram.right(datagram.size()-22)),
           getVUint32Size(datagram.right(datagram.size()-22))+name.size(),
           dataToString(datagram.right(datagram.size()-22-nameFullSize))
        );
    }
    else if ((unsigned char)datagram[0]==MsgConnectResponse)
    {

    }
}

void ProcessConnection(QByteArray data, QString name, int fullSize, QString sesskey)
{
    bool isSessKeyValid = true;

    if (isSessKeyValid)
    {

    }
}
