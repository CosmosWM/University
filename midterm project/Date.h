//David Domin
//CS 137
//Midterm Project

#ifndef DATE_H
#define DATE_H
#include<iostream>
using namespace std;
class Date
{
    //cin cout operator overloading
    friend ostream& operator <<(ostream& out, const Date& obj);
    friend istream& operator >>(istream& in, Date& obj);
    
private:
    int month; //1-12
    int day; //1-31 depending on month
    int year; //any year

    //utility function to check if day is proper for month and year
    bool checkDay(int);

public:
    Date(int = 1, int = 1, int = 1990);
    ~Date();
    Date& setDate(int, int, int);
    Date& setMonth(int);
    Date& setDay(int);
    Date& setYear(int);
    int getMonth() const;
    int getDay() const;
    int getYear() const;
    //Date& getDate();
    void print() const;
    
    //logical operators overload
    bool operator > (const Date& );
    bool operator < (const Date&);
    bool operator >= (const Date&);
    bool operator <= (const Date&);
    bool operator == (const Date&);
    bool operator != (const Date&);
};

#endif
