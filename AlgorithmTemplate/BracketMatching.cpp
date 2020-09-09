#include <bits/stdc++.h>

using namespace std;

bool bracketCheck(char str[], int length) {
    stack<char> s;
    for (int i = 0; i < length; ++i) {
        if (str[i] == '(' || str[i] == '[' || str[i] == '{')
            //左括号入栈
            s.push(str[i]);
        else {
            // 扫描到右括号，且栈空
            if (s.empty())return false;
            //栈不空
            char topElem = s.top();
            s.pop();
            cout<<topElem<<endl;
            if (str[i] == ')' && topElem != '(')
                return false;
            if (str[i] == ']' && topElem != '[')
                return false;
            if (str[i] == '}' && topElem != '{')
                return false;
        }
    }
    //检索完所有后，如果栈空，说明匹配成功
    return s.empty();
}

int main() {
    char *str = "((({})))[]";
    if (bracketCheck(str, strlen(str)))
        printf("yes\n");
    else
        printf("no\n");
    return 0;
}