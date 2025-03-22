#include "star.hpp"

Star::Star(int x, int y, int brightness, const std::string &color)
    : x(x), y(y), brightness(brightness), color(color) {}

int Star::get_x() const
{
    return x;
}
int Star::get_y() const
{
    return y;
}

