// File: Q12.cpp
// Purpose: Phishing Scanner
// Author: Kevin Osama Shaker Shukri
// Section: S17, S18
// ID: 20220256
// TA: Rana Abdelkader‏
// Date: 5 Nov 2023
#include<bits/stdc++.h>
using namespace std;
void scanPhishingKeywords(const string& filePath) {
    map<string,int> phishingKeywords = {
            {"verify your account", 2},
            {"urgent action required", 3},
            {"account suspended", 3},
            {"security alert", 2},
            {"update your information", 1},
            {"limited time offer", 1},
            {"free gift", 1},
            {"suspicious activity detected", 2},
            {"confirm your identity", 1},
            {"unusual login attempt", 2},
            {"your account has been compromised", 2},
            {"verify your payment details", 1},
            {"win a prize", 1},
            {"request for assistance", 1},
            {"your account will be closed", 2},
            {"account verification required", 1},
            {"login to prevent account closure", 2},
            {"upgrade your account", 1},
            {"lottery winner", 1},
            {"important security notice", 2},
            {"claim your refund", 1},
            {"confirm your subscription", 1},
            {"urgent security update", 2},
            {"account locked", 1},
            {"exclusive offer", 1},
            {"reset your password", 1},
            {"your account has been hacked", 2},
            {"limited stock available", 1},
            {"tax refund notification", 1},
            {"unpaid invoice", 1}

    };

    int totalPoint = 0;
    ifstream file(filePath);
    string seg;

    if (file.is_open()) {
        while (getline(file, seg)) {
            for (const auto& [keyword, point] : phishingKeywords) {
                size_t pos = seg.find(keyword);
                while (pos != string::npos) {
                    totalPoint += point;
                    cout << keyword << " : 1 occurrence, " << point << " point(s)" << endl;
                    pos = seg.find(keyword, pos + keyword.length());
                }
            }
        }
        file.close();
    } else {
        cout << "Unable to open file." << "\n";
    }

    cout << "Total points is =" << totalPoint << "\n";
}

int main() {
    string filePath = "C:\\Users\\farou\\Desktop\\oop\\untitled\\New Text Document.txt";
    scanPhishingKeywords(filePath);

}
