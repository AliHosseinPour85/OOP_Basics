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

Patient::Patient(const std::string& name, float temp, int hr, int rr, int bp, int a)
    : name(name), bodyTemperature(temp), heartRate(hr), respiratoryRate(rr), bloodPressure(bp), age(a) {
    while (temp < 0)
    {
        std::cout << "Enter correct Body Temperature!!!!" << std::endl;
        std::cin >> temp ;
        bodyTemperature = temp ;
    }

    while (hr < 0)
    {
        std::cout << "Enter correct Heart Rate!!!!" << std::endl;
        std::cin >> hr ;
        heartRate = hr ;
    }

    while (rr < 0){
        std::cout << "Enter correct Respiratory Rate!!!!" << std::endl;
        std::cin >> rr ;
        respiratoryRate = rr ;
    }

    while (bp < 0){
        std::cout << "Enter correct Blood Pressure!!!!" << std::endl;
        std::cin >> bp ;
        bloodPressure = bp ;
    }

    while (a < 0){
        std::cout << "Enter correct Age!!!!" << std::endl;
        std::cin >> a ;
        age = a ;
    }
    
    if (!isTemperatureNormal()) {
        std::cerr << "Warning: Patient " << name << " has abnormal Body Temprature!" << std::endl;
    }
    if (!isHeartRateNormal()) {
        std::cerr << "Warning: Patient " << name << " has abnormal Heart Rate!" << std::endl;
    }
    if (!isRespiratoryRateNormal()) {
        std::cerr << "Warning: Patient " << name << " has abnormal Respiratory Rate!" << std::endl;
    }
    if (!isBloodPressureNormal()) {
        std::cerr << "Warning: Patient " << name << " has abnormal Blood Pressure!" << std::endl;
    }
}

bool Patient::isTemperatureNormal() const {
    return bodyTemperature >= 36.0 && bodyTemperature <= 37.5;
}

bool Patient::isHeartRateNormal() const {
    return heartRate >= 60 && heartRate <= 100;
}

bool Patient::isRespiratoryRateNormal() const {
    if (age < 1) return respiratoryRate >= 30 && respiratoryRate <= 50; 
    if (age >= 1 && age <= 5) return respiratoryRate >= 20 && respiratoryRate <= 30; 
    if (age >= 6 && age <= 12) return respiratoryRate >= 15 && respiratoryRate <= 25;
    return respiratoryRate >= 12 && respiratoryRate <= 20; 
}

bool Patient::isBloodPressureNormal() const {
    return bloodPressure >= 80 && bloodPressure <= 120;
}

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