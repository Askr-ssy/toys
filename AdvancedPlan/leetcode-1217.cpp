#include<vector>
#include<iostream>
using namespace std;
int minCostToMoveChips(vector<int>& chips) {
    int a=0,b=0;    //奇数，偶数
    for (int j =0;j<chips.size();++j)if (chips[j]%2==0)b++;else a++;
    return a<b?a:b;
}