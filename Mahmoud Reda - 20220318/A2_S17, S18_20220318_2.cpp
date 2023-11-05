// File: Q2.cpp
// Purpose: converts male speech to inclusive speech
// Author: Mahmoud Reda
// Section: S17, S18
// ID: 20220318
// TA: Rana Abdelkader‏
// Date: 5 Nov 2023


#include <iostream>
#include <string>
#include <map>

using namespace std;

bool isDigit(char character) {
    return character >= '0' && character <= '9';
}

string replaceMasculinePronouns(const string& inputText) {
    map<string, string> pronounReplacements = {
        {"he", "he or she"},
        {"him", "him or her"},
        {"his", "his or her"},
        {"He", "He or she"}
    };

    string outputText;

    string word;
    int i = 0;
    while (i < inputText.size()) {
        char c = inputText[i];
        if (isalpha(c) || isDigit(c)) {
            word.clear();
            while (i < inputText.size() && (isalpha(inputText[i]) || isDigit(inputText[i]))) {
                word += inputText[i];
                i++;
            }

            if (pronounReplacements.find(word) != pronounReplacements.end()) {
                outputText += pronounReplacements[word];
            } else {
                outputText += word;
            }
        } else {
            outputText += c;
            i++;
        }
    }

    return outputText;
}

int main() {
    string inputSentence;
    cout << "Enter a sentence: ";
    getline(cin, inputSentence);

    string outputSentence = replaceMasculinePronouns(inputSentence);

    cout << "Converted sentence:" << endl;
    cout << outputSentence << endl;

    return 0;
}
