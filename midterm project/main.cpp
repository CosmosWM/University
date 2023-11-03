//
//  main.cpp
//  CourseSchedule
//
//  Created by David Dominguez on 7/22/21.
//

#include <iostream>
#include <iomanip>
#include "CourseSchedule.h"

using namespace std;

int main() {
    
    string studentName;
    string semesterName;
    string courseNumber;
    string courseName;
    string courseMeetingDays;
    double courseUnits;
   
    char selection;
    int maxClasses;
    
    Date semStartDate;
    Date semEndDate;
    
    cout << "Please enter your name: ";
    getline(cin,studentName);
    cout << "\nPlease enter the semester for which you wish to make a schedule: ";
    getline(cin, semesterName);
    cout<< "\nPlease enter start date of the semester in the following format: MM/DD/YYYY"<< endl;;
    cin >> semStartDate;
    cout << "\nPlease enter the end date of the semester in the following format: MM/DD/YYYY"<< endl;;
    cin >> semEndDate;
    cout << "\nEnter the maximum number of classes that can be taken this semester: ";
    cin >> maxClasses;
    cin.ignore();
    
    Semester term (semesterName,semStartDate,semEndDate);
    CourseSchedule termSchedule (studentName, term, maxClasses);
    
    do{
        Time startTime;
        Time endTime;
        Date startDate;
        Date endDate;
        
        cout << "\n\nCOURSE ENTRY MENU FOR :" << term << endl;
        cout << "------------------------------------------------\n";
        cout << "1) Enter a new course\n";
        cout << "2) Remove a course\n";
        cout << "3) Print a semester schedule\n";
        cout << "q) Quit the program\n";
        cin>> selection;
        cin.ignore();
        
        if (selection =='q' || selection == 'Q')
        {
            cout << "\n\nYou have chosen to quit the program. Goodbye!\n";
        }
        
        else if (selection == '1')
        {
            cout << "\n\nEnter the course name: ";
            getline(cin,courseName);
            cout << "\nEnter the course number: ";
            getline(cin, courseNumber);
            cout << "\nEnter the course meeting days (MTWTHF format):";
            getline(cin,courseMeetingDays);
            cout <<"\nEnter the number of units for this course: ";
            cin>>courseUnits;
            cout << "\nEnter the start date of the course (MM/DD/YYYY format): ";
            cin >>startDate;
            cout << "\nEnter the end date of the course (MM/DD/YYYY format): ";
            cin >> endDate;
            cin.ignore();
            cout << "\nEnter the starting time (12:00AM format): ";
            cin>>startTime;
            cout << "\nEnter the end time (12:00AM format): ";
            cin>>endTime;
            
            Course newCourse (courseName, courseNumber, courseMeetingDays, courseUnits, startDate, endDate, startTime, endTime);
            
            if (termSchedule.addCourse(newCourse))
            {
                cout << "Your course has been added" << endl;
            }
            
            else
            {
                cout<< "There was a problem adding your course. Please try again." << endl;
            }
        }
        
        else if (selection == '2')
        {
            string remoNum;
            cout << "Please enter the course number of the course to be removed:  ";
            cin >> remoNum;
            Course remoCourse;
            remoCourse.setCourseNum(remoNum);
            if(termSchedule.removeCourse(remoCourse))
            {
                cout << "Course was successfully removed\n";
            }
            else
            {
                cout <<"There was an error. Please try again.\n";
            }
        }
    
        else if (selection == '3')
        {
            cout << termSchedule << endl;
        }
        
        
        else{
            cout << "invalid selection" << endl;
        }
    
        
    } while (selection!='q'&& selection!='Q');
    
    
    
    return 0;
}
