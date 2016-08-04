#include <stdio.h>

#include "LoEWCT/MasterServer.h"

MasterServer loeServer;

int main(int argc, char** argv)
{
    printf("start\n");

    loeServer.Start();

    return 0;
}
