#ifndef EVENT_HPP
#define EVENT_HPP

#include <string>
#include <ctime>

class Event
{
public:
    std::string name;
    std::time_t start_time;
    std::time_t end_time;

public:
    Event(const std::string &event_name, std::time_t start, std::time_t end);
};

#endif