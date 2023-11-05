// File: Q 6(B).cpp
// Purpose: Printing Many Numbers.
// Author: Kevin Osama Shaker Shukri
// Section: S17, S18
// ID: 20220256
// TA: Rana Abdelkader‏
// Date: 5 Nov 2023

#include <iostream>
#include <string>

using namespace std;

class NumberPrinter {
public:
    static void numbers(const string& prefix, int k) {
        if (k == 0) {
            cout << prefix << endl;
        } else {
            numbers(prefix + "0", k - 1);
            numbers(prefix + "1", k - 1);
        }
    }
};
int main() {
    string prefix;
    int k;
    cin >> prefix >> k;
    NumberPrinter::numbers(prefix, k);
}
