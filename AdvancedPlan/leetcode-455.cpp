#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;
int findContentChildren(vector<int>& g, vector<int>& s) {
    sort(g.begin(),g.end());
    sort(s.begin(),s.end());
    int res=0;
    for(int s1=0;s1<s.size();++s1){
        if(s[s1]>=g[res]){res++;}
        if(res==g.size())break;
    }
    return res;
}
