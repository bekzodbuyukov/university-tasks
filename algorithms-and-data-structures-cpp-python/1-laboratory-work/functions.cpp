//
// Created by bek on 12.09.2020.
//

#include "header.h"

// function which returns randomly generated number from 1 to 15
int generateRandomNumber() {
    int number;
    number = rand() % 15 + 1;
    return number;
}

// function which returns randomly generated number of certain range
int randomNumberInRange(int beginning, int end) {
    int number, end_of_array;
    end_of_array = end - beginning;
    number = (rand() % end_of_array) + beginning;
    return number;
}

// method which prints object's array
void Array::print() {
    cout << "Ваш массив: ";
    for (int i = 0; i < getSize(); ++i) {
        cout << array[i] << "\t";
    }
    cout << endl;
}

// method for creating and filling massive by hand
void Array::fill() {
    int arraySize;
    cout << "\nВведите размер массива: ";
    cin >> arraySize;
    setSize(arraySize);

    setArray(new int[getSize()]);
    for (int i = 0; i < getSize(); ++i) {
        cout << "Число для " << i + 1 << "-элемента: ";
        cin >> array[i];
    }
}

// method for filling array by numbers of certain range
void Array::fillByRange() {
    if (getRange() == 0) {
        int arraySize;
        cout << "Введите размер массива: ";
        cin >> arraySize;
        setSize(arraySize);
    }

    setArray(new int[size]);

    int beginningOfRange, endOfRange;
    if (getRange() == 0) {
        cout << "Начало диапазона: ";
        cin >> beginningOfRange;

        cout << "Конец диапазона: ";
        cin >> endOfRange;
    }

    beginningOfRange = 10;
    endOfRange = 900;

    // cout << "size: " << size << " beginning: " << beginning_of_range << " the end: " << end_of_range << endl;

    for (int i = 0; i < size; ++i) {
        array[i] = randomNumberInRange(beginningOfRange, endOfRange);
    }

}

// method for filling array by ordered numbers
void Array::orderedFill() {
    if (getRange() == 0) {
        int arraySize;
        cout << "Введите размер массива: ";
        cin >> arraySize;
        setSize(arraySize);
    }

    setArray(new int[getSize()]);

    for (int i = 0; i < size; ++i) {
        array[i] = i + 1;
    }
}

// method for filling array by unordered numbers
void Array::unorderedFill() {
    if (getRange() == 0) {
        int arraySize;
        cout << "Введите размер массива: ";
        cin >> arraySize;
        setSize(arraySize);
    }

    setArray(new int[getSize()]);

    for (int i = 0; i < size; ++i) {
        array[i] = size - i;
    }
}

// recording array to file
void Array::recordArrayToFile() {
    string fileName;
    if (getRange() == 0) {
        cout << "Введите называние .txt файла: ";
        cin >> fileName;
    } else {
        fileName += "file001";
    }

    // cout << fileName << endl;

    ofstream file(fileName + ".txt", ios::app);

    if(!file){
        cout << "Не удалось открыть файл для записи..." << endl;
    }

    if (getRange() == 0) {
        for (int i = 0; i < getSize(); ++i) {
            if (i % 100 == 0) {
                file << "\n";
            }
            file << " " << array[i];
        }
        file << "\nПотрачено времени: " << getSpentTime() << " мc."
             << "\nСравнений: " << getComparisons()
             << "\nПерестановок: " << getRearrangements() << endl;
        file << "\n\n\n";
    } else {
        string sortingMethodDefaultName = "method not used";
        if (getSortingMethodName().length() != sortingMethodDefaultName.length()) {
            file << "Метод сортивроки: " << getSortingMethodName() << endl;
        }
        file << "На сортировку " << getSize() << " элементов, потрачено времени: "
        << getSpentTime() << " мс.\n" << endl;
    }
}

// sorting methods
// Select Sort
void Array::selectSort() {
    int i, j, x, k;
    unsigned int startTime, endTime;
    int comparisonsCounter, rearrangementCounter;
    comparisonsCounter = 0;
    rearrangementCounter = 0;

    startTime = clock();
    for(i = 0; i < size; i++) {   	// i - номер текущего шага
        k = i;
        x = array[i];

        for(j = i + 1; j < size; j++) {    // цикл выбора наименьшего элемента
            comparisonsCounter++;
            if (array[j] < x) {
                k = j;
                rearrangementCounter++;
                x = array[j];            // k - индекс наименьшего элемента
            }
               	// меняем местами наименьший с a[i]
        }
        rearrangementCounter++;
        array[k] = array[i];
        array[i] = x;

    }
    endTime = clock();
    setSpentTime((endTime - startTime) / 1000.0);
    setComparisons(comparisonsCounter);
    setRearrangements(rearrangementCounter);
    if (getRange() == 0) {
        cout << "Потрачено времени: " << getSpentTime() << " милли-сек."
             << "\nСравнений: " << getComparisons()
             << "\nПерестановок: " << getRearrangements() << endl;
    }
}

// Insert Sort
void Array::insertSort() {
    int i, j, x;
    unsigned int startTime, endTime;
    int comparisonsCounter, rearrangementCounter;
    comparisonsCounter = 0;
    rearrangementCounter = 0;

    startTime = clock();
    for (i = 0; i < size; i++) {  // цикл проходов, i - номер прохода
        x = array[i];

        // поиск места элемента в готовой последовательности
        for (j = i - 1; j >= 0 && array[j] > x; j--) {
            // array[j + 1] > array[j];
            comparisonsCounter++;
            rearrangementCounter++;
            array[j + 1] = array[j];    // сдвигаем элемент направо, пока не дошли
        }
        rearrangementCounter++;
        // место найдено, вставить элемент
        array[j + 1] = x;
    }
    endTime = clock();
    setSpentTime((endTime - startTime) / 1000.0);
    setComparisons(comparisonsCounter);
    setRearrangements(rearrangementCounter);
    if (getRange() == 0) {
        cout << "Потрачено времени: " << getSpentTime() << " милли-сек."
             << "\nСравнений: " << getComparisons()
             << "\nПерестановок: " << getRearrangements() << endl;
    }

}

// function for creating array by given range and increasing step
void Array::setArrayRangeAndIncreasingStep() {
    int arrayRange;
    cout << "Диапазон миссива: ";
    cin >> arrayRange;

    int increasingStep;
    cout << "Введите шаг изменения: ";
    cin >> increasingStep;

    if (increasingStep > arrayRange) {
        cout << "Шаг не может быть больше чем диапазон!" << endl;
        setArrayRangeAndIncreasingStep();
    } else if (increasingStep == arrayRange) {
        cout << "Шаг не может быть равен диапазону!" << endl;
        setArrayRangeAndIncreasingStep();
    } else if (increasingStep < 0) {
        cout << "Шаг увеличения не может быть отрицательным!" << endl;
        setArrayRangeAndIncreasingStep();
    }

    setRange(arrayRange);
    setStep(increasingStep);

    workWithArrays();
}

// function for working with arrays size of which are in given range (and increases by increasingStep)
void Array::workWithArrays() {
    int stepsSize;
    stepsSize = getRange() / getStep();

    char action;
    cout << "Выберите метод заполнения данных и сортировку:\n"
            "   - случайные числа:\n"
            "       [1] - сортировка с выбором\n"
            "       [2] - сортировка с включениями\n"
            "   - упорядоченная последовательность\n"
            "       [3] - сортировка с выбором\n"
            "       [4] - сортировка с включениями\n"
            "   - не упорядоченная последовательность\n"
            "       [5] - сортировка с выбором\n"
            "       [6] - сортировка с включениями\n"
            "[0] - вернуться на второй режим" << endl;
    cout << "Выберите действие: ";
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
        cout << "Процесс закончился!" << endl;
        workWithArrays();
    } else if (action == '2') {
        for (int i = 0; i < stepsSize; ++i) {
            currentArraySize += getStep();
            setSize(currentArraySize);
            fillByRange();
            insertSort();
            setSortingMethodName("insertSort");
            recordArrayToFile();
        }
        cout << "Процесс закончился!" << endl;
        workWithArrays();
    } else if (action == '3') {
        for (int i = 0; i < stepsSize; ++i) {
            currentArraySize += getStep();
            setSize(currentArraySize);
            orderedFill();
            selectSort();
            recordArrayToFile();
        }
        cout << "Процесс закончился!" << endl;
        workWithArrays();
    } else if (action == '4') {
        for (int i = 0; i < stepsSize; ++i) {
            currentArraySize += getStep();
            setSize(currentArraySize);
            orderedFill();
            insertSort();
            recordArrayToFile();
        }
        cout << "Процесс закончился!" << endl;
        workWithArrays();
    } else if (action == '5') {
        for (int i = 0; i < stepsSize; ++i) {
            currentArraySize += getStep();
            setSize(currentArraySize);
            unorderedFill();
            selectSort();
            recordArrayToFile();
        }
        cout << "Процесс закончился!" << endl;
        workWithArrays();
    } else if (action == '6') {
        for (int i = 0; i < stepsSize; ++i) {
            currentArraySize += getStep();
            setSize(currentArraySize);
            unorderedFill();
            insertSort();
            recordArrayToFile();
        }
        cout << "Процесс закончился!" << endl;
        workWithArrays();
    } else if (action == '0') {
        secondModeMenu();
    } else {
        workWithArrays();
    }

}

