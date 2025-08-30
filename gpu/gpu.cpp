//
// Created by scc on 2025/8/26.
//
#include "gpu.h"
#include "raster.h"
#include <algorithm>

GPU* GPU::getInstance()
{
    static GPU instance;
    return &instance;
}

GPU::GPU() {}

GPU::~GPU()
{}

void GPU::initSurface(const uint32_t& width, const uint32_t& height, void* buffer)
{
    mFrameBuffer = (FrameBuffer*)buffer;
}

void GPU::clear()
{
    size_t pixelSize = mFrameBuffer->mWidth * mFrameBuffer->mHeight;
    std::fill_n(mFrameBuffer->mColorBuffer, pixelSize, RGBA(0, 0, 0, 0));
}

void GPU::drawPoint(const uint32_t& x, const uint32_t& y, const RGBA& color)
{
    if(x >= mFrameBuffer->mWidth || y >= mFrameBuffer->mHeight)
        return;
    uint32_t pixelPos = (mFrameBuffer->mHeight - 1 - y) * mFrameBuffer->mWidth + x;
    mFrameBuffer->mColorBuffer[pixelPos] = color;
}

void GPU::drawLine(const Point& p1, const Point& p2)
{
    std::vector<Point> results;
    Raster::rasterizeLine(results, p1, p2);

    for(int i = 0; i < results.size(); ++i)
    {
        drawPoint(results[i].x, results[i].y, results[i].color);
    }
}
