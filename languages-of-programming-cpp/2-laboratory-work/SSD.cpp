//
// Created by bek on 10/14/20.
//

#include "Header.h"

// constructors
SSD::SSD() {
    setSpindleRotationSpeed(0);
    cout << "Конструктор по умолчанию класса: SSD" << endl;
}

SSD::SSD(SSD &T) {
    setDriveSize(T.getDriveSize());
    setReleaseYear(T.getReleaseYear());
    setManufacturerBrand(T.getManufacturerBrand());
    setCost(T.getCost());
    setSpindleRotationSpeed(T.getSpindleRotationSpeed());
    cout << "Конструктор копирования класса: SSD" << endl;
}

SSD::SSD(int driveNewSize, int newReleaseYear, const string& newManufacturerBrand,
         int newCost, int spindleRotationNewSpeed) : StorageDev(driveNewSize, newReleaseYear,
                                                                newManufacturerBrand, newCost) {
    setSpindleRotationSpeed(spindleRotationNewSpeed);
    cout << "Конструктор с параметрами класса: SSD" << endl;
}

// destructor
SSD::~SSD() {
    cout << "Деструктор класса: SSD" << endl;
}

// setter
void SSD::setSpindleRotationSpeed(int spindleRotationNewSpeed) {
    SSD::spindleRotationSpeed = spindleRotationNewSpeed;
}

// getter
int SSD::getSpindleRotationSpeed() const {
    return spindleRotationSpeed;
}

// methods
string SSD::myName() {
    return "SSD";
}

void SSD::print() {
    cout << "Объем: " << driveSize << "\t\tВыпущен: " << releaseYear <<
         "\t\tБренд: " << manufacturerBrand << "\t\t\tЦена: " << cost << "$" <<
         "\t\t\t* Скорость шпинделя: " << spindleRotationSpeed << "\t\tКласс: " << myName() << endl;
}

int SSD::generateSpindleRotationSpeed() {
    int number;
    number = rand() % 100 + 1;
    return number;
}

[[maybe_unused]] void SSD::setRandomValue() {
    setDriveSize(generateRandomSize());
    setReleaseYear(generateRandomYear());
    setManufacturerBrand(generateRandomBrand());
    setCost(generateRandomCost());
    setSpindleRotationSpeed(generateSpindleRotationSpeed());
}

void SSD::set() {
    int driveNewSize;
    int releaseNewYear;
    string manufacturerNewBrand;
    int costNew;
    int spindleRotationNewSpeed;

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

    cout << "* Введите новую скорость вращения шпинделя: ";
    cin >> spindleRotationNewSpeed;
    setSpindleRotationSpeed(spindleRotationNewSpeed);
}

