#include <gps.hpp>
#include <fstream>

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
    if (n > 0)
    {
        std::ofstream file("log.txt");
        if (file.is_open())
        {
            file << "Last latitude : " << latitude << '\t' << "Last longitude : " << longitude << std::endl;
            file.close();
            std::cout << "File saved successfully to " << "log.txt" << std::endl;
        }
        else
        {
            std::cerr << "Error: Could not open file " << "log.txt" << " for writing." << std::endl;
        }
        std::cout << "Last latitude : " << latitude << '\t' << "Last longitude : " << longitude << std::endl;
        n = 0;
    }
}