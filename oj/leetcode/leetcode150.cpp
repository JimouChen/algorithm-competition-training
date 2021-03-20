# include <bits/stdc++.h>
using namespace std;
//逆波兰表达式
class Solution {
public:
    int evalRPN(vector<string> &tokens) {
        stack<int> stack;
        for (int i = 0; i < tokens.size(); i++) {
            string the = tokens[i];
            if (!(the == "+" || the == "-" || the == "*" || the == "/")) {
                stack.push(stoi(the));
            } else {
                int n1 = stack.top();
                stack.pop();
                int n2 = stack.top();
                stack.pop();
                if (the == "+") stack.push(n2 + n1);
                else if (the == "-") stack.push(n2 - n1);
                else if (the == "*") stack.push(n2 * n1);
                else stack.push(n2 / n1);
            }
        }
        return stack.top();
    }
};

int main() {
    vector<string> v{"10","6","9","3","+","-11","*","/","*","17","+","5","+"};
    Solution s;
    cout << s.evalRPN(v) << endl;
    return 0;
}