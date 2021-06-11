#ifndef TOOL_H
#define TOOL_H

#include "interface.h"
#include "person.h"

//统计学生人数
ll getStuNum(char *fileName) {
    ifstream readIn(fileName);
    ll cnt = 0;
    string temp;
    while (getline(readIn, temp, readIn.widen('\n'))) {
        cnt++;
    }
    readIn.close();
    return cnt;
}

//字符串切割
vector<string> splitStr(string str) {
    vector<string> res;
    string temp;
    stringstream words(str);
    //一次输出到temp,并且存入res中
    while (words >> temp) {
        res.push_back(temp);
    }
    return res;
}

#endif

// template <class T>
// void outputBac(vector<Bachelor>::iterator it) {
//     cout << it->getId() << setw(5) << it->getName() << setw(5) <<
//     it->getSex()
//          << setw(5) << it->getMajor() << setw(5) << it->getMajorNumber()
//          << setw(5) << it->getClassName() << setw(5) << it->getClassNumber()
//          << setw(5) << it->getGrade().getScore()[0] << setw(5)
//          << it->getGrade().getScore()[1] << setw(5)
//          << it->getGrade().getScore()[2] << setw(5)
//          << it->getGrade().calFinalScore() << setw(5) << it->getClassRank()
//          << setw(5) << it->getSchoolRank() << endl;
//     it++;
// }

// void outputGrad(vector<Graduator>::iterator& it) {}