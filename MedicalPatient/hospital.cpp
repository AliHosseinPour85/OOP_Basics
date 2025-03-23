#include "hospital.hpp"
#include <fstream>
#include <iostream>


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

