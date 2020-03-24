#include<vector>
#include<iostream>
using namespace std;
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int sum=0;
        for (int i=0;i<prices.size();++i){
            if (i>0 && prices[i]>prices[i-1])
                sum += prices[i]-prices[i-1];
        }
        return sum;
    }
};
int main(void){
    Solution sol;
    vector<int>arr{1,2,3,4,5};
    cout<<sol.maxProfit(arr)<<endl;
}