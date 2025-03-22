#ifndef SKY_HPP
#define SKY_HPP

#include <vector>
#include "star.hpp"

class Sky {
private:
    std::vector<Star> stars;  

public:
    void addStar(const Star& star);

    void render() const;
};

#endif