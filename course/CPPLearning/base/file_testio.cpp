# include <bits/stdc++.h>

using namespace std;

int main() {
//    ofstream output("o1ut.txt");
//    string words;
//    getline(cin, words);
//    output << words;
//    output.close();

    ifstream input("o1ut.txt");
    char temp;
    while (!input.eof()) {
        input >> temp;
        cout << temp;
        temp = ' ';
    }
    input.close();
    return 0;
}

