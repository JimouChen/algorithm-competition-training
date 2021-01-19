#include<iostream>

using namespace std;

class CPU {
public:
    enum rank {
        P1 = 1, P2, P3, P4, P5, P6, P7
    };
    int frequency;
    float voltage;

    void run();

    void stop();

    CPU();

    virtual ~CPU();
};

void CPU::run() {
    rank a = P5;
    cout<<a<<endl;
    cout << "working now\n";
}

void CPU::stop() {
    cout << "stop !\n";
}

CPU::CPU() {
    cout << "construct\n";
}

CPU::~CPU() {
    cout << "destruct\n";
}

int main() {
    CPU cpu;
    cpu.run();
    cpu.stop();
    return 0;
}