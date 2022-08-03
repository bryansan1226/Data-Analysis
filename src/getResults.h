#include <iostream>
#include "getData.h"
#pragma once

using namespace std;
class getResults{
    public:
    getData data;
    getResults();
    double passrateInstructor(string instructor,vector<getData::Student> entries);
    double passrateCourse(int course,vector<getData::Student> entries);
    double wRateInstructor(string instructor,vector<getData::Student> entries);
    double wRateCourse(int course,vector<getData::Student> entries);
    double passrateCoursePerTerm(int course,vector<getData::Student> entries,string term);
    bool isPassingGrade(string);
    bool withdrew(string);

};
