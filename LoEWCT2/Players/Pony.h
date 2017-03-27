#ifndef PONY_H
#define PONY_H

#include "Player.h"

class Player;

/**
 * @brief The Pony class
 *
 * Secondary player class, the Map server handles it.
 */
class Pony
{
public:
    enum PonyType
    {
        All = 15,
        None = 0,
        EarthPony = 1,
        Pegasus = 4,
        Unicorn = 2,
        Moose = 8
    } type;

    int id;
    int netviewId;
    Player* owner;
    QString name;
    QString ponyData;
    quint32 bits;

    Pony();


};

#endif // PONY_H
