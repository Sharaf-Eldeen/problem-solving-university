// File: Q8.cpp
// Purpose: a recursive method that can generate patterns
// Author: Mahmoud Reda
// Section: S17, S18
// ID: 20220318
// TA: Rana Abdelkader‏
// Date: 5 Nov 2023

#include <iostream>
#include <cmath>
#include <string>
#include <vector>

using namespace std;

void generateCoreArray(int evenNumber, vector<int>& coreArray) {
    if (evenNumber % 2 != 0) {
        // Ensure the input is even
        return;
    }

    int i = 0;
    for (int num = 1; (pow(2, i)) <= evenNumber; i++) {
        coreArray.push_back(static_cast<int>(pow(2, i)));
    }
}

void fillRecursively(vector<string>& resArray, vector<int>& coreArray, int resSize, int i, int a, int startColumn) {
    if (i >= coreArray.size()) {
        return;  // Base case for recursion
    }
    int increment = 2 * coreArray[i];
    int start = coreArray[i] - 1;

    for (int j = start; j < resSize; j = j + increment) {
        resArray[j] = string((a + startColumn ), ' ') + string(coreArray[i], '*');
        a += coreArray[i];
    }

    fillRecursively(resArray, coreArray, resSize, i + 1, 0, startColumn);  // Recurse to the next element in coreArray
}

int main() {
    //int evenNumber = 4;
    int evenNumber;
    int startColumn;
    cout << "Enter The longest line of the pattern : ";
    cin >> evenNumber ;
    cout << "Enter The beginning column of the pattern : ";
    cin >> startColumn ;
    vector<int> coreArray;
    vector<string> resArray;
    int resSize = (2 * evenNumber - 1);

    generateCoreArray(evenNumber, coreArray);

    resArray.resize(resSize, string(coreArray.back(), ' '));

    fillRecursively(resArray, coreArray, resSize, 0, 0, startColumn);

    for (int i = 0; i < resSize; i++) {
        cout << resArray[i] << endl;
    }

    return 0;
}
