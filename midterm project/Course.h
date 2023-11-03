#ifndef COURSE_H
#define COURSE_H

#include <iostream>
#include <string>
#include <iomanip>
#include "Date.h"
#include "Time.h"

using namespace std;

class Course
{
    
    friend ostream& operator << (ostream&, const Course&);
    
private:
    string Coursenum;
    string Coursenam;
    string Coursemeet;
    double UnitNum;
    Date  DateStart;
    Date DateEnd;
    Time TimeStart;
    Time TimeEnd;
public:
    Course(const string& = "John Smith" ,const string& = "default" ,const string& = "default" ,const double = 0, const Date& = Date (), const Date& = Date(), const Time& = Time(), const Time& =Time());
    ~Course();
    string getCourseNum()const;
    string getCourseNam()const;
    string getCourseMeet()const;
    double getUnitNum()const;
    Date getDateStart()const;
    Date getDateEnd()const;
    Time getTimeStart()const;
    Time getTimeEnd()const;
    Course& setCourseNum(string);
    Course& setCourseNam(int);
    Course& setCourseMeet(int);
    Course& setUnitNum(int);
    double calcDailyDuration() const;
    void setTimeStart(int hour, int minute, char* str);
    void setTimeEnd(int hour, int minute, char* str);
    //Date setDateStart(int mn, int dy, int yr);
    //Date setDateEnd();
};
#endif

