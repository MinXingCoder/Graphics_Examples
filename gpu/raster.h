//
// Created by scc on 2025/8/28.
//
#pragma once
#include <vector>
#include "../global/base.h"

class Raster
{
public:
    Raster();
    ~Raster();

    static void rasterizeLine(
        std::vector<Point>& results,
        const Point& v0,
        const Point& v1
    );
};
