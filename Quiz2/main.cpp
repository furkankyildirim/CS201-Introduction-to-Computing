//
//  Created by Furkan Kerim YILDIRIM on 7.04.2021.
//  furkanyildirm 28138

//  Question: Write a C++ program that will calculate the frequency
//  of target string characters occuring in a given string

//  Here are some sample runs:

//  Please enter a string: computerscience
//  Please enter a target string: c++
//  The obtained frequencies are:
//  c --> 3
//  + --> 0
//  + --> 0

//  Please enter a string: sabanciuniversity
//  Please enter a target string: cs201
//  The obtained frequencies are:
//  c --> 1
//  s --> 2
//  2 --> 0
//  0 --> 0
//  1 --> 0

//  Please enter a string: techcompany
//  Please enter a target string: google
//  The obtained frequencies are:
//  g --> 0
//  o --> 1
//  o --> 1
//  g --> 0
//  l --> 0
//  e --> 1

#include <iostream>
#include <string>
using namespace std;

int main() {
    
    string mainString, targetString;
    int frequency;
    
    cout << "Please enter a string: ";
    cin >> mainString;
    
    cout << "Please enter a target string: ";
    cin >> targetString;
    
    cout << "The obtained frequencies are:" << endl;
    
    for (int i = 0; i < targetString.length(); i++){
        frequency = 0;
        for (int j = 0; j < mainString.length(); j++){
            if(targetString.at(i) == mainString.at(j)){
                frequency += 1;
            }
        }
        cout << targetString.at(i) << " --> " << frequency << endl;
    }

    return 0;
}
