//
// Created by bek on 10/14/20.
//

#include "Header.h"
#define ACTION_TEXT "Выберите действие: "
#define MENU_HEADER "\n- - - М Е Н Ю - - -"
#define MENU_FOOTER "- - - * * * * - - -\n"
#define ERROR_TEXT "Неверная команда. Попробуйте снова..."

int mainMenu() {
    cout << MENU_HEADER << endl;
    cout << "[1] - статический режим\n"
            "[2] - динамический режим\n"
            "[q] - завершить работу" << endl;
    cout << MENU_FOOTER << endl;

    char action;
    cout << ACTION_TEXT;
    cin >> action;

    if (action == '1') {
        staticModeMenu();
    } else if (action == '2') {
        preEnterTheDynamicModeMenu();
    } else if (action == 'q') {
        return 0;
    } else {
        cout << ERROR_TEXT << endl;
        mainMenu();
    }

    return 0;
}

int staticModeMenu() {
    cout << MENU_HEADER << endl;
    cout << "[/] - класс HDD:\n"
            "       [1] - конструктор по умолчанию\n"
            "       [2] - конструктор копирования\n"
            "       [3] - конструктор с параметрами\n"
            "[/] - класс SSD:\n"
            "       [4] - конструктор по умолчанию\n"
            "       [5] - конструктор копирования\n"
            "       [6] - конструктор с параметрами\n"
            "[/] - класс FlashD:\n"
            "       [7] - конструктор по умолчанию\n"
            "       [8] - конструктор копирования\n"
            "       [9] - конструктор с параметрами\n"
            "[m] - вернуться в главное меню\n"
            "[q] - завершить работу" << endl;
    cout << MENU_FOOTER << endl;

    char action;
    cout << ACTION_TEXT;
    cin >> action;

    if (action == '1') {
        HDD A;
        A.myName();
        A.print();
        staticModeMenu();
    } else if (action == '2') {
        HDD B;
        HDD C(B);
        C.myName();
        C.print();
        staticModeMenu();
    } else if (action == '3') {
        HDD D(4096, 2019, "Kingston", 45, "Тип");
        D.myName();
        D.print();
        mainMenu();
    } else if (action == '4') {
        SSD A;
        A.myName();
        A.print();
        staticModeMenu();;
    } else if (action == '5') {
        SSD B;
        SSD C(B);
        C.myName();
        C.print();
        staticModeMenu();
    } else if (action == '6') {
        SSD C(4096, 2019, "Kingston", 45, 102);
        C.myName();
        C.print();
        staticModeMenu();
    } else if (action == '7') {
        FlashD A;
        A.myName();
        A.print();
        staticModeMenu();
    } else if (action == '8') {
        FlashD B;
        FlashD C(B);
        C.myName();
        C.print();
        staticModeMenu();
    } else if (action == '9') {
        FlashD C(4096, 2019, "Kingston", 45, 2.5);
        C.myName();
        C.print();
        staticModeMenu();
    } else if (action == 'm') {
        mainMenu();
    } else if (action == 'q') {
        return 0;
    } else {
        cout << ERROR_TEXT << endl;
        staticModeMenu();
    }
    return 0;
};

void preEnterTheDynamicModeMenu() {
    Shop A;
    int arraySize;
    cout << "Размер массива: ";
    cin >> arraySize;
    A.setArraySize(arraySize);
    A.generateArray();
    A.printArray();
    dynamicModeMenu(& A);
}

int dynamicModeMenu(Shop *A) {
    cout << MENU_HEADER << endl;
    cout << "[1] - сортировка по возрастанию объема\n"
            "[2] - вывода по диапазону емкости\n"
            "[3] - показать статистику по массиву\n"
            "[4] - изменить элемент массива\n"
            "[m] - вернуться в главное меню\n"
            "[q] - завершить работу" << endl;
    cout << MENU_FOOTER << endl;

    char action;
    cout << ACTION_TEXT;
    cin >> action;

    if (action == '1' ) {
        A->filterByClassAndSortByIncreasing();
        A->printArray();
        dynamicModeMenu(A);
    } else if (action == '2') {
        int starting, ending;
        cout << "Введите начало диапазона: ";
        cin >> starting;
        cout << "Введите конец диапазона: ";
        cin >> ending;
        A->filterByMemorySizeRange(starting, ending);
        dynamicModeMenu(A);
    } else if (action == '3') {
        A->showStatistics();
        dynamicModeMenu(A);
    } else if (action == '4') {
        int index;
        cout << "Введите индекс элемента, который хотите редактировать: ";
        cin >> index;
        A->setAnElement(index - 1);
        A->printArray();
        dynamicModeMenu(A);
    } else if (action == 'm') {
        mainMenu();
    } else if (action == 'q') {
        return 0;
    } else {
        cout << ERROR_TEXT << endl;
        dynamicModeMenu(A);
    }
    return 0;
}
