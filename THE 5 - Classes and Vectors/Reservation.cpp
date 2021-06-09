//
//  Created by Furkan Kerim YILDIRIM on 24.05.2021.
//  furkanyildirim 28138

#include <iostream>
#include <string>
#include "date.h"
#include "Reservation.h"

using namespace std;

Sailor::Sailor(int i, string n, double a, double r)
{
    setId(i);
    setAge(a);
    setName(n);
    setRank(r);
}

void Sailor::setId(int i)
{
    id = i;
}

void Sailor::setName(string n)
{
    name = n;
}

void Sailor::setAge(double a)
{
    age = a;
}

void Sailor::setRank(double r)
{
    rank = r;
}

int Sailor::Id() const
{
    return id;
}

string Sailor::Name() const
{
    return name;
}

double Sailor::Age() const
{
    return age;
}

double Sailor::Rank() const
{
    return rank;
}


Boat::Boat(int i, string n, string c)
{
    setId(i);
    setName(n);
    setColor(c);
}

void Boat::setId(int i)
{
    id = i;
}

void Boat::setName(string n)
{
    name = n;
}

void Boat::setColor(string c)
{
    color = c;
}

int Boat::Id() const
{
    return id;
}

string Boat::Name() const
{
    return name;
}

string Boat::Color() const
{
    return color;
}


Reservation::Reservation(Boat b, Sailor s, Date d)
{
    setSailor(s);
    setBoat(b);
    setDate(d);
}

void Reservation::setSailor(Sailor s)
{
    sailor = s;
}

void Reservation::setBoat(Boat b)
{
    boat = b;
}

void Reservation::setDate(Date d)
{
    resDate = d;
}

Sailor Reservation::getSailor() const
{
    return sailor;
}

Boat Reservation::getBoat() const
{
    return boat;
}

Date Reservation::getDate() const
{
    return resDate;
}

void Reservation::ToString() const
{
    Boat b = getBoat();
    Date d = getDate();
    Sailor s = getSailor();
    
    cout << d.MonthName() << " " << d.Day() << " " << d.Year() << " -> ";
    cout << s.Name() << "(" << s.Age() << "," << s.Rank() << ") has";
    cout << " reserved " << b.Name() << "(" << b.Color() << ")" << endl;
}


Reservations::Reservations()
{
    vector<Reservation> reservations;
}

void Reservations::AddReservation(Boat b, Sailor s, Date d)
{
    Reservation res = Reservation(b, s, d);
    long int loc = reservations.size();
    reservations.push_back(res);

    while (loc > 0 && reservations[loc-1].getDate().More(res.getDate())) {
        reservations[loc] = reservations[loc-1];
        loc--;
    }
    
    if (reservations[loc-1].getDate().Equal(res.getDate())) {
        while (loc > 0 && res.getSailor().Name() < reservations[loc-1].getSailor().Name()) {
            reservations[loc] = reservations[loc-1];
            loc--;
            
            if (!reservations[loc-1].getDate().Equal(res.getDate())) {
                break;
            }
        }
    }
    reservations[loc] = res;
}

bool Reservations::DeleteReservation(Boat b)
{
    int pos = -1;
    for (int i = 0; i < reservations.size(); i++) {
        if (reservations[i].getBoat().Id() == b.Id()) {
            for (pos = i; pos < reservations.size()-1 ; pos++) {
                reservations[pos] = reservations[pos+1];
            }
            reservations.pop_back();
        }
    }
    return pos != -1;
}

bool Reservations::DeleteReservation(Sailor s)
{
    int pos = -1;
    for (int i = 0; i < reservations.size(); i++) {
        if (reservations[i].getSailor().Id() == s.Id()) {
            for (pos = i; pos < reservations.size()-1 ; pos++) {
                reservations[pos] = reservations[pos+1];
            }
            reservations.pop_back();
        }
    }
    return pos != -1;
}

bool Reservations::DeleteReservation(Boat b, Sailor s, Date d)
{
    int pos = -1;
    for (int i = 0; i < reservations.size(); i++) {
        if (reservations[i].getSailor().Id() == s.Id() && reservations[i].getBoat().Id() == b.Id() && reservations[i].getDate().Equal(d)){
            for (pos = i; pos < reservations.size()-1 ; pos++) {
                reservations[pos] = reservations[pos+1];
            }
            reservations.pop_back();
        }
    }
    return pos != -1;
}

vector<Reservation> Reservations::FindReservations(Boat b, Date d)
{
    vector<Reservation> res;
    for (Reservation i : reservations){
        if (i.getBoat().Id() == b.Id() && i.getDate().Equal(d)) {
            res.push_back(i);
        }
    }
    return res;
}

vector<Reservation> Reservations::FindReservations(Sailor s, Date d)
{
    vector<Reservation> res;
    for (Reservation i : reservations){
        if (i.getSailor().Id() == s.Id() && i.getDate().Equal(d)) {
            res.push_back(i);
        }
    }
    return res;
}

vector<Reservation> Reservations::FindReservations(Date d1, Date d2)
{
    vector<Reservation> res;
    for (Reservation i : reservations){
        if (i.getDate().MoreEqual(d1) && i.getDate().LessEqual(d2)) {
            res.push_back(i);
        }
    }
    return res;
}

vector<Reservation> Reservations::getReservations(){
    return reservations;
}
