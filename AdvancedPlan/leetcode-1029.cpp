#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;
int twoCitySchedCost(vector<vector<int>>& costs) {
    sort(costs.begin(),costs.end(),[](vector<int> a,vector<int> b){
        return (a[1]-a[0])>(b[1]-b[0]);
    });
    int sum=0;
    for(int i=0;i<costs.size();++i){
        if (i<costs.size()/2)sum+=costs[i][0];
        else sum+=costs[i][1];
    }
    return sum;
}
int main(){
    vector<vector<int>> consts;
    consts.push_back(vector<int>{30,200});
    consts.push_back(vector<int>{10,20});
    consts.push_back(vector<int>{400,50});
    consts.push_back(vector<int>{30,20});
    cout<<twoCitySchedCost(consts)<<endl;
}