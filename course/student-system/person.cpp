#include "person.h"
#include "tool.h"

/*�ɼ����Ա������ʵ��*/

vector<double>& Grade::getScore() {
    return score;
}

//ĳ��ѧ�����ܳɼ�
double Grade::getFinalScore() {
    finalScore = accumulate(score.begin(), score.end(), 0);
    return finalScore;
}

Student::Student(ll i,
                 string na,
                 string s,
                 string mj,
                 string mjNum,
                 string clsName,
                 string clsNum,
                 ll clsRank,
                 ll schRank,
                 Grade g)
                            : stuId(i),
                            name(na),
                            sex(s),
                            major(mj),
                            majorNumber(mjNum),
                            className(clsName),
                            classNumber(clsNum),
                            classRank(clsRank),
                            schoolRank(schRank),
                            grade(g) {}

Bachelor::Bachelor(ll i,
                   string na,
                   string sex,
                   string mj,
                   string mjNum,
                   string clsName,
                   string clsNum,
                   ll clsRank,
                   ll schRank,
                   Grade g)
    : Student(i, na, sex, mj, mjNum, clsName, clsNum, clsRank, schRank, g) {}

Graduator::Graduator(string reDir,
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
                     Grade g)
    : Student(i, na, sex, mj, mjNum, clsName, clsNum, clsRank, schRank, g),
      reDirection(reDir),
      teacher(tc) {}
