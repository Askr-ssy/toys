#include<vector>
#include<algorithm>
#include<cmath>
#include<iostream>
using namespace std;
int lastStoneWeight(vector<int>& stones) {
    if (stones.size()==1)return stones[0];
    if (stones.size()==2)return abs(stones[0]-stones[1]);
    sort(stones.begin(),stones.end());
    if (stones[stones.size()-3]==0) return stones[stones.size()-1]-stones[stones.size()-2];
    stones[stones.size()-2] = stones[stones.size()-1] - stones[stones.size()-2];
    stones.pop_back();
    return lastStoneWeight(stones);
}
int main(void){
    vector<int> stones{2,7,4,1,8,1};
    lastStoneWeight(stones);
}