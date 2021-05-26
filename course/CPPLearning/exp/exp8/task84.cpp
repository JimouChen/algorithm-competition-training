#include <fstream>
#include <iostream>
using namespace std;

int main() {
    ifstream ifile("abc.txt");
    ofstream ofile("xyz.txt");
    char ch;
    while (ifile.get(ch))
        ofile.put(ch);
    ifile.close();
    ofile.close();
    return 0;
}