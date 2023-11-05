// File: Q4.cpp
// Purpose: Prime numbers
// Author: Ibrahim Rabea
// Section: S17
// ID: 20221001
// TA: Rana Abdelkader‏
// Date: 5 Nov 2023

#include <iostream>
using namespace std ;

int main()
{
    int len ;
    cout<<"please enter any positive number "<<endl;
    cin>>len;
    int arr[len ] = {0};

    for (int i = 2; i < len; i++)
    {
        for (int j = i * i; j < len; j+=i)
        {
            arr[j - 1] = 1;
        }
    }
    for (int i = 1; i < len; i++)
    {
        if (arr[i - 1] == 0)
            cout << i << "  ";
    }
}
