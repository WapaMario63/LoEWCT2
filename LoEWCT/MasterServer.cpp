#include "MasterServer.h"

MasterServer::MasterServer()
{
    server = new Server();
    name = "LoEWCT2 Test Server";
    status = "Offline";
    running = false;

}

void MasterServer::Start()
{
    if (!running || server != nullptr)
    {
        server->Initialize();
        status = "Online";
        running = true;

        printf("Status %s\n", status.toStdString().c_str());



    }
    else
    {
        // Server is already running
        return;
    }
}
