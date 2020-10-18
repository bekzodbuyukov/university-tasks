//
// Created by bek on 10/14/20.
//

#include "Header.h"

// constructors
HDD::HDD() {
    setMemoryChipType("ChipType");
    cout << "Конструктор по умолчанию класса: HDD" << endl;
}

HDD::HDD(HDD &T) {
    setDriveSize(T.getDriveSize());
    setReleaseYear(T.getReleaseYear());
    setManufacturerBrand(T.getManufacturerBrand());
    setCost(T.getCost());
    setMemoryChipType(T.getMemoryChipType());
    cout << "Конструктор копирования класса: HDD" << endl;
}

HDD::HDD(int driveNewSize, int newReleaseYear, const string& newManufacturerBrand,
         int newCost, const string& memoryChipNewType) : StorageDev(driveNewSize, newReleaseYear,
                                                                    newManufacturerBrand, newCost) {
    setMemoryChipType(memoryChipNewType);
    cout << "Конструктор с параметрами класса: HDD" << endl;
}

// destructor
HDD::~HDD() {
    cout << "Деструктор класса: HDD" << endl;
}

// setter
void HDD::setMemoryChipType(const string &memoryNewChipType) {
    HDD::memoryChipType = memoryNewChipType;
}

// getter
const string &HDD::getMemoryChipType() const {
    return memoryChipType;
}

// methods
string HDD::myName() {
    return "HDD";
}

void HDD::print() {
    cout << "Объем: " << driveSize << "\t\tВыпущен: " << releaseYear <<
         "\t\tБренд: " << manufacturerBrand << "\t\t\tЦена: " << cost << "$" <<
         "\t\t\t* Тип чипа памяти: " << memoryChipType << "\t\tКласс: " << myName() << endl;
}

string HDD::generateMemoryChipType() {
    string array[4] = {"IDE", "SAS", "SATA II", "SATA III"};
    int number;
    number = rand() % 4 + 0;
    return array[number];
}

[[maybe_unused]] void HDD::setRandomValue() {
    setDriveSize(generateRandomSize());
    setReleaseYear(generateRandomYear());
    setManufacturerBrand(generateRandomBrand());
    setCost(generateRandomCost());
    setMemoryChipType(generateMemoryChipType());
}

void HDD::set() {
    int driveNewSize;
    int releaseNewYear;
    string manufacturerNewBrand;
    int costNew;
    string memoryChipNewType;

    cout << "Введите новый размер: ";
    cin >> driveNewSize;
    setDriveSize(driveNewSize);

    cout << "Введите новый год релиза: ";
    cin >> releaseNewYear;
    setReleaseYear(releaseNewYear);

    cout << "Введите новый бренд: ";
    cin >> manufacturerNewBrand;
    setManufacturerBrand(manufacturerNewBrand);

    cout << "Введите новую цену: ";
    cin >> costNew;
    setCost(costNew);

    cout << "* Введите новый тип чипа памяти: ";
    cin >> memoryChipNewType;
    setMemoryChipType(memoryChipNewType);
}
