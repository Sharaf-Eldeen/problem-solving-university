// File: Q10.cpp
// Purpose: Message Altering to Avoid Censorship
// Author: Ibrahim Rabea
// Section: S17
// ID: 20221001
// TA: Rana Abdelkader‏
// Date: 5 Nov 2023


#include"iostream"
#include"bits/stdc++.h"
#include"fstream"

using namespace std;

int main()
{
    string detect_file,alt_file;
    cout<<"please enter your file: \n";
    cin>>detect_file;
    detect_file+=".txt";
    cout<<"please enter your alternatives file name : \n";
    cin>>alt_file;
    alt_file+=".txt";
    ifstream detect(detect_file);  // file to read from
    ifstream alt(alt_file);    // file of the alternative words
    ofstream ans("ans.txt", ios::trunc);  // the edited file
    vector<string>v;

    if(!detect.is_open())
    {
        cout<<"error while openning the file!";
    }
    else
    {
        string word,a,sub;
        while(getline(detect,word))
        {
            while(alt >> a)
            {
                if (word.find(a)!=string::npos)   // a-> detect
                {
                    for (int i = 0; i < word.size()-a.size(); ++i) {
                        if (word.substr(i, a.size()) == a) {
                            alt >> sub;
                            word.insert(i, sub);
                            word.erase(i + sub.size(), a.size());
//                            for (int j = 0; j < a.size(); ++j) {
//                                word[i]=sub[i];
//                            }
//                            word.substr(i,a.size())=sub;
//                            cout<<word.substr(i,a.size())<<"\n";
                        }
                    }
                }
                else
                {  // a -> sub
                    alt >> a;
                }
            }
            alt.clear();  // clears the read information of the file
            alt.seekg(0,ios::beg);  // re-centering the buffer to the beginning
            ans << word <<"\n";
        }
    }
}
