#include "interface.h"
#include "menu_page.h"
#include "person.cpp"

Interface::Interface() {
    readFile();
}

//从文件中读出信息先保存到对象中，再计算成绩和排名
void Interface::readFile() {
    ifstream bacIn("bachelor.txt");
    if (!bacIn) {
        cout << "无法打开文件bachelor.txt" << endl;
        return;
    }

    ifstream gradIn("graduator.txt");
    if (!gradIn) {
        cout << "无法打开graduator.txt文件" << endl;
        return;
    }

    ifstream classIn("classes.txt");
    if (!classIn) {
        cout << "无法打开classes.txt文件" << endl;
        return;
    }

    ifstream majorIn("major.txt");
    if (!majorIn) {
        cout << "无法打开major.txt文件" << endl;
        return;
    }
    /*本科生数据存到容器*/
    ll bacId;
    string bacName;
    string bacSex;
    string bacMajor;
    string bacMajorNumber;
    string bacClassName;
    string bacClassNum;
    vector<double> bacScore(3, 0);
    double bacFinalScore;
    ll bacClassRank;
    ll bacSchoolRank;

    while (!bacIn.eof()) {
        bacIn >> bacId >> bacName >> bacSex >> bacMajor >> bacMajorNumber >>
            bacClassName >> bacClassNum >> bacScore[0] >> bacScore[1] >>
            bacScore[2] >> bacFinalScore >> bacClassRank >> bacSchoolRank;
        bacFinalScore = accumulate(bacScore.begin(), bacScore.end(), 0);

        Grade bacGrade(bacScore, 1);
        Bachelor bac(bacId, bacName, bacSex, bacMajor, bacMajorNumber,
                     bacClassName, bacClassNum, bacClassRank, bacSchoolRank,
                     bacGrade);

        bachelor.push_back(bac);
    }

    /*研究生数据存到容器*/
    vector<double> gradScore(2, 0);
    string diction;
    string teacher;
    ll gradId;
    string gradName;
    string gradSex;
    string gradMajor;
    string gradMajorNum;
    string gradClassNum;
    string gradClassName;
    double gradFinalScore;
    ll gradClassRank;
    ll gradSchoolRank;

    while (!gradIn.eof()) {
        gradIn >> gradId >> gradName >> gradSex >> gradMajor >> gradMajorNum >>
            gradClassName >> gradClassNum >> gradScore[0] >> gradScore[1] >>
            diction >> teacher >> gradFinalScore >> gradClassRank >>
            gradSchoolRank;
        gradFinalScore = gradScore[0] + gradScore[1];

        Grade gradGrade(gradScore, 2);
        Graduator grad(diction, teacher, gradId, gradName, gradSex, gradMajor,
                       gradMajorNum, gradClassName, gradClassNum, gradClassRank,
                       gradSchoolRank, gradGrade);

        graduator.push_back(grad);
    }

    /*班级和班级编号数据存到容器*/
    string majorNum;
    string majorNa;
    string className;
    string classId;

    while (!classIn.eof()) {
        classIn >> majorNum >> majorNa >> className >> classId;
        Class clsTemp(majorNum, majorNa, className, classId);
        cls.push_back(clsTemp);
    }

    /*专业和专业编号数据存到容器*/
    string mjName;
    string mjId;

    while (!majorIn.eof()) {
        majorIn >> mjName >> mjId;
        Major mjTemp(mjName, mjId);
        major.push_back(mjTemp);
    }

    bacIn.close();
    gradIn.close();
    classIn.close();
    majorIn.close();
}

//启动主菜单
void Interface::run() {
    int chioce;
    menu();
    do {
        cin >> chioce;
        if (chioce == 1) {
            stuType = 1;  //在选择时确定人员类型
            menuBac();
        } else if (chioce == 2) {
            stuType = 2;
            menuGrad();
        } else if (chioce != 0) {
            cout << "输入无效，请重新输入" << endl;
        }

    } while (chioce);
    save();  //保存文件并退出
}

//找到该班级中的最大学号，用于自动生成下一个学号
ll Interface::getNextStuId(string clsNum, int type) {
    ll maxId = 0;
    if (type == 1) {
        vector<Bachelor>::iterator it = bachelor.begin();
        while (it != bachelor.end()) {
            if (clsNum == it->getClassNumber()) {
                if (maxId < it->getId()) {
                    maxId = it->getId();
                }
            }
            it++;
        }
    } else if (type == 2) {
        vector<Graduator>::iterator it = graduator.begin();
        while (it != graduator.end()) {
            if (clsNum == it->getClassNumber()) {
                if (maxId < it->getId())
                    maxId = it->getId();
            }
            it++;
        }
    }
    return maxId + 1;
}

//本科生按总成绩排序高到低
bool Interface::cmpBacByScore(Bachelor b1, Bachelor b2) {
    return b1.getGrade().getFinalScore() > b2.getGrade().getFinalScore();
}

// //研究生按总成绩排序高到低
bool Interface::cmpGradByScore(Graduator g1, Graduator g2) {
    return g1.getGrade().getFinalScore() > g2.getGrade().getFinalScore();
}

//计算班级排名
ll Interface::calClassRank(string clsNum, ll xh) {
    ll res;
    ll rank = 1;
    int flag = 0;  //找到学号就是1
    if (stuType == 1) {
        vector<Bachelor>::iterator it = bachelor.begin();
        sort(bachelor.begin(), bachelor.end(), cmpBacByScore);
        while (it != bachelor.end()) {
            if (it->getId() == xh) {
                flag = 1;
                res = rank;
            }
            if (it->getClassNumber() == clsNum && it->getId() != -1) {
                it->getClassRank() = rank++;
            }

            it++;
        }

    } else if (stuType == 2) {
        vector<Graduator>::iterator it = graduator.begin();
        sort(graduator.begin(), graduator.end(), cmpGradByScore);

        while (it != graduator.end()) {
            if (it->getId() == xh) {
                flag = 1;
                res = rank;
            }
            if (it->getClassNumber() == clsNum && it->getId() != -1) {
                it->getClassRank() = rank++;
            }

            it++;
        }
    }
    if (flag == 0)
        return rank + 1;

    return res;
}

//计算全校排名
ll Interface::calSchoolRank(ll xh) {
    ll res = 0;
    ll rank = 1;
    int flag = 0;  //找到学号就是1，否则是0
    if (stuType == 1) {
        sort(bachelor.begin(), bachelor.end(), cmpBacByScore);
        vector<Bachelor>::iterator it = bachelor.begin();
        while (it != bachelor.end()) {
            if (it->getId() == xh) {
                flag = 1;
                res = rank;
            }
            if (it->getId() != -1) {
                it->schoolRank = rank++;
            }

            it++;
        }

    } else if (stuType == 2) {
        sort(graduator.begin(), graduator.end(), cmpGradByScore);
        vector<Graduator>::iterator it = graduator.begin();
        while (it != graduator.end()) {
            if (it->getId() == xh) {
                flag = 1;
                res = rank;
            }

            if (it->getId() != -1) {
                it->schoolRank = rank++;
            }
            it++;
        }
    }
    if (flag == 0)  //找不到学号排最后
        return rank + 1;
    return res;
}

//输入数据，把创建的一个或者批量对象加到容器
void Interface::InputBase() {
    int choice = 100;

    do {
        inputNotes();
        ll Id;
        string na;
        string s;
        string mj;
        string mjNumber;  //自动添加
        string clsNa;
        string clsNum;  //自动添加
        ll clsRank;     //由计算得到
        ll schRank;
        cout << "请输入学生的姓名：";
        cin >> na;
        cout << "请输入学生的性别：";
        cin >> s;
        cout << "请输入学生的专业名称：";
        cin >> mj;
        //去cls里面找
        vector<Class>::iterator itCls = cls.begin();
        while (itCls != cls.end()) {
            if (itCls->getMajor() == mj) {
                mjNumber = itCls->getMajorNumber();
                break;
            }
            itCls++;
        }

        cout << "请输入学生的班级名称：";
        cin >> clsNa;
        itCls = cls.begin();
        while (itCls != cls.end()) {
            if (itCls->getClassName() == clsNa) {
                clsNum = itCls->getClassId();
                break;
            }
            itCls++;
        }
        if (stuType == 1) {
            double math = -1, eng = -1, clan = -1;
            vector<double> g{math, eng, clan};
            Id = getNextStuId(clsNum, 1);
            Grade bacGrade(g, 1);
            clsRank = calClassRank(clsNum, Id);
            schRank = calSchoolRank(Id);

            Bachelor bac(Id, na, s, mj, mjNumber, clsNa, clsNum, clsRank,
                         schRank, bacGrade);
            bachelor.push_back(bac);
            saveRank();

        } else if (stuType == 2) {
            double zh = -1, paper = -1;
            string diction;
            string teacher;
            cout << "请输入学生的导师：" << endl;
            cin >> diction;
            cout << "请输入学生的研究方向：" << endl;
            cin >> teacher;
            vector<double> g{zh, paper};
            Id = getNextStuId(clsNum, 2);
            Grade gradGrade(g, 2);
            clsRank = calClassRank(clsNum, Id);
            schRank = calSchoolRank(Id);
            Graduator grad(diction, teacher, Id, na, s, mj, mjNumber, clsNa,
                           clsNum, clsRank, schRank, gradGrade);
            graduator.push_back(grad);
            saveRank();
        }
        cout << "============学生信息添加成功============" << endl;
        cout << endl
             << "回到首页菜单请输入0" << endl
             << "继续添加信息请输入1" << endl;
        cin >> choice;
        if (choice == 1)
            continue;
        // if (choice == 0)
        //     break;

    } while (choice);
    run();
}

void Interface::searchBase() {
    menuSearch();  //进入子菜单查询
}

//显示前把排名计算好存进去
void Interface::saveRank() {
    vector<Class>::iterator itCls = cls.begin();

    if (stuType == 1) {
        vector<Bachelor>::iterator it = bachelor.begin();
        while (itCls != cls.end()) {
            while (it != bachelor.end()) {
                calClassRank(itCls->getClassId(), it->getId());
                it++;
            }

            itCls++;
            it = bachelor.begin();
        }
        calSchoolRank(0);
    } else if (stuType == 2) {
        vector<Graduator>::iterator it = graduator.begin();
        while (itCls != cls.end()) {
            while (it != graduator.end()) {
                calClassRank(itCls->getClassId(), it->getId());
                it++;
            }

            itCls++;
            it = graduator.begin();
        }
        calSchoolRank(0);
    }
}

//展示学生所有信息
void Interface::displayAll() {
    int choice = 100;
    do {
        showAll();
        if (stuType == 1) {
            saveRank();
            menuBacTitle();
            vector<Bachelor>::iterator it = bachelor.begin();
            while (it != bachelor.end()) {
                if (it->getId() != -1) {
                    cout << it->getId() << setw(10) << it->getName() << setw(5)
                         << it->getSex() << setw(20) << it->getMajor()
                         << setw(10) << it->getMajorNumber() << setw(30)
                         << it->getClassName() << setw(15)
                         << it->getClassNumber() << setw(10)
                         << it->getGrade().getScore()[0] << setw(10)
                         << it->getGrade().getScore()[1] << setw(10)
                         << it->getGrade().getScore()[2] << setw(8)
                         << it->getGrade().getFinalScore() << setw(8)
                         << it->getClassRank() << setw(10)
                         << it->getSchoolRank() << endl;
                }

                it++;
            }

        } else if (stuType == 2) {
            saveRank();
            menuGradTitle();
            vector<Graduator>::iterator it = graduator.begin();
            while (it != graduator.end()) {
                if (it->getId() != -1) {
                    cout << it->getId() << setw(10) << it->getName() << setw(5)
                         << it->getSex() << setw(20) << it->getMajor()
                         << setw(10) << it->getMajorNumber() << setw(30)
                         << it->getClassName() << setw(15)
                         << it->getClassNumber() << setw(10)
                         << it->getGrade().getScore()[0] << setw(10)
                         << it->getGrade().getScore()[1] << setw(10)
                         << it->getDiction() << setw(10) << it->getTeacher()
                         << setw(5) << it->getGrade().getFinalScore()
                         << setw(10) << it->getClassRank() << setw(10)
                         << it->getSchoolRank() << endl;
                }

                it++;
            }
        }
        cout << endl
             << endl
             << "返回主菜单请输入0，返回上一页菜单请输入1,重新查询请输入2:";
        cin >> choice;
        if (choice == 2)
            continue;
        if (choice == 1)
            break;

    } while (choice);
    if (choice == 0)
        run();
    if (choice == 1)
        menuSearch();
}

//根据班级显示本班所有学生信息
void Interface::displayClassMsg() {
    int choice = 100;

    do {
        string clsNum;
        cout << "请输入你要查询学生信息的班级编号：";
        cin >> clsNum;
        cout << "您所查询的班级学生信息如下：" << endl;
        if (stuType == 1) {
            saveRank();
            menuBacTitle();
            vector<Bachelor>::iterator it = bachelor.begin();
            while (it != bachelor.end()) {
                if (it->getClassNumber() == clsNum && it->getId() != -1) {
                    cout << it->getId() << setw(10) << it->getName() << setw(5)
                         << it->getSex() << setw(20) << it->getMajor()
                         << setw(10) << it->getMajorNumber() << setw(30)
                         << it->getClassName() << setw(15)
                         << it->getClassNumber() << setw(10)
                         << it->getGrade().getScore()[0] << setw(10)
                         << it->getGrade().getScore()[1] << setw(10)
                         << it->getGrade().getScore()[2] << setw(8)
                         << it->getGrade().getFinalScore() << setw(8)
                         << it->getClassRank() << setw(10)
                         << it->getSchoolRank() << endl;
                }
                it++;
            }

        } else if (stuType == 2) {
            saveRank();
            menuGradTitle();
            vector<Graduator>::iterator it = graduator.begin();
            while (it != graduator.end()) {
                if (it->getClassNumber() == clsNum && it->getId() != -1) {
                    cout << it->getId() << setw(10) << it->getName() << setw(5)
                         << it->getSex() << setw(20) << it->getMajor()
                         << setw(10) << it->getMajorNumber() << setw(30)
                         << it->getClassName() << setw(15)
                         << it->getClassNumber() << setw(10)
                         << it->getGrade().getScore()[0] << setw(10)
                         << it->getGrade().getScore()[1] << setw(10)
                         << it->getDiction() << setw(10) << it->getTeacher()
                         << setw(5) << it->getGrade().getFinalScore()
                         << setw(10) << it->getClassRank() << setw(10)
                         << it->getSchoolRank() << endl;
                }
                it++;
            }
        }

        cout << "继续查询请输入1，返回上一级菜单请输入2，返回主菜单其输入0"
             << endl;
        cin >> choice;
        if (choice == 0 || choice == 2)
            break;
        else if (choice == 1)
            continue;
    } while (choice);
    if (choice == 0)
        run();
    if (choice == 2)
        menuSearch();
}

//根据学号或者姓名查询学生信息
void Interface::displayOneMsg() {
    int choice = 100;
    do {
        cout << "请输入你要查询信息的学号或者姓名" << endl;
        cout << "输入学号请按1，输入姓名请按2: ";
        int flag;
        ll xh = 0;
        string na = " ";

        cin >> flag;
        if (flag == 1) {
            cin >> xh;
        } else if (flag == 2) {
            cin >> na;
        }
        if (stuType == 1) {
            vector<Bachelor>::iterator it = bachelor.begin();
            saveRank();
            menuBacTitle();

            while (it != bachelor.end()) {
                if (it->getId() == xh || it->getName() == na) {
                    cout << it->getId() << setw(10) << it->getName() << setw(5)
                         << it->getSex() << setw(20) << it->getMajor()
                         << setw(10) << it->getMajorNumber() << setw(30)
                         << it->getClassName() << setw(15)
                         << it->getClassNumber() << setw(10)
                         << it->getGrade().getScore()[0] << setw(10)
                         << it->getGrade().getScore()[1] << setw(10)
                         << it->getGrade().getScore()[2] << setw(8)
                         << it->getGrade().getFinalScore() << setw(8)
                         << it->getClassRank() << setw(10)
                         << it->getSchoolRank() << endl;
                }
                it++;
            }
        } else if (stuType == 2) {
            vector<Graduator>::iterator it = graduator.begin();
            saveRank();
            menuGradTitle();
            while (it != graduator.end()) {
                if (it->getId() == xh || it->getName() == na) {
                    cout << it->getId() << setw(10) << it->getName() << setw(5)
                         << it->getSex() << setw(20) << it->getMajor()
                         << setw(10) << it->getMajorNumber() << setw(30)
                         << it->getClassName() << setw(15)
                         << it->getClassNumber() << setw(10)
                         << it->getGrade().getScore()[0] << setw(10)
                         << it->getGrade().getScore()[1] << setw(10)
                         << it->getDiction() << setw(10) << it->getTeacher()
                         << setw(5) << it->getGrade().getFinalScore()
                         << setw(10) << it->getClassRank() << setw(10)
                         << it->getSchoolRank() << endl;
                }
                it++;
            }
        }
        cout << endl
             << "继续查询请输入1，返回上一级菜单请输入2，返回主菜单其输入0"
             << endl;
        cin >> choice;
        if (choice == 0 || choice == 2)
            break;
        else if (choice == 1)
            continue;
    } while (choice);
    if (choice == 0)
        run();
    if (choice == 2)
        menuSearch();
}

//在某个班级中查询某门课成绩不及格学生信息
void Interface::displayBad() {
    int choice = 100;
    string clsNum;

    do {
        int flag = 0;  //如果有结果就是1
        if (stuType == 1) {
            cout << "请输入您要查询的班级编号：";
            cin >> clsNum;
            vector<Bachelor>::iterator it = bachelor.begin();
            int temp;
            vector<string> courseName{"高数", "英语", "C语言"};
            cout << "请输入查询哪一门课：0-高数  1-英语  2-C语言：";
            cin >> temp;
            cout << "课程为" << courseName[temp] << "不及格的本科生信息如下："
                 << endl;
            saveRank();
            menuBacTitle();
            while (it != bachelor.end()) {
                if (it->getClassNumber() == clsNum &&
                    it->getGrade().getScore()[temp] < 60 && it->getId() != -1) {
                    flag = 1;
                    cout << it->getId() << setw(10) << it->getName() << setw(5)
                         << it->getSex() << setw(20) << it->getMajor()
                         << setw(10) << it->getMajorNumber() << setw(30)
                         << it->getClassName() << setw(15)
                         << it->getClassNumber() << setw(10)
                         << it->getGrade().getScore()[0] << setw(10)
                         << it->getGrade().getScore()[1] << setw(10)
                         << it->getGrade().getScore()[2] << setw(8)
                         << it->getGrade().getFinalScore() << setw(8)
                         << it->getClassRank() << setw(10)
                         << it->getSchoolRank() << endl;
                }
                it++;
            }

        } else if (stuType == 2) {
            cout << "请输入您要查询的班级编号：";
            cin >> clsNum;
            vector<Graduator>::iterator it = graduator.begin();
            int temp;
            vector<string> courseName{"综合成绩", "论文成绩"};

            cout << "请输入查询哪一门课：0-综合成绩  1-论文成绩：";
            cin >> temp;
            cout << "课程为" << it->getGrade().getScore()[temp]
                 << "不及格的研究生信息如下：" << endl;
            saveRank();
            menuGradTitle();
            while (it != graduator.end()) {
                if (it->getClassNumber() == clsNum &&
                    it->getGrade().getScore()[temp] < 60 && it->getId() != -1) {
                    flag = 1;
                    cout << it->getId() << setw(10) << it->getName() << setw(5)
                         << it->getSex() << setw(20) << it->getMajor()
                         << setw(10) << it->getMajorNumber() << setw(30)
                         << it->getClassName() << setw(15)
                         << it->getClassNumber() << setw(10)
                         << it->getGrade().getScore()[0] << setw(10)
                         << it->getGrade().getScore()[1] << setw(10)
                         << it->getDiction() << setw(10) << it->getTeacher()
                         << setw(5) << it->getGrade().getFinalScore()
                         << setw(10) << it->getClassRank() << setw(10)
                         << it->getSchoolRank() << endl;
                }
                it++;
            }
        }
        if (flag == 0)
            cout << "无检索结果，该班的这门课没有不及格的学生" << endl;
        cout << endl
             << "继续查询请输入1，返回上一级菜单请输入2，返回主菜单其输入0"
             << endl
             << endl;
        cin >> choice;
        if (choice == 0 || choice == 2)
            break;
        else if (choice == 1)
            continue;

    } while (choice);
    if (choice == 0)
        run();
    if (choice == 2)
        menuSearch();
}

//根据学号修改
void Interface::modifyBase() {
    ll xh;
    int choice = 100;
    string changing;
    do {
        if (stuType == 1) {
            cout << "请输入你要修改的本科生学号：";
            cin >> xh;
            menuModifyBac();
            vector<Bachelor>::iterator it = bachelor.begin();
            cin >> choice;
            while (it != bachelor.end()) {
                if (it->getId() == xh)
                    break;
                it++;
            }
            switch (choice) {
                case 1:
                    cout << "请输入修改后的姓名：";
                    cin >> changing;
                    it->getName() = changing;
                    break;
                case 2:
                    cout << "请输入修改后的性别：";
                    cin >> changing;
                    it->getSex() = changing;
                    break;
                case 3: {
                    cout << "请输入修改后的专业：";
                    cin >> changing;
                    it->getMajor() = changing;
                    //根据专业修改专业编号，同时班级也要一起修改
                    vector<Class>::iterator itCls = cls.begin();
                    while (itCls != cls.end()) {
                        if (itCls->getMajor() == changing) {
                            it->getMajorNumber() = itCls->getMajorNumber();
                            it->getClassName() = itCls->getClassName();
                            it->getClassNumber() = itCls->getClassId();
                            break;
                        }
                        itCls++;
                    }
                }

                break;
                case 4: {
                    cout << "请输入修改后的班级：";
                    cin >> changing;
                    it->getClassName() = changing;
                    //根据班级修改班级班级编号,专业也要跟着改
                    vector<Class>::iterator itCls = cls.begin();
                    while (itCls != cls.end()) {
                        if (itCls->getClassName() == changing) {
                            it->getClassNumber() = itCls->getClassId();
                            it->getMajor() = itCls->getMajor();
                            it->getMajorNumber() = itCls->getMajorNumber();
                            break;
                        }
                        itCls++;
                    }
                }

                break;
            }
        } else if (stuType == 2) {
            cout << "请输入你要修改的研究生学号：";
            cin >> xh;
            menuModityGrad();
            vector<Graduator>::iterator it = graduator.begin();
            cin >> choice;

            while (it != graduator.end()) {
                if (it->getId() == xh)
                    break;
                it++;
            }
            switch (choice) {
                case 1:
                    cout << "请输入修改后的姓名：";
                    cin >> changing;
                    it->getName() = changing;
                    break;
                case 2:
                    cout << "请输入修改后的性别：";
                    cin >> changing;
                    it->getSex() = changing;
                    break;
                case 3: {
                    cout << "请输入修改后的专业：";
                    cin >> changing;
                    it->getMajor() = changing;
                    //根据专业修改专业编号，同时班级也要一起修改
                    vector<Class>::iterator itCls = cls.begin();
                    while (itCls != cls.end()) {
                        if (itCls->getMajor() == changing) {
                            it->getMajorNumber() = itCls->getMajorNumber();
                            it->getClassName() = itCls->getClassName();
                            it->getClassNumber() = itCls->getClassId();
                            break;
                        }
                        itCls++;
                    }

                } break;
                case 4: {
                    cout << "请输入修改后的班级：";
                    cin >> changing;
                    it->getClassName() = changing;
                    //根据班级修改班级班级编号
                    vector<Class>::iterator itCls = cls.begin();
                    while (itCls != cls.end()) {
                        if (itCls->getClassName() == changing) {
                            it->getClassNumber() = itCls->getClassId();
                            it->getMajor() = itCls->getMajor();
                            it->getMajorNumber() = itCls->getMajorNumber();
                            break;
                        }
                        itCls++;
                    }

                } break;
                case 5:
                    cout << "请输入修改后的专业方向：";
                    cin >> changing;
                    it->getDiction() = changing;
                    break;
                case 6:
                    cout << "请输入修改后的导师名称：";
                    cin >> changing;
                    it->getTeacher() = changing;
                    break;
            }
        }
        cout << endl << "修改完毕!" << endl;
        cout << "如果要继续修改请输入1，返回上一级菜单请输入2，返回主菜单请输入"
                "0";
        cin >> choice;
        if (choice == 1)
            continue;
        if (choice == 0 || choice == 2)
            break;

    } while (choice);
    if (choice == 0)
        run();
    else if (choice == 2) {
        if (stuType == 1)
            menuBac();
        if (stuType == 2)
            menuGrad();
    }
}

//删除信息，把学号设为-1
void Interface::deleteStu() {
    int choice = 100;
    ll xh;
    cout << "请输入你要删除的学生信息的学号：";
    cin >> xh;
    do {
        if (stuType == 1) {
            vector<Bachelor>::iterator it = bachelor.begin();
            while (it != bachelor.end()) {
                if (it->getId() == xh) {
                    it->getId() = -1;
                    break;
                }
                it++;
            }
            saveRank();  //删除后要重新排名
        } else if (stuType == 2) {
            vector<Graduator>::iterator it = graduator.begin();
            while (it != graduator.end()) {
                if (it->getId() == xh) {
                    it->getId() = -1;
                    break;
                }
                it++;
            }
            saveRank();  //删除后要重新排名
        }
        cout << endl << "删除学生成功" << endl;
        cout << "继续删除请输入1，返回上一级菜单请输入2，返回首页菜单请输入0：";
        cin >> choice;
        if (choice == 1)
            continue;
        if (choice == 0 || choice == 2)
            break;

    } while (choice);
    if (choice == 0)
        run();
    else if (choice == 2) {
        if (stuType == 1)
            menuBac();
        if (stuType == 2)
            menuGrad();
    }
}

//输入成绩
void Interface::InputScore() {
    int choice = 100;
    do {
        if (stuType == 1) {
            ll xh;
            cout << "请输入你要添加成绩的本科生学号：";
            cin >> xh;
            vector<Bachelor>::iterator it = bachelor.begin();

            while (it != bachelor.end()) {
                if (it->getId() == xh) {
                    double a, b, c;
                    cout << "请依次输入高数、英语、C语言的分数：";
                    cin >> a >> b >> c;
                    vector<double> v{a, b, c};
                    it->getGrade().getScore() = v;  //赋值
                    break;
                }
                it++;
            }
        } else if (stuType == 2) {
            ll xh;
            cout << "请输入你要添加成绩的研究生学号：";
            cin >> xh;
            vector<Graduator>::iterator it = graduator.begin();

            while (it != graduator.end()) {
                if (it->getId() == xh) {
                    double a, b;
                    cout << "请依次输入综合成绩和论文成绩的分数：";
                    cin >> a >> b;
                    vector<double> v{a, b};
                    it->getGrade().getScore() = v;  //赋值
                    break;
                }
                it++;
            }
        }
        cout << "成绩添加完毕" << endl;
        cout << "继续添加成绩请输入1，返回上一级菜单请输入2，返回首页菜单请输入"
                "0：";
        cin >> choice;
        if (choice == 1)
            continue;
        if (choice == 0 || choice == 2)
            break;

    } while (choice);
    if (choice == 0)
        run();
    else if (choice == 2) {
        if (stuType == 1)
            menuBac();
        if (stuType == 2)
            menuGrad();
    }
}

//统计功能
void Interface::statistics() {
    menuStatistics();
    int choice;
    cin >> choice;
    switch (choice) {
        case 1:
            stAvg();
            break;
        case 2:
            stLevelCount();
            break;
        case 0:
            if (stuType == 1)
                menuBac();
            if (stuType == 2)
                menuGrad();
            break;
    }
}

//某门课每个班的平均成绩
void Interface::stAvg() {
    int choice = 100;
    do {
        if (stuType == 1) {
            int temp;
            cout << "请选择输入需要统计平均成绩的课程：" << endl;
            cout << "0-高数  1-英语  2-C语言" << endl;
            cin >> temp;
            string courseName = getCourseNameByTemp(temp, 1);
            vector<Bachelor>::iterator it;
            vector<Class>::iterator itCls = cls.begin();
            double avg, sum = 0;
            ll cnt = 0;  //计算该班级的人数

            cout << endl
                 << "班级名称" << setw(15) << courseName << "平均分" << endl;
            while (itCls != cls.end()) {  //遍历所有班级
                sum = 0;
                cnt = 0;
                it = bachelor.begin();
                while (it != bachelor.end()) {
                    if (it->getClassNumber() == itCls->getClassId()) {
                        sum += (it->getGrade().getScore()[temp]);
                        cnt++;
                    }
                    it++;
                }
                avg = sum / cnt;
                if ((itCls->getClassId()).substr(0, 4) ==
                    "2018")  //只输出本科生
                    cout << itCls->getClassName() << setw(10) << avg << endl;
                itCls++;
            }

        } else if (stuType == 2) {
            int temp;
            cout << "请输入需要统计平均成绩的课程名称：" << endl;
            cout << endl << "0-课程综合分数  1-论文分数" << endl;
            cin >> temp;
            string courseName = getCourseNameByTemp(temp, 2);

            vector<Graduator>::iterator it = graduator.begin();
            vector<Class>::iterator itCls = cls.begin();
            double avg = 0, sum = 0;
            ll cnt = 0;  //计算该班级的人数

            cout << "班级名称" << setw(15) << courseName << "平均分" << endl;
            while (itCls != cls.end()) {  //遍历所有班级
                sum = 0;
                cnt = 0;
                it = graduator.begin();
                while (it != graduator.end()) {
                    if (it->getClassNumber() == itCls->getClassId()) {
                        sum += (it->getGrade().getScore()[temp]);
                        cnt++;
                    }
                    it++;
                }
                avg = sum / cnt;
                if ((itCls->getClassId()).substr(0, 4) ==
                    "2015")  //只输出本科生
                    cout << itCls->getClassName() << setw(10) << avg << endl;
                itCls++;
            }
        }

        cout << endl
             << "继续查询平均成绩请输入1，返回上级菜单请输入2，返回首页菜单请输"
                "入0：";
        cin >> choice;
        if (choice == 1)
            continue;
        if (choice == 0 || choice == 2)
            break;

    } while (choice);
    if (choice == 0)
        run();
    else if (choice == 2) {
        statistics();
    }
}

//在某个班中统计并显示某门课程不同等级的学生人数
void Interface::stLevelCount() {
    int choice = 100;
    string clsNum;
    int tempCourse;
    do {
        if (stuType == 1) {
            cout << "请输入您要查询的本科生的班级编号：";
            cin >> clsNum;
            cout << "请选择您要查询的课程" << endl;
            cout << "0-高数  1-英语  2-C语言" << endl;
            cin >> tempCourse;
            ll cntA = 0, cntB = 0, cntC = 0, cntD = 0, cntE = 0;
            vector<Bachelor>::iterator it = bachelor.begin();

            while (it != bachelor.end()) {
                if (it->getClassNumber() == clsNum) {
                    double tempScore = it->getGrade().getScore()[tempCourse];
                    if (tempScore >= 90)
                        cntA++;
                    else if (tempScore >= 80)
                        cntB++;
                    else if (tempScore >= 70)
                        cntC++;
                    else if (tempScore >= 60)
                        cntD++;
                    else
                        cntE++;
                }
                it++;
            }

            vector<Class>::iterator itCls = cls.begin();
            while (itCls != cls.end()) {
                if (itCls->getClassId() == clsNum)
                    break;
                itCls++;
            }

            cout << "班级名称：" << itCls->getClassName() << endl;
            cout << "课程为：" << itCls->getClassName() << endl;
            cout << "统计完毕，不同等级的学生人数如下：" << endl;
            cout << "优" << setw(6) << "良" << setw(6) << "中" << setw(6)
                 << "及格" << setw(6) << "不及格" << endl
                 << endl;

            cout << cntA << setw(6) << cntB << setw(6) << cntC << setw(6)
                 << cntD << setw(6) << cntE << endl
                 << endl;

        } else if (stuType == 2) {
            cout << "请输入您要查询的研究生的班级编号：";
            cin >> clsNum;
            cout << "请选择您要查询的课程" << endl;
            cout << "0-课程综合成绩  1-论文成绩" << endl;
            cin >> tempCourse;
            ll cntA = 0, cntB = 0, cntC = 0, cntD = 0, cntE = 0;
            vector<Graduator>::iterator it = graduator.begin();

            while (it != graduator.end()) {
                if (it->getClassNumber() == clsNum) {
                    double tempScore = it->getGrade().getScore()[tempCourse];
                    if (tempScore >= 90)
                        cntA++;
                    else if (tempScore >= 80)
                        cntB++;
                    else if (tempScore >= 70)
                        cntC++;
                    else if (tempScore >= 60)
                        cntD++;
                    else
                        cntE++;
                }
                it++;
            }

            vector<Class>::iterator itCls = cls.begin();
            while (itCls != cls.end()) {
                if (itCls->getClassId() == clsNum)
                    break;
                itCls++;
            }

            cout << "班级名称：" << itCls->getClassName() << endl;
            cout << "课程为：" << itCls->getClassName() << endl;
            cout << "统计完毕，不同等级的学生人数如下：" << endl;
            cout << "优" << setw(6) << "良" << setw(6) << "中" << setw(6)
                 << "及格" << setw(6) << "不及格" << endl
                 << endl;

            cout << cntA << setw(6) << cntB << setw(6) << cntC << setw(6)
                 << cntD << setw(6) << cntE << endl
                 << endl;
        }

        cout << "继续查询请输入1，返回上级菜单请输入2，返回首页菜请输入0：";
        cin >> choice;
        if (choice == 1)
            continue;
        if (choice == 0 || choice == 2)
            break;

    } while (choice);
    if (choice == 0)
        run();
    else if (choice == 2) {
        statistics();
    }
}

void Interface::save() {
    ofstream saveBac("bachelor.txt");
    if (!saveBac) {
        cout << "不能打开文件" << endl;
        return;
    }
    ofstream saveGrad("graduator.txt");
    if (!saveGrad) {
        cout << "不能打开文件" << endl;
        return;
    }
    vector<Bachelor>::iterator itBac = bachelor.begin();
    vector<Graduator>::iterator itGrad = graduator.begin();
    ll countBac = bachelor.size();
    ll countGrad = graduator.size();
    ll i = 0;  //为了避免写入文件时最后一行重复写入

    while (itBac != bachelor.end()) {
        if (i == countBac)
            break;
        i++;
        saveBac << itBac->getId() << " " << itBac->getName() << " "
                << itBac->getSex() << " " << itBac->getMajor() << " "
                << itBac->getMajorNumber() << " " << itBac->getClassName()
                << " " << itBac->getClassNumber() << " "
                << itBac->getGrade().getScore()[0] << " "
                << itBac->getGrade().getScore()[1] << " "
                << itBac->getGrade().getScore()[2] << " "
                << itBac->getGrade().getFinalScore() << " "
                << itBac->getClassRank() << " " << itBac->getSchoolRank();
        if (i != countBac)  //避免写入文件最后一行多个回车
            saveBac << endl;

        itBac++;
    }
    i = 0;

    while (itGrad != graduator.end()) {
        if (i == countGrad)
            break;
        i++;
        saveGrad << itGrad->getId() << " " << itGrad->getName() << " "
                 << itGrad->getSex() << " " << itGrad->getMajor() << " "
                 << itGrad->getMajorNumber() << " " << itGrad->getClassName()
                 << " " << itGrad->getClassNumber() << " "
                 << itGrad->getGrade().getScore()[0] << " "
                 << itGrad->getGrade().getScore()[1] << " "
                 << itGrad->getDiction() << " " << itGrad->getTeacher() << " "
                 << itGrad->getGrade().getFinalScore() << " "
                 << itGrad->getClassRank() << " " << itGrad->getSchoolRank();
        if (i != countGrad)
            saveGrad << endl;
        itGrad++;
    }

    cout << endl << "文件保存完毕!" << endl;
    saveBac.close();
    saveGrad.close();
    exit(0);
}

Interface::~Interface() {
    save();
}