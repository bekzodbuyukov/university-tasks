#include "header.h"

int main() {
    FractionalNumber A, B;

    cout << "Enter the data for 1-st object: ";
    cin >> A;

    cout << "Enter the data for 2-nd object: ";
    cin >> B;

//    cout << "Your object data:" << endl;
    bool resultBigger = A > B;
    bool resultSmaller =  A < B;
    cout << A << B << ">: " << resultBigger << " <: " << resultSmaller;

    return 0;
}
