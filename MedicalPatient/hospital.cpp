#include "hospital.hpp"
#include <fstream>
#include <iostream>


void Hospital::loadPatients()
{
    std::ifstream file(filename, std::ios::in);
    if (!file)
    {
        return;
    }

    std::string line;
    while (std::getline(file, line))
    {
        try
        {
            patients.push_back(Patient::deserialize(line));
        }
        catch (const std::invalid_argument &e)
        {
            std::cerr << "Error loading patient data: " << e.what() << std::endl;
        }
    }
    file.close();
}

Hospital::Hospital()
{
    loadPatients();
}

void Hospital::addPatient(const Patient &patient)
{
    patients.push_back(patient);
}

void Hospital::listPatients() const
{
    std::cout << "Patients in the hospital:" << std::endl;
    for (const auto &patient : patients)
    {
        std::cout << "-------------------------\n"
                  << "Name: " << patient.getName()
                  << "\n- Temperature: " << patient.getBodyTemperature()
                  << "\n- Heart Rate: " << patient.getHeartRate()
                  << "\n- Respiratory Rate: " << patient.getRespiratoryRate()
                  << "\n- Blood Pressure: " << patient.getBloodPressure()
                  << "\n- Age: " << patient.getAge() << std::endl;
    }
}


void Hospital::savePatients() const
{
    std::ofstream file(filename, std::ios::out);
    if (!file)
    {
        std::cerr << "Error saving patient data!" << std::endl;
        return;
    }

    for (const auto &patient : patients)
    {
        file << patient.serialize() << std::endl;
    }
    file.close();
}

Hospital::~Hospital()
{
    savePatients();
}