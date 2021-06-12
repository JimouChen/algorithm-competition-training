#ifndef INTERFACE_H
#define INTERFACE_H

#include "person.h"
using namespace std;

class Interface {
private:
    vector<Bachelor> bachelor;
    vector<Graduator> graduator;
    vector<Class> cls;
    vector<Major> major;
    int stuType;

public:
    Interface();  //打开文件读取数据
    ~Interface();

    void readFile(); //被构造函数调用
    void menu();      //主菜单展示
    void menuBac();   //本科生管理菜单
    void menuGrad();  //研究生管理主菜单

    void menuSearch();       //查询选择菜单
    void displayAll();       //查询时显示所有学生信息
    void displayClassMsg();  //按班级显示本班全部学生信息
    void displayOneMsg();    //根据学号或者姓名查询学生信息
    void displayBad();  //在某个班级中查询某门课成绩不及格学生信息

    void run();  //启动
    void save();        //保存
    void InputBase();   //添加学生基本资料数据（一个或者批量）
    void modifyBase();  //通过学号来修改信息
    void deleteStu();   //通过学号删除一个学生
    void searchBase();  //通过学号查询学生基本信息

    /*成绩数据维护*/
    void InputScore();    //输入学生成绩（一个或者批量）
    void modifyGrade();   //修改学生成绩
    void searchGrade();   //通过学号查询学生成绩
    void calGradeRank();  //计算学生成绩，排名
    void statistics();    //统计功能
    void stAvg();         //统计显示某门课每个班的平均成绩
    void stLevelCount();  //统计显示某门课不同等级的人数

    /*用于比较和排序*/
    static bool cmpBacByScore(Bachelor b1, Bachelor b2);
    static bool cmpGradByScore(Graduator g1, Graduator g2);

    ll getNextStuId(string clsNum, int type);  //获取下一个学号
    ll calClassRank(string clsNum, ll xh);            //计算班级排名
    ll calSchoolRank(ll xh);             //计算全校排名
    void saveRank();
};

#endif //INTERFACE_H
