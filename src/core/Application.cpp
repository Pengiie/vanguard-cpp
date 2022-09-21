#include "Application.h"

Application::Application() {
    WindowDescriptor descriptor{};
    descriptor.title = "Vanguard";
    descriptor.width = 800;
    descriptor.height = 600;
    m_window = std::make_unique<Window>(descriptor);

    m_events.registerListener<WindowCloseEvent>([this](const WindowCloseEvent& event) {
        m_isRunning = false;
    });
}

void Application::run() {
    m_isRunning = true;

    while (m_isRunning) {
        m_window->pollEvents();
    }
}

void Application::onWindowClose(const Event& event) {

}


