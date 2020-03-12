#include<set>
#include<unordered_set>
#include<iostream>
#include<iterator>
#include<vector>
#include<cmath>
#include<algorithm>
#include<array>
int recv(int n)
{
    if(1 == n || n==0)
    {
        return 1;
    }
    return n * recv(n - 1);
}
int ce(std::vector<int> nums){
    int sum = 0;
    for (int i=0;i<nums.size();++i){
        int count = 0;
        for(int j=i+1;j<=nums.size();++j){
            if (nums[i]>nums[j])count+=1;
        }
        sum += (count-1) * recv(nums.size()-(i+1));
    }   
    return sum;
}

auto dece(int n,std::vector<int> nums){
    std::vector<int> result {};
    --n;
    std::cout<<nums[nums.size()-2]<<std::endl;
    while(n){
        // n
    }
}


int main(void){
    std::vector<int> nums{
        3,4,1,5,2
    };
    std::cout<<ce(nums)+1<<std::endl;
    dece(ce(nums),{1,2,3,4,5});
    return 0;
}