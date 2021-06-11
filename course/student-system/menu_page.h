#ifndef MENU_H
#define MENU_H

#include "interface.h"

void Interface::menu() {
    system("color F1");
    cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
    cout << "\t\t\t\t��ӭ����ѧ���ɼ��������ϵͳ!"
            "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
    cout << "=================================================================="
            "===="
            "=========\r"
         << endl;
    cout << "��������Ҫ�������Ա����" << endl;
    cout << "1-������\t 2-�о���\t 0-�˳�����ϵͳ" << endl;
}

void Interface::menuBac() {
    int chioce;

    cout << "========================�������ɼ�����˵�========================"
         << endl;
    cout << "=*=*=*=*=*==*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*="
         << endl
         << endl
         << endl;
    cout << "\t\t��1������/������ӱ�����������Ϣ" << endl;
    cout << "\t\t��2����ѯ��������Ϣ" << endl;
    cout << "\t\t��3������ѧ���޸ı�������Ϣ" << endl;
    cout << "\t\t��4������ѧ��ɾ����������Ϣ" << endl;
    cout << "\t\t��5������/�������뱾�����ɼ�" << endl;
    cout << "\t\t��6��ͳ�ƹ���" << endl;
    cout << "\t\t��0���������˵�" << endl;
    cout << "=*=*=*=*=*==*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*="
         << endl
         << endl;
    cout << "��������Ҫ���еĲ���:";
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
    cout << "========================�о����ɼ�����˵�========================"
         << endl;
    cout << "=*=*=*=*=*==*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*="
         << endl
         << endl
         << endl;
    cout << "\t\t��1������/��������о���������Ϣ" << endl;
    cout << "\t\t��2����ѯ�о�����Ϣ" << endl;
    cout << "\t\t��3������ѧ���޸��о�����Ϣ" << endl;
    cout << "\t\t��4������ѧ��ɾ���о�����Ϣ" << endl;
    cout << "\t\t��5������/���������о����ɼ�" << endl;
    cout << "\t\t��6��ͳ�ƹ���" << endl;
    cout << "\t\t��0���������˵�" << endl;
    cout << "=*=*=*=*=*==*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*="
         << endl
         << endl;
    cout << "��������Ҫ���еĲ���:";
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
    cout << "\t\t��1����ʾ����ѧ����Ϣ" << endl;
    cout << "\t\t��2�����༶��ʾ����ȫ��ѧ����Ϣ" << endl;
    cout << "\t\t��3������ѧ�Ż���������ѯѧ����Ϣ" << endl;
    cout << "\t\t��4����ĳ���༶�в�ѯĳ�ſγɼ�������ѧ����Ϣ" << endl;
    cout << "\t\t��0���ص���һҳ" << endl << endl << endl;
    cout << "����������ѡ��";
}
void Interface::menuSearch() {
    int choice;
    if (stuType == 1) {
        cout << "========================��������Ϣ��ѯ�˵�===================="
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
        cout << "========================�о�����Ϣ��ѯ�˵�===================="
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
    cout << "========================��ʾ����ѧ����Ϣ========================"
         << endl;
    cout << "=*=*=*=*=*==*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*="
         << endl
         << endl;
}

void menuBacTitle() {
    cout << "ѧ��" << setw(5) << "����" << setw(5) << "�Ա�" << setw(5)
         << "רҵ" << setw(5) << "רҵ���" << setw(5) << "�༶" << setw(5)
         << "�༶���" << setw(5) << "�����ɼ�" << setw(5) << "Ӣ��ɼ�"
         << setw(5) << "C���Գɼ�" << setw(5) << "�ܳɼ�" << setw(5)
         << "�༶����" << setw(5) << "ѧУ����" << endl
         << endl;
}

void menuGradTitle() {
    cout << "ѧ��" << setw(5) << "����" << setw(5) << "�Ա�" << setw(5)
         << "רҵ" << setw(5) << "רҵ���" << setw(5) << "�༶" << setw(5)
         << "�༶���" << setw(5) << "�ۺϳɼ�" << setw(5) << "���ĳɼ�"
         << setw(5) << "�о�����" << setw(5) << "��ʦ" << setw(5) << "�ܳɼ�"
         << setw(5) << "�༶����" << setw(5) << "ѧУ����" << endl
         << endl;
}

//�޸���רҵ֮�󣬴�רҵ�ļ������ҵ���Ӧ��רҵ��ţ��Զ��޸�רҵ���
//�༶�Ͱ༶���Ҳ�����
void menuModifyBac() {
    cout << "��������Ҫ�޸ĵ�ѡ�(ѧ�Ų����޸�)" << endl;
    cout << "1-����" << setw(5) << "2-�Ա�" << setw(5) << "3-רҵ" << setw(5)
         << "4-�༶" << endl;
}

void menuModityGrad() {
    cout << "��������Ҫ�޸ĵ�ѡ�(ѧ�Ų����޸�)" << endl;
    cout << "1-����" << setw(5) << "2-�Ա�" << setw(5) << "3-רҵ" << setw(5)
         << "4-�༶" << setw(5) << "5-רҵ����" << setw(5) << "6-��ʦ" << endl;
}

void menuStatistics() {
    cout << "========================ͳ��ѧ����Ϣ========================"
         << endl;
    cout << "\t1-ͳ�Ʋ���ʾĳ�ſ�ÿ�����ƽ���ɼ�" << endl;
    cout << "\t2-��ĳ������ͳ�Ʋ���ʾĳ�ſγ̲�ͬ�ȼ���ѧ������" << endl;
    cout << "\t0-�ص���һҳ�˵�" << endl;
    cout << "=*=*=*=*=*==*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*="
         << endl
         << endl;
}

string getCourseNameByTemp(int temp, int type) {
    if (type == 1) {
        if (temp == 0)
            return "����";
        if (temp == 1)
            return "Ӣ��";
        if (temp == 2)
            return "C����";
    } else if (type == 2) {
        if (temp == 0)
            return "�ۺϿγ�";
        if (temp == 1)
            return "����";
    }
}

void inputNotes() {
    cout << "\t����˵��" << endl;
    cout << "��Ӱ༶����רҵʱ����ע���ϸ���classes."
            "txt�ļ��а༶��רҵ�ĸ�ʽ��������"
         << endl;
    cout << "���������һ��ѧ����Ϣʱ����ӵİ༶��רҵ���������еİ༶��רҵ"
         << endl;
    cout << "��������ʽ����������" << endl << endl;
    cout << "\t\t  רҵ����\t\t\t�༶����" << endl;
    cout << "\t\t������� ---  2018���������1��" << endl;
    cout << "\t\t������� ---  2018���������2��" << endl;
    cout << "\t\t�������ѧ�뼼�� --- 2018���������ѧ�뼼��1��" << endl;
    cout << "\t\t�������ѧ�뼼�� --- 2018���������ѧ�뼼��2��" << endl;
    cout << "\t\t���繤�� --- 2018�����繤��1��" << endl;
    cout << "\t\t���繤�� --- 2018�����繤��2��" << endl;
    cout << "\t\t������ --- 2018��������1��" << endl;
    cout << "\t\t������ --- 2018��������2��" << endl;
    cout << endl << "�о�����ʽ����������" << endl << endl;
    cout << "\t\t  רҵ����\t\t\t�༶����" << endl;
    cout << "\t\t�������ѧ�뼼�� --- 2015���������ѧ�뼼��1��" << endl;
    cout << "\t\t�������ѧ�뼼�� --- 2015���������ѧ�뼼��2��" << endl;
    cout << endl;
}

#endif