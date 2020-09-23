#ifndef INC_1_LAB_HEADER_H
#define INC_1_LAB_HEADER_H

#include <iostream>
#include <fstream>
#include <istream>
#include <iomanip>
#include <cstring>
using namespace std;

// lab-1, opt-2

// Structure for temporally saving data in it before saving to TPatient Class
struct TPatientStruct {
    string fullName;
    int yearOfBirth;
    int medicineCardNumber;
    string diagnosis;
};

// Class with needed Objects, Constructors and Methods
class TPatient {
    // objects (fields) of the Class
    string fullName;
    int yearOfBirth{};
    int medicineCardNumber{};
    string diagnosis;
public:
    // constructors
    // default constructor
    TPatient();

    // constructor which gets parameter
    TPatient(const string& fullName, int yearOfBirth, int medicineCardNumber, const string& patientDiagnosis);

    // copying constructor
    TPatient(const TPatient &T);


    // destructor is not needed, because all data of Class is not dynamic

    // Getters
    [[nodiscard]] const string &getFullName() const;
    [[nodiscard]] int getYearOfBirth() const;
    [[nodiscard]] int getMedicineCardNumber() const;
    [[nodiscard]] const string &getDiagnosis() const;

    // Setters
    void setFullName(const string &fullName);
    void setYearOfBirth(int yearOfBirth);
    void setMedicineCardNumber(int medicineCardNumber);
    void setDiagnosis(const string &diagnosis);

    // other methods of the Class
    void set();                     // setting object info
    void printObjectData() const;   // printing object info
    void recordObjectDataToFile(ofstream & file) const;  // recording object data to file
    void copy_data_from_struct(const TPatientStruct& Temp);

    // overloading operators
    friend bool operator<(const TPatient &lhs, const TPatient &rhs);
    friend bool operator>(const TPatient &lhs, const TPatient &rhs);
};

// other functions

// filling array of objects from file using structure
TPatient * fillFromFile(ifstream & file, int size);
// simple printing of object's data of array
void printData(TPatient array[], int size);
// opening file for writing
ofstream openFileForWriting();
// opening file for reading
ifstream openFileForReading();
// getting array size
int getArraySize(ifstream & file);
// printing data to cmd in table mode
void recordDataTableToFile(TPatient array[], int size, ofstream & openedFile);
// sorting by Year of Birth in Increasing Mode
void sortByYearOfBirthIncreasingMode(TPatient * array, int size);
// sorting by Year of Birth in Increasing Mode
void sortByYearOfBirthDecreasingMode(TPatient * array, int size);
// filtering by Diagnosis and Year of Birth
void filterByDiagnosisAndYearOfBirth(TPatient * array, int size);
// filtering by Medicine Card Number
void filterByMedicineCardNumber(TPatient * array, int size);
// filtering by Year of Birth
void filterByYearOfBirth(TPatient * array, int size);

// menu functions
int mainMenu();
int staticModeMenu();
int dynamicModeMenu(TPatient * array, int size);
void preEnterToDynamicModeMenu();

#endif //INC_1_LAB_HEADER_H
