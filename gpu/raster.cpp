//
// Created by scc on 2025/8/28.
//
#include "raster.h"

Raster::Raster() {}

Raster::~Raster() {}

void Raster::rasterizeLine(
    std::vector<Point>& results,
    const Point& v0, const Point& v1)
{
    int xStart = v0.x, xEnd = v1.x, yStart = v0.y, yEnd = v1.y;
    bool flipY = false, swapXY = false;

    if(xStart > xEnd)
    {
        std::swap(xStart, xEnd);
        std::swap(yStart, yEnd);
    }

    if(yStart > yEnd)
    {
        flipY = true;
        yStart = -yStart, yEnd = -yEnd;
    }

    int deltaX = xEnd - xStart, deltaY = yEnd - yStart;

    if(deltaY > deltaX)
    {
        std::swap(xStart, yStart);
        std::swap(xEnd, yEnd);
        std::swap(deltaX, deltaY);
        swapXY = true;
    }

    int xResult = xStart, yResult = yStart;

    int p = 2 * deltaY - deltaX;

    while(xStart < xEnd)
    {
        xResult = xStart, yResult = yStart;

        if(swapXY)
        {
            std::swap(xResult, yResult);
        }

        if(flipY)
        {
            yResult = -yResult;
        }

        results.push_back(Point{xResult, yResult});

        ++xStart;
        if(p >= 0)
        {
            yStart += 1;
            p = p - 2 * deltaX;
        }

        p = p + 2 * deltaY;
    }

    results.push_back(Point{xEnd, yEnd});
}