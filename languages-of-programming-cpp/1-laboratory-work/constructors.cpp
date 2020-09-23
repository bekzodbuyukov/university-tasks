//
// Created by bek on 18.09.2020.
//

#include "header.h"

// BEGIN: STABLE CODE

// default constructor
TPatient::TPatient() {
    setFullName("фио пациента");
    setYearOfBirth(2020);
    setMedicineCardNumber(0);
    setDiagnosis("диагноз пациента");
}

// constructor with parameters
TPatient::TPatient(const string& fullName, int yearOfBirth, int medicineCardNumber, const string& patientDiagnosis) {
    setFullName(fullName);
    setYearOfBirth(yearOfBirth);
    setMedicineCardNumber(medicineCardNumber);
    setDiagnosis(patientDiagnosis);
}

// copying constructor
TPatient::TPatient(const TPatient &T) {
    setFullName(T.getFullName());
    setYearOfBirth(T.getYearOfBirth());
    setMedicineCardNumber(T.getMedicineCardNumber());
    setDiagnosis(T.getDiagnosis());
}

// Getters
const string &TPatient::getFullName() const {
    return fullName;
}

int TPatient::getYearOfBirth() const {
    return yearOfBirth;
}

int TPatient::getMedicineCardNumber() const {
    return medicineCardNumber;
}

const string &TPatient::getDiagnosis() const {
    return diagnosis;
}

// Setters
void TPatient::setFullName(const string &newFullName) {
    fullName = newFullName;
}

void TPatient::setYearOfBirth(int newYearOfBirth) {
    yearOfBirth = newYearOfBirth;
}

void TPatient::setMedicineCardNumber(int newMedicineCardNumber) {
    medicineCardNumber = newMedicineCardNumber;
}

void TPatient::setDiagnosis(const string &newDiagnosis) {
    TPatient::diagnosis = newDiagnosis;
}

// END: STABLE CODE

// destructor [is not needed]