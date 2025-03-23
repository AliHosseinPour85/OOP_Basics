#include "hospital.hpp"
#include <iostream>

int main()
{
    Hospital hospital;

    hospital.addPatient(Patient("Babak", 36.5, 75, 18, 110, 32));
    hospital.addPatient(Patient("Hossein", 37.0, 5, 20, 115, 25));

    hospital.listPatients();

    return 0;
}