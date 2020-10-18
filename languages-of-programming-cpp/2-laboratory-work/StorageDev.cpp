//
// Created by bek on 10/14/20.
//

//
// Created by bek on 10/14/20.
//

#include "Header.h"

// constructors
StorageDev::StorageDev() {
    setDriveSize(0);
    setReleaseYear(2020);
    setManufacturerBrand("Kingston");
    setCost(0);
}

StorageDev::StorageDev(StorageDev &T) {
    setDriveSize(T.getDriveSize());
    setReleaseYear(T.getReleaseYear());
    setManufacturerBrand(T.getManufacturerBrand());
    setCost(T.getCost());
}

StorageDev::StorageDev(int driveNewSize, int newReleaseYear, const string& newManufacturerBrand, int newCost) {
    setDriveSize(driveNewSize);
    setReleaseYear(newReleaseYear);
    setManufacturerBrand(newManufacturerBrand);
    setCost(newCost);
}

// destructor
StorageDev::~StorageDev() {
    cout << "Деструктор класса: StorageDev" << endl;
}

// setters
void StorageDev::setDriveSize(int driveNewSize) {
    StorageDev::driveSize = driveNewSize;
}

void StorageDev::setReleaseYear(int releaseNewYear) {
    StorageDev::releaseYear = releaseNewYear;
}

void StorageDev::setManufacturerBrand(const string &manufacturerNewBrand) {
    StorageDev::manufacturerBrand = manufacturerNewBrand;
}

void StorageDev::setCost(int newCost) {
    StorageDev::cost = newCost;
}

// getters
int StorageDev::getDriveSize() const {
    return driveSize;
}

int StorageDev::getReleaseYear() const {
    return releaseYear;
}

const string &StorageDev::getManufacturerBrand() const {
    return manufacturerBrand;
}

int StorageDev::getCost() const {
    return cost;
}