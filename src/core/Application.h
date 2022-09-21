#pragma once

#include "Events.h"
#include "Window.h"

#include <memory>

class Application {
public:
    Application();

    void run();

    void onWindowClose(const Event& event);

private:
    Events m_events;
    std::unique_ptr<Window> m_window;

    bool m_isRunning = false;
};
