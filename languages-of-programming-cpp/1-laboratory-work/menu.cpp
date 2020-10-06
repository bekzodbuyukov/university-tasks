//
// Created by bek on 18.09.2020.
//

#include "header.h"

#define CHOOSE_ACTION "\n�������� ��������: "
#define NOT_CORRECT_ACTION_ERROR "������: �� ������� �� ������������ ��������, ���������� ���������� �����."
#define BOTTOM_DIVIDER "-=-=-=-=-=-=-=-=-=-=-=-\n"
#define CLEAR_CMD system("cls");

// Main Menu Function
int mainMenu() {
    string menuHeader = "\n-=-=-=-= ���� =-=-=-=-\n";
    char action;

    cout << menuHeader;
    cout << "[1] - ����������� �����\n"
        "[2] - ������������ �����\n"
        "[m] - ������� ����\n"
        "[q] - ��������� ������" << endl;
    cout << BOTTOM_DIVIDER;

    cout << CHOOSE_ACTION;
    cin >> action;

    if (action == '1') {
        CLEAR_CMD
        staticModeMenu();
    }
    else if (action == '2') {
        CLEAR_CMD
        preEnterToDynamicModeMenu();
    }
    else if (action == 'm') {
        CLEAR_CMD
        system("cls");
        mainMenu();
    }
    else if (action == 'q') {
        return 0;
    }
    else {
        CLEAR_CMD
        cout << NOT_CORRECT_ACTION_ERROR << endl;
        mainMenu();
    }


    return 0;
}

// Static Mode Menu Function
int staticModeMenu() {
    string menuHeader = "\n-= ����������� ����� =-\n";
    cout << menuHeader;

    cout << "[1] - ����������� �� ���������\n"
        "[2] - ����������� � �����������\n"
        "[3] - ����������� �����������\n"
        "[4] - ���������� ������ ��� ������ �������\n"
        "[5] - ������ ������� � ����\n"
        "[m] - ������� ����\n"
        "[0] - ������� ����" << endl;
    cout << BOTTOM_DIVIDER;

    char action;
    cout << CHOOSE_ACTION;
    cin >> action;
    
    TPatient A;
    TPatient B(0, "������ ������", 2001, 13, "������!");
    const TPatient& C(B);
    TPatient D;
    TPatient E;

    if (action == '1') {
        CLEAR_CMD
        cout << "\n���������� �� ���������:\n";
        A.printObjectData();
        staticModeMenu();
    }
    else if (action == '2') {
        CLEAR_CMD
        cout << "\n���������� � �����������:\n";
        B.printObjectData();
        staticModeMenu();
    }
    else if (action == '3') {
        CLEAR_CMD
        cout << "\n���������� �����������:\n";
        C.printObjectData();
        staticModeMenu();
    }
    else if (action == '4') {
        CLEAR_CMD
        D.set();
        CLEAR_CMD
        cout << "\n���������:\n";
        D.printObjectData();
        staticModeMenu();
    }
    else if (action == '5') {
        CLEAR_CMD
        ofstream openedFile;
        openedFile = openFileForWriting();
        E.recordObjectDataToFile(openedFile);
        staticModeMenu();
    }
    else if (action == 'm') {
        CLEAR_CMD
        staticModeMenu();
    }
    else if (action == '0') {
        CLEAR_CMD
        mainMenu();
    }
    else {
        CLEAR_CMD
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

    TPatient* array;
    array = fillFromFile(readingFile, size);
    CLEAR_CMD
    dynamicModeMenu(array, size);
}

// Dynamic Mode Menu Function
int dynamicModeMenu(TPatient* array, int size) {
    string menuHeader = "\n-= ������������ ����� =-\n";
    cout << menuHeader;
    cout << "[/] - �����:\n"
        "       [1] - ������ ������� � ��������\n"
        "       [2] - �� �������� � ��������� ���� ��������\n"
        "       [3] - �� ��������� ������ ����������� �����\n"
        "       [4] - ��������� ����� ���������� ���� ��������\n"
        "[/] - ����� ����������� ���� ��������:\n"
        "       [5] - �� ����������� (>)\n"
        "       [6] - �� ����������  (<)\n"
        "[7] - �������� ������ � ����\n"
        "[m] - ������� ����\n"
        "[0] - ������� ����" << endl;
    cout << BOTTOM_DIVIDER;

    char action;
    cout << CHOOSE_ACTION;
    cin >> action;

    if (action == '1') {
        CLEAR_CMD
        printData(array, size);
        dynamicModeMenu(array, size);
    }
    else if (action == '2') {
        CLEAR_CMD
        filterByDiagnosisAndYearOfBirth(array, size);
        dynamicModeMenu(array, size);
    }
    else if (action == '3') {
        CLEAR_CMD
        filterByMedicineCardNumber(array, size);
        dynamicModeMenu(array, size);
    }
    else if (action == '4') {
        CLEAR_CMD
        filterByYearOfBirth(array, size);
        dynamicModeMenu(array, size);
    }
    else if (action == '5') {
        CLEAR_CMD
        sortByYearOfBirthIncreasingMode(array, size);
        dynamicModeMenu(array, size);
    }
    else if (action == '6') {
        CLEAR_CMD
        sortByYearOfBirthDecreasingMode(array, size);
        dynamicModeMenu(array, size);
    }
    else if (action == '7') {
        CLEAR_CMD
        ofstream writingFile;
        writingFile = openFileForWriting();
        recordDataTableToFile(array, size, writingFile);
        dynamicModeMenu(array, size);
    }
    else if (action == 'm') {
        CLEAR_CMD
        dynamicModeMenu(array, size);
    }
    else if (action == '0') {
        CLEAR_CMD
        mainMenu();
    }
    else {
        CLEAR_CMD
        cout << NOT_CORRECT_ACTION_ERROR << endl;
        dynamicModeMenu(array, size);
    }

    return 0;
}