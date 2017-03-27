#ifndef PLAYER_H
#define PLAYER_H

#include <QObject>
#include <QList>
#include "Pony.h"

class Pony;

/**
 * @brief The Player class
 *
 * Main player class, the master server handles it.
 */
class Player : public QObject
{
    Q_OBJECT
public:
    int id;
    QString IP;
    quint16 port;
    QString name;
    QString passhash;
    float lastPingTime;
    int lastPingNumber;
    bool isConnected;
    quint8 ingame;
    quint16 receivedPacketDups;
    QList<Pony*> ponies;

    Player();

    void reset();
    void resetNetwork();

    static void savePonies(Player* player, QList<Pony*> ponies);
    static void savePlayerData(Player* player, QList<Pony*> ponies);
    static QList<Pony*> loadPonies(Player* player);
};

#endif // PLAYER_H
