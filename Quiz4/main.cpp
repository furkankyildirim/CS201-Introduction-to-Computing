//
//  Created by Furkan Kerim YILDIRIM on 24.05.2021.
//  furkanyildirim 28138

//  Question: Write a program that reads an input file ("movies.txt"),
//  whose lines contain positive integers  corresponding to movie ids
//  and total lenght duration in minutes, seperated by space; then print
//  out the total length of that movie database; subsequently, print out
//  the list with all movie information whose lengths exceeds (exluding)
//  90 minutes; if there is no such movie, then print out "There exists no
//  movie length more than 90 minutes!".

//  An example input file is as follows:
//  1   95
//  2   80
//  3   150
//  4   90

//  Expected output:
//  This movie database contains totally 415 minutes of movies.
//  Here is the list og movies with length exceeding 90 minutes:
//  Movie id=1 length=95 (minutes)
//  Movie id=3 length=150 (minutes)

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

struct Movie {
    int id;
    int length;
};

int main(){
    string file_name = "movies.txt";
    ifstream file(file_name.c_str());

    if (file.fail()){
        cout << "Cannot open the provided file." << endl;
        return -1;
    }

    string line;
    Movie mv;
    vector<Movie> list;

    int sum = 0;

    while (getline(file,line)){

        istringstream ss(line);
        ss >> mv.id >> mv.length;
        sum += mv.length;

        if(mv.length > 90) {
            list.push_back(mv);
        }
    }

    cout << "The movie database contains totally " << sum << " minutes of movies" << endl;

    if (list.size() > 0) {
        cout << "Here is the list of movies with length exceeding 90 minutes:" << endl;
        for (int i = 0; i < list.size(); i++){
            cout << "Movie id=" << list[i].id << "; length=" << list[i].length << " (minutes)" << endl;
        }
    } else {
        cout << "There exists no movie with length more than 90 minutes!" << endl;
    }

    return 0;
}
