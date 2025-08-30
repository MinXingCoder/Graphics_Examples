//
// Created by scc on 2025/8/24.
//
#pragma once
#include <cstdint>

#define PI                3.14159265358979323
#define DEG2RAD(theta)    (0.01745329251994329 * (theta))
#define FRACTION(v)       ((v) - (int)(v))

using byte = unsigned char;

struct RGBA
{
    byte mR;
    byte mG;
    byte mB;
    byte mA;

    RGBA(byte r = 255, byte g = 255, byte b = 255, byte a = 255)
    {
        mR = r; mG = g; mB = b; mA = a;
    }
};

struct Point
{
    int32_t x;
    int32_t y;
    RGBA color;
};