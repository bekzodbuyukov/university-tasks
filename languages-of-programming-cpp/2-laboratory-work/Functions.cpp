//
// Created by bek on 10/14/20.
//

#include "Header.h"

int generateRandomSize() {
    int number;
    number = rand() % 8000 + 1000;
    return number;
}

int generateRandomYear() {
    int number;
    number = rand() % 5 + 2015;
    return number;
}

string generateRandomBrand() {
    string array[25] = {"Kingston", "A-Data", "AMD Radeon", "Apacer", "Crucial", "DEXP", "GIGABYTE", "HP",
                        "Goodram", "Hikvision", "Intel", "Toshiba", "Lexar", "LexOn", "Neo Forza", "Netca",
                        "Patriot Memory", "Pioner", "Plextor", "Smartbuy", "QUMO", "Samsung", "Sandisk",
                        "Seagate", "Western Digital"};
    int number;
    number = rand() % 25;
    return array[number];
}

int generateRandomCost() {
    int number;
    number = rand() % 130 + 20;
    return number;
}
