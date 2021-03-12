#include <iostream>
#include <cmath>
using namespace std;

class Data {
//    friend void show(Data);
    friend void show(Data data) {
        cout << data.y << endl;
    }

private:
    int y;
public:
    Data(int year) : y(year) {}

    ~Data() {}
};


int main() {
    Data data(2021);
//    show(data);
    cout<<pow(2,3);
    return 0;
}