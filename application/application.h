//
// Created by scc on 2025/8/24.
//
#pragma once
#include <stdint.h>

class GLFWwindow;
#define winApp Application::getInstance()

class Application
{
public:
    static Application* getInstance();
    Application();
    ~Application();

    bool initApplication(const uint32_t& width = 800, const uint32_t& height = 600);

    void close();

    bool peekMessage();

    void beginFrame();

    void endFrame();

    uint32_t getWidth() const;

    uint32_t getHeight() const;

private:
    GLFWwindow* mWindow { nullptr };

    uint32_t mWidth { 0 };
    uint32_t mHeight { 0 };
};