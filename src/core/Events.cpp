#include "Events.h"

void Events::submitEvent(const Event& event) {
    if (auto it = m_eventListeners.find(event.type()); it != m_eventListeners.end()) {
        for (const auto& listener: it->second) {
            listener(event);
        }
    }
}

template<typename T>
void Events::registerListener(const std::function<void(const T&)>& listener) {
    m_eventListeners[T::type()].push_back(listener);
}
