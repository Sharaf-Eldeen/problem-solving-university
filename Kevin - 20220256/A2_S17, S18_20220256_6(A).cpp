// File: Q 6(a).cpp
// Purpose: One Binary Number
// Author: Kevin Osama Shaker Shukri
// Section: S17, S18
// ID: 20220256
// TA: Rana Abdelkader‏
// Date: 5 Nov 2023

#include <iostream>
using namespace std;
class BinaryPrinter {
public:
    static void binaryPrint(int n) {

        if (n == 0) {
            cout << 0;
        } else if (n > 0) {
            binaryPrint(n / 2);
            cout << n % 2;
        }
    }
};
int main() {
    int n ;
    cin >> n ;
    BinaryPrinter::binaryPrint(n);

    return 0;
}
