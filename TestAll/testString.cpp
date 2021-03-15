#include <bits/stdc++.h>
//#include <iostream>
using namespace std;

int main() {
    string s = "1523525431873";
//    for (int i = 0; i < s.length(); ++i)
//        cout << s[i];
//
//    cout << '\n';
//    for (string::iterator iter = s.begin(); iter != s.end(); iter++)
//        cout << *iter;
//
//    cout << '\n';
//    for (auto i : s)
//        cout << i;
//
//
//    cout << endl << s;
//    string a(s.begin() + 2, s.end() - 2);
//    cout << a << endl;
//    a.append("as");
//    cout << a << endl;
//    a.replace(a.find('a'), 1,"===");
//    cout << a << endl;
//    cout << a.find('5') << endl;
//    cout << a.find("254") << endl;
//    cout << a.length() << s.size();
////    cout<<s(s.begin(), s.end());
    map<string, string> dict;
    dict["a"] = "2";
    dict["b"] = "wwdew";
    dict.insert(pair<string , string> ("qq", "qwqwqw5"));
    for(const auto& item: dict){
        cout<<item.first<<" "<<item.second<<endl;
    }
    vector<int> v{1,2,3,4};
    int c = v.size();
    for (int i=0;i<c;i++){
        cout<<v[i]<<"  ";
    }
    return 0;
}