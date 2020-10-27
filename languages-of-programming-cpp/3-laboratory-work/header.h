//
// Created by bek on 26.10.2020.
//

#ifndef INC_3_LABORATORY_WORK_HEADER_H
#define INC_3_LABORATORY_WORK_HEADER_H

#include <iostream>
#include <cmath>
using namespace std;

#define TYPE double

// class: Fractional Number
class FractionalNumber {
    TYPE numerator;                  // numerator part of the fractional number
    TYPE denominator;                // denominator part of the fractional number
    TYPE fractionalNumber;
public:
    // overloading the operators of input and output
    friend istream& operator>>(istream &in, FractionalNumber &F);
    friend ostream& operator<<(ostream &out, FractionalNumber &F);

    // overloading operators of comparison
    friend bool operator>(FractionalNumber& LeftObject, FractionalNumber& RightObject);
    friend bool operator<(FractionalNumber& LeftObject, FractionalNumber& RightObject);

};


/*// класс: Числитель
class Numerator : public FractionalNumber {

};

// класс: Знаменатель
class Denominator : public FractionalNumber {

};*/

#endif //INC_3_LABORATORY_WORK_HEADER_H
