// File: Q11.cpp
// Purpose: File Comparison.
// Author: Mahmoud Reda
// Section: S17, S18
// ID: 20220318
// TA: Rana Abdelkader‏
// Date: 5 Nov 2023

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

vector<char> CharacterByCharacterComparison(ifstream& file1, ifstream& file2) {
    vector<char> differences;
    char char1, char2;
    int lineCount = 1;
    bool firstDifferentLine = false;

    while (file1.get(char1) && file2.get(char2)) {
        if (char1 != char2) {
            differences.push_back(char1);
            differences.push_back(char2);
            differences.push_back('\n');
            firstDifferentLine = true;
        }
        if ((char1 == '\n' || char2 == '\n') && firstDifferentLine) {
            cout << "Files are different at line " << lineCount << ":" << endl;
            break;
        }
        if ((char1 == '\n' || char2 == '\n') && !firstDifferentLine) {
            lineCount++;
        }
    }

    return differences;
}

bool WordByWordComparison(ifstream& file1, ifstream& file2) {
    string line1, line2;
    int lineCount = 0;

    while (getline(file1, line1) && getline(file2, line2)) {
        lineCount++;
        istringstream lineStream1(line1);
        istringstream lineStream2(line2);
        string word1;
        string word2;
        while (lineStream1 >> word1 && lineStream2 >> word2) {
            if (word1 != word2) {
                cout << "Files are different at line " << lineCount << ":" << endl;
                cout << "File 1: " << word1 << endl;
                cout << "File 2: " << word2 << endl;
                return false;
            }
        }
    }

    return true; // Both files reached the end simultaneously
}

int main() {
    string fileName1, fileName2;
    int choice;

    cout << "Enter the name of the first file: ";
    cin >> fileName1;

    cout << "Enter the name of the second file: ";
    cin >> fileName2;

    ifstream file1(fileName1);
    ifstream file2(fileName2);

    if (!file1.is_open() || !file2.is_open()) {
        cerr << "Error opening files. Make sure the file names are correct." << endl;
        return 1;
    }

    cout << "Choose comparison type:" << endl;
    cout << "1. Character by character comparison" << endl;
    cout << "2. Word by word comparison" << endl;
    cin >> choice;

    if (choice == 1) {
        vector<char> differences = CharacterByCharacterComparison(file1, file2);

        if (!differences.empty()) {
            cout << "The number of different characters is " << differences.size() / 2 << ":" << endl;
            for (char diff : differences) {
                cout << " " << diff;
            }
            cout << endl;
        } else {
            cout << "Files are identical." << endl;
        }
    } else if (choice == 2) {
        if (WordByWordComparison(file1, file2)) {
            cout << "Files are identical." << endl;
        }
    } else {
        cerr << "Invalid choice. Please select 1 or 2." << endl;
    }

    file1.close();
    file2.close();

    return 0;
}
