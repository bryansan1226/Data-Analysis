#include <iostream>
#include <vector>
using namespace std;
#pragma once

class getData{
    public:
    struct Student{
        string id;
        int courseno;
        string instructorid;
        string grade;
        string termid;
        string termName;
    };

    vector<Student> students;

    getData();
    void readData();
    string getTerm(string termid);
    };

    