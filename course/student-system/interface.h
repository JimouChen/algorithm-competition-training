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
    Interface();  //���ļ���ȡ����
    ~Interface();

    void readFile();  //�����캯������
    void menu();      //���˵�չʾ
    void menuBac();   //����������˵�
    void menuGrad();  //�о����������˵�

    void menuSearch();       //��ѯѡ��˵�
    void displayAll();       //��ѯʱ��ʾ����ѧ����Ϣ
    void displayClassMsg();  //���༶��ʾ����ȫ��ѧ����Ϣ
    void displayOneMsg();    //����ѧ�Ż���������ѯѧ����Ϣ
    void displayBad();  //��ĳ���༶�в�ѯĳ�ſγɼ�������ѧ����Ϣ

    void run();         //����
    void save();        //����
    void InputBase();   //���ѧ�������������ݣ�һ������������
    void modifyBase();  //ͨ��ѧ�����޸���Ϣ
    void deleteStu();   //ͨ��ѧ��ɾ��һ��ѧ��
    void searchBase();  //ͨ��ѧ�Ų�ѯѧ��������Ϣ

    /*�ɼ�����ά��*/
    void InputScore();    //����ѧ���ɼ���һ������������
    void modifyGrade();   //�޸�ѧ���ɼ�
    void searchGrade();   //ͨ��ѧ�Ų�ѯѧ���ɼ�
    void calGradeRank();  //����ѧ���ɼ�������
    void statistics();    //ͳ�ƹ���
    void stAvg();         //ͳ����ʾĳ�ſ�ÿ�����ƽ���ɼ�
    void stLevelCount();  //ͳ����ʾĳ�ſβ�ͬ�ȼ�������

    /*���ڱȽϺ�����*/
    static bool cmpBacByScore(Bachelor b1, Bachelor b2);
    static bool cmpGradByScore(Graduator g1, Graduator g2);

    ll getNextStuId(string clsNum, int type);  //��ȡ��һ��ѧ��
    ll calClassRank(string clsNum, ll xh);     //����༶����
    ll calSchoolRank(ll xh);                   //����ȫУ����
    void saveRank();
};

#endif  // INTERFACE_H
