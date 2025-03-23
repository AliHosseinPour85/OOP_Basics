#ifndef PATIENT_HPP
#define PATIENT_HPP

#include <string>
#include <vector>

class Patient
{
private:
    std::string name;
    float bodyTemperature;
    int heartRate;
    int respiratoryRate;
    int bloodPressure;
    int age;

    static std::string xorCipher(const std::string& data, char key);

public:
    Patient(const std::string &name, float temp, int hr, int rr, int bp, int age);

    std::string getName() const;
    float getBodyTemperature() const;
    int getHeartRate() const;
    int getRespiratoryRate() const;
    int getBloodPressure() const;
    int getAge() const;
    
};

#endif