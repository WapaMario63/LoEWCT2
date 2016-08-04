#ifndef MASTERSERVER_H
#define MASTERSERVER_H

#include <LoEWCTServer/Server.h>

class MasterServer : public Server
{
public:
    MasterServer();

    void LoadConfig();

    void Start();
    void Restart();
    void Stop();

public:
    bool running;
    QString name;
    QString status;
    Server* server;
};

extern MasterServer loeServer;

#endif // MASTERSERVER_H
