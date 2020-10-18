#include <iostream>
#include <cstdlib>
#include <ctime>
#include <random>
#include <string>
#include <vector>
using namespace std;

/*
 * Constructors: default, copying, with parameters
 * Destructor
 * virtual function MName() which gives name of the current working Class
 * In Base Class create GenerateRandomValue() function, which gets the array size,
 * this method will choose one of child-classes and fills it using child-class's SetRandomValue() method
 * For child-classes:
 *      setting values from terminal
 *      randomly setting values using SetRandomValue() method
 *      changing values*/

class StorageDev {
protected:
	int driveSize{};						    // memory drive device size
	int releaseYear{};							// release year of memory drive device
	string manufacturerBrand;					// brand name of manufacture company
	int cost{};									// memory drive device cost at shop
public:
    // constructors
    StorageDev();
    StorageDev(StorageDev& T);
    StorageDev(int driveNewSize, int newReleaseYear, const string& newManufacturerBrand, int newCost);

    // destructor
    ~StorageDev();

    // setter
    void setDriveSize(int driveSize);
    void setReleaseYear(int releaseYear);
    void setManufacturerBrand(const string &manufacturerBrand);
    void setCost(int cost);

    // getters
    [[nodiscard]] int getDriveSize() const;
    [[nodiscard]] int getReleaseYear() const;
    [[nodiscard]] const string &getManufacturerBrand() const;
    [[nodiscard]] int getCost() const;

    // methods
	virtual void print() =0;
    virtual void setRandomValue() =0;
	virtual string myName() =0;                      // prints the name of Class
	virtual void set() =0;
};

class HDD : public StorageDev {
	string memoryChipType;						// memory chip type
public:
    // constructors
    HDD();
    HDD(HDD& T);
    HDD(int driveNewSize, int newReleaseYear, const string& newManufacturerBrand,
        int newCost, const string& memoryChipNewType);

    // destructor
    ~HDD();

    // setter
    void setMemoryChipType(const string &memoryChipType);

    // getter
    [[nodiscard]] const string &getMemoryChipType() const;

    // methods
    string generateMemoryChipType();
	string myName() override;
	void print() override;
    void setRandomValue() override;
    void set() override;
};

class SSD : public StorageDev {
	int spindleRotationSpeed{};					// speed of rotation of spindle
public:
    // constructors
    SSD();
    SSD(SSD& T);
    SSD(int driveNewSize, int newReleaseYear, const string& newManufacturerBrand,
        int newCost, int spindleRotationNewSpeed);

    // destructor
    ~SSD();

    // setter
    void setSpindleRotationSpeed(int spindleRotationSpeed);

    // getter
    [[nodiscard]] int getSpindleRotationSpeed() const;

    // methods
    int generateSpindleRotationSpeed();
	string myName() override;
	void print() override;
    void setRandomValue() override;
    void set() override;
};

class FlashD : public StorageDev {
	double usbType{};								// type of USB connection
public:
    // constructors
    FlashD();
    FlashD(FlashD& T);
    FlashD(int driveNewSize, int newReleaseYear, const string& newManufacturerBrand,
           int newCost, double usbNewType);

    // destructor
    ~FlashD();

    // setter
    void setUsbType(double usbType);

    // getter
    [[nodiscard]] double getUsbType() const;

    // methods
    double generateUsbType();
	string myName() override;
	void print() override;
	void setRandomValue() override;
	void set() override;
};

class Shop {
	int arraySize{};								            // array size
	StorageDev** array;			// declaring object dynamically
public:
    // constructors
    Shop();
    Shop(Shop& T);
    explicit Shop(int arraySize);

    // destructor
    ~Shop();

    // setters
    void setArraySize(int arraySize);
    void setArray(StorageDev * newArray);

    // getters
    [[nodiscard]] int getArraySize() const;
    [[nodiscard]] StorageDev *getArray() const;

    // methods
    void filterByClassAndSortByIncreasing();	// printing objects which are filter
    // filtering and printing objects memory size of which in given range
    void filterByMemorySizeRange(int starting, int ending);
    // show statistics
    void showStatistics();
	void generateArray();
	void printArray();
	void setAnElement(int indexOfAnElement);
};

// other functions
int mainMenu();
int staticModeMenu();
void preEnterTheDynamicModeMenu();
int dynamicModeMenu(Shop *A);
int generateRandomSize();
int generateRandomYear();
string generateRandomBrand();
int generateRandomCost();
