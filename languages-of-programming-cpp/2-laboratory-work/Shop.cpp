//
// Created by bek on 10/14/20.
//

#include "Header.h"


// constructors
Shop::Shop() {
    setArraySize(0);
}

Shop::Shop(Shop &T) {
    setArray(T.getArray());
}

Shop::Shop(int arraySize) {
    setArraySize(arraySize);
}

// destructor
Shop::~Shop() {
    cout << "Деструктор класса: Shop" << endl;
}

// setters
void Shop::setArraySize(int arrayNewSize) {
    Shop::arraySize = arrayNewSize;
}

void Shop::setArray(StorageDev * newArray) {
    Shop::array = &newArray;
}

// getters
int Shop::getArraySize() const {
    return arraySize;
}

StorageDev *Shop::getArray() const {
    return *array;
}

// methods
void Shop::filterByClassAndSortByIncreasing() {
    StorageDev * tempObject;
    for (int i = 0; i < arraySize; ++i) {
        for (int j = arraySize - 1; j > i; --j) {
            if (array[j - 1]->getDriveSize() > array[j]->getDriveSize()) {
                tempObject = array[j - 1];
                array[j - 1] = array[j];
                array[j] = tempObject;
            }
        }
    }
}

void Shop::filterByMemorySizeRange(int starting, int ending) {
    for (int i = 0; i < arraySize; ++i) {
        if (array[i]->getDriveSize() > starting && array[i]->getDriveSize() < ending) {
            array[i]->print();
        }
    }
}

void Shop::generateArray() {
    array = new StorageDev*[arraySize];
    int number;

    for (int i = 0; i < arraySize; ++i) {
        number = rand() % 3;
        if (number == 0) {
            array[i] = new HDD();
            array[i]->setRandomValue();
        } else if (number == 1) {
            array[i] = new SSD();
            array[i]->setRandomValue();
        } else {
            array[i] = new FlashD();
            array[i]->setRandomValue();
        }
    }
}

void Shop::printArray() {
    for (int i = 0; i < arraySize; ++i) {
        cout << "[" << i + 1 << "] ";
        array[i]->print();
    }
}

void Shop::showStatistics() {
    filterByClassAndSortByIncreasing();

    int hddCounter = 0,
    ssdCounter = 0,
    flashDCounter = 0;

    StorageDev ** HDD, ** SSD, ** FlashD;
    vector<int> indexHDDArray;
    vector<int> indexSSDArray;
    vector<int> indexFlashDArray;

    for (int i = 0; i < arraySize; ++i) {
        if (array[i]->myName() == "HDD") {
            hddCounter += 1;
            indexHDDArray.push_back(i);
        } else if (array[i]->myName() == "SSD") {
            ssdCounter += 1;
            indexSSDArray.push_back(i);
        } else {
            flashDCounter += 1;
            indexFlashDArray.push_back(i);
        }
    }

    HDD = new StorageDev*[hddCounter];
    SSD = new StorageDev*[ssdCounter];
    FlashD = new StorageDev*[flashDCounter];

    cout << "Массив объектов класса: HDD" << endl;
    for (int i = 0; i < hddCounter; ++i) {
        HDD[i] = array[indexHDDArray[i]];
        HDD[i]->print();
    }

    cout << "Статистика HDD:\n"
            "   - Самый маленький по емкости носитель:\n";
    HDD[0]->print();
    cout << "       - Соотношение объем/цена: " << HDD[0]->getDriveSize() << "мб / "
         << HDD[0]->getCost() << "$\n" << endl;

    cout << "   - Самый большой по емкости наоситель:\n";
    HDD[hddCounter - 1]->print();
    cout << "       - Соотношение объем/цена: " << HDD[hddCounter - 1]->getDriveSize() << "мб / "
         << HDD[hddCounter - 1]->getCost() << "$\n" << endl;

    cout << "Массив объектов класса: SSD" << endl;
    for (int i = 0; i < ssdCounter; ++i) {
        SSD[i] = array[indexSSDArray[i]];
        SSD[i]->print();
    }

    cout << "Статистика SSD:\n"
            "   - Самый маленький по емкости носитель:\n";
    SSD[0]->print();
    cout << "       - Соотношение объем/цена: " << SSD[0]->getDriveSize() << "мб / "
         << SSD[0]->getCost() << "$\n" << endl;

    cout << "   - Самый большой по емкости наоситель:\n";
    SSD[ssdCounter - 1]->print();
    cout << "       - Соотношение объем/цена: " << SSD[ssdCounter - 1]->getDriveSize() << "мб / "
         << SSD[ssdCounter - 1]->getCost() << "$\n" << endl;

    cout << "Массив объектов класса: FlashD" << endl;
    for (int i = 0; i < flashDCounter; ++i) {
        FlashD[i] = array[indexFlashDArray[i]];
        FlashD[i]->print();
    }

    cout << "Статистика FlashD:\n"
            "   - Самый маленький по емкости носитель:\n";
    FlashD[0]->print();
    cout << "       - Соотношение объем/цена: " << FlashD[0]->getDriveSize() << "мб / "
         << FlashD[0]->getCost() << "$\n" << endl;

    cout << "   - Самый большой по емкости наоситель:\n";
    FlashD[flashDCounter - 1]->print();
    cout << "       - Соотношение объем/цена: " << FlashD[flashDCounter - 1]->getDriveSize() << "мб / "
         << FlashD[flashDCounter - 1]->getCost() << "$\n" << endl;

    StorageDev* minElement, * maxElement;
    minElement = array[0];
    maxElement = array[arraySize - 1];

    cout << "Статистика:\n"
            "   - Самый маленький по емкости носитель:\n";
    minElement->print();
    cout << "       - Соотношение объем/цена: " << minElement->getDriveSize() << "мб / "
    << minElement->getCost() << "$\n" << endl;

    cout << "   - Самый большой по емкости наоситель:\n";
    maxElement->print();
    cout << "       - Соотношение объем/цена: " << maxElement->getDriveSize() << "мб / "
    << maxElement->getCost() << "$\n" << endl;

    cout << "   - HDD в массиве: " << hddCounter << " шт.\n" <<
    "   - SSD в массиве: " << ssdCounter << " шт.\n" <<
    "   - FlashD в массиве: " << flashDCounter << " шт." << endl;

}

void Shop::setAnElement(int indexOfAnElement) {
    array[indexOfAnElement]->print();
    array[indexOfAnElement]->set();
}
