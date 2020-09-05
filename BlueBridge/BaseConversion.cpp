#include <bits/stdc++.h>
using namespace std;
int main(){
    int a=0;
    cin>>a;
    char str[100];
//    itoa(a, str, 16);
    sprintf(str, "%x", a);

    for (int i = 0; i < strlen(str); ++i) {
        if (str[i]>='a' && str[i]<='z'){
            str[i] = char(str[i] - 32);
        }
    }
    cout<<str;
    return 0;
}