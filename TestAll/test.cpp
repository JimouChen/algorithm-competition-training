# include<iostream>
# include <vector>
#include <algorithm>

using namespace std;
typedef struct {
    int rank;
    int value;
} A;

bool cmp(A a1, A a2) {
    return a1.value > a2.value;
}

int main() {
    vector<A> aa;
    A q{1, 2}, w{3, 2}, e{5, 0};
    aa.push_back(q);
    aa.push_back(w);
    aa.push_back(e);
    sort(aa.begin(), aa.end(), cmp);
    int i = 1;

    vector<A>::iterator it = aa.begin();
    while (it != aa.end()) {
        it->rank = i;

        it++;
        if ((it - 1)->value == it->value) {
            it->rank = (it-1)->rank;
            it++;
            i++;
        }
        i++;
    }

    for (int i = 0; i < aa.size(); ++i) {
        cout << aa[i].rank << " ";
    }

    return 0;
}

/**
Program function:
input the text from the keyboard, store it in
character vector, count the number of lines, words and letters.#
 */