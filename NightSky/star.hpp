#ifndef STAR_HPP
#define STAR_HPP

#include <raylib.h>

class Star {
private:
    int x, y;          
    float brightness;  
    Color color;       
public:
    Star(int x, int y, float brightness, Color color);

    int getX() const;
    int getY() const;
    float getBrightness() const;
    Color getColor() const;

};

#endif