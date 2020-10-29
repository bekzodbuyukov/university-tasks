//
// Created by bek on 28.10.2020.
//

/*#include "header.h"

#define MENU_HEADER "\n - - - - MENU - - - -"
#define MENU_FOOTER "- - - - - - - - - - -\n"
#define ASKING_FOR_ARRAY_SIZE "\nEnter the size of an array: "
#define ASKING_FOR_BEGINNING_OF_ARRAY "\nEnter the beginning of array: "
#define ASKING_FOR_END_OF_ARRAY "\nEnter the end of array: "

template<typename T>
int subMenu(T **array, int arraySize) {
    string menu = "[1] - print\n"
                  "[2] - sort\n"
                  "[3] - AAM for even rows\n"
                  "[4] - AAM for odd rows\n"
                  "[m] - return menu\n"
                  "[0] - main menu\n";

    cout << MENU_HEADER << menu << MENU_FOOTER;

    char action;
    cout << ">>> ";
    cin >> action;

    if (action == '1') {
        printArray(array, arraySize);
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
        fillArray<FractionalNumber>(array, fractionalNumbersArraySize, beginning, end);
        subMenu(array, fractionalNumbersArraySize);

    } else if (action == 'q') {
        char quitConfirmation;
        cout << "Are you sure you want to quit? [y/n]: ";
        cin >> quitConfirmation;
        if (quitConfirmation == 'y') {
            return 0;
        } else {
            mainMenu();
        }
    }
    return 0;
}*/
