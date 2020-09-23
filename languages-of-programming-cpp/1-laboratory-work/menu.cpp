//
// Created by bek on 18.09.2020.
//

#include "header.h"

#define CHOOSE_ACTION "\nВыберите действие: "
#define NOT_CORRECT_ACTION_ERROR "ОШИБКА: Вы выбрали не существующее действие, пожалуйста попробуйте снова."
#define BOTTOM_DIVIDER "-=-=-=-=-=-=-=-=-=-=-=-\n"

// Main Menu Function
int mainMenu() {
    string menuHeader = "\n-=-=-=-= МЕНЮ =-=-=-=-\n";
    char action;

    cout << menuHeader;
    cout << "[1] - статический режим\n"
            "[2] - динамический режим\n"
            "[m] - вернуть меню\n"
            "[q] - завершить работу" << endl;
    cout << BOTTOM_DIVIDER;

    cout << CHOOSE_ACTION;
    cin >> action;

    if (action == '1') {
        staticModeMenu();
    } else if (action == '2') {
        preEnterToDynamicModeMenu();
    } else if (action == 'm') {
        mainMenu();
    } else if (action == 'q') {
        return 0;
    } else {
        cout << NOT_CORRECT_ACTION_ERROR << endl;
        mainMenu();
    }

    return 0;
}

// Static Mode Menu Function
int staticModeMenu() {
    string menuHeader = "\n-= СТАТИЧЕСКИЙ РЕЖИМ =-\n";
    cout << menuHeader;

    cout << "[1] - конструктор по умолчанию\n"
            "[2] - конструктор с параметрами\n"
            "[3] - конструктор копирования\n"
            "[4] - установить данные для одного объекта\n"
            "[5] - запись объекта в файл\n"
            "[m] - вернуть меню\n"
            "[0] - главное меню" << endl;
    cout << BOTTOM_DIVIDER;

    char action;
    cout << CHOOSE_ACTION;
    cin >> action;

    TPatient A;
    TPatient B("Бекзод Буюков", 2001, 13, "Здоров!");
    const TPatient& C(B);
    TPatient D;
    TPatient E;

    if (action == '1') {
        cout << "\nКонтруктор по умолчанию:\n";
        A.printObjectData();
        staticModeMenu();
    } else if (action == '2') {
        cout << "\nКонтруктор с параметрами:\n";
        B.printObjectData();
        staticModeMenu();
    } else if (action == '3') {
        cout << "\nКонтруктор копирования:\n";
        C.printObjectData();
        staticModeMenu();
    } else if (action == '4') {
        D.set();
        cout << "\nРезультат:\n";
        D.printObjectData();
        staticModeMenu();
    } else if (action == '5') {
        ofstream openedFile;
        openedFile = openFileForWriting();
        E.recordObjectDataToFile(openedFile);
        staticModeMenu();
    } else if (action == 'm') {
        staticModeMenu();
    } else if (action == '0') {
        mainMenu();
    } else {
        cout << NOT_CORRECT_ACTION_ERROR << endl;
        staticModeMenu();
    }

    return 0;
}

// pre entering step to dynamic mode menu
void preEnterToDynamicModeMenu() {
    ifstream readingFile;
    readingFile = openFileForReading();

    int size;
    size = getArraySize(readingFile);

    TPatient * array;
    array = fillFromFile(readingFile, size);

    dynamicModeMenu(array, size);
}

// Dynamic Mode Menu Function
int dynamicModeMenu(TPatient * array, int size) {
    string menuHeader = "\n-= ДИНАМИЧЕСКИЙ РЕЖИМ =-\n";
    cout << menuHeader;
    cout << "[/] - вывод:\n"
            "       [1] - данных массива в терминал\n"
            "       [2] - по диагнозу и диапазону года рождения\n"
            "       [3] - по интервалу номера медицинской карты\n"
            "       [4] - пациентов после указанного года рождения\n"
            "[/] - вывод сортировкой года рождения:\n"
            "       [5] - по возрастанию (>)\n"
            "       [6] - по уменьшению  (<)\n"
            "[7] - записать данные в файл\n"
            "[m] - вернуть меню\n"
            "[0] - главное меню" << endl;
    cout << BOTTOM_DIVIDER;

    char action;
    cout << CHOOSE_ACTION;
    cin >> action;

    if (action == '1') {
        printData(array, size);
        dynamicModeMenu(array, size);
    } else if (action == '2') {
        filterByDiagnosisAndYearOfBirth(array, size);
        dynamicModeMenu(array, size);
    } else if (action == '3') {
        filterByMedicineCardNumber(array, size);
        dynamicModeMenu(array, size);
    } else if (action == '4') {
        filterByYearOfBirth(array, size);
        dynamicModeMenu(array, size);
    } else if (action == '5') {
        sortByYearOfBirthIncreasingMode(array, size);
        dynamicModeMenu(array, size);
    } else if (action == '6') {
        sortByYearOfBirthDecreasingMode(array, size);
        dynamicModeMenu(array, size);
    } else if (action == '7') {
        ofstream writingFile;
        writingFile = openFileForWriting();
        recordDataTableToFile(array, size, writingFile);
        dynamicModeMenu(array, size);
    } else if (action == 'm') {
        dynamicModeMenu(array, size);
    } else if (action == '0') {
        mainMenu();
    } else {
        cout << NOT_CORRECT_ACTION_ERROR << endl;
        dynamicModeMenu(array, size);
    }

    return 0;
}