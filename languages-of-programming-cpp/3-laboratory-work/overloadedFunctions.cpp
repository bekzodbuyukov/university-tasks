//
// Created by bek on 27.10.2020.
//

#include "header.h"

istream &operator>>(istream &in, FractionalNumber &F) {
    in >> F.numerator >> F.denominator;
    return in;
}

ostream &operator<<(ostream &out, FractionalNumber &F) {
    F.fractionalNumber = round((F.numerator / F.denominator) * 100.0) / 100.0;
    // F.fractionalNumber = sf::rounder(F.numerator / F.denominator);
    out << "Numerator: " << F.numerator << " Denominator: " << F.denominator << " ";
    out << "Fractional number: " << F.fractionalNumber << endl;
    return out;
}

bool operator>(FractionalNumber &LeftObject, FractionalNumber &RightObject) {
    return LeftObject.fractionalNumber > RightObject.fractionalNumber;
}

bool operator<(FractionalNumber &LeftObject, FractionalNumber &RightObject) {
    return RightObject.fractionalNumber > LeftObject.fractionalNumber;
}

FractionalNumber &FractionalNumber::operator=(double number) {
    denominator = modf(number, &numerator);
    denominator*= 100;
    return *this;
}


