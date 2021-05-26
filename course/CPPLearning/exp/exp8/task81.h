
#ifndef ALGORITHM_COMPETITION_TRAINING_TASK81_H
#define ALGORITHM_COMPETITION_TRAINING_TASK81_H

#include <cstring>
#include <fstream>
#include <iostream>

using namespace std;

const int L = 100;

class Person {
private:
    char name[L], id[L];

public:
    Person(char na[] = "", char d[] = "") {  //默认带参构造
        strcpy(name, na);
        strcpy(id, d);
    }

    friend istream &operator>>(istream &in, Person &pe);

    friend ostream &operator<<(ostream &out, const Person &pe);
};

istream &operator>>(istream &in, Person &pe) {
    cout << "please input name and id" << endl;
    in >> pe.name >> pe.id;
    return in;
}

ostream &operator<<(ostream &out, const Person &pe) {
    out << "name: " << pe.name << ", id: " << pe.id << endl;
    return out;
}

void writeDataToFile(char *filename) {
    ofstream output(filename);
    const int N = 4;
    Person per[N];
    for (int i = 0; i < N; i++) {
        cin >> per[i];
    }
    output.write((char *) per, sizeof(Person) * N);  //写入N条记录内容
    output.close();
}

void ReadDataFromFile(char *filename) {
    ifstream input(filename);
    const int N = 4;
    Person per[N];
    int i = 0;
    while (!input.eof()) {
        input.read((char *) &per[i], sizeof(Person));
        if (input.gcount() == 0)
            break;
        cout << per[i];
        i++;
    }
    input.close();
}

#endif //ALGORITHM_COMPETITION_TRAINING_TASK81_H
