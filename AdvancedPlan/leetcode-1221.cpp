#include<stack>
#include<string>
using namespace std;
int balancedStringSplit(string s) {
    int flag = 0;
    int l=0,r=0;
    for (int i=0;i<s.size();++i){
        if (s[i]=='L')l++;
        else if (s[i]=='R')r++;
         
        if (l==r){
            l=0;
            r=0;
            ++flag;
        }
    }
    return flag;
}
