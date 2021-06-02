//
//  Furkan K. YILDIRIM
//  furkankyildirim 28138

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main(){
    string word, filename;
    int numWords = 0;
    ifstream input;
    
    cout << "Please enter the filename: ";
    cin >> filename;
    input.open(filename.c_str());
    
    if(input.fail()){
        cout << "Cannot open " << filename << "." << endl;
    } else {
        while (input >> word) {
            numWords ++;
        }
        cout << filename << " contains " << numWords << " words." << endl;
    }
    
    
    return 0;
}
