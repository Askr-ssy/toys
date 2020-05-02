#include<vector>
#include<iostream>
using namespace std;
bool canJump(vector<int>& nums) {
    if (nums.size()==1)return true;
    int maxJump = 0;    //最远距离 小于这个数量的默认可达
    for(int i=0;i<nums.size();++i){
        if (i<=maxJump)
            if((i+nums[i])>maxJump)
                maxJump=nums[i]+i;
    }
    return maxJump>=nums.size()-1?true:false;
}

int main(void){
    vector<int> arr{2,0,0};
    cout<<canJump(arr)<<endl;
}