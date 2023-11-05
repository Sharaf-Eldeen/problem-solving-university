// File: Q7.cpp
// Purpose: The game of dominos
// Author: Ibrahim Rabea
// Section: S17
// ID: 20221001
// TA: Rana Abdelkader‏
// Date: 5 Nov 2023

#include <bits/stdc++.h>
using namespace std;

set<pair<int, int>> ans, dominos;

bool isPossibleToConnect(pair<int, int> d1, pair<int, int> d2) {
    return d1.second == d2.first;
}

bool findDominoChain(pair<int, int> d) {
    ans.insert(d);
    if (ans.size() == dominos.size()) {
        return true;
    }
    for (auto x : dominos) {
        if (ans.find(x) != ans.end()) continue;
        if (isPossibleToConnect(d, x)) {
            if (findDominoChain(x)) return true;
            ans.erase(x);
        }
    }
    return false;
}

void printDominoPath() {
    for (const auto &d : ans) {
        cout << d.first << "|" << d.second;
        if (d != *ans.rbegin()) {
            cout << " - ";
        }
    }
    cout << endl;
}

int main() {
    cout << "Enter the number of Dominos: ";
    int n;
    cin >> n;
    if (n <= 0) {
        cout << "Invalid number of dominos." << endl;
        return 1;
    }
    cout << "Enter the Dominos:" << endl;
    for (int i = 0; i < n; i++) {
        pair<int, int> a;
        cin >> a.first >> a.second;
        dominos.insert(a);
    }
    if (findDominoChain(*dominos.begin())) {
        cout << "Yes, there is a path: ";
        printDominoPath();
    } else {
        cout << "No, there is no path." << endl;
    }
    return 0;
}
