#ifndef MASTERSERVER_H
#define MASTERSERVER_H

#include "Server.h"
#include "Players/Player.h"
#include "MapServer.h"
#include <QList>

/**
 * @brief The MasterServer class
 *
 */
class MasterServer : public Server
{
public:
    QList<Player*> players;
    QList<MapServer*> mapRooms;

    MasterServer();

    ~MasterServer();

    virtual void startServer() override;
    virtual void stopServer() override;
private:
    /**
     * @brief CreateMapServersFromVortex
     *
     * Reads all files in the vortex folder, loads each map info and then creates a map server for each of them.
     */
    void CreateMapServersFromVortex();
public slots:
    virtual void processPendingDatagrams() override;
};

#endif // MASTERSERVER_H
