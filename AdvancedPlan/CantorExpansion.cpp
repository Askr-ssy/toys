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

auto dece(int n,const std::vector<int> nums){
    std::vector<int> result {};
    int j = nums.size()-1;
    std::vector<int> temp_result  = nums;
    while(true){
        if (--j <0)break;
        int _recv = recv(nums[j]);
        int temp = n / _recv;        
        result.push_back(temp_result[temp]);
        temp_result.erase(temp_result.begin()+temp);
        n = n % _recv;
    }
    result.push_back(temp_result[0]);
    return result;
}


int main(void){
    std::vector<int> nums{
        3,4,1,5,2
    };
    std::cout<<ce(nums)+1<<std::endl;
    std::vector<int> result = dece(ce(nums),{1,2,3,4,5});
    for (auto x : result)std::cout<<x<<" ";

    return 0;
}