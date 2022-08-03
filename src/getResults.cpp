#include <iostream>
#include <algorithm>
#include <fstream>
#include "getResults.h"
#include "getData.h"


using namespace std;
/*
getResults initializes a few variables that have the unique instructor id's and course id's.
It generates a list of the unique instructor id's by using the count function
and adding the id to a uniqueInstructors vector if it doesn't already exist. 

the passRate and wRate functions all work similarly, only differering 
in order to accept different arguments. They initialize two doubles, one for the
total entries and the other for entries where the student either passed or withdrew.
They then check every file to check if they fit match the arguments passed. If they do,
the totalEntries variable will increase by 1 and the passingEntries variable will only
increase if the student passed or withdrew from the course. The two variables are then divided 
and multiplied by 100 to return a pass rate.
*/
getResults::getResults(){
    ofstream passRate("./output/passRate.txt");
    ofstream wRate("./output/withdrawRate.txt");
    ofstream passRatePerTerm("./output/passRatePerTerm");

    vector<string> uniqueInstructors;
    int uniqueCourses[3]={1115,3115,3130};
    string fallTerms[6]={"T04","T08","T12","T16","T20","T23"};
    string springTerms[6]={"T02","T06","T10","T14","T18","T21"};

    for (int i=0;i<data.students.size();i++){
            if (count(uniqueInstructors.begin(),uniqueInstructors.end(),data.students[i].instructorid))
                continue;
            else
            uniqueInstructors.push_back(data.students[i].instructorid);
    }
    passRate<<"Pass rate per instructors:"<<endl;
    for (int i=0;i<uniqueInstructors.size();i++)
        {passRate<<"Instructor "<<uniqueInstructors[i]<<" pass rate: ";
        passRate.precision(4);
        passRate<<passrateInstructor(uniqueInstructors[i],data.students)<<endl;
        }
    passRate<<"Pass rate per courses:"<<endl;
    for (int i=0;i<3;i++){
        passRate<<"Course "<<uniqueCourses[i]<<" pass rate: "
        <<passrateCourse(uniqueCourses[i],data.students)<<endl;
    }
    passRate.close();

    wRate<<"Pass rate per instructors:"<<endl;
    for (int i=0;i<uniqueInstructors.size();i++)
        {wRate<<"Instructor "<<uniqueInstructors[i]<<" W rate: ";
        wRate.precision(4);
        wRate<<wRateInstructor(uniqueInstructors[i],data.students)<<endl;
        }
    wRate<<"Pass rate per courses:"<<endl;
    for (int i=0;i<3;i++){
        wRate<<"Course "<<uniqueCourses[i]<<" W rate: "
        <<wRateCourse(uniqueCourses[i],data.students)<<endl;
    }
    wRate.close();

    passRatePerTerm<<"Fall vs Spring pass rate for each course:"<<endl;
        for (int i=0;i<3;i++){
            passRatePerTerm<<"Course "<<uniqueCourses[i]<<" pass rate: "<<endl;
            passRatePerTerm<<"Fall: ";
            passRatePerTerm.precision(4);
            passRatePerTerm<<passrateCoursePerTerm(uniqueCourses[i],data.students,"Fall")<<endl;
            passRatePerTerm<<"Spring: "<<passrateCoursePerTerm(uniqueCourses[i],data.students,"Spring")<<endl<<endl;
        }
        passRatePerTerm.close();





}
double getResults::passrateInstructor(string instructor,vector<getData::Student> entries){
    double totalEntries=0,passingEntries=0;
    for(int i=0;i<entries.size();i++){
        if (instructor.compare(entries[i].instructorid)==0){
            if (isPassingGrade(entries[i].grade))
            {
                passingEntries++;
                totalEntries++;
            }
            else totalEntries++;
        }
    }
    return (passingEntries/totalEntries)*100;    
    
}
double getResults::passrateCourse(int course, vector<getData::Student> entries){
    double totalEntries=0,passingEntries=0;
    for(int i=0;i<entries.size();i++){
        if (course==entries[i].courseno){
            if (isPassingGrade(entries[i].grade))
            {
                passingEntries++;
                totalEntries++;
            }
            else totalEntries++;

        }
    }
    return (passingEntries/totalEntries)*100;
}
double getResults::wRateInstructor(string instructor,vector<getData::Student> entries){
    double totalEntries=0,passingEntries=0;
    for(int i=0;i<entries.size();i++){
        if (instructor.compare(entries[i].instructorid)==0){
            if (withdrew(entries[i].grade))
            {
                passingEntries++;
                totalEntries++;
            }
            else totalEntries++;
        }
    }
    return (passingEntries/totalEntries)*100;    
    
}
double getResults::wRateCourse(int course, vector<getData::Student> entries){
    double totalEntries=0,passingEntries=0;
    for(int i=0;i<entries.size();i++){
        if (course==entries[i].courseno){
            if (withdrew(entries[i].grade))
            {
                passingEntries++;
                totalEntries++;
            }
            else totalEntries++;

        }
    }
    return (passingEntries/totalEntries)*100;
}
double getResults::passrateCoursePerTerm(int course, vector<getData::Student> entries,string term){
    double totalEntries=0,passingEntries=0;
    for(int i=0;i<entries.size();i++){
        if (course==entries[i].courseno&&entries[i].termName.compare(term)==0){
            if (isPassingGrade(entries[i].grade))
            {
                passingEntries++;
                totalEntries++;
            }
            else totalEntries++;

        }
    }
    return (passingEntries/totalEntries)*100;
}

bool getResults::isPassingGrade(string grade){
    if (grade[0]=='A'||grade[0]=='B'||grade[0]=='C'||grade[0]=='D')
        return true;
    else return false;
}
bool getResults::withdrew(string grade){
    if(grade[0]=='W')
        return true;
    else return false;

}