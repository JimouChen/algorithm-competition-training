#ifndef PERSON_H
#define PERSON_H

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

class Grade {  //成绩类
private:
    vector<double> score;  //保存每个学生的成绩
    double finalScore;     //总成绩
    int stuType;           //学生类型，1是本科生，2是研究生

public:
    Grade(vector<double>& sc, int type) : score(sc), stuType(type) {}
    Grade(){}
    ~Grade(){}

    vector<double>& getScore();  //获取各科成绩
    double getFinalScore();      //计算一个学生总成绩
};

class Student {  //学生类
public:
    ll stuId;
    string name;
    string sex;
    string major;        //专业名称
    string majorNumber;  //专业编号
    string classNumber;  //班级编号
    string className;    //班级名称
    ll classRank;        //班级排名
    ll schoolRank;       //学校排名
    Grade grade;         //一个学生的成绩

public:
    Student(ll i,
            string na,
            string s,
            string mj,
            string mjNum,
            string clsName,
            string clsNum,
            ll clsRank,
            ll schRank,
            Grade g);
    ~Student(){}

    ll &getId() { return stuId; }
    string& getName() { return name; }
    string& getSex() { return sex; }
    string& getMajor() { return major; }
    string& getMajorNumber() { return majorNumber; }
    string& getClassNumber() { return classNumber; }
    string& getClassName() { return className; }
    ll& getClassRank() { return classRank; }
    ll& getSchoolRank() { return schoolRank; }
    Grade& getGrade() { return grade; }
};


class Bachelor : virtual public Student {
public:
    Bachelor(ll i,
             string na,
             string sex,
             string mj,
             string mjNum,
             string clsName,
             string clsNum,
             ll clsRank,
             ll schRank,
             Grade g);
    ~Bachelor(){}
};

class Graduator : virtual public Student {
private:
    string reDirection;  //研究方向
    string teacher;      //导师
public:
    Graduator(string reDir,
              string tc,
              ll i,
              string na,
              string sex,
              string mj,
              string mjNum,
              string clsName,
              string clsNum,
              ll clsRank,
              ll schRank,
              Grade g);
    ~Graduator(){}
    string& getDiction() { return reDirection; }
    string& getTeacher() { return teacher; }
};

class Class {
private:
    string majorNumber;  //专业编号
    string major;        //专业名称
    string className;    //班级名称
    string classId;      //班级编号
public:
    Class(string mjNum, string mj, string clsName, string id)
            : majorNumber(mjNum), major(mj), className(clsName), classId(id){};
    ~Class(){}
    string& getMajorNumber() { return majorNumber; }
    string& getMajor() { return major; }
    string& getClassName() { return className; }
    string& getClassId() { return classId; }
};

class Major {
private:
    string majorName;  //专业名称
    string majorId;    //专业编号

public:
    Major(string mjName, string id) : majorName(mjName), majorId(id){};
    ~Major(){}
     string& getMajorName()  { return majorName; }
     string& getMajorId()  { return majorId; }
};

#endif
