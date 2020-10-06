//
// Created by bek on 17.09.2020.
//

#include "header.h"
#include "Functions.cpp"
//#include "Source.cpp"
#include "Constructors.cpp"
#define NOT_EXISTING_COMMAND_ERROR_MESSAGE "������: �� ������������ ��������, ���������� �����..."
#define BOTTOM_SEPARATOR "_-_-_-_-_-_-_-_-_-_-_-_-_"
#define TYPE int

int mainMenu() {
    string top_separator, bottom_separator;
    top_separator = "\n_-_-_- ������� ���� -_-_-_\n";
    bottom_separator = "_-_-_-_-_-_-_-_-_-_-_-_-_-\n";
    char action;
    cout << top_separator;
    cout << "[1] - ������ �����\n"
        "[2] - ������ �����\n"
        "[q] - ��������� ������" << endl;
    cout << BOTTOM_SEPARATOR << endl;
    cout << "�������� ��������: ";
    cin >> action;

    if (action == '1') {
        firstModeMenu();
    }
    else if (action == '2') {
        secondModeMenu();
    }
    else if (action == 'q') {
        return 0;
    }
    else {
        cout << NOT_EXISTING_COMMAND_ERROR_MESSAGE << endl;
        mainMenu();
    }

    return 0;
}

int firstModeMenu() {
    string top_separator, bottom_separator;
    top_separator = "\n_-_-_- ������ ����� -_-_-_\n";
    bottom_separator = "_-_-_-_-_-_-_-_-_-_-_-_-_\n";
    char action;
    cout << top_separator;

    cout << "[/] - ������� ������ � ��������� ���������� � ������� �� ����:\n"
        "       [1] - ������� �������\n"
        "       [2] - �������� �����������\n"
        "[0] - ��������� � ������� ����" << endl;

    cout << BOTTOM_SEPARATOR << endl;
    cout << "�������� ��������: ";
    cin >> action;

    if (action == '9') {
        Array<TYPE> A;
        A.fillByRange();
        // A.print();
        A.recordArrayToFile();
        cout << "������ ������� ������, �������� � ������� � ����!" << endl;
        firstModeMenu();
    }
    else if (action == '1') {
        Array<TYPE> A;
        // operations
        A.fillByRange();
        A.recordArrayToFile();
        A.print();
        A.selectSort();
        A.print();
        A.recordArrayToFile();
        // getting back to menu
        firstModeMenu();
    }
    else if (action == '2') {
        Array<TYPE> A;
        // operations
        A.fillByRange();
        A.recordArrayToFile();
        A.print();
        A.insertSort();
        A.print();
        A.recordArrayToFile();
        // getting back to menu
        firstModeMenu();
    }
    else if (action == '0') {
        mainMenu();
    }
    else {
        cout << NOT_EXISTING_COMMAND_ERROR_MESSAGE << endl;
        firstModeMenu();
    }

    return 0;
}

int secondModeMenu() {
    string top_separator, bottom_separator;
    top_separator = "\n_-_-_- ������ ����� -_-_-_\n";
    bottom_separator = "_-_-_-_-_-_-_-_-_-_-_-_-_\n";
    char action;
    cout << top_separator;

    cout << "[/] - ������� ������ ������������ ��������� �������:\n"
        "   [/] - ��������� ��������\n"
        "       [1] - ���������� � �������\n"
        "       [2] - ���������� � �����������\n"
        "   [/] - ������������� ������������������ ��������\n"
        "       [3] - ���������� � �������\n"
        "       [4] - ���������� � �����������\n"
        "   [/] - �������� ����������� � �������� �������\n"
        "       [5] - ���������� � �������\n"
        "       [6] - ���������� � �����������\n"
        "[7] - �������� �������� � ��� ��������� �������� �������\n"
        "[0] - ��������� � ������� ����" << endl;

    cout << BOTTOM_SEPARATOR << endl;
    cout << "�������� ��������: ";
    cin >> action;

    if (action == '1') {
        Array<TYPE> A;
        A.fillByRange();
        A.recordArrayToFile();
        A.selectSort();
        A.recordArrayToFile();
        secondModeMenu();
    }
    else if (action == '2') {
        Array<TYPE> B;
        B.fillByRange();
        B.recordArrayToFile();
        B.insertSort();
        B.recordArrayToFile();
        secondModeMenu();
    }
    else if (action == '3') {
        Array<TYPE> C;
        C.orderedFill();
        C.recordArrayToFile();
        C.selectSort();
        C.recordArrayToFile();
        secondModeMenu();
    }
    else if (action == '4') {
        Array<TYPE> D;
        D.orderedFill();
        D.recordArrayToFile();
        D.insertSort();
        D.recordArrayToFile();
        secondModeMenu();
    }
    else if (action == '5') {
        Array<TYPE> E;
        E.unorderedFill();
        E.recordArrayToFile();
        E.selectSort();
        E.recordArrayToFile();
        secondModeMenu();
    }
    else if (action == '6') {
        Array<TYPE> F;
        F.unorderedFill();
        F.recordArrayToFile();
        F.insertSort();
        F.recordArrayToFile();
        secondModeMenu();
    }
    else if (action == '7') {
        Array<TYPE> J;
        J.setArrayRangeAndIncreasingStep();
        J.workWithArrays();
        secondModeMenu();
    }
    else if (action == '0') {
        mainMenu();
    }
    else {
        cout << NOT_EXISTING_COMMAND_ERROR_MESSAGE << endl;
        firstModeMenu();
    }

    return 0;
}
