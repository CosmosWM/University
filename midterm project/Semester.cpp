//
//  Semester.cpp
//  CourseSchedule
//
//  Created by David Dominguez on 7/23/21.
//
#include "Semester.h"
#include <string>
#include<iostream>

using namespace std;

Semester::Semester(string name, const Date& start, const Date& end):semesterName(name), startDate(start),endDate(end)
{

}


void  Semester::setSemesterName(string term)
{
    
    semesterName= term;
}

string Semester::getSemesterName() const
{
    return semesterName;
}

void Semester::setStartDate(int mn, int dy, int yr)
{
    startDate.setDate(mn, dy, yr);
}

void Semester::setEndDate(int mn, int dy,int yr)
{
    endDate.setDate(mn, dy,yr);
}

/*ostream& Semester::getStartDate() const
{
    cout << startDate;
}

void Semester::getEndDate() const
{
    cout << endDate;
}*/

int Semester::getStartDay() const
{
    return startDate.getDay();
}

int Semester::getStartYear() const
{
    return startDate.getYear();
}

int Semester::getStartMonth() const
{
    return startDate.getMonth();
}

int Semester::getEndDay() const
{
    return endDate.getDay();
}

int Semester::getEndYear() const
{
    return endDate.getYear();
}

int Semester::getEndMonth() const
{
    return endDate.getMonth();
}

Date Semester::getStartDate()const
{
    return startDate;
}

Date Semester::getEndDate() const
{
    return endDate;
}

ostream& operator <<(ostream& output,const Semester& obj)
{
    /*output << "Semester: " << obj.getSemesterName() << " (" << obj.getStartMonth() << "/" << obj.getStartDay() << "/" << obj.getStartYear()<< "-" << obj.getEndMonth()<< "/" << obj.getEndDay() << "/" << obj.getEndYear() << ")";*/
    
    output<<"Semester: " << obj.getSemesterName() << " (" << obj.startDate << "-" << obj.endDate << ")" << endl;
    
    return output;
}

istream& operator >>(istream& input, Semester& obj)
{
    //int startMonth, startDay, startYear;
    //int endMonth, endDay, endYear;
    string term;
    //int sm, sd, sy;
    //int em, ed, ey;*/
    
    
    getline(cin, term);
    obj.setSemesterName(term);
    input>> obj.startDate;
    input >> obj.endDate;
    /*cout << "\nEnter Start Date in Form: MM DD YYYY: ";
    input >> sm >> sd >> sy;
    cin.ignore();
    cout << "\nEnter End Date in Form: MM DD YYYY: ";
    input >> em >> ed >> ey;
    
    obj.setSemesterName(term);
    obj.setStartDate(sm, sd, sy);
    obj.setEndDate(em, ed, ey);*/
    
    return input;
}
