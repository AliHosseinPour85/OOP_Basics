#ifndef GPS_HPP
#define GPS_HPP


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
