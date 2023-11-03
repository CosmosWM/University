//
//  CourseSchedule.cpp
//  CourseSchedule
//
//  Created by David Dominguez on 7/22/21.
//

#include "CourseSchedule.h"

CourseSchedule::CourseSchedule(string name,Semester& input, int max):studentName(name), term(input),maxNum(max)
{
    numCourses=0;
    coursePtr = nullptr;
    coursePtr = new Course[maxNum];
}

CourseSchedule::~CourseSchedule()
{
    delete [] coursePtr;
}
void CourseSchedule::setStudentName(string name)
{
    studentName = name;
}

string CourseSchedule::getStudentName()const
{
    return studentName;
}

int CourseSchedule::getNumCourse()const
{
    return numCourses;
}

Semester& CourseSchedule::getSemester()
{
    return term;
}

bool CourseSchedule::checkDates(const Semester& sem ,const Date& start, const Date& end)
{
    if (sem.getStartDate() > start || sem.getEndDate() < end)
    {
        return false;
    }
    
    else {
        return true;
    }
}

bool CourseSchedule::addCourse(const Course& newCourse)
{
    if (numCourses < maxNum && checkDates(getSemester(),newCourse.getDateStart(), newCourse.getDateEnd()))
    {
        coursePtr[numCourses-1]=newCourse;
        numCourses++;
        return true;
    }
    
    else
    {
        return false;
    }
}

bool CourseSchedule::removeCourse(const Course& oldCourse)
{
    int removed = 0;
    
    for(int i=0;i<numCourses;i++ )
    {
        
        if (coursePtr[i].getCourseNum() == oldCourse.getCourseNum())
        {
            coursePtr[i] = coursePtr[i+1];
            i--;
            numCourses--;
            removed=1;
        }
        
    }
    if (removed == 1)
    {
        return true;
    }
    else
    {
        return false;
    }
}


ostream& operator << (ostream& output, const CourseSchedule& sched)
{
    output<<"CLASS SCHEDULE\n";
    output<<"---------------------\n";
    output<< "Name: " << sched.getStudentName() << endl;
    output<< "Semester: " << sched.term << endl;
    output<< "Number of Classes: " << sched.numCourses << endl;
    for (int i=0; i<sched.numCourses; i++)
    {
        output<<sched.coursePtr[i] << endl;
    }
    
    return output;
}


