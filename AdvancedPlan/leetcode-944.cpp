#include<vector>
#include<iostream>
#include<string>
using namespace std;
int minDeletionSize(vector<string>& A) {
    if (A.empty())return 0;
    int d = 0;
    for (int i=0;i<A[0].size();++i){
        for (int j=0;j<A.size()-1;++j){
            if (A[j][i]>A[j+1][i]){ d++;break;}
        }
    }
    return d;
}