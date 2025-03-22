#include "star.hpp"

Star::Star(int Tol, int Arz, float Nor, Color Rang) {
    x = Tol;
    y = Arz;
    brightness = Nor;
    color = Rang;
}

int Star::getX() const { return x; }
int Star::getY() const { return y; }
float Star::getBrightness() const { return brightness; }
Color Star::getColor() const { return color; }
