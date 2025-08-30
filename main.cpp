//
// Created by scc on 2025/8/24.
//
#include "application.h"
#include "gpu.h"
#include <cstdlib>

void render()
{
    sgl->clear();

    Point p1{100, 100};
    Point p2{500, 600};

    sgl->drawLine(p1, p2);
}

int main()
{
    if(!winApp->initApplication(800, 600))
    {
        return -1;
    }

    sgl->initSurface(winApp->getWidth(), winApp->getHeight(),
        winApp->getFrameBuffer());

    while(!winApp->peekMessage())
    {
        winApp->beginFrame();
        render();
        winApp->show();
        winApp->endFrame();
    }

    winApp->close();
}