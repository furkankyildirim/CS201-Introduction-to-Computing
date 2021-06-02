//
//  Created by Furkan Kerim YILDIRIM on 26.04.2021.
//  furkanyildirim 28138

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

string findHouse(int);
ifstream getInputs(string);
void calculatePoint(string, string, int &);

int main() {
    string line, word, name, surname, answer, row;
    ifstream keyFile, answerFile;
    int score;
    
    cout << "Hello and welcome to the Hogwarts house sorting hat program!" << endl;
    cout << "When I call your name, you'll come forth, I shall place the sorting hat ";
    cout << "on your head, and you will be sorted into your houses." << endl;

    keyFile = getInputs("key");
    answerFile = getInputs("answer");
    
    while(getline(answerFile,line)) {
        score = 0;
        istringstream input(line);
        input >> name >> surname;
        
        while(input >> answer){
            getline(keyFile,row);
            calculatePoint(row, answer, score);
        }
        
        if (score != 0){
            string house = findHouse(score);
            cout << "Oh! we have " << name << " " << surname << " under the sorting hat. ";
            cout << name << ", you scored " << score << " points, you are a " << house << "!" << endl;
        }

        keyFile.clear();
        keyFile.seekg(0);
    }
    
    return 0;
}

ifstream getInputs(string type){
    ifstream in;
    string file;
    
    cout << "Enter the name of the "<< type <<" file: ";
    cin >> file;
    in.open(file.c_str());
    
    while (in.fail()){
        cout << "Error: Cannot open file " << file << endl;
        cout << "Enter the name of the "<< type <<" file: ";
        cin >> file;
        in.open(file.c_str());
    }
    
    return in;
}

void calculatePoint(string line, string answer, int & score){
    istringstream input(line);
    int point = 1;
    string value;
    
    while (input >> value) {
        if (answer == value) score += point;
        else point ++;
    }
}

string findHouse(int score){
    if (score < 10){
        return "Hufflepuff";
    } else if (10 <= score && score < 15){
        return "Ravenclaw";
    } else if (15 <= score && score < 21){
        return "Gryffindor";
    } else {
        return "Slytherin";
    }
}
