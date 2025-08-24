//
// Created by scc on 2025/8/24.
//
#include "application.h"

int main()
{
    if(!winApp->initApplication(800, 600))
    {
        return -1;
    }

    while(!winApp->peekMessage())
    {
        winApp->beginFrame();
        winApp->endFrame();
    }

    winApp->close();
}