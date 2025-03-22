#include "sky.hpp"
#include <raylib.h>
#include <iostream>

void Sky::addStar(const Star& star) {
    stars.push_back(star);
}

void Sky::display() const {
    for (const auto& star : stars) {
        if (GetScreenWidth() < star.getX())
        {
            std::cout << "Star at (" << star.getX() << " , " << star.getY() << ") is out of sky!!!";
            return;
        }
        if (GetScreenHeight() < star.getY())
        {
            std::cout << "Star is out of sky!!!";
            return;
        }
        
        std::cout << "Star at (" << star.getX() << " , " << star.getY() << ") "
                  << "Brightness: " << star.getBrightness() << std::endl;
    }
}

void Sky::render() const {
    for (const auto& star : stars) {
        DrawCircle(star.getX(), star.getY(), 5 * star.getBrightness(), star.getColor());
    }
}