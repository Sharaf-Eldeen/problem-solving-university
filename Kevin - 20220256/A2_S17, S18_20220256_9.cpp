// File: Q9.cpp
// Purpose: Teddy Bear Picnic
// Author: Kevin Osama Shaker Shukri
// Section: S17, S18
// ID: 20220256
// TA: Rana Abdelkader‏
// Date: 5 Nov 2023


#include <iostream>
using namespace std;

bool BearShare(int x)
{
    if (x == 42) {
       return true;
   }

   else if (x % 5 == 0) {
        return BearShare(42 - x);
    }

    else if (x % 4 == 0 || x % 3 == 0) {
        int one = x % 10;
        int two = (x % 100) / 10;
        return BearShare(one * two);
    }

    else if (x % 2 == 0) {
        return BearShare(x / 2);
    } else {
        return false;
    }
}

int main()
{
    int x;
    cout << "Enter the number of bears: ";
    cin >> x;

    bool won = BearShare(x);

    if (won) {
        cout << "You have reached the goal!" << endl;
    } else {
        cout << "keep trying " << endl;
    }

    return 0;
}
