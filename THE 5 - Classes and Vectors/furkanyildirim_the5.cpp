//
//  Created by Furkan Kerim YILDIRIM on 24.05.2021.
//  furkanyildirim 28138

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include "Reservation.h"
#include "date.h"

using namespace std;

Boat readBoat(ifstream &, int);
Sailor readSailor(ifstream &, int);

int main() {

    Reservations reservations;
    ifstream boatsFile, sailorsFile, reservesFile;
    string filename, boatsText = "Boats.txt", sailorsText = "Sailors.txt";
    cout << "Enter filename for reservation database: ";
    cin >> filename;
    
    boatsFile.open(boatsText.c_str());
    sailorsFile.open(sailorsText.c_str());
    reservesFile.open(filename.c_str());
    
    if (!boatsFile.fail() && !sailorsFile.fail() && !reservesFile.fail()) {

        string line, process, dayString;
        int sid, bid, m, d, y;
        
        while (getline(reservesFile,line)) {
            istringstream in(line);
            in >> process >> sid >> bid >> dayString;
            
            for (int i =0; i < dayString.length(); i++) {
                if (dayString[i] == '-') {
                    dayString[i] = ' ';
                }
            }
            istringstream dayStream(dayString);
            dayStream >> y >> m >> d;
            
            if (process == "A"){
                Boat boat = readBoat(boatsFile, bid);
                Sailor sailor = readSailor(sailorsFile, sid);
                Date date = Date(m, d, y);
                reservations.AddReservation(boat, sailor, date);
                
            } else if (process == "D"){
                if (sid == 0) {
                    Boat boat = Boat();
                    boat.setId(bid);
                    if (!reservations.DeleteReservation(boat)) {
                        cout << "Error: Could not delete reservation for boat id " << bid << "\n"<< endl;
                    }
                
                } else if (bid == 0) {
                    Sailor sailor = Sailor();
                    sailor.setId(sid);
                    if (!reservations.DeleteReservation(sailor)) {
                        cout << "Error: Could not delete reservation for sailor id " << sid << "\n"<< endl;
                    }
                    
                } else {
                    Boat boat = Boat();
                    Sailor sailor = Sailor();
                    Date date = Date(m, d, y);
                    
                    boat.setId(bid);
                    sailor.setId(sid);
                    if (!reservations.DeleteReservation(boat, sailor, date)) {
                        for (int i =0; i < dayString.length(); i++) {
                            if (dayString[i] == ' ') {
                                dayString[i] = '-';
                            }
                        }
                        cout << "Error: Could not delete reservation \"" << sid << " " << bid << " " << dayString << "\"\n"<< endl;
                    }
                }
                
            } else if (process == "F"){
                if (bid == 0 && sid == 0) {
                    string dayString2;
                    Date d1 = Date(m, d, y);
                    in >> dayString2;
                    
                    for (int i =0; i < dayString2.length(); i++) {
                        if (dayString2[i] == '-') {
                            dayString2[i] = ' ';
                        }
                    }

                    istringstream dayStream(dayString2);
                    dayStream >> y >> m >> d;
                    Date d2 = Date(m, d, y);

                    vector<Reservation> results = reservations.FindReservations(d1, d2);
                    cout << "Find Results:" << endl;
                    if (results.size() > 0){
                        for (Reservation i : results) {
                            i.ToString();
                        }
                        cout << endl;
                    } else {
                        for (int i =0; i < dayString.length(); i++) {
                            if (dayString[i] == ' ') {
                                dayString[i] = '-';
                                dayString2[i] = '-';
                            }
                        }
                        cout << "Error: No matching reservation found between dates " << dayString << " & " << dayString2 << "\n"  << endl;
                    }
                } else if (sid == 0){
                    Boat boat = Boat();
                    boat.setId(bid);
                    Date date = Date(m, d, y);

                    vector<Reservation> results = reservations.FindReservations(boat, date);
                    cout << "Find Results:" << endl;
                    if (results.size() > 0){
                        for (Reservation i : results) {
                            i.ToString();
                        }
                        cout << endl;
                    } else {
                        for (int i =0; i < dayString.length(); i++) {
                            if (dayString[i] == ' ') {
                                dayString[i] = '-';
                            }
                        }
                        cout << "Error: No matching reservation found for boat id " << bid << " on " << dayString << "\n" << endl;
                        
                    }
                } else if (bid == 0){
                    Sailor sailor = Sailor();
                    sailor.setId(sid);
                    Date date = Date(m, d, y);

                    vector<Reservation> results = reservations.FindReservations(sailor, date);
                    cout << "Find Results:" << endl;
                    if (results.size() > 0){
                        for (Reservation i : results) {
                            i.ToString();
                        }
                        cout << endl;
                    } else {
                        for (int i =0; i < dayString.length(); i++) {
                            if (dayString[i] == ' ') {
                                dayString[i] = '-';
                            }
                        }
                        cout << "Error: No matching reservation found for sailor id " << sid << " on " << dayString << "\n" << endl;
                        
                    }
                }
            }

        }
        
    } else{
        cout << "Cannot open the files. Exiting...\n" << endl;
        return -1;
    }
    
    return 0;
}

Boat readBoat(ifstream & file, int bid){
    int id;
    string line, name, color;
    getline(file,line);
    
    while (getline(file,line)) {
        istringstream in(line);
        in >> id >> name >> color;
        
        if (id == bid) {
            Boat boat = Boat(id, name, color);
            
            file.clear();
            file.seekg(0);
            
            return boat;
        }
    }
    return Boat();
}

Sailor readSailor(ifstream & file, int sid){
    int id;
    double age, rank;
    string line, name;
    getline(file,line);
    
    while (getline(file,line)) {
        istringstream in(line);
        in >> id >> name >> rank >> age;
        
        if (id ==sid) {
            Sailor sailor = Sailor(id, name, age, rank);
            
            file.clear();
            file.seekg(0);
            
            return sailor;
        }
    }
    return Sailor();
}

