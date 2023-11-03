//David Dominguez
//CS 137
//Midterm Project

#include <iostream>
using namespace std;

#include "Date.h"

//constructor validates month and calls utility function to validate day
Date::Date(int mn, int dy, int yr):month(mn),day(dy),year(yr)
{
}

//DESTRUCTOR
Date::~Date()
{
}

Date& Date::setDate(int mn, int dy, int yr)
{
    setMonth(mn);

    setYear(yr); //could also validate year

    setDay(dy);
    
    return *this;

}

/*//CONST PRINT FUNCTION
void Date::print() const
{
    cout << month << '/' << day << '/' << year << endl;
}*/

//PRIVATE COST UTILITY FUNCTION
bool Date::checkDay(int testDay)
{
    static const int daysPerMonth[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};

    if(testDay > 0 && testDay <= daysPerMonth[month])
    {
        day= testDay;
        return true;
    }

    //determine whether testDay is valid for a specific month
    else if(month == 2 && testDay == 29 && (year  % 400 == 0 || (year % 4  == 0 && year % 100 != 0)))
    {
        day= testDay;
        return true;
    }

    else
    {
        return false;
    }
    //keep data in valid state
}
int Date::getMonth() const
{
    return month;
}
int Date::getYear() const
{
    return year;
}
int Date::getDay() const
{
    return day;
}


Date& Date::setMonth(int m)
{
    month = (m>1 && m<13) ? m : 0;
    return *this;
}
Date& Date::setDay(int d)
{
    if (checkDay(d)== true)
    {
        day = d;
        return *this;
    }
    
    else
    {
        day = 0;
        return *this;
    }

}

Date& Date::setYear(int y)
{
    year = y;
    return *this;
}
bool Date::operator > (const Date& obj)
{
    if (this->year > obj.getYear())
    {
        return true;
    }
    else if (this->year == obj.getYear() && this->getMonth() > obj.getMonth())
    {
        return true;
    }
    else if (this->year == obj.getYear() && this->getMonth() == obj.getMonth() && this->getDay() > obj.getDay())
    {
        return true;
    }
    else
        return false;
}
bool Date::operator < (const Date& obj)
{
    if (this->year < obj.getYear())
    {
        return true;
    }
    else if (this->year == obj.getYear() && this->getMonth() < obj.getMonth())
    {
        return true;
    }
    else if (this->year == obj.getYear() && this->getMonth() == obj.getMonth() && this->getDay() < obj.getDay())
    {
        return true;
    }
    else
        return false;
}
bool Date::operator >= (const Date& obj)
{
    if ((*this > obj) == true || (*this == obj) == true)
    {
        return true;
    }
    else
        return false;
}
bool Date::operator <= (const Date& obj)
{
    if ((*this < obj) == true || (*this == obj) == true)
    {
        return true;
    }
    else
        return false;
}
bool Date::operator == (const Date& obj)
{
    if (this->year == obj.getYear() && this->getMonth() == obj.getMonth() && this->getDay() == obj.getDay())
    {
        return true;
    }
    else
        return false;
}
bool Date::operator != (const Date& obj)
{
    if ((*this == obj) == false)
    {
        return true;
    }
    else
        return false;
}



ostream& operator << (ostream & out, const Date&obj)
{
    out << obj.month << '/' << obj.day << '/' << obj.year;
    return out;
}
/*istream& operator >>(istream& in, Date& obj)
{
    char input[500];
    in.getline(input, 500, '\n');
    char month[20];
    char day[20];
    char year[20];
    //extract month from string
    int k = 0;
    for (int i = 0;input[i] != '/';i++)
    {
        month[k++] = input[i];
    }
    month[k] = '\0';
    k++;
    int kk = 0;
    for (int i = k;input[i] != '/';i++)
    {
        day[kk++] = input[i];
    }
    day[kk] = '\0';
    kk++;
    kk = kk + k;
    int kkk = 0;
    for (int i = kk;i<strlen(input);i++)
    {
        year[kkk++] = input[i];
    }
    year[kkk] = '\0';
    //converting into integers;
    int mo = atoi(month);
    int d = atoi(day);
    int y = atoi(year);
    //setDate
    obj.setDate(mo, d, y);
    return in;
}*/

istream& operator>>(istream& input, Date& obj)
{
    input >> obj.month;
    input.ignore();
    input >> obj.day;
    input.ignore();
    input >> obj.year;

    return input;
}
