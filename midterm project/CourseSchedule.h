//
//  CourseSchedule.hpp
//  CourseSchedule
//
//  Created by David Dominguez on 7/22/21.
//

#ifndef CourseSchedule_h
#define CourseSchedule_h

#include <stdio.h>
#include <iostream>
#include "CourseSchedule.h"
#include "Semester.h"
#include "Course.h"
#include "Date.h"
#include "Time.h"

using namespace std;

class CourseSchedule
{

    friend ostream& operator << (ostream&,const CourseSchedule&);
    
private:
    int maxNum;
    string studentName;
    int numCourses;
    bool checkDates(const Semester&,const Date&, const Date&);
    Course* coursePtr;
    Semester term;
    
public:
    CourseSchedule (string,Semester&,int);
    ~CourseSchedule();
    string getStudentName() const;
    void setStudentName(string);
    int getNumCourse() const;
    Semester& getSemester();
    bool addCourse(const Course &);
    bool removeCourse(const Course&);
    
    
};

#endif /* CourseSchedule_hpp */

