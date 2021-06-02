#ifndef _DATE_H
#define _DATE_H

/******************************************************************** 
This code is freely distributable and modifiable providing you
leave this notice in it.
Copyright @ Owen Astrachan
********************************************************************/
#include <iostream>
#include <string>
using namespace std;

// a class for manipulating dates
//
// Date class represents a date in the Gregorian calendar
// works only for dates after October, 1752
//
// attempts to construct invalid dates, e.g., 15 month,
// or 38th day result in month == 1, day == 1.  years aren't checked
// for validity
//
// Date()                  --- construct default date (today)
// Date(long days)     --- construct date given absolute # of days from
//                             1 A.D., e.g., 710,347 = November 12, 1945
//
// Date(int m,int d,int y) --- constructor requires three parameters:
//                             month, day, year, e.g.,
//                             Date d(4,8,1956); initializes d to represent
//                             the date April 8, 1956.  Full year is required
//
//    
// int Month()             --- return, respectively, month, day, and year
// int Day()                   corresponding to date with 1 = january,
// int Year()                  2 = february, ... 12 = december
//                                
//
// string DayName()        --- return string corresponding to day of week
//                             either "Monday", "Tuesday", ... "Sunday"
// string MonthName()      --- return string corresponding to month
//                             either "January", "February",..."December"
//
// int DaysIn()            --- return number of days in month
//                                                         
//    
// long Absolute() --- returns absolute # of date assuming
//                         that Jan 1, 1 AD is day 1.  Has property
//                         that Absolute() % 7 = k, where k = 0 is sunday
//                         k = 1 is monday, ... k = 6 is saturday
//
// string ToString()  -- returns string version of date, e.g.,
//                    -- d.SetDate(11,23,1963); then d.ToString()
//                       returns string "November 23 1963"
// *************************************************
//         arithmetic operators for dates
// *************************************************
//
// dates support some addition and subtraction operations
//
// Date d(1,1,1960);        // 1960 is a leap year
// d++;                     // d represents January 2, 1960
// d--;                     // d is back to January 1, 1960
// d += 31;                 // d is February 1, 1960
// d -= 32;                 // d is December 31, 1959
// Date d2 = d + 1;         // d2 is January 1, 1960
// Date d3 = 365 + d2;      // d3 is December 31, 1961
// Date d4 = d - 1;         // d4 is December 30, 1959
//
// *************************************************
class Date
{
  public:
              // constructors
    Date();                       // construct date with default value
    Date(long days);          // construct date from absolute #
    Date(int m,int d,int y);      // construct date with specified values

              // accessor functions

    int Month()          const;     // return month corresponding to date
    int Day()            const;     // return day corresponding to date
    int Year()           const;     // return year corresponding to date
    int DaysIn()         const;     // return # of days in month
    string DayName()     const;     // "monday", "tuesday", ... or "sunday"
    string MonthName()   const;     // "january","february",... or "december"
    long Absolute()      const;     // number of days since 1 A.D. for date
    string ToString()    const;     // returns string for date in ascii

    bool Equal(const Date & rhs) const;  // for implementing <, >, etc
    bool Less(const Date & rhs) const;
    
    // mutator functions

    Date operator ++(int);         // add one day, postfix operator
    Date operator --(int);         // subtract one day, postfix operator
    Date& operator +=(long dx);    // add dx, e.g., jan 1 + 31 = feb 1
    Date& operator -=(long dx);    // subtract dx, e.g., jan 1 - 1 = dec 31
	void SetYear(int);

  private:
    
    int myDay;                    // day of week, 0-6
    int myMonth;                  // month, 0-11
    int myYear;                   // year in four digits, e.g., 1899

	void CheckDate(int m, int d, int y); // make sure that date is valid
};

Date operator + (const Date & d, long dx);   // add dx to date d
Date operator + (long dx, const Date & d);   // add dx to date d
Date operator - (const Date & d, long dx);   // subtract dx from date d
long operator - (const Date & lhs, const Date & rhs);

ostream & operator << (ostream & os, const Date & d);
bool operator == (const Date & lhs, const Date & rhs);
bool operator != (const Date & lhs, const Date & rhs);
bool operator <  (const Date & lhs, const Date & rhs);
bool operator >  (const Date & lhs, const Date & rhs);
bool operator <= (const Date & lhs, const Date & rhs);
bool operator >= (const Date & lhs, const Date & rhs);

#endif
