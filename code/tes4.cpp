#include <bits/stdc++.h>
using namespace std;


int main(){
    char *str = (char *)malloc(10);
    strcpy(str, "hello");
    char *str1 = str;
    cout << (int*)str << endl;
    cout << (int*)str1 << endl;
    free(str);
    if(str == nullptr){
        strcpy(str, "world");
    }
    cout << bitset<2>(str) << endl;
    //cout << (int*)str1 << endl;
    return 0;
}