#pragma once

#include <iostream>
#include <Windows.h>
using namespace std;

class StorageDev {
	int driveSize;								// memory drive device size
	string pyhsicalInterface;					// physical interface of memory drive device
	int releaseYear;							// release year of memory drive device
	string manufacturerBrand;					// brand name of manufacture company
	int cost;									// memory drive device cost at shop
public:
	void printStatistics();						// printing statistics for memory drive device
};

class HDD : public StorageDev {
	string memoryChipType;						// memory chip type
};

class SSD : public StorageDev {
	int spindleRotationSpeed;					// speed of rotation of spindle
};

class FlashD : public StorageDev {
	double usbType;								// type of USB connection
};

class Shop {
	int arraySize;								// array size
	StorageDev* array = new StorageDev[arraySize];			// declaring object dynamically
public:
	void filterByClassAndSortByIncreasing();	// printing objects which are filtere
	void filterByMemorySizeRange();				// filtering and printing objects memory size of which in given range
};
