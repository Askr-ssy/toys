#include<iostream>
#include<string>
using namespace std;
class Solution {
public:
    bool isSubsequence(string s, string t) {
        int s1=0,t1=0;
        if (s.empty())
            return true;
        for (int i=0;i<t.size();++i){
            if (t[i]==s[s1])s1++;
        }
        if (s1==s.size())return true;
        
        return false;
    }
};
int main(void){
    Solution sol;
    string s{"123"},t{"14563"};
    cout<<sol.isSubsequence(s,t)<<endl;
}