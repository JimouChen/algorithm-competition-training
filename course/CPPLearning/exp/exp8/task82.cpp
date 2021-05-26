#include <fstream>
#include <iostream>
#include <string>

using namespace std;

void creatFile(char *filename) {
    ifstream input(filename);
    ofstream outLetter("letter.txt"), outOtherChar("otherChar.txt");
    while (!input.eof()) {
        char temp;
        input >> temp;
        if ((temp <= 'z' && temp >= 'a') || (temp >= 'A' && temp <= 'Z')) {
            outLetter << temp;
        } else
            outOtherChar << temp;
        temp = ' ';
    }

    input.close();
    outOtherChar.close();
    outLetter.close();
}

void readOut(char *filename) {
    ifstream show(filename);
    while (!show.eof()) {
        char temp;
        show >> temp;
        cout << temp;
        temp = ' ';
    }
    show.close();
    cout << endl << endl;
}

int main() {
    creatFile("task82.cpp");
    readOut("letter.txt");
    readOut("otherChar.txt");
    return 0;
}