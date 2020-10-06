//
// Created by bek on 12.09.2020.
//

#include "header.h"

#define SEARCH_NOT_FOUND "Совпадений не найдено..."
#define ID_SIZE 2
#define FULL_NAME_SIZE 30
#define YEAR_OF_BIRTH_SIZE 5
#define MEDICINE_CARD_NUMBER_SIZE 5
#define DIAGNOSIS_SIZE 50

// BEGIN: STABLE CODE

// function for setting object data
void TPatient::set() {
    cout << ".:: Введите данные пациента ::." << endl;

    setIndex(1);

    string newFullName;
    cout << "ФИО: ";
    cin.get();
    getline(cin, newFullName);
    setFullName(newFullName);

    int newYearOfBirth;
    cout << "Год рождения: ";
    cin >> newYearOfBirth;
    setYearOfBirth(newYearOfBirth);

    int newMedicineCardNumber;
    cout << "Номер медицинской карты: ";
    cin >> newMedicineCardNumber;
    setMedicineCardNumber(newMedicineCardNumber);

    string newDiagnosis;
    cout << "Диагноз: ";
    cin.get();
    getline(cin, newDiagnosis);
    setDiagnosis(newDiagnosis);
}

// function for printing object data
void TPatient::printObjectData() const {
    cout << left << setw(ID_SIZE) << getIndex()
        << setw(FULL_NAME_SIZE) << getFullName()
        << setw(YEAR_OF_BIRTH_SIZE) << getYearOfBirth()
        << setw(MEDICINE_CARD_NUMBER_SIZE) << getMedicineCardNumber()
        << setw(DIAGNOSIS_SIZE) << getDiagnosis() << endl;
}

// function for copying data from structure directly to Class
void TPatient::copy_data_from_struct(const TPatientStruct& Temp) {
    setFullName(Temp.fullName);
    setYearOfBirth(Temp.yearOfBirth);
    setMedicineCardNumber(Temp.medicineCardNumber);
    setDiagnosis(Temp.diagnosis);
}

// function for recording data as a table to file
void TPatient::recordObjectDataToFile(ofstream& file) const {
    file << left << setw(ID_SIZE) << getIndex()
        << setw(FULL_NAME_SIZE) << getFullName()
        << setw(YEAR_OF_BIRTH_SIZE) << getYearOfBirth()
        << setw(MEDICINE_CARD_NUMBER_SIZE) << getMedicineCardNumber()
        << setw(DIAGNOSIS_SIZE) << getDiagnosis() << endl;
    //file.close();
}

// overloading of operator '<'
bool operator<(const TPatient& lhs, const TPatient& rhs) {
    return lhs.getYearOfBirth() < rhs.getYearOfBirth();
}

// overloading of operator '>'
bool operator>(const TPatient& lhs, const TPatient& rhs) {
    return rhs.getYearOfBirth() < lhs.getYearOfBirth();
}

// function for returning file, which is opened for writing data in it
ofstream openFileForWriting() {
    string fileName;

    cout << "Введите называние .txt файла: ";
    cin.get();
    getline(cin, fileName);

    ofstream writingFile(fileName + ".txt", ios::ate);

    if (!writingFile) {
        cout << "Не удалось открыть файл для записи..." << endl;
    }

    return writingFile;
}

// function for returning file, which is opened for reading data from it
ifstream openFileForReading() {
    string fileName;

    cout << "Введите называние .txt файла: ";
    cin.get();
    getline(cin, fileName);
    cout << fileName + ".txt" << endl;
    ifstream readingFile(fileName + ".txt");

    if (!readingFile) {
        cout << "Не удалось открыть файл для чтения..." << endl;
    }

    return readingFile;
}

// function return future array size, which was read from file
int getArraySize(ifstream& file) {
    int size;
    bool status = true;
    while (status) {
        file >> size;
        status = false;
    }

    return size;
}

// function for writing data as a table to file, gets array
void recordDataTableToFile(TPatient array[], int size, ofstream& openedFile) {
    for (int i = 0; i < size; ++i) {
        // array[i].setIndex(i);
        array[i].recordObjectDataToFile(openedFile);
    }
    openedFile.close();
}

// function for filtering and printing data by given diagnosis and range of year of birth
void filterByDiagnosisAndYearOfBirth(TPatient* array, int size) {
    string neededDiagnosis;

    cout << "Необходимый диагноз: ";
    cin.get();
    getline(cin, neededDiagnosis);

    int fromYearOfBirth;
    cout << "Год рождения от: ";
    cin >> fromYearOfBirth;

    int toYearOfBirth;
    cout << "Год рождения от: ";
    cin >> toYearOfBirth;

    cout << "Результат:" << endl;

    int counter = 0;
    for (int i = 0; i < size; ++i) {
        if (array[i].getDiagnosis() == neededDiagnosis) {
            if (array[i].getYearOfBirth() >= fromYearOfBirth && array[i].getYearOfBirth() <= toYearOfBirth) {
                array[i].printObjectData();
                counter += 1;
            }
        }
    }

    if (counter == 0) {
        cout << SEARCH_NOT_FOUND << endl;
    }
}

// function for filtering and printing data by medicine card number (prints data which has number in given range)
void filterByMedicineCardNumber(TPatient* array, int size) {
    int fromMedicineCardNumber;
    cout << "Номер мед. карты от: ";
    cin >> fromMedicineCardNumber;

    int toMedicineCardNumber;
    cout << "Номер мед. карты до: ";
    cin >> toMedicineCardNumber;

    cout << "Результат:" << endl;

    int counter = 0;
    for (int i = 0; i < size; ++i) {
        if (array[i].getMedicineCardNumber() > fromMedicineCardNumber &&
            array[i].getMedicineCardNumber() < toMedicineCardNumber) {
            array[i].printObjectData();
            counter += 1;
        }
    }

    if (counter == 0) {
        cout << SEARCH_NOT_FOUND << endl;
    }
}

// function for filtering and printing data by year of birth (prints data which has number greater than given)
void filterByYearOfBirth(TPatient* array, int size) {
    int afterYearOfBirth;
    cout << "Год рождения после: ";
    cin >> afterYearOfBirth;

    cout << "Результат:" << endl;

    int counter = 0;
    for (int i = 0; i < size; ++i) {
        if (array[i].getYearOfBirth() > afterYearOfBirth) {
            array[i].printObjectData();
            counter += 1;
        }
    }

    if (counter == 0) {
        cout << SEARCH_NOT_FOUND << endl;
    }
}

// function for filling data to array of objects from file (uses structures and function which works which structure)
TPatient* fillFromFile(ifstream& file, int size) {
    struct TPatientStruct Temp;
    auto* array = new TPatient[size];
    string surname, other_name;

    for (int i = 0; i < size; i++) {
        file >> Temp.fullName >> surname >> other_name >> Temp.yearOfBirth
            >> Temp.medicineCardNumber >> Temp.diagnosis;

        Temp.fullName += " " + surname;
        Temp.fullName += " " + other_name;

        array[i].copy_data_from_struct(Temp);
    }
    file.close();

    return array;
}

// function for printing data of array
void printData(TPatient array[], int size) {
    for (int i = 0; i < size; ++i) {
        array[i].setIndex(i + 1);
        array[i].printObjectData();
    }
}

// function for sorting array by given year of birth in '>' (increasing) mode [NOT OPTIMISED]
void sortByYearOfBirthIncreasingMode(TPatient* array, int size) {
    int i, j;
    TPatient tempObject;

    // Bubble Sort Algorithm
    for (i = 0; i < size; ++i) {
        for (j = size - 1; j > i; --j) {
            if (array[j - 1] > array[j]) {
                tempObject = array[j - 1];
                array[j - 1] = array[j];
                array[j] = tempObject;
            }
        }
    }

    for (i = 0; i < size; ++i) {
        array[i].printObjectData();
    }
}

// function for sorting array by given year of birth in '<' (decreasing) mode [NOT OPTIMISED]
void sortByYearOfBirthDecreasingMode(TPatient* array, int size) {
    int i, j;
    TPatient tempObject;

    // Bubble Sort Algorithm
    for (i = 0; i < size; ++i) {
        for (j = size - 1; j > i; --j) {
            if (array[j - 1] < array[j]) {
                tempObject = array[j - 1];
                array[j - 1] = array[j];
                array[j] = tempObject;
            }
        }
    }

    for (i = 0; i < size; ++i) {
        array[i].printObjectData();
    }
}

// END: STABLE CODE
