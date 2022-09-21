#include "Window.h"

#define GLFW_INCLUDE_NONE

#include <GLFW/glfw3.h>
#include <stdexcept>

Window::Window(const WindowDescriptor& descriptor) {
    if (!glfwInit()) {
        throw std::runtime_error("Failed to initialize GLFW");
    }

    glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);

    m_handle = glfwCreateWindow(descriptor.width, descriptor.height, descriptor.title,
                                descriptor.fullscreen ? glfwGetPrimaryMonitor() : nullptr, nullptr);
    if (!m_handle) {
        throw std::runtime_error("Failed to create window");
    }
}

bool Window::shouldClose() const {
    return glfwWindowShouldClose(m_handle);
}

Window::~Window() {
    glfwDestroyWindow(m_handle);
    glfwTerminate();
}

void Window::pollEvents() {
    glfwPollEvents();
}

