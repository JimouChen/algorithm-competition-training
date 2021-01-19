#include <iostream>
#include <cstring>

using namespace std;
int main(){
    char s[] = "apple";
    char s1[] = "";
    strcpy(s1, s);
    cout<<s1<<endl;

    return 0;
}