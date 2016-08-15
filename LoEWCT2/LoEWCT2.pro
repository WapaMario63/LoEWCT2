QT += core network

CONFIG += console
CONFIG += c++11

SOURCES += \
    main.cpp \
    Player/Player.cpp \
    LoEWCTRoom/Room.cpp \
    LoEWCTServer/ProcessUdp.cpp \
    LoEWCTServer/Server.cpp \
    LoEWCT/MasterServer.cpp \
    Utilities/serialize.cpp \
    Utilities/DataType.cpp \
    LoEWCTServer/MessageMgr.cpp

HEADERS += \
    MessageInfo.h \
    Player/Player.h \
    LoEWCTRoom/Room.h \
    LoEWCTServer/Server.h \
    LoEWCT/MasterServer.h \
    Utilities/serialize.h \
    Utilities/DataType.h \
    LoEWCTServer/MessageMgr.h
