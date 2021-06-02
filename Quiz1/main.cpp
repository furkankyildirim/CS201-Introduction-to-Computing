//
//  Created by Furkan Kerim YILDIRIM on 22.03.2021.
//  furkanyildirim 28138

//  Question: Write a c++ code that can convert ounces to euros
//  or convert euros to ounces. 1 ounce = 1439.78€

#include <iostream>
#include <string>
using namespace std;


int main() {
    string convertType;
    double amount, equivalent;
    
    cout << "Enter the operation (EtoG / GtoE): ";
    cin >> convertType;
    
    if (convertType == "EtoG"){
        cout << "Enter the total amount to be converted: ";
        cin >> amount;
        
        equivalent = amount / 1439.78;
        cout << "Equivalent of " << amount << " EUR is: " << equivalent << " ounce of gold." << endl;
        
        
    } else if (convertType == "GtoE"){
        cout << "Enter the total amount to be converted: ";
        cin >> amount;
        
        equivalent = amount * 1439.78;
        cout << "Equivalent of " << amount << " ounce of gold is: " << equivalent << " EUR." << endl;
        
        
    } else {
        cout << "Invalid Operation Input" << endl;
    }
    
    return 0;
}
