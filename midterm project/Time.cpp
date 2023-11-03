//David Dominguez
//CS 137
//Midterm Project Time

#include <iostream>
#include <iomanip>
using namespace std;

#include "Time.h"

//Constructor function to initialize private data
//remember a constructor is called whenever a new object of
//a class data type is instantiated, if a constructor is not defined the C++ do
//nothing constructor is run, it is better to ALWAYS have your own contructor
//once you have your own constructor the default is no longer available
//Constructors can and should be overloaded
//Constructors cannot be const since they always manipulate private data
Time::Time(int hour, int minute)
{
    setTime(hour, minute);
}
//takes in standardTime
Time::Time(int hour, int minute,char *str)
{
    convertUniversal(hour, minute, str);
}
//1:30 PM
void Time::convertUniversal(int hour,int min,string str)
{
    if (hour == 12)
    {
        hour = 0;
    }
    if (str == "AM")
    {
        setTime(hour, min);
    }
    else
    {
        setTime((hour + 12), min);
    }
    
}

/*SET FUNCTIONS: Never const since they need to modify private member data*/

//setTime function now is set up to enable cascading
Time& Time::setTime(int hour, int minute)
{
    setHour(hour);
    setMinute(minute);
    return *this;
}
Time& Time::setTime(int hour, int minute,char* str)
{
    convertUniversal(hour, minute, str);
    return *this;
}

//setHour function is now set up to enable cascading
Time& Time::setHour(int h)
{
    hour = (h >= 0 && h < 24) ? h : 0;  //validates hour, if valid set to h, else set to 0
    return *this;
}

//setMinute function is now set up to enable cascading
Time& Time::setMinute(int m)
{
    minute = (m >= 0 && m < 60) ? m : 0;  //validates minute, if valid set to m, else set to 0
    return *this;
}


/*GET FUNCTIONS:  Do not modify private member data normally always const*/

//get Hour
int Time::getHour() const  //must be const since prototype is const
{
    return hour;
}

//get Minute
int Time::getMinute() const  //must be const since prototype is const
{
    return minute;
}

/*PRINT FUNCTIONS:  Normally do not modify private member data so should be const*/

void Time::printUniversal()const  //must be const since prototype is const
{
    cout << setfill('0') << setw(2) << hour << ":" << setw(2) << minute<< endl;
}

void Time::printStandard()const  //must be const since prototype is const
{
    cout << ((hour == 0 || hour == 12 || hour==24) ? 12 : hour % 12) << ":"
         << setfill ('0') << setw(2)<< minute << setw(2) << (hour <= 12 ? "AM" : "PM" );
}
//overloading input operator
ostream& operator <<(ostream& out, const Time& obj)
{
    out << ((obj.hour == 0 || obj.hour == 12) ? 12 : obj.hour % 12) << ":"
        << setfill('0') << setw(2) << setfill('0') << setw(2) <<obj.getMinute()<< setw(2) << (obj.hour >0 && obj.hour <= 12 ? "AM" : "PM");
    return out;
}
//overloading output operator
istream& operator >>(istream& input, Time& obj)
{
    int hr, min;
    string ampm;
    input >> setw(2) >> hr;
    input.ignore();
    input >> setw(2) >> min;
    input.ignore();
    input >> setw(2) >> ampm;
    obj.convertUniversal(hr, min, ampm);
    return input;

}

/*{
    int h, m;
    char hr[10];
    char minute[10];
    char amPm[10];
    char str[50];
    in.getline(str,50,'\n');
    if (strlen(str) > 5)
    {
        int k = 0;
        //extract hour from string
        for (int i = 0;str[i] != ':';i++)
        {
            hr[k++] = str[i];
        }
        hr[k] = '\0';
        int kk = 0;
        k = k + 1;
        //extract minute from string
        for (int i = k;str[i] != ' ';i++)
        {
            minute[kk++] = str[i];
        }
        k = k+kk+1;
        minute[kk] = '\0';
        int kkk = 0;
        //extract AM/PM from string
        for (int i = k;i < strlen(str);i++)
        {
            amPm[kkk++] = str[i];
        }
        amPm[kkk] = '\0';
        //convert strings to Integers
        h = atoi(hr);
        m = atoi(minute);
        //settime
        obj.setTime(h, m, amPm);
    }
    return in;
}*/

/*float operator - (const Time& lhs,const Time& rhs)
{
    float dTimeDiff;
    //convert universal time into decimals
    float h1 = lhs.getHour()/1.0;
    float h2 = rhs.getHour()/1.0;
    float m1 = lhs.getMinute()/ 60.0;
    float m2 = rhs.getMinute ()/ 60.0;
    h1 = h1 + m1;
    h2 = h2 + m2;
    if (h1 >= h2)
    {
        dTimeDiff = h1 - h2;
    }
    else if (h2 >= h1)
    {
        if (h1 > 12 && h2 > 12)
        {
            dTimeDiff = h2 - h1;
        }
        else if(h1 > 12 || h2 > 12)
        {
            dTimeDiff = h2 - h1;
            dTimeDiff += 12;
        }
        else
            dTimeDiff = h2 - h1;
    }
    return dTimeDiff;*/

double Time::operator -(const Time & time2)
{
    double difference;
    difference = abs((getHour()+double(getMinute()/60)))-(time2.getHour()-double(time2.getMinute()/60));
    return difference;
}
