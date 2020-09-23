//
// Created by bek on 12.09.2020.
//

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <random>
#include <ostream>
#include <fstream>
using namespace std;

// class Array
class Array {
    // class fields
    int size{};                                 // array size
    int* array{};                               // array pointer
    double spentTime{};                           // time spent for sorting
    int comparisons{};                            // comparisons number while sorting
    int rearrangements{};                         // rearrangements number while sorting
    int step{};
    int range{};
    string sortingMethodName;
public:
    // constructors
    Array();                                    // default constructor
    Array(int * newArray, int newSize);         // constructor with parameters
    Array(const Array & A);                     // copying constructor
    ~Array();                                   // destructor

    // methods
    void fill();
    void print();
    void fillByRange();
    void orderedFill();
    void unorderedFill();
    void recordArrayToFile();
    void setArrayRangeAndIncreasingStep();
    void workWithArrays();

    // Getters
    [[nodiscard]] int getSize() const;
    [[nodiscard]] int *getArray() const;
    [[nodiscard]] double getSpentTime() const;
    [[nodiscard]] int getComparisons() const;
    [[nodiscard]] int getRearrangements() const;
    [[nodiscard]] int getStep() const;
    [[nodiscard]] int getRange() const;
    [[nodiscard]] const string &getSortingMethodName() const;

    // Setters
    void setSize(int size);
    void setArray(int *array);
    void setSpentTime(double spentTime);
    void setComparisons(int comparisons);
    void setRearrangements(int rearrangements);
    void setStep(int step);
    void setRange(int range);
    void setSortingMethodName(const string &sortingMethodName);

    // sorting methods
    void insertSort();
    void selectSort();
};

// other functions
int generateRandomNumber();
int randomNumberInRange(int beginning, int end);

// menu functions
int mainMenu();
int firstModeMenu();
int secondModeMenu();

template<class T>
void selectSort(T a[], long size);