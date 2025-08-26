//
// Created by scc on 2025/8/25.
//
#include "frameBuffer.h"

FrameBuffer::FrameBuffer(uint32_t width, uint32_t height, void* buffer)
{
    mWidth = width;
    mHeight = height;

    if(!buffer)
    {
        buffer = new RGBA[width * height];
        mExternalBuffer = false;
    }
    else
    {
        mExternalBuffer = true;
    }

    mColorBuffer = (RGBA*)buffer;
}

FrameBuffer::~FrameBuffer()
{
    if(!mExternalBuffer && mColorBuffer)
    {
        delete[] mColorBuffer;
    }
}
