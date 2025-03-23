#ifndef HOSPITAL_HPP
#define HOSPITAL_HPP

#include <vector>
#include <string>
#include "patient.hpp"

class Hospital
{
private:
    std::vector<Patient> patients;

public:

    void addPatient(const Patient &patient);
    void listPatients() const;

};

#endif