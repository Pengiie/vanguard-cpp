#include "core/Window.h"

int main() {
    WindowDescriptor descriptor{};
    descriptor.title = "Vanguard";
    descriptor.width = 800;
    descriptor.height = 600;

    Window window(descriptor);
    while (!window.shouldClose()) {
        Window::pollEvents();

    }
    return 0;
}
