#include "interface.h"
#include "menu_page.h"
#include "person.cpp"

Interface::Interface() {
    readFile();
}

//���ļ��ж�����Ϣ�ȱ��浽�����У��ټ���ɼ�������
void Interface::readFile() {
    ifstream bacIn("bachelor.txt");
    if (!bacIn) {
        cout << "�޷����ļ�bachelor.txt" << endl;
        return;
    }

    ifstream gradIn("graduator.txt");
    if (!gradIn) {
        cout << "�޷���graduator.txt�ļ�" << endl;
        return;
    }

    ifstream classIn("classes.txt");
    if (!classIn) {
        cout << "�޷���classes.txt�ļ�" << endl;
        return;
    }

    ifstream majorIn("major.txt");
    if (!majorIn) {
        cout << "�޷���major.txt�ļ�" << endl;
        return;
    }
    /*���������ݴ浽����*/
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

    /*�о������ݴ浽����*/
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

    /*�༶�Ͱ༶������ݴ浽����*/
    string majorNum;
    string majorNa;
    string className;
    string classId;

    while (!classIn.eof()) {
        classIn >> majorNum >> majorNa >> className >> classId;
        Class clsTemp(majorNum, majorNa, className, classId);
        cls.push_back(clsTemp);
    }

    /*רҵ��רҵ������ݴ浽����*/
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

//�������˵�
void Interface::run() {
    int chioce;
    menu();
    do {
        cin >> chioce;
        if (chioce == 1) {
            stuType = 1;  //��ѡ��ʱȷ����Ա����
            menuBac();
        } else if (chioce == 2) {
            stuType = 2;
            menuGrad();
        } else if (chioce != 0) {
            cout << "������Ч������������" << endl;
        }

    } while (chioce);
    save();  //�����ļ����˳�
}

//�ҵ��ð༶�е����ѧ�ţ������Զ�������һ��ѧ��
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

//���������ܳɼ�����ߵ���
bool Interface::cmpBacByScore(Bachelor b1, Bachelor b2) {
    return b1.getGrade().getFinalScore() > b2.getGrade().getFinalScore();
}

// //�о������ܳɼ�����ߵ���
bool Interface::cmpGradByScore(Graduator g1, Graduator g2) {
    return g1.getGrade().getFinalScore() > g2.getGrade().getFinalScore();
}

//����༶����
ll Interface::calClassRank(string clsNum, ll xh) {
    ll res;
    ll rank = 1;
    int flag = 0;  //�ҵ�ѧ�ž���1
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

//����ȫУ����
ll Interface::calSchoolRank(ll xh) {
    ll res = 0;
    ll rank = 1;
    int flag = 0;  //�ҵ�ѧ�ž���1��������0
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
    if (flag == 0)  //�Ҳ���ѧ�������
        return rank + 1;
    return res;
}

//�������ݣ��Ѵ�����һ��������������ӵ�����
void Interface::InputBase() {
    int choice = 100;

    do {
        inputNotes();
        ll Id;
        string na;
        string s;
        string mj;
        string mjNumber;  //�Զ����
        string clsNa;
        string clsNum;  //�Զ����
        ll clsRank;     //�ɼ���õ�
        ll schRank;
        cout << "������ѧ����������";
        cin >> na;
        cout << "������ѧ�����Ա�";
        cin >> s;
        cout << "������ѧ����רҵ���ƣ�";
        cin >> mj;
        //ȥcls������
        vector<Class>::iterator itCls = cls.begin();
        while (itCls != cls.end()) {
            if (itCls->getMajor() == mj) {
                mjNumber = itCls->getMajorNumber();
                break;
            }
            itCls++;
        }

        cout << "������ѧ���İ༶���ƣ�";
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
            cout << "������ѧ���ĵ�ʦ��" << endl;
            cin >> diction;
            cout << "������ѧ�����о�����" << endl;
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
        cout << "============ѧ����Ϣ��ӳɹ�============" << endl;
        cout << endl
             << "�ص���ҳ�˵�������0" << endl
             << "���������Ϣ������1" << endl;
        cin >> choice;
        if (choice == 1)
            continue;
        // if (choice == 0)
        //     break;

    } while (choice);
    run();
}

void Interface::searchBase() {
    menuSearch();  //�����Ӳ˵���ѯ
}

//��ʾǰ����������ô��ȥ
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

//չʾѧ��������Ϣ
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
                         << it->getClassRank() << setw(10) << it->getSchoolRank()
                         << endl;
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
                         << it->getSex() << setw(20) << it->getMajor() << setw(10)
                         << it->getMajorNumber() << setw(30)
                         << it->getClassName() << setw(15)
                         << it->getClassNumber() << setw(10)
                         << it->getGrade().getScore()[0] << setw(10)
                         << it->getGrade().getScore()[1] << setw(10)
                         << it->getDiction() << setw(10) << it->getTeacher()
                         << setw(5) << it->getGrade().getFinalScore() << setw(10)
                         << it->getClassRank() << setw(10) << it->getSchoolRank()
                         << endl;
                }

                it++;
            }
        }
        cout << endl
             << endl
             << "�������˵�������0��������һҳ�˵�������1,���²�ѯ������2:";
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

//���ݰ༶��ʾ��������ѧ����Ϣ
void Interface::displayClassMsg() {
    int choice = 100;

    do {
        string clsNum;
        cout << "��������Ҫ��ѯѧ����Ϣ�İ༶��ţ�";
        cin >> clsNum;
        cout << "������ѯ�İ༶ѧ����Ϣ���£�" << endl;
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
                         << it->getClassRank() << setw(10) << it->getSchoolRank()
                         << endl;
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
                         << it->getSex() << setw(20) << it->getMajor() << setw(10)
                         << it->getMajorNumber() << setw(30)
                         << it->getClassName() << setw(15)
                         << it->getClassNumber() << setw(10)
                         << it->getGrade().getScore()[0] << setw(10)
                         << it->getGrade().getScore()[1] << setw(10)
                         << it->getDiction() << setw(10) << it->getTeacher()
                         << setw(5) << it->getGrade().getFinalScore() << setw(10)
                         << it->getClassRank() << setw(10) << it->getSchoolRank()
                         << endl;
                }
                it++;
            }
        }

        cout << "������ѯ������1��������һ���˵�������2���������˵�������0"
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

//����ѧ�Ż���������ѯѧ����Ϣ
void Interface::displayOneMsg() {
    int choice = 100;
    do {
        cout << "��������Ҫ��ѯ��Ϣ��ѧ�Ż�������" << endl;
        cout << "����ѧ���밴1�����������밴2: ";
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
                         << it->getClassRank() << setw(10) << it->getSchoolRank()
                         << endl;
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
                         << it->getSex() << setw(20) << it->getMajor() << setw(10)
                         << it->getMajorNumber() << setw(30)
                         << it->getClassName() << setw(15)
                         << it->getClassNumber() << setw(10)
                         << it->getGrade().getScore()[0] << setw(10)
                         << it->getGrade().getScore()[1] << setw(10)
                         << it->getDiction() << setw(10) << it->getTeacher()
                         << setw(5) << it->getGrade().getFinalScore() << setw(10)
                         << it->getClassRank() << setw(10) << it->getSchoolRank()
                         << endl;
                }
                it++;
            }
        }
        cout << endl
             << "������ѯ������1��������һ���˵�������2���������˵�������0"
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

//��ĳ���༶�в�ѯĳ�ſγɼ�������ѧ����Ϣ
void Interface::displayBad() {
    int choice = 100;
    string clsNum;

    do {
        int flag = 0;  //����н������1
        if (stuType == 1) {
            cout << "��������Ҫ��ѯ�İ༶��ţ�";
            cin >> clsNum;
            vector<Bachelor>::iterator it = bachelor.begin();
            int temp;
            vector<string> courseName{"����", "Ӣ��", "C����"};
            cout << "�������ѯ��һ�ſΣ�0-����  1-Ӣ��  2-C���ԣ�";
            cin >> temp;
            cout << "�γ�Ϊ" << courseName[temp] << "������ı�������Ϣ���£�"
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
                         << it->getClassRank() << setw(10) << it->getSchoolRank()
                         << endl;
                }
                it++;
            }

        } else if (stuType == 2) {
            cout << "��������Ҫ��ѯ�İ༶��ţ�";
            cin >> clsNum;
            vector<Graduator>::iterator it = graduator.begin();
            int temp;
            vector<string> courseName{"�ۺϳɼ�", "���ĳɼ�"};

            cout << "�������ѯ��һ�ſΣ�0-�ۺϳɼ�  1-���ĳɼ���";
            cin >> temp;
            cout << "�γ�Ϊ" << it->getGrade().getScore()[temp]
                 << "��������о�����Ϣ���£�" << endl;
            saveRank();
            menuGradTitle();
            while (it != graduator.end()) {
                if (it->getClassNumber() == clsNum &&
                    it->getGrade().getScore()[temp] < 60 && it->getId() != -1) {
                    flag = 1;
                    cout << it->getId() << setw(10) << it->getName() << setw(5)
                         << it->getSex() << setw(20) << it->getMajor() << setw(10)
                         << it->getMajorNumber() << setw(30)
                         << it->getClassName() << setw(15)
                         << it->getClassNumber() << setw(10)
                         << it->getGrade().getScore()[0] << setw(10)
                         << it->getGrade().getScore()[1] << setw(10)
                         << it->getDiction() << setw(10) << it->getTeacher()
                         << setw(5) << it->getGrade().getFinalScore() << setw(10)
                         << it->getClassRank() << setw(10) << it->getSchoolRank()
                         << endl;
                }
                it++;
            }
        }
        if (flag == 0)
            cout << "�޼���������ð�����ſ�û�в������ѧ��" << endl;
        cout << endl
             << "������ѯ������1��������һ���˵�������2���������˵�������0"
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

//����ѧ���޸�
void Interface::modifyBase() {
    ll xh;
    int choice = 100;
    string changing;
    do {
        if (stuType == 1) {
            cout << "��������Ҫ�޸ĵı�����ѧ�ţ�";
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
                    cout << "�������޸ĺ��������";
                    cin >> changing;
                    it->getName() = changing;
                    break;
                case 2:
                    cout << "�������޸ĺ���Ա�";
                    cin >> changing;
                    it->getSex() = changing;
                    break;
                case 3: {
                    cout << "�������޸ĺ��רҵ��";
                    cin >> changing;
                    it->getMajor() = changing;
                    //����רҵ�޸�רҵ��ţ�ͬʱ�༶ҲҪһ���޸�
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
                    cout << "�������޸ĺ�İ༶��";
                    cin >> changing;
                    it->getClassName() = changing;
                    //���ݰ༶�޸İ༶�༶���,רҵҲҪ���Ÿ�
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
            cout << "��������Ҫ�޸ĵ��о���ѧ�ţ�";
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
                    cout << "�������޸ĺ��������";
                    cin >> changing;
                    it->getName() = changing;
                    break;
                case 2:
                    cout << "�������޸ĺ���Ա�";
                    cin >> changing;
                    it->getSex() = changing;
                    break;
                case 3: {
                    cout << "�������޸ĺ��רҵ��";
                    cin >> changing;
                    it->getMajor() = changing;
                    //����רҵ�޸�רҵ��ţ�ͬʱ�༶ҲҪһ���޸�
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
                    cout << "�������޸ĺ�İ༶��";
                    cin >> changing;
                    it->getClassName() = changing;
                    //���ݰ༶�޸İ༶�༶���
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
                    cout << "�������޸ĺ��רҵ����";
                    cin >> changing;
                    it->getDiction() = changing;
                    break;
                case 6:
                    cout << "�������޸ĺ�ĵ�ʦ���ƣ�";
                    cin >> changing;
                    it->getTeacher() = changing;
                    break;
            }
        }
        cout << endl << "�޸����!" << endl;
        cout << "���Ҫ�����޸�������1��������һ���˵�������2���������˵�������"
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

//ɾ����Ϣ����ѧ����Ϊ-1
void Interface::deleteStu() {
    int choice = 100;
    ll xh;
    cout << "��������Ҫɾ����ѧ����Ϣ��ѧ�ţ�";
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
            saveRank();  //ɾ����Ҫ��������
        } else if (stuType == 2) {
            vector<Graduator>::iterator it = graduator.begin();
            while (it != graduator.end()) {
                if (it->getId() == xh) {
                    it->getId() = -1;
                    break;
                }
                it++;
            }
            saveRank();  //ɾ����Ҫ��������
        }
        cout << endl << "ɾ��ѧ���ɹ�" << endl;
        cout << "����ɾ��������1��������һ���˵�������2��������ҳ�˵�������0��";
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

//����ɼ�
void Interface::InputScore() {
    int choice = 100;
    do {
        if (stuType == 1) {
            ll xh;
            cout << "��������Ҫ��ӳɼ��ı�����ѧ�ţ�";
            cin >> xh;
            vector<Bachelor>::iterator it = bachelor.begin();

            while (it != bachelor.end()) {
                if (it->getId() == xh) {
                    double a, b, c;
                    cout << "���������������Ӣ�C���Եķ�����";
                    cin >> a >> b >> c;
                    vector<double> v{a, b, c};
                    it->getGrade().getScore() = v;  //��ֵ
                    break;
                }
                it++;
            }
        } else if (stuType == 2) {
            ll xh;
            cout << "��������Ҫ��ӳɼ����о���ѧ�ţ�";
            cin >> xh;
            vector<Graduator>::iterator it = graduator.begin();

            while (it != graduator.end()) {
                if (it->getId() == xh) {
                    double a, b;
                    cout << "�����������ۺϳɼ������ĳɼ��ķ�����";
                    cin >> a >> b;
                    vector<double> v{a, b};
                    it->getGrade().getScore() = v;  //��ֵ
                    break;
                }
                it++;
            }
        }
        cout << "�ɼ�������" << endl;
        cout << "������ӳɼ�������1��������һ���˵�������2��������ҳ�˵�������"
                "0��";
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

//ͳ�ƹ���
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

//ĳ�ſ�ÿ�����ƽ���ɼ�
void Interface::stAvg() {
    int choice = 100;
    do {
        if (stuType == 1) {
            int temp;
            cout << "��ѡ��������Ҫͳ��ƽ���ɼ��Ŀγ̣�" << endl;
            cout << "0-����  1-Ӣ��  2-C����" << endl;
            cin >> temp;
            string courseName = getCourseNameByTemp(temp, 1);
            vector<Bachelor>::iterator it;
            vector<Class>::iterator itCls = cls.begin();
            double avg, sum = 0;
            ll cnt = 0;  //����ð༶������

            cout << endl
                 << "�༶����" << setw(15) << courseName << "ƽ����" << endl;
            while (itCls != cls.end()) {  //�������а༶
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
                    "2018")  //ֻ���������
                    cout << itCls->getClassName() << setw(10) << avg << endl;
                itCls++;
            }

        } else if (stuType == 2) {
            int temp;
            cout << "��������Ҫͳ��ƽ���ɼ��Ŀγ����ƣ�" << endl;
            cout << endl << "0-�γ��ۺϷ���  1-���ķ���" << endl;
            cin >> temp;
            string courseName = getCourseNameByTemp(temp, 2);

            vector<Graduator>::iterator it = graduator.begin();
            vector<Class>::iterator itCls = cls.begin();
            double avg = 0, sum = 0;
            ll cnt = 0;  //����ð༶������

            cout << "�༶����" << setw(15) << courseName << "ƽ����" << endl;
            while (itCls != cls.end()) {  //�������а༶
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
                    "2015")  //ֻ���������
                    cout << itCls->getClassName() << setw(10) << avg << endl;
                itCls++;
            }
        }

        cout << endl
             << "������ѯƽ���ɼ�������1�������ϼ��˵�������2��������ҳ�˵�����"
                "��0��";
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

//��ĳ������ͳ�Ʋ���ʾĳ�ſγ̲�ͬ�ȼ���ѧ������
void Interface::stLevelCount() {
    int choice = 100;
    string clsNum;
    int tempCourse;
    do {
        if (stuType == 1) {
            cout << "��������Ҫ��ѯ�ı������İ༶��ţ�";
            cin >> clsNum;
            cout << "��ѡ����Ҫ��ѯ�Ŀγ�" << endl;
            cout << "0-����  1-Ӣ��  2-C����" << endl;
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

            cout << "�༶���ƣ�" << itCls->getClassName() << endl;
            cout << "�γ�Ϊ��" << itCls->getClassName() << endl;
            cout << "ͳ����ϣ���ͬ�ȼ���ѧ���������£�" << endl;
            cout << "��" << setw(6) << "��" << setw(6) << "��" << setw(6)
                 << "����" << setw(6) << "������" << endl
                 << endl;

            cout << cntA << setw(6) << cntB << setw(6) << cntC << setw(6)
                 << cntD << setw(6) << cntE << endl
                 << endl;

        } else if (stuType == 2) {
            cout << "��������Ҫ��ѯ���о����İ༶��ţ�";
            cin >> clsNum;
            cout << "��ѡ����Ҫ��ѯ�Ŀγ�" << endl;
            cout << "0-�γ��ۺϳɼ�  1-���ĳɼ�" << endl;
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

            cout << "�༶���ƣ�" << itCls->getClassName() << endl;
            cout << "�γ�Ϊ��" << itCls->getClassName() << endl;
            cout << "ͳ����ϣ���ͬ�ȼ���ѧ���������£�" << endl;
            cout << "��" << setw(6) << "��" << setw(6) << "��" << setw(6)
                 << "����" << setw(6) << "������" << endl
                 << endl;

            cout << cntA << setw(6) << cntB << setw(6) << cntC << setw(6)
                 << cntD << setw(6) << cntE << endl
                 << endl;
        }

        cout << "������ѯ������1�������ϼ��˵�������2��������ҳ��������0��";
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
        cout << "���ܴ��ļ�" << endl;
        return;
    }
    ofstream saveGrad("graduator.txt");
    if (!saveGrad) {
        cout << "���ܴ��ļ�" << endl;
        return;
    }
    vector<Bachelor>::iterator itBac = bachelor.begin();
    vector<Graduator>::iterator itGrad = graduator.begin();
    ll countBac = bachelor.size();
    ll countGrad = graduator.size();
    ll i = 0;  //Ϊ�˱���д���ļ�ʱ���һ���ظ�д��

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
        if (i != countBac)  //����д���ļ����һ�ж���س�
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

    cout << endl << "�ļ��������!" << endl;
    saveBac.close();
    saveGrad.close();
    exit(0);
}

Interface::~Interface() {
    save();
}