#include "Calendar.hpp"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <chrono>

int Calendar::n = 0;

void Calendar::add_event(const std::string &name, std::time_t start, std::time_t end, std::time_t Now)
{
    while (start < Now)
    {
        std::time_t s;
        std::cerr << "Enter correct start time(second) : " << std::endl ;
        std::cin >> s;
        start = Now + s;
    }
    
    
    for (const auto &event : events)
    {
        if ((start < event.end_time && end > event.start_time))
        {
            std::cout << "Event \"" << name << "\" has been added.\n";
            std::cout << "Event \"" << name << "\" has conflict with \"" << event.name << "\".\n";
            events.push_back(Event(name, start, end));
            n++;
            return;
        }
    }
    events.push_back(Event(name, start, end));
    n++;
    std::cout << "Event \"" << name << "\" has been added.\n";

}

void Calendar::refresh()
{
    std::time_t current_time = time(nullptr);
    
    for (size_t i = 0 ; i< n ; i++)
    {
        if (events[i].end_time < current_time)
        {
            std::cout << "\tEvent \"" << events[i].name << "\" has expired and will be removed." << std::endl;
            
            Delete_event(i);
            
            i--;
        }
    }
}

void Calendar::Delete_event( int i){
    for (size_t j = i ; j < n-1; j++)
    {
        events[j].name = events[j+1].name;
        events[j].start_time = events[j+1].start_time;
        events[j].end_time = events[j+1].end_time;
        
    }
    events.pop_back();
    n--;
}

void Calendar::save_events()
{
    std::ofstream file("events.txt");
    if (!file.is_open())
    {
        return;
    }

    if (events.empty())
    {
        file << "No events in the calendar." << std::endl;
    }
    else
    {
        for (const auto &event : events)
        {
            file << event.name << "\t" << event.start_time << '\t' << event.end_time << "\n";
        }
    }

    file.close();
}

void Calendar::load_file() {
    std::ifstream file("events.txt");
    if (!file.is_open()) {
        return;
    }

    std::string name;
    std::time_t start_time;
    std::time_t end_time;

    while (file >> name >> start_time >> end_time) {
        events.push_back(Event(name, start_time, end_time));
        n++;
    }

    file.close();
}

Calendar::~Calendar(){
    
    for (size_t i = 0; i < n; i++) {
        time_t Stime = events[i].start_time; // for better print
        time_t Etime = events[i].end_time; // for better print
        std::cout <<"----------------------------" << std::endl << "Event Name       : " 
                  << events[i].name << std::endl 
                  << "Event Start Time : " << ctime(&Stime) 
                  << "Event End Time   : " << ctime(&Etime) ;
    }

}