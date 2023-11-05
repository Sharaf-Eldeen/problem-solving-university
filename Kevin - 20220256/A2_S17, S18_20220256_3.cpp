// File: Q3.cpp
// Purpose: implement the function split
// Author: Kevin Osama Shaker Shukri
// Section: S17, S18
// ID: 20220256
// TA: Rana Abdelkader‏
// Date: 5 Nov 2023

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class StringSplitter {
private:
    vector<string> tokens;
    string delimiter;

    void splitString(const string& target) {
        string token;
        size_t start = 0;
        size_t end = target.find(delimiter);

        while (end != string::npos) {
            token = target.substr(start, end - start);
            tokens.push_back(token);
            start = end + delimiter.length();
            end = target.find(delimiter, start);
        }

        token = target.substr(start);
        tokens.push_back(token);
    }

public:
    vector<string> split(const string& target, const string& delimiter) {
        tokens.clear();
        this->delimiter = delimiter;
        splitString(target);
        return tokens;
    }
};

int main() {
    string targetString = "10,20,30";
    string delimiter = ",";

    StringSplitter splitter;
    vector<string> result = splitter.split(targetString, delimiter);

    for (const string& token : result) {
        cout << token << endl;
    }

    return 0;
}
