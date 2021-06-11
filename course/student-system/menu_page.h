#ifndef MENU_H
#define MENU_H

#include "interface.h"

void Interface::menu() {
    system("color F1");
    cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
    cout << "\t\t\t\t欢迎进入学生成绩管理管理系统!"
            "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
    cout << "=================================================================="
            "===="
            "=========\r"
         << endl;
    cout << "请输入你要管理的人员类型" << endl;
    cout << "1-本科生\t 2-研究生\t 0-退出管理系统" << endl;
}

void Interface::menuBac() {
    int chioce;

    cout << "========================本科生成绩管理菜单========================"
         << endl;
    cout << "=*=*=*=*=*==*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*="
         << endl
         << endl
         << endl;
    cout << "\t\t【1】批量/单个添加本科生基本信息" << endl;
    cout << "\t\t【2】查询本科生信息" << endl;
    cout << "\t\t【3】根据学号修改本科生信息" << endl;
    cout << "\t\t【4】根据学号删除本科生信息" << endl;
    cout << "\t\t【5】批量/单个输入本科生成绩" << endl;
    cout << "\t\t【6】统计功能" << endl;
    cout << "\t\t【0】返回主菜单" << endl;
    cout << "=*=*=*=*=*==*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*="
         << endl
         << endl;
    cout << "请输入您要进行的操作:";
    cin >> chioce;
    switch (chioce) {
        case 0:
            run();
            break;
        case 1:
            InputBase();
            break;
        case 2:
            searchBase();
            break;
        case 3:
            modifyBase();
            break;
        case 4:
            deleteStu();
            break;
        case 5:
            InputScore();
            break;
        case 6:
            statistics();
            break;
    }
}

void Interface::menuGrad() {
    int chioce;
    cout << "========================研究生成绩管理菜单========================"
         << endl;
    cout << "=*=*=*=*=*==*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*="
         << endl
         << endl
         << endl;
    cout << "\t\t【1】批量/单个添加研究生基本信息" << endl;
    cout << "\t\t【2】查询研究生信息" << endl;
    cout << "\t\t【3】根据学号修改研究生信息" << endl;
    cout << "\t\t【4】根据学号删除研究生信息" << endl;
    cout << "\t\t【5】批量/单个输入研究生成绩" << endl;
    cout << "\t\t【6】统计功能" << endl;
    cout << "\t\t【0】返回主菜单" << endl;
    cout << "=*=*=*=*=*==*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*="
         << endl
         << endl;
    cout << "请输入您要进行的操作:";
    cin >> chioce;
    switch (chioce) {
        case 0:
            run();
            break;
        case 1:
            InputBase();
            break;
        case 2:
            searchBase();
            break;
        case 3:
            modifyBase();
            break;
        case 4:
            deleteStu();
            break;
        case 5:
            InputScore();
            break;
        case 6:
            statistics();
            break;
    }
}
void subMenuSeaarch() {
    cout << "=*=*=*=*=*==*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*="
         << endl
         << endl;
    cout << "\t\t【1】显示所有学生信息" << endl;
    cout << "\t\t【2】按班级显示本班全部学生信息" << endl;
    cout << "\t\t【3】根据学号或者姓名查询学生信息" << endl;
    cout << "\t\t【4】在某个班级中查询某门课成绩不及格学生信息" << endl;
    cout << "\t\t【0】回到上一页" << endl << endl << endl;
    cout << "请输入您的选择：";
}
void Interface::menuSearch() {
    int choice;
    if (stuType == 1) {
        cout << "========================本科生信息查询菜单===================="
                "===="
             << endl;
        subMenuSeaarch();
        cin >> choice;
        switch (choice) {
            case 0:
                menuBac();
                break;
            case 1:
                displayAll();
                break;
            case 2:
                displayClassMsg();
                break;
            case 3:
                displayOneMsg();
                break;
            case 4:
                displayBad();
                break;
        }

    } else if (stuType == 2) {
        cout << "========================研究生信息查询菜单===================="
                "===="
             << endl;
        subMenuSeaarch();
        cin >> choice;
        switch (choice) {
            case 0:
                menuGrad();
                break;
            case 1:
                displayAll();
                break;
            case 2:
                displayClassMsg();
                break;
            case 3:
                displayOneMsg();
                break;
            case 4:
                displayBad();
                break;
        }
    }
}

void showAll() {
    cout << "========================显示所有学生信息========================"
         << endl;
    cout << "=*=*=*=*=*==*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*="
         << endl
         << endl;
}

void menuBacTitle() {
    cout << "学号" << setw(5) << "姓名" << setw(5) << "性别" << setw(5)
         << "专业" << setw(5) << "专业编号" << setw(5) << "班级" << setw(5)
         << "班级编号" << setw(5) << "高数成绩" << setw(5) << "英语成绩"
         << setw(5) << "C语言成绩" << setw(5) << "总成绩" << setw(5)
         << "班级排名" << setw(5) << "学校排名" << endl
         << endl;
}

void menuGradTitle() {
    cout << "学号" << setw(5) << "姓名" << setw(5) << "性别" << setw(5)
         << "专业" << setw(5) << "专业编号" << setw(5) << "班级" << setw(5)
         << "班级编号" << setw(5) << "综合成绩" << setw(5) << "论文成绩"
         << setw(5) << "研究方向" << setw(5) << "导师" << setw(5) << "总成绩"
         << setw(5) << "班级排名" << setw(5) << "学校排名" << endl
         << endl;
}

//修改了专业之后，从专业文件里面找到对应的专业编号，自动修改专业编号
//班级和班级编号也是如此
void menuModifyBac() {
    cout << "请输入你要修改的选项：(学号不能修改)" << endl;
    cout << "1-姓名" << setw(5) << "2-性别" << setw(5) << "3-专业" << setw(5)
         << "4-班级" << endl;
}

void menuModityGrad() {
    cout << "请输入你要修改的选项：(学号不能修改)" << endl;
    cout << "1-姓名" << setw(5) << "2-性别" << setw(5) << "3-专业" << setw(5)
         << "4-班级" << setw(5) << "5-专业方向" << setw(5) << "6-导师" << endl;
}

void menuStatistics() {
    cout << "========================统计学生信息========================"
         << endl;
    cout << "\t1-统计并显示某门课每个班的平均成绩" << endl;
    cout << "\t2-在某个班中统计并显示某门课程不同等级的学生人数" << endl;
    cout << "\t0-回到上一页菜单" << endl;
    cout << "=*=*=*=*=*==*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*="
         << endl
         << endl;
}

string getCourseNameByTemp(int temp, int type) {
    if (type == 1) {
        if (temp == 0)
            return "高数";
        if (temp == 1)
            return "英语";
        if (temp == 2)
            return "C语言";
    } else if (type == 2) {
        if (temp == 0)
            return "综合课程";
        if (temp == 1)
            return "论文";
    }
}

void inputNotes() {
    cout << "\t输入说明" << endl;
    cout << "添加班级或者专业时，请注意严格按照classes."
            "txt文件中班级和专业的格式进行输入"
         << endl;
    cout << "另外在添加一个学生信息时，添加的班级和专业必须是现有的班级和专业"
         << endl;
    cout << "本科生格式和内容如下" << endl << endl;
    cout << "\t\t  专业名称\t\t\t班级名称" << endl;
    cout << "\t\t软件工程 ---  2018级软件工程1班" << endl;
    cout << "\t\t软件工程 ---  2018级软件工程2班" << endl;
    cout << "\t\t计算机科学与技术 --- 2018级计算机科学与技术1班" << endl;
    cout << "\t\t计算机科学与技术 --- 2018级计算机科学与技术2班" << endl;
    cout << "\t\t网络工程 --- 2018级网络工程1班" << endl;
    cout << "\t\t网络工程 --- 2018级网络工程2班" << endl;
    cout << "\t\t物联网 --- 2018级物联网1班" << endl;
    cout << "\t\t物联网 --- 2018级物联网2班" << endl;
    cout << endl << "研究生格式和内容如下" << endl << endl;
    cout << "\t\t  专业名称\t\t\t班级名称" << endl;
    cout << "\t\t计算机科学与技术 --- 2015级计算机科学与技术1班" << endl;
    cout << "\t\t计算机科学与技术 --- 2015级计算机科学与技术2班" << endl;
    cout << endl;
}

#endif