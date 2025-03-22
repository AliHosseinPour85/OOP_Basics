#ifndef GPS_HPP
#define GPS_HPP

#include <iostream>

class Position
{
private:
    double latitude;
    double longitude;

public:
    Position(double lat, double lon);
    ~Position();
};

#endif
