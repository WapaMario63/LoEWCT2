QT += core network gui widgets

CONFIG += console
CONFIG += c++11

SOURCES += \
    main.cpp \
    Utilities/serialize.cpp \
    Utilities/DataType.cpp \
    Server.cpp \
    Servers/MasterServer.cpp \
    Players/Player.cpp \
    Players/Pony.cpp \
    Servers/MapServer.cpp \
    Servers/RoomServer.cpp

HEADERS += \
    MessageInfo.h \
    Utilities/serialize.h \
    Utilities/DataType.h \
    Server.h \
    Servers/MasterServer.h \
    Players/Player.h \
    Players/Pony.h \
    Servers/MapServer.h \
    Servers/RoomServer.h

FORMS +=
