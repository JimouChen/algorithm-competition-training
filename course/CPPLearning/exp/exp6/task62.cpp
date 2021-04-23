# include <iostream>
# include <cstring>
using namespace std;

struct item {
    char *userName; //用户名
    long int telNum; //电话号码
};

class Tel_array { //数组类
private:
    item *table; //用户信息数组
    int max; //可能的最多元素个数
    int items; //实际存在的元素个数
public:
    Tel_array();
    Tel_array(int nm);
    ~Tel_array();
    long &operator[](char *na);
    void printAll();
};

Tel_array::Tel_array() {
    max = 0;
    table = new item[max];
    items = 0;
}

Tel_array::Tel_array(int nm) {
    max = nm;
    table = new item[max];
    items = 0;
}

Tel_array::~Tel_array() {
    delete[] table;
}

long &Tel_array::operator[](char *na) {
    for (int i = 0; i < items; ++i)
        if (!strcmp(na, table[i].userName))
            return table[i].telNum;

    //没有就新建一条记录
    table[items].telNum = 0;
    table[items].userName = new char[strlen(na) + 1];
    strcpy(table[items].userName, na);
    return table[items++].telNum;
}

void Tel_array::printAll() {
    for (int i = 0; i < items; ++i)
        cout << table[i].userName << ": " << table[i].telNum << endl;
    cout << endl;
}

int main() {
    Tel_array telArray(10);
    telArray["Tony"] = 123456789;
    telArray["Peter"] = 123235359;
    telArray["Lucy"] = 1234237869;
    telArray.printAll();

    cout << "find Tony:" << telArray["Tony"] << endl;
    cout << "find Lucy:" << telArray["Lucy"] << endl;
    cout << "find Alex:" << telArray["Alex"] << endl;
    telArray.printAll();
    return 0;
}