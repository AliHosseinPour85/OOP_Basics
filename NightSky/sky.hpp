#ifndef SKY_HPP
#define SKY_HPP

#include "star.hpp"
#include <vector>
#include <iostream>

class Sky {
private:
    std::vector<Star> stars; 
    int width; 
    int height; 

public:
    Sky(int width, int height);

    void add_star(const Star& star);
};

#endif