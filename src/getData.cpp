#include <iostream>
#include "getData.h"
#include <fstream>
#include <sstream>
using namespace std;
getData::getData(){
   
    readData();
}
/*readData will open all 3 csv files. It then passes each line into a stringstream, 
s, to divide the line by columns. It saves each column into an appropriately named
variable and then creates a student struct with the read values. It does this 3 times for 
the 3 .csv files

getTerm will take the term id of the student struct as an argument, if the term id matches 
the term id of a fall term, it will return "fall", otherwise it will return "Spring."
*/
void getData::readData(){
    fstream data1115,data3115,data3130;
    string line;
    string word;
    string id,instructorid,termid,sectionid,grade;
    int courseno;
    //int i=0;
    
    data1115.open("./data/1115.csv");
    getline(data1115,line);
    while(getline(data1115,line)){
        stringstream s(line);
        getline(s,word,',');
        id=word;
        getline(s,word,',');
        courseno=stoi(word);
        getline(s,word,',');
        instructorid=word;
        getline(s,word,',');
        termid=word;
        getline(s,word,',');
        sectionid=word;
        getline(s,word,',');
        grade=word;
        Student myStudent={id,courseno,instructorid,grade,termid};
               
        students.push_back(myStudent);
  
    };
    data1115.close();
    
    data3115.open("./data/3115.csv");
    getline(data3115,line);
    while(getline(data3115,line)){
        stringstream s(line);
        getline(s,word,',');
        id=word;
        getline(s,word,',');
        courseno=stoi(word);
        getline(s,word,',');
        instructorid=word;
        getline(s,word,',');
        termid=word;
        getline(s,word,',');
        sectionid=word;
        getline(s,word,',');
        grade=word;
        Student myStudent={id,courseno,instructorid,grade,termid,getTerm(termid)};

               
        students.push_back(myStudent);
   
    };

    data3115.close();
    
    data3130.open("./data/3130.csv");
    getline(data3130,line);
    while(getline(data3130,line)){
        stringstream s(line);
        getline(s,word,',');
        id=word;
        getline(s,word,',');
        courseno=stoi(word);
        getline(s,word,',');
        instructorid=word;
        getline(s,word,',');
        termid=word;
        getline(s,word,',');
        sectionid=word;
        getline(s,word,',');
        grade=word;
        Student myStudent={id,courseno,instructorid,grade,termid,getTerm(termid)};

               
        students.push_back(myStudent);

    };

    data3130.close();
    

}
string getData::getTerm(string termid){
    string term;
    if (termid.compare("T04")==0||termid.compare("T08")==0||
    termid.compare("T12")==0||termid.compare("T16")==0||
    termid.compare("T20")==0||termid.compare("T23")==0)
        term="Fall";
    else
        term="Spring";
    return term;

}