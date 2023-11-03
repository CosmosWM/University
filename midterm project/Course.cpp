#include "Course.h"
#include<iostream>
#include <string>
#include <iomanip>
#include "Time.h"
#include "Date.h"


Course::Course(const string& name, const string& num, const string& meet, const double units, const Date& DS, const Date& DE, const Time& TS, const Time& TE):Coursenam(name),Coursenum(num),Coursemeet(meet), UnitNum(units), DateStart(DS), DateEnd(DE), TimeStart(TS), TimeEnd(TE)
{
    
}

Course::~Course() {
}

string Course::getCourseNum()const {
    return Coursenum;
}

string Course::getCourseNam()const {
    return Coursenam;
}

string Course::getCourseMeet()const {
    return Coursemeet;
}

double Course::getUnitNum()const {
    return UnitNum;
}

Date Course::getDateStart()const {
     return DateStart;
}

Date Course::getDateEnd() const{
    return DateEnd;
}

Time Course::getTimeStart()const {
    return TimeStart;
}

Time Course::getTimeEnd()const {
    return TimeEnd;
}

Course& Course::setCourseNum(string num) {
    Coursenum = num;
    return *this;
}
Course& Course::setCourseNam(int nam) {
    if (nam != 0)
    {
        Coursenam = nam;
    }
    
    else
    {
        Coursenam = "default";
    }
    return *this;
}
Course& Course::setCourseMeet(int meet)
{
    if (meet != 0)
    {
        Coursemeet = meet;
    }
    else
    {
        Coursemeet = "default";
    }
    
    return *this;
}

Course& Course::setUnitNum(int unit) {
    if (unit != 0)
    {
        UnitNum = unit;
    }
    
    else
    {
        UnitNum= 0;
    }
    return *this;
}
void Course::setTimeStart(int hour, int minute, char*str)
{

    TimeStart.setTime(hour, minute, str);
}

void Course::setTimeEnd(int hour, int minute, char* str)
{
    TimeEnd.setTime(hour, minute, str);
}

double Course::calcDailyDuration() const {
    double DailyDuration;
    DailyDuration = getTimeStart() - getTimeEnd();
    return DailyDuration;
}


ostream& operator << (ostream& output, const Course& course)
{
    output<< "Course Info: "<< course.Coursenum << " -- " << course.Coursenam << endl;
    output<< "# of Units: " << fixed << setw(3) << setprecision(2)<< course.getUnitNum() << endl;
    output << "Course Dates: " << course.DateStart << "-" << course.DateEnd << endl;
    output << "Meeting Days: " << course.Coursemeet << endl;
    output << "Meeting Times: " << course.TimeStart << "-" << course.TimeEnd;
    output<< "Daily Duration: " << course.calcDailyDuration() << "hours" << endl;
    return output;
}
