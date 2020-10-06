//
// Created by bek on 12.09.2020.
//

#include "header.h"
#define TYPE int

// function which returns randomly generated number from 1 to 15
/*int generateRandomNumber() {
    int number;
    number = rand() % 15 + 1;
    return number;
}*/

// function which returns randomly generated number of certain range
template <typename T>
T randomNumberInRange(int beginning, int end) {
    T number;
    int end_of_array;
    end_of_array = end - beginning;
    number = (rand() % end_of_array) + beginning;
    return number;
}

// method which prints object's array
template <typename T>
void Array<T>::print() {
    cout << "��� ������: ";
    for (int i = 0; i < getSize(); ++i) {
        cout << array[i] << "\t";
    }
    cout << endl;
}

// method for creating and filling massive by hand
template <typename T>
void Array<T>::fill() {
    int arraySize;
    cout << "\n������� ������ �������: ";
    cin >> arraySize;
    setSize(arraySize);

    setArray(new int[getSize()]);
    for (int i = 0; i < getSize(); ++i) {
        cout << "����� ��� " << i + 1 << "-��������: ";
        cin >> array[i];
    }
}

// method for filling array by numbers of certain range
template <typename T>
void Array<T>::fillByRange() {
    if (getRange() == 0) {
        int arraySize;
        cout << "������� ������ �������: ";
        cin >> arraySize;
        setSize(arraySize);
    }

    setArray(new T[size]);

    int beginningOfRange, endOfRange;
    if (getRange() == 0) {
        cout << "������ ���������: ";
        cin >> beginningOfRange;

        cout << "����� ���������: ";
        cin >> endOfRange;
    }

    beginningOfRange = 10;
    endOfRange = 900;

    // cout << "size: " << size << " beginning: " << beginning_of_range << " the end: " << end_of_range << endl;

    for (int i = 0; i < size; ++i) {
        array[i] = randomNumberInRange<TYPE>(beginningOfRange, endOfRange);
    }

}

// method for filling array by ordered numbers
template <typename T>
void Array<T>::orderedFill() {
    if (getRange() == 0) {
        int arraySize;
        cout << "������� ������ �������: ";
        cin >> arraySize;
        setSize(arraySize);
    }

    setArray(new T[getSize()]);

    for (int i = 0; i < size; ++i) {
        array[i] = i + 1;
    }
}

// method for filling array by unordered numbers
template <typename T>
void Array<T>::unorderedFill() {
    if (getRange() == 0) {
        int arraySize;
        cout << "������� ������ �������: ";
        cin >> arraySize;
        setSize(arraySize);
    }

    setArray(new T[getSize()]);

    for (int i = 0; i < size; ++i) {
        array[i] = size - i;
    }
}

// recording array to file
template <typename T>
void Array<T>::recordArrayToFile() {
    string fileName;
    if (getRange() == 0) {
        cout << "������� ��������� .txt �����: ";
        cin >> fileName;
    }
    else {
        fileName = "file-001";
    }

    // cout << fileName << endl;

    // ofstream file(fileName + ".txt", fstream::app);
    fstream file;
    file.open(fileName + ".txt", std::fstream::out | std::fstream::app);

    if (!file) {
        cout << "�� ������� ������� ���� ��� ������..." << endl;
    }

    if (getRange() == 0) {
        for (int i = 0; i < getSize(); ++i) {
            if (i % 100 == 0) {
                file << "\n";
            }
            file << " " << array[i];
        }
        file << "\n��������� �������: " << getSpentTime() << " �����-���."
            << "\n���������: " << getComparisons()
            << "\n������������: " << getRearrangements() << endl;
        file << "\n\n\n";
    }
    else {
        string sortingMethodDefaultName = "method not used";
        if (getSortingMethodName().length() != sortingMethodDefaultName.length()) {
            file << "����� ����������: " << getSortingMethodName() << endl;
        }
        file << "�� ���������� " << getSize() << " ���������, ��������� �������: "
            << getSpentTime() << " ��.\n" << endl;
    }
    file.close();
}

// sorting methods
// Select Sort
template <typename T>
void Array<T>::selectSort() {
    setSortingMethodName("selectSort");

    int i, j, x, k;
    clock_t startTime, endTime;
    int comparisonsCounter, rearrangementCounter;
    comparisonsCounter = 0;
    rearrangementCounter = 0;

    // time(&startTime);
    startTime = clock();
    for (i = 0; i < size; i++) {   	// i - ����� �������� ����
        k = i;
        x = array[i];

        for (j = i + 1; j < size; j++) {    // ���� ������ ����������� ��������
            comparisonsCounter++;
            if (array[j] < x) {
                k = j;
                rearrangementCounter++;
                x = array[j];            // k - ������ ����������� ��������
            }
            // ������ ������� ���������� � a[i]
        }
        rearrangementCounter++;
        array[k] = array[i];
        array[i] = x;

    }
    // time(&endTime);
    endTime = clock();
    setSpentTime(endTime - startTime);
    setComparisons(comparisonsCounter);
    setRearrangements(rearrangementCounter);
    if (getRange() == 0) {
        cout << "��������� �������: " << getSpentTime() << " �����-���."
            << "\n���������: " << getComparisons()
            << "\n������������: " << getRearrangements() << endl;
    }
}

// Insert Sort
template <typename T>
void Array<T>::insertSort() {
    setSortingMethodName("insertSort");

    int i, j, x;
    clock_t startTime, endTime;
    int comparisonsCounter, rearrangementCounter;
    comparisonsCounter = 0;
    rearrangementCounter = 0;

    startTime = clock();
    for (i = 0; i < size; i++) {  // ���� ��������, i - ����� �������
        x = array[i];

        // ����� ����� �������� � ������� ������������������
        for (j = i - 1; j >= 0 && array[j] > x; j--) {
            // array[j + 1] > array[j];
            comparisonsCounter++;
            rearrangementCounter++;
            array[j + 1] = array[j];    // �������� ������� �������, ���� �� �����
        }
        rearrangementCounter++;
        // ����� �������, �������� �������
        array[j + 1] = x;
    }
    endTime = clock();
    setSpentTime((endTime - startTime));
    setComparisons(comparisonsCounter);
    setRearrangements(rearrangementCounter);
    if (getRange() == 0) {
        cout << "��������� �������: " << getSpentTime() << " �����-���."
            << "\n���������: " << getComparisons()
            << "\n������������: " << getRearrangements() << endl;
    }
    
}

// function for creating array by given range and increasing step
template <typename T>
void Array<T>::setArrayRangeAndIncreasingStep() {
    int arrayRange;
    cout << "�������� �������: ";
    cin >> arrayRange;

    int increasingStep;
    cout << "������� ��� ���������: ";
    cin >> increasingStep;    

    if (increasingStep > arrayRange) {
        cout << "��� �� ����� ���� ������ ��� ��������!" << endl;
        setArrayRangeAndIncreasingStep();
    }
    else if (increasingStep == arrayRange) {
        cout << "��� �� ����� ���� ����� ���������!" << endl;
        setArrayRangeAndIncreasingStep();
    }
    else if (increasingStep < 0) {
        cout << "��� ���������� �� ����� ���� �������������!" << endl;
        setArrayRangeAndIncreasingStep();
    }

    setRange(arrayRange);
    setStep(increasingStep);

    // workWithArrays();
}

// function for working with arrays size of which are in given range (and increases by increasingStep)
template <typename T>
void Array<T>::workWithArrays() {
    int stepsSize;
    stepsSize = getRange() / getStep();

    char action;
    cout << "�������� ����� ���������� ������ � ����������:\n"
        "   - ��������� �����:\n"
        "       [1] - ���������� � �������\n"
        "       [2] - ���������� � �����������\n"
        "   - ������������� ������������������\n"
        "       [3] - ���������� � �������\n"
        "       [4] - ���������� � �����������\n"
        "   - �� ������������� ������������������\n"
        "       [5] - ���������� � �������\n"
        "       [6] - ���������� � �����������\n"
        "[0] - ��������� �� ������ �����" << endl;
    cout << "�������� ��������: ";
    cin >> action;

    int currentArraySize = 0;
    if (action == '1') {
        for (int i = 0; i < stepsSize; ++i) {
            currentArraySize += getStep();
            setSize(currentArraySize);
            fillByRange();
            selectSort();
            setSortingMethodName("selectSort");
            recordArrayToFile();
        }
        cout << "������� ����������!" << endl;
        workWithArrays();
    }
    else if (action == '2') {
        for (int i = 0; i < stepsSize; ++i) {
            currentArraySize += getStep();
            setSize(currentArraySize);
            fillByRange();
            insertSort();
            setSortingMethodName("insertSort");
            recordArrayToFile();
        }
        cout << "������� ����������!" << endl;
        workWithArrays();
    }
    else if (action == '3') {
        for (int i = 0; i < stepsSize; ++i) {
            currentArraySize += getStep();
            setSize(currentArraySize);
            orderedFill();
            selectSort();
            recordArrayToFile();
        }
        cout << "������� ����������!" << endl;
        workWithArrays();
    }
    else if (action == '4') {
        for (int i = 0; i < stepsSize; ++i) {
            currentArraySize += getStep();
            setSize(currentArraySize);
            orderedFill();
            insertSort();
            recordArrayToFile();
        }
        cout << "������� ����������!" << endl;
        workWithArrays();
    }
    else if (action == '5') {
        for (int i = 0; i < stepsSize; ++i) {
            currentArraySize += getStep();
            setSize(currentArraySize);
            unorderedFill();
            selectSort();
            recordArrayToFile();
        }
        cout << "������� ����������!" << endl;
        workWithArrays();
    }
    else if (action == '6') {
        for (int i = 0; i < stepsSize; ++i) {
            currentArraySize += getStep();
            setSize(currentArraySize);
            unorderedFill();
            insertSort();
            recordArrayToFile();
        }
        cout << "������� ����������!" << endl;
        workWithArrays();
    }
    else if (action == '0') {
        secondModeMenu();
    }
    else {
        workWithArrays();
    }

}

