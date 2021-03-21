//#include <bits/stdc++.h>
//using namespace std;
//
//int main() {
//    char str[10];
//    while(cin >> str){
//        int len = strlen(str);
//        do {
//            cout << str << endl;
//        } while (next_permutation(str, str + len));
//    }
//
//    return 0;
//}

#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

int main()
{
    char str[7];
    while(scanf("%s", str) != EOF)
    {
        int len = strlen(str);
        do
        {
            printf("%s\n", str);
        }while(next_permutation(str, str+len));
    }
    printf("\n");
    return 0;
}