#include "patient.hpp"
#include <iostream>


std::string Patient::xorCipher(const std::string& data, char key) {
    std::string result = data;
    for (size_t i = 0; i < data.size(); ++i) {
        result[i] = data[i] ^ key;
    }
    return result;
}

Patient::Patient(const std::string& name, float temp, int hr, int rr, int bp, int age)
    : name(name), bodyTemperature(temp), heartRate(hr), respiratoryRate(rr), bloodPressure(bp), age(age) {}



std::string Patient::getName() const { return name; }
float Patient::getBodyTemperature() const { return bodyTemperature; }
int Patient::getHeartRate() const { return heartRate; }
int Patient::getRespiratoryRate() const { return respiratoryRate; }
int Patient::getBloodPressure() const { return bloodPressure; }
int Patient::getAge() const { return age; }


