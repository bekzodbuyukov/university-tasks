//
// Created by bek on 21.09.2020.
//

#include "header.h"

// default constructor
Array::Array() {
    setSize(0);
    setSpentTime(0);
    setRearrangements(0);
    setComparisons(0);
    setRange(0);
    setStep(0);
    setSortingMethodName("method not used");

    /*this->setSize(generateRandomNumber());
    this->setArray(new int[this->getSize()]);

    for (int i = 0; i < this->getSize(); ++i) {
        array[i] = generateRandomNumber();
    }*/
}

// copying constructor
Array::Array(const Array &A) {
    this->setSize(A.getSize());
    this->setArray(A.getArray());
}

// constructor with parameters
Array::Array(int * newArray, int newSize) {
    this->setSize(newSize);
    this->setArray(newArray);
}

// destructor: deleting object array and assigning nullptr to array pointer
Array::~Array() {
    delete[] array;
    this->array = nullptr;
}

// Getters
int Array::getSize() const {
    return size;
}

int *Array::getArray() const {
    return array;
}

double Array::getSpentTime() const {
    return spentTime;
}

int Array::getComparisons() const {
    return comparisons;
}

int Array::getRearrangements() const {
    return rearrangements;
}

int Array::getStep() const {
    return step;
}

int Array::getRange() const {
    return range;
}

// Setters
void Array::setSize(int newSize) {
    Array::size = newSize;
}

void Array::setArray(int *newArray) {
    Array::array = newArray;
}

void Array::setSpentTime(double spentTime) {
    Array::spentTime = spentTime;
}

void Array::setComparisons(int comparisons) {
    Array::comparisons = comparisons;
}

void Array::setRearrangements(int rearrangements) {
    Array::rearrangements = rearrangements;
}

void Array::setStep(int step) {
    Array::step = step;
}

void Array::setRange(int range) {
    Array::range = range;
}

const string &Array::getSortingMethodName() const {
    return sortingMethodName;
}

void Array::setSortingMethodName(const string &sortingMethodName) {
    Array::sortingMethodName = sortingMethodName;
}



