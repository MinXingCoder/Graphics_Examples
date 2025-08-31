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
    Point start = v0, end = v1;
    bool flipY = false, swapXY = false;

    if(start.x > end.x)
    {
        std::swap(start, end);
    }

    if(start.y > end.y)
    {
        start.y *= -1;
        end.y *= -1;
        flipY = true;
    }

    int deltaX = end.x - start.x, deltaY = end.y - start.y;

    if(deltaY > deltaX)
    {
        std::swap(start.x, start.y);
        std::swap(end.x, end.y);
        std::swap(deltaX, deltaY);
        swapXY = true;
    }

    int xResult = start.x, yResult = start.y;

    int p = 2 * deltaY - deltaX;

    int xCurrent = start.x, yCurrent = start.y;

    while(xCurrent < end.x)
    {
        xResult = xCurrent, yResult = yCurrent;

        if(swapXY)
        {
            std::swap(xResult, yResult);
        }

        if(flipY)
        {
            yResult = -yResult;
        }

        Point target{xResult, yResult};
        interpolantLine(start, end, target);
        results.push_back(target);

        ++xCurrent;
        if(p >= 0)
        {
            yCurrent += 1;
            p = p - 2 * deltaX;
        }

        p = p + 2 * deltaY;
    }

    results.push_back(end);
}

void Raster::interpolantLine(const Point& v0, const Point& v1, Point& target)
{
    float weight = 0.0f;

    if(v0.x != v1.x)
    {
        weight = static_cast<float>(target.x - v0.x) / (v1.x - v0.x);
    } else if(v0.y != v1.y)
    {
        weight = static_cast<float>(target.y - v0.y) / (v1.y - v0.y);
    }

    target.color.mR = static_cast<byte>(static_cast<float>(v0.color.mR) * (1 - weight) +
                      static_cast<float>(v1.color.mR) * weight);
    target.color.mG = static_cast<byte>(static_cast<float>(v0.color.mG) * (1 - weight) +
                      static_cast<float>(v1.color.mG) * weight);
    target.color.mB = static_cast<byte>(static_cast<float>(v0.color.mB) * (1 - weight) +
                      static_cast<float>(v1.color.mB) * weight);
    target.color.mA = static_cast<byte>(static_cast<float>(v0.color.mA) * (1 - weight) +
                      static_cast<float>(v1.color.mA) * weight);
}
