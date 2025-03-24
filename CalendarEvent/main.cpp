#include "Calendar.hpp"
#include <iostream>

int main() {
    Calendar calendar;
    
    std::time_t Now = time(nullptr);
    
    calendar.add_event("playinggggg", Now , Now + 8400 , Now);
    calendar.add_event("Meetingggg", Now + 100 , Now + 8 , Now);  
    calendar.add_event("Lunchhhhh", Now , Now + 3600 , Now);  

    calendar.load_file();
    
    calendar.refresh();

    calendar.save_events();

    return 0;
}