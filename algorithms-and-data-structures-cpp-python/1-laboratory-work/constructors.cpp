#include "header.h"

// default constructor
template <typename T>
Array<T>::Array() {
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
template <typename T>
Array<T>::Array(const Array& A) {
    this->setSize(A.getSize());
    // this->setArray(A.getArray());
    this->setArray(new T[getSize()]);
    for (int i = 0; i < A.getArray(); i++) {
        this->array[i] = A.array[i];
    }
}

// constructor with parameters
template <typename T>
Array<T>::Array(int* newArray, int newSize) {
    this->setSize(newSize);
    this->setArray(newArray);
}

// destructor: deleting object array and assigning nullptr to array pointer
template <typename T>
Array<T>::~Array() {
    delete[] array;
    this->array = nullptr;
}

// Getters
template <typename T>
int Array<T>::getSize() const {
    return size;
}

template <typename T>
int* Array<T>::getArray() const {
    return array;
}

template <typename T>
double Array<T>::getSpentTime() const {
    return spentTime;
}

template <typename T>
int Array<T>::getComparisons() const {
    return comparisons;
}

template <typename T>
int Array<T>::getRearrangements() const {
    return rearrangements;
}

template <typename T>
int Array<T>::getStep() const {
    return step;
}

template <typename T>
int Array<T>::getRange() const {
    return range;
}

// Setters
template <typename T>
void Array<T>::setSize(int newSize) {
    Array::size = newSize;
}

template <typename T>
void Array<T>::setArray(T* newArray) {
    Array::array = newArray;
}

template <typename T>
void Array<T>::setSpentTime(double spentTime) {
    Array::spentTime = spentTime;
}

template <typename T>
void Array<T>::setComparisons(int comparisons) {
    Array::comparisons = comparisons;
}

template <typename T>
void Array<T>::setRearrangements(int rearrangements) {
    Array::rearrangements = rearrangements;
}

template <typename T>
void Array<T>::setStep(int step) {
    Array::step = step;
}

template <typename T>
void Array<T>::setRange(int range) {
    Array::range = range;
}

template <typename T>
const string& Array<T>::getSortingMethodName() const {
    return sortingMethodName;
}

template <typename T>
void Array<T>::setSortingMethodName(const string& sortingMethodName) {
    Array::sortingMethodName = sortingMethodName;
}



