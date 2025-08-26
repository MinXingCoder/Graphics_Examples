//
// Created by scc on 2025/8/26.
//
#include "gpu.h"
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
    uint32_t pixelPos = (mFrameBuffer->mHeight - y) * mFrameBuffer->mWidth + x;
    mFrameBuffer->mColorBuffer[pixelPos] = color;
}
