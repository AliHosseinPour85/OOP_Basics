#ifndef HOSPITAL_HPP
#define HOSPITAL_HPP

#include <vector>
#include <string>
#include "patient.hpp"

class Hospital
{
private:
    std::vector<Patient> patients;
    std::string filename = "patients.dat";

    void loadPatients();
    void savePatients() const;

public:
    Hospital();

    void addPatient(const Patient &patient);
    void listPatients() const;

    ~Hospital();
};

#endif