#ifndef STAR_HPP
#define STAR_HPP

#include <string>

class Star {
private:
    int x; 
    int y; 
    int brightness; 
    std::string color; 

public:
    Star(int x, int y, int brightness, const std::string& color);

    
    int get_x() const;
    int get_y() const;

};

#endif