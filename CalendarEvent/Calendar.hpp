#ifndef CALENDAR_HPP
#define CALENDAR_HPP

#include "Event.hpp"
#include <vector>
#include <ctime>

class Calendar {
private:
    std::vector<Event> events;
    static int n ;
public:
    
    void add_event(const std::string& name, std::time_t start, std::time_t end, std::time_t Now);
    void refresh();
    void Delete_event(int);
    void save_events();
    void load_file();
    
    ~Calendar();
};

#endif