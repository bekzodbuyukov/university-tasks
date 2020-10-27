#include "header.h"

int main() {
    srandom(time(nullptr));
    double a, b;
    a = 0.16;
    b = 0.42;
    bool result = a > b;
    bool otherResult = a < b;
    cout << result << " " << otherResult << endl;
    if (a < b) {
        cout << "a is bigger than b" << endl;
    } else {
        cout << "a is smaller than b" << endl;
    }

    FractionalNumber A{}, B{};

    cout << "Enter the data for 1-st object: ";
    cin >> A;

    cout << "Enter the data for 2-nd object: ";
    cin >> B;

    cout << "Your object data:" << endl;
    bool resultBigger = A > B;
    bool resultSmaller = A < B;
    cout << A << B << "1 > 2: " << resultBigger << endl << "1 < 2: " << resultSmaller << endl;

    FractionalNumber C{};
    C = 14.57;
    cout << C;

    double start, finish;
    start = 3.12;
    finish = 5.26;
    generateRandomNumberInRange<double>(start, finish);

    return 0;
}
