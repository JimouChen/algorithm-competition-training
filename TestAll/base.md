# string
## 输入输出字符串
```c++
#include <bits/stdc++.h>
using namespace std;

int main(){
//    string s = "12312hello world...";
    string s;
    getline(cin, s);//输入字符串
    cout<<s;
    return 0;
}
```
```
21314 hello woefsdcsd
21314 hello woefsdcsd
Process finished with exit code 0
```
## 字符串拼凑
```c++
#include <bits/stdc++.h>
using namespace std;

int main(){
//    string s = "12312hello world...";
    string s;
    s += "shda s";
    s += "shda s";
    s += '5';

    cout<<s;
    return 0;
}
```
```
shda sshda s5
Process finished with exit code 0
```
## 排序
```c++
#include <bits/stdc++.h>

using namespace std;

int main() {
    string s = "1523525431873";
    sort(s.begin(), s.end());
    cout << s;
    return 0;
}
```
```
1122333455578
Process finished with exit code 0
```
- ```s.begin(), s.end()```是迭代器，可以看成是指针
- 如果要访问最后一个字符，应该是```*(--s.end())```

## erase删除
```c++
#include <bits/stdc++.h>

using namespace std;

int main() {
    string s = "1523525431873";
    s.erase(s.begin());
    s.erase(--s.end());
    cout << s;
    return 0;
}
```
```
52352543187
Process finished with exit code 0
```

## substr取子串
```c++
#include <bits/stdc++.h>

using namespace std;

int main() {
    string s = "1523525431873";
    s = s.substr(2, 3);//从索引为2开始取，往后取三个
    cout << s;
    s = "1523525431873";
    s = s.substr(6, -1);//从索引为6开始取，直到最后一个
    cout << endl << s;
    return 0;
}
```
```
235
5431873
Process finished with exit code 0
```

## 几种循环方式
```c++
#include <bits/stdc++.h>

using namespace std;

int main() {
    string s = "1523525431873";
    for (int i = 0; i < s.length(); ++i)
        cout << s[i];

    cout << '\n';
    for (string::iterator iter = s.begin(); iter != s.end(); iter++)
        cout << *iter;
    
    cout << '\n';
    for (auto i : s)
        cout << i;


    cout << endl << s;
    return 0;
}
```
```
1523525431873
1523525431873
1523525431873
1523525431873
Process finished with exit code 0

```
# vector
## 初始化、打印
```c++
#include <bits/stdc++.h>

using namespace std;

int main() {
    vector<int> v(3, 1);//初始化3个1
    vector<int> v1(3);//初始化3个0
    vector<int> v2{1, 2, 3, 4, 5};//初始化5个数
    for (auto x:v)cout << x;
    cout << '\n';
    for (auto x:v1)cout << x;
    cout << '\n';
    for (auto x:v2)cout << x;
    cout << '\n';
    return 0;
}
```
```
111
000
12345

Process finished with exit code 0
```
## 取元素 []或者at()
```c++
#include <bits/stdc++.h>

using namespace std;

int main() {
    vector<int> v{1, 2, 3, 4, 5};//初始化5个数
    //取某个元素
    cout<<v[2];//取索引为2 元素
    cout<<v.at(4);//取索引为4的元素
    return 0;
}
```
## 追加push_back
```c++
#include <bits/stdc++.h>

using namespace std;

int main() {
    vector<int> v{1, 2, 3, 4, 5};//初始化5个数
    v.push_back(7);
    v.push_back(7);
    v.push_back(7);
    for (auto x:v) cout << x;
    return 0;
}
```
```
12345777
Process finished with exit code 0
```
## resize重置大小，后面补0
```c++
#include <bits/stdc++.h>

using namespace std;

int main() {
    vector<int> v{1, 2, 3, 4, 5};//初始化5个数
    v.push_back(7);
    v.push_back(7);
    v.push_back(7);
    for (auto x:v) cout << x;
    v.resize(20);//进行重置大小，后面补0
    cout<<endl;
    for (auto x:v) cout << x;
    return 0;
}
```
```
12345777
12345777000000000000
Process finished with exit code 0
```
## erase删除，在vector中的复杂度为O(n)
```c++
#include <bits/stdc++.h>

using namespace std;

int main() {
    vector<int> v{1, 2, 3, 4, 5};//初始化5个数
    v.push_back(7);
    v.push_back(7);
    v.push_back(7);
    for (auto x:v) cout << x;
    cout<<endl;
    //删除,在这里的复杂度为O(n)
    v.erase(v.begin());
    v.erase(--v.end());
    for (auto x:v) cout << x;

    return 0;
}
```
```
12345777
234577
Process finished with exit code 0
```
## front(),back()
```c++
#include <bits/stdc++.h>

using namespace std;

int main() {
    vector<int> v{1, 2, 3, 4, 5};//初始化5个数
    v.push_back(7);
    v.push_back(7);
    v.push_back(7);
    for (auto x:v) cout << x;
    cout << endl;
    //取元素
    cout << v.front() << ' ' << v.back() << endl;
    cout << *v.begin() << ' ' << *(--v.end()) << ' ' << v[v.size() - 1];
    return 0;
}
```
```
12345777
1 7
1 7 7
Process finished with exit code 0
```
## 排序sort
```c++
#include <bits/stdc++.h>

using namespace std;

int main() {
    vector<int> v{1, 55, 15, 4, 25};//初始化5个数
    v.push_back(7);
    v.push_back(7);
    v.push_back(7);
    for (auto x:v) cout << x << ' ';
    cout << endl;

    sort(v.begin(), v.end());
    for (auto x:v) cout << x << ' ';
    cout << endl;

    sort(v.rbegin(), v.rend());
    for (auto x:v) cout << x << ' ';
    cout << endl;

    return 0;
}
```
```
1 55 15 4 25 7 7 7
1 4 7 7 7 15 25 55
55 25 15 7 7 7 4 1

Process finished with exit code 0
```
- 从大到小还可以用
```sort(v.begin(), v.end(), greater<>());```
## 循环与string的类似
- 用的较多的是```for (auto x:v) cout << x << ' ';```

# stack
## 初始化
- 一般刷算法题都直接这样写``` stack<int> s;```
- 如果不用```<bits/stdc++.h>```,那要用```<stack>```
```c++
#include <bits/stdc++.h>
using namespace std;
int main() {
    stack<int> s;
    cout << endl;
    return 0;
}
```
## push, pop, top
```c++
#include <bits/stdc++.h>

using namespace std;

int main() {
    stack<int> s;
    s.push(2);
    s.push(1);
    s.push(3);
    cout << s.top();
    s.pop();
    cout << s.top();
    return 0;
}
```
```
31
```
- push 入栈
- pop出栈
- top取栈顶
- size取长度
- ```cout << s.empty();``` 是空就返回1，否则为0
## 十进制转二进制
```c++
#include <bits/stdc++.h>

using namespace std;

int tenToTwo(int decimal) {
    stack<int> s;
    int res = 0;
    while (decimal != 0) {
        s.push(decimal % 2);
        decimal /= 2;
    }
    while (!s.empty()) {
        res = res * 10 + s.top();
        s.pop();
    }
    return res;
}

int main() {
    cout << tenToTwo(11);
    return 0;
}
```
```
1011
Process finished with exit code 0
```
## 逆序输出句子单词
```c++
#include <bits/stdc++.h>
using namespace std;
int main() {
    stringstream ss;
    string str;
    getline(cin, str);
    ss << str;
    stack<string> s;
    while (ss >> str) {
        s.push(str);
    }
    while (!s.empty()) {
        cout << s.top();
        if (s.size() != 1) cout << ' ';
        s.pop();
    }
    return 0;
}

```
```
we are young man
man young are we
Process finished with exit code 0
```

## 字符串转化为数字
### 方法一
```c++
#include <bits/stdc++.h>
using namespace std;
int main() {
    stringstream ss;
    string str = "12455";
    //把字符串转换为数字
    ss << str;//先把“12345”流入ss
    int num;
    ss >> num;//再从ss流入整型num
    cout << num;
    return 0;
}
```
```
12455
Process finished with exit code 0
```
### 方法二
```c++
int main() {
    stringstream ss;
    string str = "12455";
    //把字符串转换为数字
    int num = stoi(str);
    cout << num;
    return 0;
}
```
```
12455
Process finished with exit code 0
```c++
## 数字转换为字符串
### 方法一
```
#include <bits/stdc++.h>
using namespace std;

int main() {
    stringstream ss;
    string str;
    //数字转化为字符串
    int num = 12556;
    ss << num;
    ss >> str;
    cout << str;
    return 0;
}
```
```
12556
Process finished with exit code 0
```
### 方法二
```c++
#include <bits/stdc++.h>
using namespace std;

int main() {
    stringstream ss;
    string str;
    //数字转化为字符串
    int num = 12556;
    str = to_string(num);
    cout << str;
    return 0;
}
```
```
12556
```
# queue

```c++
#include <bits/stdc++.h>
using namespace std;

int main() {
    queue<int> q;
    q.push(4);
    q.push(3);
    q.push(5);
    cout<<q.size()<<' '<<q.front();
    return 0;
}
```
```
3 4
```
# map 和 unordered_map
- map: 有序的，底层是树状结构
```c++
#include <bits/stdc++.h>

using namespace std;

int main() {
    map<int, int> dict;
    dict[1] = 2;
    dict[2] = 0;
    dict[4] = 12;
    //打印
    for (auto item: dict)
        cout << item.first << ' ' << item.second << endl;
    //另一种打印方式
    for (auto iterator = dict.begin(); iterator != dict.end(); iterator++)
        cout << iterator->first << ' ' << iterator->second << endl;
    return 0;
}
```
1 2
2 0
4 12
1 2
2 0
4 12

Process finished with exit code 0
```
- unordered——map：无序的，底层是哈希结构
```c++
#include <bits/stdc++.h>

using namespace std;

int main() {
    unordered_map<int, int> dict;
    dict[1] = 2;
    dict[2] = 0;
    dict[4] = 12;
    //打印
    for (auto item: dict)
        cout << item.first << ' ' << item.second << endl;
    //另一种打印方式
    for (auto iterator = dict.begin(); iterator != dict.end(); iterator++)
        cout << iterator->first << ' ' << iterator->second << endl;
    return 0;
}
```
```
4 12
1 2
2 0
4 12
1 2
2 0
Process finished with exit code 0

```
- 打印出来是无序的
# set
```c++
#include <bits/stdc++.h>

using namespace std;


int main() {
    unordered_set<int> s;
//    set<int> s;
    s.insert(2);
    s.insert(2);
    s.insert(3);

    cout << s.size();
    for (auto i:s)
        cout << i;
    return 0;
}
```
```
232
Process finished with exit code 0
```

# deque
```c++
#include <bits/stdc++.h>
using namespace std;

int main() {
    deque<int> deque;
    deque.push_back(1);
    deque.push_back(2);
    deque.push_front(3);
    deque.push_front(4);
    for (auto i: deque)
        cout << i;
    deque.pop_back();
    deque.pop_front();
    cout<<endl;
    for (auto i: deque)
        cout << i;
    return 0;
}
```

```
4312
31
Process finished with exit code 0
```
## 可以排序
```c++
#include <bits/stdc++.h>

using namespace std;


int main() {
    deque<int> deque;
    deque.push_back(1);
    deque.push_back(2);
    deque.push_front(3);
    deque.push_front(4);
    for (auto i: deque)
        cout << i;
    sort(deque.begin(), deque.end());
    cout<<endl;
    for (auto i: deque)
        cout << i;
    return 0;
}
```
```
4312
1234
Process finished with exit code 0
```

# list
```c++
#include <bits/stdc++.h>

using namespace std;


int main() {
    list<int> list;
    list.push_front(2);
    list.push_front(3);
    list.push_back(4);
    list.push_back(1);
    for (auto i: list)
        cout << i << ' ';
    cout << endl;
    //插入
    list.insert(++list.begin(), 99);
    for (auto i: list)
        cout << i << ' ';
    cout << endl;
    //里面的值
    list.remove(3);
    for (auto i: list)
        cout << i << ' ';
    return 0;
}
```
```
3 2 4 1
3 99 2 4 1
99 2 4 1
Process finished with exit code 0
```