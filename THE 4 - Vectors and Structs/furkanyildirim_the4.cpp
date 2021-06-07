//
//  Created by Furkan Kerim YILDIRIM on 8.05.2021.
//  furkanyildirim 28138

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

struct reserve {
    string sname, bname, color, date;
    unsigned int sid, bid;
    double age, rating;
};

void readReserves(ifstream&, vector<reserve>&);
void readSailors(ifstream&, reserve&);
void readBoats(ifstream&, reserve&);
void sortReserves(vector<reserve>&);

int main() {
    string filename, boatsText = "Boats.txt", sailorsText = "Sailors.txt";
    ifstream boatsDb, sailorsDb, reservesDb;
    vector<reserve> reserves;
    
    cout << "Enter filename for reservation database: ";
    cin >> filename;
    
    
    boatsDb.open(boatsText.c_str());
    sailorsDb.open(sailorsText.c_str());
    reservesDb.open(filename.c_str());
    
    if (!boatsDb.fail() && !sailorsDb.fail() && !reservesDb.fail()) {
        readReserves(reservesDb,reserves);
        
        for (int i = 0; i < reserves.size(); i++) {
            readSailors(sailorsDb, reserves[i]);
            readBoats(boatsDb, reserves[i]);
        }
        sortReserves(reserves);
        
        for (int i = 0; i < reserves.size(); i++) {
            reserve rsv = reserves[i];
            
            cout << rsv.date << " -> " << rsv.sname << "(" << rsv.age << "," << rsv.rating << ")";
            cout << " has reserved " << rsv.bname << "(" << rsv.color << ")" << endl;
        }
        
    } else {
        cout << "Cannot open the files. Exiting..." << endl;
    }
    
    return 0;
}

void readReserves(ifstream& file, vector<reserve>& reserves){
    string line;
    getline(file, line);
    
    while (getline(file, line)) {
        reserve rsv;
        istringstream in(line);
        in >> rsv.sid >> rsv.bid >> rsv.date;
        reserves.push_back(rsv);
    }
}

void readSailors(ifstream& file, reserve& rsv){
    int id;
    string line;
    getline(file, line);
    
    while (getline(file, line)) {
        istringstream in(line);
        in >> id;
        
        if (id == rsv.sid){
            in  >> rsv.sname >> rsv.rating >> rsv.age;
        }
    }
    
    file.clear();
    file.seekg(0);
}

void readBoats(ifstream& file, reserve& rsv){
    int id;
    string line;
    getline(file, line);
    
    while (getline(file, line)) {
        istringstream in(line);
        in >> id;
        
        if (id == rsv.bid) {
            in >> rsv.bname >> rsv.color;
        }
    }
    
    file.clear();
    file.seekg(0);
}

void sortReserves(vector<reserve>& reserves){
    
    for (int i = 0; i < reserves.size()-1; i++) {
        int min = i;
        for (int j = i+1; j < reserves.size(); j++){
            if (reserves[j].date < reserves[min].date) {
                min = j;
            }
            if (reserves[j].date == reserves[min].date){
                if (reserves[j].sname < reserves[min].sname) {
                    min = j;
                }
            }
        }
        
        reserve temp = reserves[min];
        reserves[min] = reserves[i];
        reserves[i] = temp;
    }
}

