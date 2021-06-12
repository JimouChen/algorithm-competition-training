#ifndef PERSON_H
#define PERSON_H

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

class Grade {  //�ɼ���
private:
    vector<double> score;  //����ÿ��ѧ���ĳɼ�
    double finalScore;     //�ܳɼ�
    int stuType;           //ѧ�����ͣ�1�Ǳ�������2���о���

public:
    Grade(vector<double>& sc, int type) : score(sc), stuType(type) {}
    ~Grade(){}

    vector<double>& getScore();  //��ȡ���Ƴɼ�
    double getFinalScore();      //����һ��ѧ���ܳɼ�
};

class Student {  //ѧ����
public:
    ll stuId;
    string name;
    string sex;
    string major;        //רҵ����
    string majorNumber;  //רҵ���
    string classNumber;  //�༶���
    string className;    //�༶����
    ll classRank;        //�༶����
    ll schoolRank;       //ѧУ����
    Grade grade;         //һ��ѧ���ĳɼ�

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
    string reDirection;  //�о�����
    string teacher;      //��ʦ
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
    string majorNumber;  //רҵ���
    string major;        //רҵ����
    string className;    //�༶����
    string classId;      //�༶���
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
    string majorName;  //רҵ����
    string majorId;    //רҵ���

public:
    Major(string mjName, string id) : majorName(mjName), majorId(id){};
    ~Major(){}
     string& getMajorName()  { return majorName; }
     string& getMajorId()  { return majorId; }
};

#endif
