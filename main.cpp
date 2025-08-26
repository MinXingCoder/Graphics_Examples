//
// Created by scc on 2025/8/24.
//
#include "application.h"
#include "gpu.h"
#include <cstdlib>

void render()
{
    sgl->clear();

    for(uint32_t i = 0; i < winApp->getWidth(); ++i)
    {
        for(uint32_t j = 0; j < winApp->getHeight(); ++j)
        {
            uint32_t v = std::rand() % 255;
            RGBA color(v, v, v, v);
            sgl->drawPoint(i, j, color);
        }
    }
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