//David Dominguez
//CS 137
//Midterm Project Time

//Time Class Definition with const member functions
#ifndef TIME_H
#define TIME_H
#include <iostream>
using namespace std;
class Time
{

private:
    int hour;  //0-23 (24 hour clock format)
    int minute; //0-59
    void convertUniversal(int h,int m,string str);
public:
    //default constructor
    Time(int = 0, int = 0);
    Time(int h, int m, char*str);

    //set functions - not const since they modify private data
    //The & return type enables cascading
    Time& setTime(int, int);
    Time& setTime(int, int, char*);
    Time& setHour(int);
    Time& setMinute(int);

    //get functions - (normally always declared const)
    int getHour() const;
    int getMinute() const;

    //print functions - (normally always declared const since they do not modify private members, merely inspect
    void printUniversal() const;
    void printStandard()const;

    //cout and cin operator overloaded
    friend ostream& operator <<(ostream& out,const Time& obj);
    friend istream& operator >>(istream& in, Time& obj);
    //rest of operators overloading
    //made it a friend function since the requirement was to take two Times as params
    //friend float operator - (Time& lhs,Time& rhs);
    double operator-(const Time& time2);
};

#endif
