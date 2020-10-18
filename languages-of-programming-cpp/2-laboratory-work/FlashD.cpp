//
// Created by bek on 10/14/20.
//

#include "Header.h"

// constructors
FlashD::FlashD() {
    setUsbType(0.0);
    cout << "Конструктор по умолчанию класса: FlashD" << endl;
}

FlashD::FlashD(FlashD &T) {
    setDriveSize(T.getDriveSize());
    setReleaseYear(T.getReleaseYear());
    setManufacturerBrand(T.getManufacturerBrand());
    setCost(T.getCost());
    setUsbType(getUsbType());
    cout << "Конструктор копирования класса: FlashD" << endl;
}

FlashD::FlashD(int driveNewSize, int newReleaseYear, const string& newManufacturerBrand,
               int newCost, double usbNewType) : StorageDev(driveNewSize, newReleaseYear,
                                               newManufacturerBrand, newCost) {
    setUsbType(usbNewType);
    cout << "Конструктор с параметрами класса: FlashD" << endl;
}

// destructor
FlashD::~FlashD() {
    cout << "Деструктор класса: FlashD" << endl;
}

// setter
void FlashD::setUsbType(double usbNewType) {
    FlashD::usbType = usbNewType;
}

// getter
double FlashD::getUsbType() const {
    return usbType;
}

// methods
string FlashD::myName() {
    return "FlashD";
}

void FlashD::print() {
    cout << "Объем: " << driveSize << "\t\tВыпущен: " << releaseYear <<
         "\t\tБренд: " << manufacturerBrand << "\t\t\tЦена: " << cost << "$" <<
         "\t\t\t* Тип USB: " << usbType << "\t\tКласс: " << myName() << endl;
}

double FlashD::generateUsbType() {
    double array[2] = {2.0, 3.0};
    int number;
    number = rand() % 2;
    return array[number];
}

void FlashD::setRandomValue() {
    setDriveSize(generateRandomSize());
    setReleaseYear(generateRandomYear());
    setManufacturerBrand(generateRandomBrand());
    setCost(generateRandomCost());
    setUsbType(generateUsbType());
}

void FlashD::set() {
    int driveNewSize;
    int releaseNewYear;
    string manufacturerNewBrand;
    int costNew;
    double usbNewType;

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

    cout << "* Введите новый тип USB: ";
    cin >> usbNewType;
    setUsbType(usbNewType);
}


