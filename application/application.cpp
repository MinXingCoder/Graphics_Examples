//
// Created by scc on 2025/8/24.
//
#include "application.h"
#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl2.h"
#include <GLFW/glfw3.h>
#include <stdio.h>

Application* Application::getInstance()
{
    static Application app;
    return &app;
}

Application::Application() {}
Application::~Application() {}

static void glfw_error_callback(int error, const char* description)
{
    fprintf(stderr, "GLFW Error %d: %s\n", error, description);
}

bool Application::initApplication(const uint32_t& width, const uint32_t& height)
{
    mWidth = width;
    mHeight = height;

    glfwSetErrorCallback(glfw_error_callback);

    if(!glfwInit())
        return false;

    mWindow = glfwCreateWindow(mWidth, mHeight, "SoftRenderer Example", nullptr, nullptr);
    if(!mWindow)
        return false;

    glfwMakeContextCurrent(mWindow);
    glfwSwapInterval(1);                // Enable vsync

    // Setup Dear ImGui context
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();

    // Setup Dear ImGui Style
    ImGui::StyleColorsDark();

    ImGui_ImplGlfw_InitForOpenGL(mWindow, true);
    ImGui_ImplOpenGL2_Init();

    return true;
}

void Application::close()
{
    ImGui_ImplOpenGL2_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();

    glfwDestroyWindow(mWindow);
    glfwTerminate();
}

bool Application::peekMessage()
{
    bool alive = glfwWindowShouldClose(mWindow);
    glfwPollEvents();
    return alive;
}

void Application::beginFrame()
{
    ImGui_ImplOpenGL2_NewFrame();
    ImGui_ImplGlfw_NewFrame();
    ImGui::NewFrame();

    ImGui::Begin("SoftRender");
}

void Application::endFrame()
{
    ImGui::End();

    ImGui::Render();
    glViewport(0, 0, mWidth, mHeight);
    glClear(GL_COLOR_BUFFER_BIT);

    ImGui_ImplOpenGL2_RenderDrawData(ImGui::GetDrawData());
    glfwMakeContextCurrent(mWindow);
    glfwSwapBuffers(mWindow);
}

uint32_t Application::getWidth() const
{
    return mWidth;
}

uint32_t Application::getHeight() const
{
    return mHeight;
}