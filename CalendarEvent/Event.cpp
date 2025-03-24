#include "Event.hpp"
#include <iostream>

Event::Event(const std::string &event_name, std::time_t start, std::time_t end)
    : name(event_name), start_time(start), end_time(end) {}
