#ifndef TOOL_H
#define TOOL_H

#include "interface.h"
#include "person.h"

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