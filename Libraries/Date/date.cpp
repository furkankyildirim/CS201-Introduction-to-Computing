#include "date.h"
#include <time.h>
#include <stdio.h>   // for sprintf

/******************************************************************** 
This code is freely distributable and modifiable providing you
leave this notice in it.
Copyright @ Owen Astrachan
********************************************************************/
//Security fix by Gökhan Göktürk
static int DaysInMonth(int,int);             // # of days in month in year
static bool IsLeap(int year);                // is year a leap year

static string dayNames [] = {"Sunday",  "Monday", "Tuesday","Wednesday",
                      "Thursday","Friday", "Saturday"};

static string monthNames [] = {"January","February","March","April",
				 "May","June","July","August",
				 "September","October","November","December"};

Date::Date()
// postcondition: date initialized to default date (today)
{
    time_t theTime = time(NULL);

    struct tm *aTime = localtime(&theTime);

    

    myDay= aTime->tm_mday;

    myMonth = aTime->tm_mon + 1; // Month is 0 - 11, add 1 to get a jan-dec 1-12 concept

    myYear = aTime->tm_year + 1900; // Year is # years since 1900
}

Date::Date(int m, int d, int y)
// postcondition: date properly initialized for date m/d/y (american style)
// exception:  if m isn't between 1 and 12, converted to 1
//             if d out of range for month, converted to 1     
{
    CheckDate(m,d,y);    
}

Date::Date(long days)
// postcondition: date initialized corresponding to absolute days
//                after 1 A.D.
{
    // this code is taken from "Calendrical Calculations, II"
    // Reingold and Dershowitz and Clamen
    // Software Practice and Experience, V. 23(4) 383-404 (april 1993)

    long prior = days - 1;                // prior days
    long years400 = prior / 146097L;      // # of 400 year cycles
    long days400 = prior % 146097L;       // days NOT in years400

    long years100 = days400 / 36524L;     // # 100 yr. cycles not checked
    long days100 =  days400 % 36524L;     // days NOT already included

    long years4 = days100 / 1461L;        // # 4 yr cycles not checked
    long days4 = days100 % 1461L;         // days NOT already included

    long year1 = days4 / 365L;            // # years not already checked
    long day1  = days4 % 365L;            // days NOT already included

    // use "magic formula" from SP&E article
    long finalDay;
    long finalYear = 400*years400 + 100*years100 + 4*years4 + year1;
    
    if (years100 == 4 || year1 == 4){      // December 31 of leap year
        finalDay = 366;
    }
    else{
        finalDay = day1 + 1;
        finalYear += 1;
    }

    // now have year and day #, find month and day in month
    myMonth = 1;
    while (myMonth <= 12 && 0 < finalDay){
	finalDay -= DaysInMonth(myMonth, int(finalYear));
	myMonth += 1;
    }
    myMonth -= 1;                              // went one to far
    finalDay += DaysInMonth(myMonth, int(finalYear));

    myDay = int(finalDay);
    myYear = int(finalYear);
}
    

int Date::Month() const
// postcondition: returns month of Date     
{
    return myMonth;
}

int Date::Day() const
// postcondition: returns day of Date     
{
    return myDay;
}

int Date::Year() const
// postcondition: returns year of Date     
{
    return myYear;
}

string Date::ToString() const
// postcondition: returns string (ascii) for date: day, month, year
{
     const int BUFSIZE = 50;

    char buf[BUFSIZE];

    sprintf(buf," %d %d",myDay, myYear);



    return MonthName() + buf;
}


static bool IsLeap(int year)
// postcondition: returns 1 if year is a leap year, else returns 0     
{
    if (year % 400 == 0){
        return true;
    }
    else if (year % 100 == 0){
        return false;
    }
    else if (year % 4 == 0){
        return true;
    }

    return false;
}

static int DaysInMonth(int month,int year)
// postcondition: returns # of days in month in year     
{
    int days = 30;

        // 30 days hath september, april, june, and november
        // other months have 31 as below (except February)
    
    if (month == 1 || month == 3 || month == 5 || month == 7 ||
        month == 8 || month == 10 || month == 12){
        days = 31;
    }
    else if (month == 2){          // treat February differently
        days = 28;
        if (IsLeap(year)){        // add 1 for leap years
            days += 1;
        }
    }
    return days;
}

int Date::DaysIn() const
{
    return DaysInMonth(myMonth,myYear);
}

long Date::Absolute() const
// postcondition: returns absolute # days corresponding to Date
//                assuming January 1, 1 B.C is day 1
{
    int m = 1;               // start in January;
    int daysBefore = 0;      // count # days before month

    while (m < myMonth){       // tally # of days in preceding months
        daysBefore += DaysInMonth(m,myYear);
        m += 1;
    }

    // days before this year
    long dayYears = 365 * ((long)(myYear) - 1);

    // add 1 extra day for each leap year
    
    int leapYears = (myYear - 1) / 4;     // initial # of leap years

    leapYears -= (myYear - 1) / 100;      // subtract years divisible by 100
    leapYears += (myYear - 1) / 400;      // add back years divisibly by 400

    return myDay + daysBefore + dayYears + leapYears;
}

string Date::DayName() const
{
    return dayNames[int(Absolute() % 7)];
}

string Date::MonthName() const
{
    return monthNames[myMonth-1];
}

ostream & operator << (ostream & os, const Date & d)
{
    os << d.ToString();
    return os;
}

Date& Date::operator +=(long dx)
{
    *this = Date(Absolute()+dx);
    return *this;
}

Date& Date::operator -=(long dx)
{
    *this = Date(Absolute()-dx);
    return *this;
}

Date Date::operator ++(int)
{
    Date hold = *this;
    *this += 1;
    return hold;
}

Date Date::operator --(int)
{
    Date hold = *this;
    *this -= 1;
    return hold;
}

Date operator + (const Date & d, long dx)
{
    return Date(d) += dx;
}

Date operator + (long dx, const Date & d)
{
    return d+dx;
}

Date operator - (const Date & d, long dx)
{
    return Date(d) -= dx;
}

long operator - (const Date & lhs, const Date & rhs)
{
    return lhs.Absolute() - rhs.Absolute();
}

void Date::CheckDate(int m, int d, int y)
{
    if (m < 1 || 12 < m)              // month out of range?
    {   m = 1;
    }
    myMonth = m;
    
    if (d < 1 || DaysInMonth(m,y) < d)   // day out of range?
    {   d = 1;
    }
    myDay = d;
    myYear = y;   
}

bool Date::Equal(const Date & rhs) const
{
    return Absolute() == rhs.Absolute();
}

bool Date::Less(const Date & rhs) const
{
    return Absolute() < rhs.Absolute();
}


bool operator == (const Date & lhs, const Date & rhs)
{
    return lhs.Equal(rhs);
}

bool operator != (const Date & lhs, const Date & rhs)
{
    return ! (lhs == rhs);
}

bool operator <  (const Date & lhs, const Date & rhs)
{
    return lhs.Less(rhs);
}

bool operator >  (const Date & lhs, const Date & rhs)
{
    return rhs < lhs;
}

bool operator <= (const Date & lhs, const Date & rhs)
{
    return lhs == rhs || lhs < rhs;
}

bool operator >= (const Date & lhs, const Date & rhs)
{
    return rhs <= lhs;
}
