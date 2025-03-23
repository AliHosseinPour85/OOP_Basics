#include "patient.hpp"
#include <iostream>
#include <vector>

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


std::string Patient::serialize() const {
    std::string data = xorCipher(name, 'K') + "," +
                       std::to_string(bodyTemperature) + "," +
                       std::to_string(heartRate) + "," +
                       std::to_string(respiratoryRate) + "," +
                       std::to_string(bloodPressure) + "," +
                       std::to_string(age);
    return data;
}

Patient Patient::deserialize(const std::string& data) {
    std::vector<std::string> info;
    std::string patientInformation;
    
    for (char ch : data) {
        if (ch == ',') {
            info.push_back(patientInformation);
            patientInformation.clear(); 
        } else {
            patientInformation += ch; 
        }
    }
    info.push_back(patientInformation); 

    if (info.size() != 6) {
        throw std::invalid_argument("Invalid patient data format!");
    }

    std::string encryptedName = info[0];
    float temp = std::stof(info[1]); 
    int hr = std::stoi(info[2]);    
    int rr = std::stoi(info[3]);    
    int bp = std::stoi(info[4]);    
    int age = std::stoi(info[5]);   

    std::string name = xorCipher(encryptedName, 'K');
    
    return Patient(name, temp, hr, rr, bp, age);
}