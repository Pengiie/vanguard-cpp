#pragma once

#include <GLFW/glfw3.h>
#include "Events.h"

struct WindowDescriptor {
    const char* title;
    int width;
    int height;
    bool fullscreen;
    bool vsync;
};

class Window {
public:
    explicit Window(const WindowDescriptor& descriptor);

    bool shouldClose() const;

    static void pollEvents();

    ~Window();

private:
    GLFWwindow* m_handle;
};

struct WindowCloseEvent : public Event {
    static constexpr EventType name = "WindowClose";

    EventType type() const override {
        return name;
    }
};
