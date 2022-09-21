#pragma once

#include <map>
#include <vector>
#include <functional>

struct Event {
    using EventType = const char*;

    virtual EventType getType() const = 0;

    static EventType type(const Event& event) {
        return event.getType();
    }
};

class Events {
public:
    template<typename T>
    void registerListener(const std::function<void(const T&)>& listener);

    void submitEvent(const Event& event);

private:
    std::map<Event::EventType, std::vector<std::function<void(const Event&)>>> m_eventListeners;
};