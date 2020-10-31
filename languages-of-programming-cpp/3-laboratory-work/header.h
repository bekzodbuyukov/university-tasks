//
// Created by bek on 26.10.2020.
//
#pragma once

#ifndef INC_3_LABORATORY_WORK_HEADER_H
#define INC_3_LABORATORY_WORK_HEADER_H

#include <iostream>
#include <cmath>
#include <random>
#include <ctime>
#include <cstdlib>
#include <chrono>
using namespace std;

// class: Fractional Number
class FractionalNumber {
    double numerator;                  // numerator part of the fractional number
    double denominator;                // denominator part of the fractional number
    double fractionalNumber;
public:
    //setters
    [[maybe_unused]] void setFractionalNumber(double newFractionalNumber) {
        FractionalNumber::fractionalNumber = newFractionalNumber;
    }

    // getters
    [[maybe_unused]] [[nodiscard]] double getFractionalNumber() const {
        return fractionalNumber;
    }

    // overloading the operators of input and output
    friend istream& operator>>(istream &in, FractionalNumber &F){
        in >> F.numerator >> F.denominator;
        return in;
    }

    friend ostream& operator<<(ostream &out, FractionalNumber &F){
        F.fractionalNumber = round((F.numerator / F.denominator) * 100.0) / 100.0;
        out << F.numerator << "/" << F.denominator << " = " << F.fractionalNumber << "   ";
        return out;
    }

    // overloading operators of comparison
    friend bool operator>(FractionalNumber &LeftObject, FractionalNumber &RightObject) {
        return LeftObject.fractionalNumber > RightObject.fractionalNumber;
    }

    friend bool operator<(FractionalNumber &LeftObject, FractionalNumber &RightObject) {
        return RightObject.fractionalNumber > LeftObject.fractionalNumber;
    }

    // overloading operator of assignment
    FractionalNumber& operator=(double number) {
        denominator = modf(number, &numerator);
        if (denominator == 0) {
            denominator = 1;
        } else {
            denominator*= 100;
        }
        fractionalNumber = numerator / denominator;
        return *this;
    }

    FractionalNumber& operator=(FractionalNumber &number) {
        numerator = number.numerator;
        denominator = number.denominator;
        fractionalNumber = numerator / denominator;
        return *this;
    }

    friend FractionalNumber& operator+=(FractionalNumber &LeftObject, FractionalNumber &RightObject) {
        double tempNumerator = 0.0, tempDenominator = 0.0;

        tempNumerator = LeftObject.numerator * RightObject.denominator + RightObject.numerator * LeftObject.denominator;
        tempDenominator = RightObject.denominator*LeftObject.denominator;

        LeftObject.numerator = tempNumerator;
        LeftObject.denominator = tempDenominator;

        return LeftObject;
    }

    friend FractionalNumber& operator/=(FractionalNumber &LeftObject, double divider) {
        LeftObject.denominator = LeftObject.denominator * divider;
        return LeftObject;
    }

};

// template function for generating random number
double generateRandomNumberInRange(int beginning, int end) {
    random_device rd; // obtain a random number from hardware
    mt19937 gen(rd()); // seed the generator
    uniform_int_distribution<> distr(beginning, end - 1); // define the range

    random_device sd; // obtain a random number from hardware
    mt19937 gens(sd()); // seed the generator
    uniform_int_distribution<> distrs(beginning, end - 1); // define the range

    double number = (round((double)(distrs(gens)) + (distr(gen)) * 100.0)) / 100.0;
    return number;
}

// functions for generating an array of FractionalNumber data type
template<typename T>
T **generateArray(int arraySize) {
    auto ** array = new T * [arraySize];
    for (int i = 0; i < arraySize; ++i) {
        array[i] = new T[arraySize];
    }
    return array;
}

// function for filling an array of FractionalNumber data type
template<typename T>
void fillArray(T **array, int arraySize, int rangeBeginning, int rangeEnd) {
    for (int i = 0; i < arraySize; ++i) {
        for (int j = 0; j < arraySize; ++j) {
            array[i][j] = generateRandomNumberInRange(rangeBeginning, rangeEnd);
        }
    }
}

// function for printing array
template<typename T>
void printArray(T **array, int arraySize) {
    for (int i = 0; i < arraySize; ++i) {
        for (int j = 0; j < arraySize; ++j) {
            cout << array[i][j] << "     ";
        }
        cout << endl;
    }
}

// function for sorting the rows of an array
template<typename T>
void sortArrayRows(T **array, int arraySize) {
    T tempObject{};
    for (int i = 0; i < arraySize; ++i) {
        for (int j = 0; j < arraySize; ++j) {
            for (int l = arraySize - 1; l > j; --l) {
                if (array[i][l - 1] > array[i][l]) {
                    tempObject = array[i][l - 1];
                    array[i][l - 1] = array[i][l];
                    array[i][l] = tempObject;
                }
            }
        }
    }
}

// function for calculating the average arithmetic mean of even rows
template<typename T>
void calculateAverageArithmeticMeansOfColumns(T ** array, int arraySize) {
    T sum{};
    sum = 0.0;
    double counter = 0;

    cout << "\nAAM for Even Columns:" << endl;
    for (int j = 0; j < arraySize; ++j) {
        if (j % 2 == 0) {
            for (int i = 0; i < arraySize; ++i) {
                counter += 1.0;
                sum += array[i][j];
            }
            sum /= counter;
            cout << sum << endl;
            counter = 0;
            sum = 0.0;
        }
    }
    cout << "\nAAM for Odd Columns:" << endl;
    for (int j = 0; j < arraySize; ++j) {
        if (j % 2 != 0) {
            for (int i = 0; i < arraySize; ++i) {
                counter += 1.0;
                sum += array[i][j];
            }
            sum /= counter;
            cout << sum << endl;
            counter = 0;
            sum = 0.0;
        }
    }
}

#define MENU_HEADER "\n - - - - MENU - - - -\n"
#define MENU_FOOTER "- - - - - - - - - - -\n"
#define ASKING_FOR_ARRAY_SIZE "\nEnter the size of an array: "
#define ASKING_FOR_BEGINNING_OF_ARRAY "Enter the beginning of array: "
#define ASKING_FOR_END_OF_ARRAY "Enter the end of array: "
#define NOT_EXISTING_COMMAND_ERROR "You have entered not existing command. Try other command.\n"

template<typename T>
int subMenu(T **array, int arraySize) {
    string menu = "[1] - print\n"
                  "[2] - sort rows\n"
                  "[3] - AAM for even and odd columns\n"
                  "[m] - return menu\n"
                  "[0] - main menu\n";

    cout << MENU_HEADER << menu << MENU_FOOTER;

    char action;
    cout << ">>> ";
    cin >> action;

    if (action == '1') {
        printArray(array, arraySize);
        subMenu(array, arraySize);
    } else if (action == '2') {
        sortArrayRows(array, arraySize);
        printArray(array, arraySize);
        subMenu(array, arraySize);
    } else if (action == '3') {
        calculateAverageArithmeticMeansOfColumns(array, arraySize);
        subMenu(array, arraySize);
    } else if (action == 'm') {
        subMenu(array, arraySize);
    } else if (action == '0') {
        return 0;
    } else {
        cout << NOT_EXISTING_COMMAND_ERROR;
        subMenu(array, arraySize);
    }
    return 0;
}

int mainMenu() {
    string menu = "[1] - int\n"
                  "[2] - double\n"
                  "[3] - fractional number\n"
                  "[q] - quit\n";
    cout << MENU_HEADER << menu << MENU_FOOTER << endl;
    char action;

    cout << ">>> ";
    cin >> action;

    if (action == '1') {
        int intNumbersArraySize;
        cout << ASKING_FOR_ARRAY_SIZE;
        cin >> intNumbersArraySize;
        int **array;
        array = generateArray<int>(intNumbersArraySize);
        int beginning, end;
        cout << ASKING_FOR_BEGINNING_OF_ARRAY;
        cin >> beginning;
        cout << ASKING_FOR_END_OF_ARRAY;
        cin >> end;
        fillArray<int>(array, intNumbersArraySize, beginning, end);
        subMenu(array, intNumbersArraySize);
        mainMenu();
    } else if (action == '2') {
        int doubleNumbersArraySize;
        cout << ASKING_FOR_ARRAY_SIZE;
        cin >> doubleNumbersArraySize;
        double **array;
        array = generateArray<double>(doubleNumbersArraySize);
        int beginning, end;
        cout << ASKING_FOR_BEGINNING_OF_ARRAY;
        cin >> beginning;
        cout << ASKING_FOR_END_OF_ARRAY;
        cin >> end;
        fillArray<double>(array, doubleNumbersArraySize, beginning, end);
        subMenu(array, doubleNumbersArraySize);
        mainMenu();
    } else if (action == '3') {
        int fractionalNumbersArraySize;
        cout << ASKING_FOR_ARRAY_SIZE;
        cin >> fractionalNumbersArraySize;
        FractionalNumber ** array;
        array = generateArray<FractionalNumber>(fractionalNumbersArraySize);
        int beginning, end;
        cout << ASKING_FOR_BEGINNING_OF_ARRAY;
        cin >> beginning;
        cout << ASKING_FOR_END_OF_ARRAY;
        cin >> end;
        fillArray(array, fractionalNumbersArraySize, beginning, end);
        subMenu(array, fractionalNumbersArraySize);
        mainMenu();
    } else if (action == 'q') {
        char quitConfirmation;
        cout << "Are you sure you want to quit? [y/n]: ";
        cin >> quitConfirmation;
        if (quitConfirmation == 'y') {
            return 0;
        } else {
            mainMenu();
        }
    } else {
        cout << NOT_EXISTING_COMMAND_ERROR;
        mainMenu();
    }
    return 0;
}

#endif //INC_3_LABORATORY_WORK_HEADER_H
