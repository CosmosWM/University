//
//  Semester.hpp
//  CourseSchedule
//
//  Created by David Dominguez on 7/23/21.
//
#ifndef SEMESTER_H
#define SEMESTER_H
#include <string>
#include <iostream>
#include "Date.h"

using namespace std;

class Semester
{
    friend ostream& operator <<(ostream&, const Semester&);
    friend istream& operator >>(istream&, Semester&);
    
private:
    string semesterName;
    Date startDate;
    Date endDate;

public:
    Semester(string = "Fall" , const Date& = Date(), const Date& = Date());
    void setSemesterName(string);
    void setStartDate(int, int, int);
    void setEndDate(int, int, int);
    int getStartMonth() const;
    int getStartDay() const;
    int getStartYear() const;
    int getEndMonth() const;
    int getEndDay() const;
    int getEndYear() const;
    
    /*Date& setStartDate(Date&);
    Date& setEndDate(Date&);
    Date& setStartMonth(Date&);
    Date& setStertDay(Date&);
    Date& setStartYear(Date&);
    Date& setEndDay(Date&);
    Date& setEndMonth(Date&);
    Date& setEndYear(Date&);*/
    
    Date getStartDate() const;
    Date getEndDate()const;
    string getSemesterName() const;
};

#endif

