#include "Calendar.hpp"
#include <iostream>

int main() {
    Calendar calendar;
    
    std::time_t Now = time(nullptr);
    
    calendar.add_event("playing", Now , Now + 8400);
    calendar.add_event("Meeting", Now , Now + 8);  
    calendar.add_event("Lunch", Now , Now + 3600);  

    calendar.load_file();
    
    calendar.refresh();

    calendar.save_events();

    return 0;
}