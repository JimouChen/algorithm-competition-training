#ifndef MENU_H
#define MENU_H

#include "interface.h"

void Interface::menu() {
    system("color F1");
    cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
    cout << "        ��ӭ����ѧ���ɼ��������ϵͳ!"
            "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
    cout << "=================================================================="
            "===="
            "=========\r"
         << endl;
    cout << "��������Ҫ�������Ա����" << endl;
    cout << "1-������   2-�о���   0-�˳�����ϵͳ" << endl;
}

void Interface::menuBac() {
    int chioce;

    cout << "========================�������ɼ�����˵�========================"
         << endl;
    cout << "=*=*=*=*=*==*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*="
         << endl
         << endl
         << endl;
    cout << "    ��1������/������ӱ�����������Ϣ" << endl;
    cout << "    ��2����ѯ��������Ϣ" << endl;
    cout << "    ��3������ѧ���޸ı�������Ϣ" << endl;
    cout << "    ��4������ѧ��ɾ����������Ϣ" << endl;
    cout << "    ��5������/�������뱾�����ɼ�" << endl;
    cout << "    ��6��ͳ�ƹ���" << endl;
    cout << "    ��0���������˵�" << endl;
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
    cout << "    ��1������/��������о���������Ϣ" << endl;
    cout << "    ��2����ѯ�о�����Ϣ" << endl;
    cout << "    ��3������ѧ���޸��о�����Ϣ" << endl;
    cout << "    ��4������ѧ��ɾ���о�����Ϣ" << endl;
    cout << "    ��5������/���������о����ɼ�" << endl;
    cout << "    ��6��ͳ�ƹ���" << endl;
    cout << "    ��0���������˵�" << endl;
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
    cout << "    ��1����ʾ����ѧ����Ϣ" << endl;
    cout << "    ��2�����༶��ʾ����ȫ��ѧ����Ϣ" << endl;
    cout << "    ��3������ѧ�Ż���������ѯѧ����Ϣ" << endl;
    cout << "    ��4����ĳ���༶�в�ѯĳ�ſγɼ�������ѧ����Ϣ" << endl;
    cout << "    ��0���ص���һҳ" << endl << endl << endl;
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
    cout << "   ѧ��" << "\t\t  " << "����" << "  " << "�Ա�" << " \t\t   "
         << "רҵ" << "     " << "רҵ���" << "  \t\t  " << "�༶" << "     \t\t"
         << "�༶���" << "   " << "�����ɼ�" << " " << "Ӣ��ɼ�"
         << " " << "C���Գɼ�" << " " << "�ܳɼ�" << "  "
         << "�༶����" << "  " << "ѧУ����" << endl
         << endl;
}

void menuGradTitle() {
    cout << "   ѧ��" << "\t\t  " << "����" << "  " << "�Ա�" << " \t\t   "
         << "רҵ" << "     " << "רҵ���" << " \t\t  " << "�༶" << "   \t\t"
         << "�༶���" << "   " << "�ۺϳɼ�" << " " << "���ĳɼ�"
         << " " << "�о�����" << "    " << "��ʦ" << "  " << "�ܳɼ�"
         << "  " << "�༶����" << "  " << "ѧУ����" << endl
         << endl;
}

//�޸���רҵ֮�󣬴�רҵ�ļ������ҵ���Ӧ��רҵ��ţ��Զ��޸�רҵ���
//�༶�Ͱ༶���Ҳ�����
void menuModifyBac() {
    cout << "��������Ҫ�޸ĵ�ѡ�(ѧ�Ų����޸�)" << endl;
    cout << "1-����" << setw(10) << "2-�Ա�" << setw(10) << "3-רҵ" << setw(10)
         << "4-�༶" << endl;
}

void menuModityGrad() {
    cout << "��������Ҫ�޸ĵ�ѡ�(ѧ�Ų����޸�)" << endl;
    cout << "1-����" << setw(10) << "2-�Ա�" << setw(10) << "3-רҵ" << setw(10)
         << "4-�༶" << setw(10) << "5-רҵ����" << setw(10) << "6-��ʦ" << endl;
}

void menuStatistics() {
    cout << "========================ͳ��ѧ����Ϣ========================"
         << endl;
    cout << "  1-ͳ�Ʋ���ʾĳ�ſ�ÿ�����ƽ���ɼ�" << endl;
    cout << "  2-��ĳ������ͳ�Ʋ���ʾĳ�ſγ̲�ͬ�ȼ���ѧ������" << endl;
    cout << "  0-�ص���һҳ�˵�" << endl;
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
    cout << "  ����˵��" << endl;
    cout << "��Ӱ༶����רҵʱ����ע���ϸ���classes."
            "txt�ļ��а༶��רҵ�ĸ�ʽ��������"
         << endl;
    cout << "���������һ��ѧ����Ϣʱ����ӵİ༶��רҵ���������еİ༶��רҵ"
         << endl;
    cout << "��������ʽ����������" << endl << endl;
    cout << "      רҵ����      �༶����" << endl;
    cout << "    ������� ---  2018���������1��" << endl;
    cout << "    ������� ---  2018���������2��" << endl;
    cout << "    �������ѧ�뼼�� --- 2018���������ѧ�뼼��1��" << endl;
    cout << "    �������ѧ�뼼�� --- 2018���������ѧ�뼼��2��" << endl;
    cout << "    ���繤�� --- 2018�����繤��1��" << endl;
    cout << "    ���繤�� --- 2018�����繤��2��" << endl;
    cout << "    ������ --- 2018��������1��" << endl;
    cout << "    ������ --- 2018��������2��" << endl;
    cout << endl << "�о�����ʽ����������" << endl << endl;
    cout << "      רҵ����      �༶����" << endl;
    cout << "    �������ѧ�뼼�� --- 2015���������ѧ�뼼��1��" << endl;
    cout << "    �������ѧ�뼼�� --- 2015���������ѧ�뼼��2��" << endl;
    cout << "    ������� --- 2015���������1��" << endl;
    cout << "    ������� --- 2015���������2��" << endl;
    cout << endl;
}

#endif