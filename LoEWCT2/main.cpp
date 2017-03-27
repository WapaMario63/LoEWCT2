#include <stdio.h>
#include <QApplication>
#include <QTranslator>
#include "Servers/MasterServer.h"

int argc = 0;
QApplication app(argc, (char**)0);

void printHeader()
{

    printf("********************************************************************************");
    printf("* ==============================   LoEWCT2   ================================= *");
    printf("* =========================   LoE Private Server   =========================== *");
    printf("* ==============================   v0.0.1a   ================================= *");
    printf("********************************************************************************\n");

    printf("* By WapaMario63\n\n");

}

int main(int, char**)
{
    printHeader();

    // Because I want to keep things neat in the filesystem.
    app.addLibraryPath("bin");

    app.processEvents();

    MasterServer* server = new MasterServer();
    server->startServer();

    return app.exec();
}
