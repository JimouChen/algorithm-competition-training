#ifndef TOOL_H
#define TOOL_H

#include "interface.h"
#include "person.h"

//�ַ����и�
vector<string> splitStr(string str) {
    vector<string> res;
    string temp;
    stringstream words(str);
    //һ�������temp,���Ҵ���res��
    while (words >> temp) {
        res.push_back(temp);
    }
    return res;
}

#endif