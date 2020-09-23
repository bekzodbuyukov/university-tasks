//
// Created by bek on 17.09.2020.
//

#include "header.h"
#define NOT_EXISTING_COMMAND_ERROR_MESSAGE "ОШИБКА: Не существующее действие, попробуйте снова..."
#define BOTTOM_SEPARATOR "_-_-_-_-_-_-_-_-_-_-_-_-_"

int mainMenu() {
    string top_separator, bottom_separator;
    top_separator = "\n_-_-_- ГЛАВНОЕ МЕНЮ -_-_-_\n";
    bottom_separator = "_-_-_-_-_-_-_-_-_-_-_-_-_-\n";
    char action;
    cout << top_separator;
    cout << "[1] - первый режим\n"
            "[2] - второй режим\n"
            "[q] - завершить работу" << endl;
    cout << BOTTOM_SEPARATOR << endl;
    cout << "Выберите действие: ";
    cin >> action;

    if (action == '1') {
        firstModeMenu();
    } else if (action == '2') {
        secondModeMenu();
    } else if (action == 'q') {
        return 0;
    } else {
        cout << NOT_EXISTING_COMMAND_ERROR_MESSAGE << endl;
        mainMenu();
    }

    return 0;
}

int firstModeMenu() {
    string top_separator, bottom_separator;
    top_separator = "\n_-_-_- ПЕРВЫЙ РЕЖИМ -_-_-_\n";
    bottom_separator = "_-_-_-_-_-_-_-_-_-_-_-_-_\n";
    char action;
    cout << top_separator;

    cout << "[/] - создать массив и применить сортировку с выводом на файл:\n"
            "       [1] - простым выбором\n"
            "       [2] - простыми включениями\n"
            "[0] - вернуться в главное меню" << endl;

    cout << BOTTOM_SEPARATOR << endl;
    cout << "Выберите действие: ";
    cin >> action;

    if (action == '9') {
        Array A;
        A.fillByRange();
        // A.print();
        A.recordArrayToFile();
        cout << "Массив успешно создан, заполнен и записан в файл!" << endl;
        firstModeMenu();
    } else if (action == '1') {
        Array A;
        // operations
        A.fillByRange();
        A.recordArrayToFile();
        A.print();
        A.selectSort();
        A.print();
        A.recordArrayToFile();
        // getting back to menu
        firstModeMenu();
    } else if (action == '2') {
        Array A;
        // operations
        A.fillByRange();
        A.recordArrayToFile();
        A.print();
        A.insertSort();
        A.print();
        A.recordArrayToFile();
        // getting back to menu
        firstModeMenu();
    } else if (action == '0') {
        mainMenu();
    } else {
        cout << NOT_EXISTING_COMMAND_ERROR_MESSAGE << endl;
        firstModeMenu();
    }

    return 0;
}

int secondModeMenu() {
    string top_separator, bottom_separator;
    top_separator = "\n_-_-_- ВТОРОЙ РЕЖИМ -_-_-_\n";
    bottom_separator = "_-_-_-_-_-_-_-_-_-_-_-_-_\n";
    char action;
    cout << top_separator;

    cout << "[/] - выбирать способ формирования элементов массива:\n"
            "   [/] - случайные значения\n"
            "       [1] - сортировка с выбором\n"
            "       [2] - сортировка с включениями\n"
            "   [/] - упорядоченная последовательность значений\n"
            "       [3] - сортировка с выбором\n"
            "       [4] - сортировка с включениями\n"
            "   [/] - значения расположены в обратном порядке\n"
            "       [5] - сортировка с выбором\n"
            "       [6] - сортировка с включениями\n"
            "[7] - задавать диапазон и шаг изменения размеров массива\n"
            "[0] - вернуться в главное меню" << endl;

    cout << BOTTOM_SEPARATOR << endl;
    cout << "Выберите действие: ";
    cin >> action;

    if (action == '1') {
        Array A;
        A.fillByRange();
        A.recordArrayToFile();
        A.selectSort();
        A.recordArrayToFile();
        secondModeMenu();
    } else if (action == '2') {
        Array B;
        B.fillByRange();
        B.recordArrayToFile();
        B.insertSort();
        B.recordArrayToFile();
        secondModeMenu();
    } else if (action == '3') {
        Array C;
        C.orderedFill();
        C.recordArrayToFile();
        C.selectSort();
        C.recordArrayToFile();
        secondModeMenu();
    } else if (action == '4') {
        Array D;
        D.orderedFill();
        D.recordArrayToFile();
        D.insertSort();
        D.recordArrayToFile();
        secondModeMenu();
    } else if (action == '5') {
        Array E;
        E.unorderedFill();
        E.recordArrayToFile();
        E.selectSort();
        E.recordArrayToFile();
        secondModeMenu();
    } else if (action == '6') {
        Array F;
        F.unorderedFill();
        F.recordArrayToFile();
        F.insertSort();
        F.recordArrayToFile();
        secondModeMenu();
    } else if (action == '7') {
        Array J;
        J.setArrayRangeAndIncreasingStep();
        secondModeMenu();
    } else if (action == '0') {
        mainMenu();
    } else {
        cout << NOT_EXISTING_COMMAND_ERROR_MESSAGE << endl;
        firstModeMenu();
    }

    return 0;
}
