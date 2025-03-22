#include "sky.hpp"
#include <raylib.h>
#include <iostream>

void Sky::addStar(const Star& star) {
    stars.push_back(star);
}


void Sky::render() const {
    for (const auto& star : stars) {
        DrawCircle(star.getX(), star.getY(), 5 * star.getBrightness(), star.getColor());
    }
}

