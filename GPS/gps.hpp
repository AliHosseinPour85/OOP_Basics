#ifndef GPS_HPP
#define GPS_HPP

#include <iostream>

class Position
{
private:
    double latitude;
    double longitude;
    static int n;//it use for last position

public:
    Position(double lat, double lon);
    ~Position();
};

#endif
