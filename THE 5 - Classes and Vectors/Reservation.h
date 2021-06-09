#include <iostream>
#include <vector>
#include <string>
#include "date.h"

class Sailor
{
public:
    Sailor()
    {
        id = 0;
        name = "Jane Doe";
        age = 0;
        rank = 0;
    }
    Sailor(int i, string n, double a, double r);
    
    void setId(int i);
    void setName(string n);
    void setAge(double a);
    void setRank(double r);
    
    int Id()        const;
    string Name()   const;
    double Age()    const;
    double Rank()   const;
    
private:
    int id;
    string name;
    double age;
    double rank;
};

class Boat
{
public:
    Boat()
    {
        id = 0;
        name = "Default";
        color = "Default";
    }
    Boat(int i, string n, string c);
    
    void setId(int i);
    void setName(string n);
    void setColor(string c);
    
    int Id()        const;
    string Name()   const;
    string Color()  const;

private:
    int id;
    string name;
    string color;
};

class Reservation
{
public:
    Reservation()
    {
        Sailor s;
        sailor = s;
        Boat b;
        boat = b;
        Date d(1,1,1900);
        resDate = d;
    }
    Reservation(Boat b, Sailor s, Date d);
    
    void setSailor(Sailor s);
    void setBoat(Boat b);
    void setDate(Date d);
    
    Sailor getSailor()     const;
    Boat getBoat()         const;
    Date getDate()         const;
    
    void ToString()        const;

private:
    Date resDate;
    Sailor sailor;
    Boat boat;
};

class Reservations
{
public:
    Reservations();
		// Fill this part with the member functions
		// 1. Add a Reservation

		// 2. Delete a Reservation

		// 3.1. Find a Reservation (sailor and boat ids are 0)
		// 3.2. Find a Reservation (only sailor id is 0)
		// 3.3. Find a Reservation (only boat id is 0)
    
    void AddReservation(Boat b, Sailor s, Date d);
    
    bool DeleteReservation(Boat b);
    bool DeleteReservation(Sailor s);
    bool DeleteReservation(Boat b, Sailor s, Date d);
    
    vector<Reservation> FindReservations(Boat b, Date d);
    vector<Reservation> FindReservations(Sailor s, Date d);
    vector<Reservation> FindReservations(Date d1, Date d2);
    
    vector<Reservation> getReservations();


private:
    vector<Reservation> reservations;
	
};


