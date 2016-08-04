#ifndef MESSAGEINFO_H
#define MESSAGEINFO_H

enum NetviewRemoveReasonCodes
{
    NetviewRemoveReasonDefault = 0,
    NetviewRemoveReasonKill = 1
};

enum MessageTypes
{
    MsgUnconnected = 0,
    MsgUserUnreliable = 1,
    MsgPing = 0x81,
    MsgPong = 0x82,
    MsgConnect = 0x83,
    MsgConnectResponse = 0x84,
    MsgConnectionEstablished = 0x85,
    MsgAcknowledge = 0x86,
    MsgDisconnect = 0x87,
    MsgUserReliableOrdered1 = 0x43,
    MsgUserReliableOrdered2 = 0x44,
    MsgUserReliableOrdered3 = 0x45,
    MsgUserReliableOrdered4 = 0x46,
    MsgUserReliableOrdered5 = 0x47,
    MsgUserReliableOrdered6 = 0x48,
    MsgUserReliableOrdered7 = 0x49,
    MsgUserReliableOrdered8 = 0x4a,
    MsgUserReliableOrdered9 = 0x4b,
    MsgUserReliableOrdered10 = 0x4c,
    MsgUserReliableOrdered11 = 0x4d,
    MsgUserReliableOrdered12 = 0x4e,
    MsgUserReliableOrdered13 = 0x4f,
    MsgUserReliableOrdered14 = 0x50,
    MsgUserReliableOrdered15 = 0x51,
    MsgUserReliableOrdered16 = 0x52,
    MsgUserReliableOrdered17 = 0x53,
    MsgUserReliableOrdered18 = 0x54,
    MsgUserReliableOrdered19 = 0x55,
    MsgUserReliableOrdered20 = 0x56,
    MsgUserReliableOrdered21 = 0x57,
    MsgUserReliableOrdered22 = 0x58,
    MsgUserReliableOrdered23 = 0x59,
    MsgUserReliableOrdered24 = 0x5A,
    MsgUserReliableOrdered25 = 0x5b,
    MsgUserReliableOrdered26 = 0x5c,
    MsgUserReliableOrdered27 = 0x5d,
    MsgUserReliableOrdered28 = 0x5e,
    MsgUserReliableOrdered29 = 0x5f,
    MsgUserReliableOrdered30 = 0x60,
    MsgUserReliableOrdered31 = 0x61,
    MsgUserReliableOrdered32 = 0x62,
    MsgUserUnordered = 0x22
};

#endif // MESSAGEINFO_H
