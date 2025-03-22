#include <gps.hpp>

Position::Position(double lat, double lon)
{
    if (lat < -90.0 || lat > 90.0)
    {
        std::cerr << "Latitude must be between -90 and 90." << std::endl;
        return;
    }
    if (lon < -180.0 || lon > 180.0)
    {
        std::cerr << "Longitude must be between -180 and 180." << std::endl;
        return;
    }

    latitude = lat;
    longitude = lon;

    std::cout << "Latitude: " << latitude << ", Longitude: " << longitude << std::endl;
}

Position::~Position(){
    
}